#ifndef YOLOV5FACEDETECTIONUI_H
#define YOLOV5FACEDETECTIONUI_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QLabel>
class YOLOv5FaceDetectionUI:public QWidget
{
    Q_OBJECT
public:
    YOLOv5FaceDetectionUI();

    void initUI();


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
    QDoubleSpinBox* scoreSpinBox{nullptr};

    QLabel* imgLabel{nullptr};
    QPushButton* runBtn{nullptr};
};

#endif // YOLOV5FACEDETECTIONUI_H
