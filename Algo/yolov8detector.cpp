#include "yolov8detector.h"

YOLOv8Detector::YOLOv8Detector() {}

void YOLOv8Detector::initConfig(dataSettings &settings)
{
    // 加载ONNX文件里的模型到net中
    net = cv::dnn::readNetFromONNX(settings.getWeight_file());
    //cv::dnn::DNN_BACKEND_OPENCV 表示使用OpenCV自带的深度学习后端
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    //cv::dnn::DNN_TARGET_CPU 表示使用CPU进行计算
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    score= settings.getT_score();
    input_w = settings.getInput_w();
    input_h = settings.getInput_h();
    show_fps = settings.getShow_fps();
    show_score = settings.getShow_score();

    // 读取标签文件  标签文件里存放的是各个种类
    std::ifstream fp(settings.getConfig_file());
    if (!fp.is_open())
    {
        printf("could not open file...\n");
        exit(-1);
    }
    std::string name;
    while (!fp.eof())
    {
        std::getline(fp, name);
        if (name.length())
            class_names.push_back(name);
    }
    fp.close();

}

void YOLOv8Detector::infer_frame(cv::Mat &frame)
{
    int64 start = cv::getTickCount();

    // 图象预处理 - 格式化操作   必须要和网络模型要求的输入大小一致
    int w = frame.cols;
    int h = frame.rows;
    int _max = std::max(h, w); // 计算宽度和高度中的较大值
    cv::Mat image = cv::Mat::zeros(cv::Size(_max, _max), CV_8UC3);
    cv::Rect roi(0, 0, w, h);
    frame.copyTo(image(roi));// 注意：！！！是将原始图像frame的内容复制到新图像image的roi区域内 不要搞反

    float x_factor = image.cols / 640.0f;
    float y_factor = image.rows / 640.0f;

    // 推理
    //用于将图像转换为深度学习模型所需的输入格式，即“blob”。这个函数特别适用于那些接受固定大小输入的模型
    cv::Mat blob = cv::dnn::blobFromImage(image,
                                          1 / 255.0,  // 图像像素值的缩放因子。这里将像素值从[0, 255]范围缩放到[0, 1]范围。
                                          cv::Size(640, 640), // 输出blob的大小。这表示无论输入图像的大小如何，它都会被缩放（或填充）到640x640像素。
                                          cv::Scalar(0, 0, 0), // 在图像缩放后填充边缘时使用的颜色。这里使用黑色（RGB值为(0, 0, 0)。
                                          true, // 表示是否交换图像的通道顺序，以匹配某些深度学习框架的输入要求（例如，从BGR转换为RGB）
                                          false);  // 表示是否对图像进行裁剪以适合目标大小。在这个例子中，我们不进行裁剪，而是使用填充（由前面的cv::Size和cv::Scalar参数控制）。

    //预处理后的图像数据（即blob）设置为深度学习模型的输入  net是前面已经加载并配置好的深度学习网络对象
    //一旦数据被正确设置，网络就准备好进行前向传播计算了
    net.setInput(blob);
    // 执行前向传播计算，并获取预测结果
    cv::Mat preds = net.forward();

    // 后处理, 1x84x8400
    // preds.size[1]就是84  preds.size[2]是8400
    // 84分别代表cx, cy, w, h, 后面 80 个是 MSCOCO 的分类得分  得分最高的就是检测出的类别
    // 总预测的目标框数目：20x20+40x40+80x80=8400
    cv::Mat detOut(preds.size[1], preds.size[2], CV_32F, preds.ptr<float>());
    cv::Mat det_output = detOut.t();  //转置  8400x84
    std::vector<cv::Rect> boxes; //记录边界框
    std::vector<int> classIds;  //记录种类ID
    std::vector<float> confidences; //记录得分
    for (int i = 0; i < det_output.rows; i++) {
        //访问矩阵中特定位置的元素，i是行索引，4是列索引。
        //yolov8和yolov5的区别就是没有边框置信度
        //float confidence = det_output.at<float>(i, 4);
        cv::Mat classes_scores = det_output.row(i).colRange(4, preds.size[1]);//截取4到85的范围
        cv::Point classIdPoint;//cv::Point 是一个用于表示二维空间点的类 这里用来记录类别里最大值所在的位置坐标
        double score;  //用来记录最大值是几
        //寻找数组或矩阵中的最小值和最大值
        minMaxLoc(classes_scores, //输入参数，代表需要搜索的数组或矩阵
                  0, //输出参数，用于存储找到的最小值
                  &score, //输出参数，用于存储找到的最大值
                  0, //输出参数，用于记录最小值所在的位置（坐标）
                  &classIdPoint); //输出参数，用于记录最大值所在的位置（坐标）

        // 置信度 0～1之间
        if (score > this->score)
        {
            //0-3代表的是x y w c h
            float cx = det_output.at<float>(i, 0);
            float cy = det_output.at<float>(i, 1);
            float ow = det_output.at<float>(i, 2);
            float oh = det_output.at<float>(i, 3);
            //放缩为原始图像大小的x y w h
            int x = static_cast<int>((cx - 0.5 * ow) * x_factor);
            int y = static_cast<int>((cy - 0.5 * oh) * y_factor);
            int width = static_cast<int>(ow * x_factor);
            int height = static_cast<int>(oh * y_factor);

            cv::Rect box;
            box.x = x;
            box.y = y;
            box.width = width;
            box.height = height;

            boxes.push_back(box);
            classIds.push_back(classIdPoint.x);
            confidences.push_back(score);
        }
    }

    std::vector<int> indexes;//记录输出保留的检测框的索引
    // NMS  去掉多余的框 选择得分最大的框
    // 0.25得分阈值  0.50 NMS阈值
    cv::dnn::NMSBoxes(boxes,  // 输入的检测框
                      confidences, // 与检测框对应的置信度
                      0.25,  // 置信度阈值，低于此值的检测框将被丢弃
                      0.50, // 非极大值抑制的阈值，控制重叠程度
                      indexes); // 输出保留的检测框的索引

    for (size_t i = 0; i < indexes.size(); i++) {
        int index = indexes[i];
        int idx = classIds[index];
        //cv::rectangle在图像上绘制矩形
        //绘制检测框
        cv::rectangle(frame, boxes[index], cv::Scalar(0, 0, 255), 2, 8);
        //在检测框上20像素位置绘制一个矩形 用来书写内容
        cv::rectangle(frame, cv::Point(boxes[index].tl().x, boxes[index].tl().y - 20),
                      cv::Point(boxes[index].br().x, boxes[index].tl().y), cv::Scalar(255, 255, 255), -1);
        //用来在上面绘制的矩形里写上检测到的类别
        cv::putText(frame, class_names[idx], cv::Point(boxes[index].tl().x, boxes[index].tl().y - 10), cv::FONT_HERSHEY_SIMPLEX, .5, cv::Scalar(0, 0, 0));
    }
    //计时器读数结束
    float t = (cv::getTickCount() - start) / static_cast<float>(cv::getTickFrequency());
    //在图像上添加文本 输出帧率
    putText(frame, cv::format("FPS: %.2f", 1.0 / t), cv::Point(20, 40), cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(255, 0, 0), 2, 8);

}
