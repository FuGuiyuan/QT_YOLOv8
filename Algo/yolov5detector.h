#ifndef YOLOV5DETECTOR_H
#define YOLOV5DETECTOR_H

#include "Algo/AlgoInterface.h"
#include <fstream>

class YOLOv5Detector:public YOLOInterface
{
public:
    YOLOv5Detector();

    void initConfig(dataSettings &settings) override;

    void infer_frame(cv::Mat &frame) override;

private:
    cv::dnn::Net net;
    bool show_fps = true;
    bool show_score = true;
    float score = 0.5;
    float conf = 0.5; //置信度
    int input_w = 640;
    int input_h = 640;

    std::vector<std::string> class_names;

};

#endif // YOLOV5DETECTOR_H
