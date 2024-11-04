#include "yolov5facedetectionui.h"
#include<QDebug>

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QFileDialog>
#include "Algo/datasettings.h"

YOLOv5FaceDetectionUI::YOLOv5FaceDetectionUI() {
    qDebug()<<"YOLOv5FaceDetectionUI 构造函数";
    initUI();
}

void YOLOv5FaceDetectionUI::initUI()
{


    imgFileBtn = new QRadioButton("图片文件");
    imgFileBtn->setChecked(true);
    videoFileBtn = new QRadioButton("视频文件");
    dataFilePath = new QLineEdit();
    dataFilePath->setEnabled(false);
    chooseImgBtn =new QPushButton("选择图片");

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
    QVBoxLayout* vbox2 = new QVBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox5 = new QHBoxLayout();
    hbox2->addWidget(new QLabel("权重文件"));
    hbox2->addWidget(weightFilePath);
    hbox2->addWidget(chooseWeightBtn);
    hbox5->addWidget(new QLabel("配置文件"));
    hbox5->addWidget(configFilePath);
    hbox5->addWidget(chooseConfigBtn);
    vbox2->addLayout(hbox2);
    vbox2->addLayout(hbox5);
    modelBox->setLayout(vbox2);

    showFPSCheck = new QCheckBox("FPS");
    showScoreCheck = new QCheckBox("置信度");
    showFPSCheck->setChecked(true);
    showScoreCheck->setChecked(true);
    scoreSpinBox = new QDoubleSpinBox();
    scoreSpinBox->setRange(0,1);
    scoreSpinBox->setSingleStep(0.01);
    scoreSpinBox->setValue(0.5);
    configSpinBox = new QDoubleSpinBox();
    configSpinBox->setRange(0,1);
    configSpinBox->setSingleStep(0.01);
    configSpinBox->setValue(0.5);

    QGroupBox* showBox = new QGroupBox("显示");
    QVBoxLayout* vbox3 = new QVBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout;
    hbox3->addWidget(showFPSCheck);
    hbox3->addWidget(showScoreCheck);

    QHBoxLayout* hbox6 = new QHBoxLayout;
    hbox6->addWidget(new QLabel("置信:"));
    hbox6->addWidget(configSpinBox);
    QHBoxLayout* hbox7 = new QHBoxLayout;
    hbox7->addWidget(new QLabel("得分:"));
    hbox7->addWidget(scoreSpinBox);
    vbox3->addLayout(hbox3);
    vbox3->addLayout(hbox6);
    vbox3->addLayout(hbox7);
    showBox->setLayout(vbox3);

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



    QPixmap  pixmap(":/resources/woman.png");
    imgLabel=new QLabel();
    imgLabel->setAlignment(Qt::AlignCenter);
    imgLabel->setStyleSheet("background-color:rgb(127,127,127)");
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

    connect(chooseImgBtn,&QPushButton::clicked,this,&YOLOv5FaceDetectionUI::selectImg);
    connect(chooseWeightBtn,&QPushButton::clicked,this,&YOLOv5FaceDetectionUI::selectWeightFile);
    connect(chooseConfigBtn,&QPushButton::clicked,this,&YOLOv5FaceDetectionUI::selectConfigFile);
    connect(runBtn,&QPushButton::clicked,this,&YOLOv5FaceDetectionUI::runYoloDetection);

    dataSettings DS(DETECT_ALGO_TYPE::YOLOv5_DNN);
    DS.loadSettings(); //如果有历史内容 直接加载
    weightFilePath->setText(QString::fromStdString(DS.getWeight_file()));
    configFilePath->setText(QString::fromStdString(DS.getConfig_file()));
    scoreSpinBox->setValue(DS.getT_score());
    configSpinBox->setValue(DS.getConf());
    showFPSCheck->setChecked(DS.getShow_fps());
    showScoreCheck->setChecked(DS.getShow_score());
}

void YOLOv5FaceDetectionUI::selectImg()
{
    //图片文件被选中
    qDebug()<<"select Image...";
    if(imgFileBtn->isChecked())
    {
        QString Imgpath = QFileDialog::getOpenFileName(this,"选择图片",R"(C:\Users\15648\Pictures\Saved Pictures)",tr("Images(*.png *.jpg);"));
        if(Imgpath.isEmpty())
        {
            qDebug()<<"Image path is empty...";
            return ;
        }
        QPixmap pixmap(Imgpath);
        imgLabel->setPixmap(pixmap);
        dataFilePath->setText(Imgpath);
    }

    //视频文件被选中
    else if(videoFileBtn->isChecked())
    {
        QString videopath = QFileDialog::getOpenFileName(this,"选择视频",R"(D:\Video)",tr("Videos(*.mp4);"));
        if(videopath.isEmpty())
        {
            qDebug()<<"video path is empty...";
            return;
        }

        dataFilePath->setText(videopath);
    }

}

void YOLOv5FaceDetectionUI::selectWeightFile()
{
    QString weigthPath = QFileDialog::getOpenFileName(this, "选择模型权重文件", "C:/Users/15648/Desktop/QT/opencv/opencv_tutorial_data-master/opencv_tutorial_data-master/models", tr("Weights(*.onnx);"));
    if(weigthPath.isEmpty())
    {
        qDebug()<<"weigthPath is empty...";
        return ;
    }
    weightFilePath->setText(weigthPath);
}

void YOLOv5FaceDetectionUI::selectConfigFile()
{
    QString configPath = QFileDialog::getOpenFileName(this, "选择模型配置文件", "C:/Users/15648/Desktop/QT/opencv/opencv_tutorial_data-master/opencv_tutorial_data-master/models", tr("Labels(*.txt);"));
    if(configPath.isEmpty())
    {
        qDebug()<<"configPath is empty...";
        return ;
    }
    configFilePath->setText(configPath);
}

//点击按钮 开始检测
void YOLOv5FaceDetectionUI::runYoloDetection()
{
    //按钮设置不可用
    runBtn->setEnabled(false);

    dataSettings DS(DETECT_ALGO_TYPE::YOLOv5_DNN);
    DS.setData_path(dataFilePath->text().toStdString());
    DS.setWeight_file(weightFilePath->text().toStdString());
    DS.setConfig_file(configFilePath->text().toStdString());
    DS.setShow_fps(showFPSCheck->isChecked());
    DS.setShow_score(showScoreCheck->isChecked());
    DS.setConf(configSpinBox->value());
    DS.setT_score(scoreSpinBox->value());
    DS.dumpSettings(); //记录到yml文件里

    workThread = new ObjectDetectorThread(DS);
    qRegisterMetaType<cv::Mat>("cv::Mat");
    connect(workThread, SIGNAL(sendResult(cv::Mat)), this, SLOT(showDetectedImage(cv::Mat)));
    connect(workThread, &ObjectDetectorThread::finished, workThread, &QObject::deleteLater);
    this->workThread->start(); // callback

}

void YOLOv5FaceDetectionUI::showDetectedImage(cv::Mat frame)
{
    //如果返回空 说明结束了
    if(frame.empty())
    {
        runBtn->setEnabled(true);
        return;
    }

    cv::Mat image;
    cv::cvtColor(frame, image, cv::COLOR_BGR2RGB);
    QImage img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    img = img.scaled(QSize(800, 500), Qt::KeepAspectRatio);

    QPixmap  pixmap;
    pixmap = pixmap.fromImage(img);
    this->imgLabel->setPixmap(pixmap);
}
