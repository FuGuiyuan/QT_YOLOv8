#include "objectdetectorthread.h"
#include "Algo/ObjectDetectorFactory.h"
ObjectDetectorThread::ObjectDetectorThread(dataSettings &DS) {
    detector = ObjectDetectorFactory::createDetector(DS.getName());
    detector->initConfig(DS);
    filePath = DS.getData_path();
}

void ObjectDetectorThread::run()
{
    QString path = QString::fromStdString(filePath);
    //std::vector<ODResultBox> boxes;

    //图片文件处理
    if(path.endsWith(".jpg") || path.endsWith(".png")) {
        cv::Mat frame = cv::imread(filePath);
        detector->infer_frame(frame);

        emit sendResult(frame);
    }

    //视频文件处理   就是处理多张图片 每处理一帧就发送一次信号
    if(path.endsWith(".mp4"))
    {
        cv::VideoCapture capture(filePath);
        cv::Mat frame;
        //boxes.clear(); //每次用完后clear掉
        while(true)
        {
            capture.read(frame);
            if(frame.empty())
            {
                break;
            }
            detector->infer_frame(frame);
            emit sendResult(frame);
        }
    }


    //最后结束发一张空
    cv::Mat empty_img;
    emit sendResult(empty_img);
}
