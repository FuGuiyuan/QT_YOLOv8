#ifndef YOLOV8DETECTOR_H
#define YOLOV8DETECTOR_H

#include "Algo/AlgoInterface.h"
#include <fstream>
class YOLOv8Detector:public YOLOInterface
{
public:
    YOLOv8Detector();

    void initConfig(dataSettings &settings) override;

    void infer_frame(cv::Mat &frame) override;

private:
    cv::dnn::Net net;
    //yolov8不需要置信度
    float score = 0.25;
    int input_w = 640;
    int input_h = 640;
    bool show_fps = true;
    bool show_score = true;

    std::vector<std::string> class_names;  //种类标签
};

#endif // YOLOV8DETECTOR_H
