#ifndef OBJECTDETECTORTHREAD_H
#define OBJECTDETECTORTHREAD_H

#include <QThread>
#include "Algo/AlgoInterface.h"
class ObjectDetectorThread:public QThread
{
    Q_OBJECT
public:
    ObjectDetectorThread(dataSettings &DS);

protected:
    void run() override;

signals:
    //每检测完一张图片就发送一次信号
    void sendResult(cv::Mat);

private:
    std::string filePath;
    std::shared_ptr<YOLOInterface> detector{nullptr};

};

#endif // OBJECTDETECTORTHREAD_H
