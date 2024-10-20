#ifndef ALGOINTERFACE_H
#define ALGOINTERFACE_H

#include "opencv2/opencv.hpp"
#include "datasettings.h"

class YOLOInterface
{
public:
    virtual void initConfig(dataSettings &settings)=0;
    virtual void infer_frame(cv::Mat &frame)=0;
};


#endif // ALGOINTERFACE_H
