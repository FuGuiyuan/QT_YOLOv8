#ifndef OBJECTDETECTORFACTORY_H
#define OBJECTDETECTORFACTORY_H
#include "Algo/AlgoInterface.h"

class ObjectDetectorFactory
{
public:
    //工厂模式 抽象各种算法接口
    static std::shared_ptr<YOLOInterface> createDetector(DETECT_ALGO_TYPE type);

};

#endif // OBJECTDETECTORFACTORY_H
