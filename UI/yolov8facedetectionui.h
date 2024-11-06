#ifndef YOLOV8FACEDETECTIONUI_H
#define YOLOV8FACEDETECTIONUI_H

#include <QWidget>
#include "objectdetectorthread.h"
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>
class YOLOv8FaceDetectionUI:public QWidget
{
    Q_OBJECT
public:
    YOLOv8FaceDetectionUI();

    void initUI();

public slots:

    void selectImg();

    void selectWeightFile();

    void selectConfigFile();

    void runYoloDetection();

    void showDetectedImage(cv::Mat frame);

private:
    QRadioButton* imgFileBtn{nullptr};
    QRadioButton* videoFileBtn{nullptr};
    QLineEdit* dataFilePath{nullptr};
    QPushButton* chooseImgBtn{nullptr};

    QLineEdit* weightFilePath{nullptr};
    QLineEdit* configFilePath{nullptr};
    QPushButton* chooseWeightBtn{nullptr};
    QPushButton* chooseConfigBtn{nullptr};

    QCheckBox* showFPSCheck{nullptr};
    QCheckBox* showScoreCheck{nullptr};
    //QDoubleSpinBox* configSpinBox{nullptr};
    QDoubleSpinBox* scoreSpinBox{nullptr};

    QLabel* imgLabel{nullptr};
    QPushButton* runBtn{nullptr};

    ObjectDetectorThread *workThread;

};

#endif // YOLOV8FACEDETECTIONUI_H
