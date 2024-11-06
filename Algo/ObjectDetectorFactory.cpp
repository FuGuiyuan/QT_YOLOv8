#include "ObjectDetectorFactory.h"

#include "Algo/yolov5detector.h"
#include "Algo/yolov8detector.h"
std::shared_ptr<YOLOInterface> ObjectDetectorFactory::createDetector(DETECT_ALGO_TYPE type)
{
    if(type == DETECT_ALGO_TYPE::YOLOv5_DNN)
    {
        return std::make_shared<YOLOv5Detector>();
    }
    else if(type == DETECT_ALGO_TYPE::YOLOv8_DNN)
    {
        return std::make_shared<YOLOv8Detector>();
    }
}
