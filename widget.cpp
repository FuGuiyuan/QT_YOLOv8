#include "widget.h"
#include "ui_widget.h"
#include "UI/mainwidget.h"
#include "UI/yolov5facedetectionui.h"

#include <QVBoxLayout>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setFixedSize(800,600);
    this->setStyleSheet("background-color:rgba(173,216,230,0.5)"); //rgba(255,128,123,0.5)
    QVBoxLayout* vbox = new QVBoxLayout;
    MainWidget* mainWidget = new MainWidget();
    vbox->addWidget(mainWidget);
    this->setLayout(vbox);


    //主界面跳转到YOLOv5界面
    connect(mainWidget,&MainWidget::ToYolov5Widget,this,[&](){
        //隐藏主界面
        mainWidget->hide();
        //删除原来的布局
        QLayout* oldLayout = this->layout();
        delete oldLayout;

        //添加新的布局
        QVBoxLayout* vbox1 = new QVBoxLayout;
        YOLOv5FaceDetectionUI* yolov5UI = new YOLOv5FaceDetectionUI();
        vbox1->addWidget(yolov5UI);
        this->setLayout(vbox1);
    });


}

Widget::~Widget()
{
    delete ui;
}
