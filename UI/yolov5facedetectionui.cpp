#include "yolov5facedetectionui.h"
#include<QDebug>

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
YOLOv5FaceDetectionUI::YOLOv5FaceDetectionUI() {
    qDebug()<<"YOLOv5FaceDetectionUI 构造函数";
    initUI();
}

void YOLOv5FaceDetectionUI::initUI()
{


    imgFileBtn = new QRadioButton("图片文件");
    videoFileBtn = new QRadioButton("视频文件");
    dataFilePath = new QLineEdit();
    dataFilePath->isReadOnly();
    chooseImgBtn =new QPushButton();

    QGroupBox* dataBox = new QGroupBox("数据");
    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addWidget(imgFileBtn);
    hbox1->addWidget(videoFileBtn);
    hbox1->addWidget(dataFilePath);
    hbox1->addWidget(chooseImgBtn);
    dataBox->setLayout(hbox1);


    weightFilePath = new QLineEdit();
    configFilePath = new QLineEdit();
    weightFilePath->setEnabled(false);
    configFilePath->setEnabled(false);
    chooseWeightBtn = new QPushButton("选择权重文件");
    chooseConfigBtn = new QPushButton("选择配置文件");

    QGroupBox* modelBox = new QGroupBox("模型");
    QHBoxLayout* hbox2 = new QHBoxLayout;
    hbox2->addWidget(new QLabel("权重文件"));
    hbox2->addWidget(weightFilePath);
    hbox2->addWidget(chooseWeightBtn);
    hbox2->addWidget(new QLabel("配置文件"));
    hbox2->addWidget(configFilePath);
    hbox2->addWidget(chooseConfigBtn);
    modelBox->setLayout(hbox2);

    showFPSCheck = new QCheckBox("FPS");
    showScoreCheck = new QCheckBox("置信度");
    scoreSpinBox = new QDoubleSpinBox();
    scoreSpinBox->setRange(0,1);
    scoreSpinBox->setSingleStep(0.01);
    scoreSpinBox->setValue(0.5);

    QGroupBox* showBox = new QGroupBox("模型");
    QHBoxLayout* hbox3 = new QHBoxLayout;
    hbox3->addWidget(showFPSCheck);
    hbox3->addWidget(showScoreCheck);
    hbox3->addWidget(new QLabel("得分:"));
    hbox3->addWidget(scoreSpinBox);
    showBox->setLayout(hbox3);

    runBtn = new QPushButton("运行");
    QHBoxLayout *hbox4 = new QHBoxLayout();
    QWidget *runWidget = new QWidget();
    //hbox4->addStretch(1);
    hbox4->addWidget(runBtn);
    runWidget->setLayout(hbox4);

    QWidget* showBtnWidget = new QWidget();
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(dataBox);
    vbox->addWidget(modelBox);
    vbox->addWidget(showBox);
    vbox->addWidget(runWidget);
    //vbox->addStretch(1);
    showBtnWidget->setLayout(vbox);



    QPixmap  pixmap("C:/Users/15648/Pictures/Saved Pictures/sp_noise.png");
    imgLabel=new QLabel();
    imgLabel->setAlignment(Qt::AlignCenter);
    imgLabel->setStyleSheet("background-color:rgb(0,0,0)");
    imgLabel->setPixmap(pixmap);
    //imgLabel->setFixedSize(800,550);

    QWidget* showImgWidget = new QWidget();
    QVBoxLayout *vbox1 = new QVBoxLayout();
    vbox1->addWidget(imgLabel);
    showImgWidget->setLayout(vbox1);


    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(showBtnWidget);
    splitter->addWidget(showImgWidget);
    splitter->setStretchFactor(0,1);//索引位置0占用的比例是1  第一个窗口占用的比例
    splitter->setStretchFactor(1,2); //索引位置1占用的比例是2   第二个窗口占用的比例

    QHBoxLayout* hboxmain =new QHBoxLayout;
    hboxmain->addWidget(splitter);
    this->setLayout(hboxmain);
}
