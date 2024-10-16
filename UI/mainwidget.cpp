#include "mainwidget.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>

MainWidget::MainWidget()
{
    qDebug()<<"MainWidget 构造函数";
    initUI();
}

void MainWidget::initUI()
{
    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    QWidget* v5Widget =new QWidget(this);
    QVBoxLayout* vbox1 = new QVBoxLayout;
    ToYolov5Btn = new QToolButton(this);
    ToYolov5Btn->setIcon(QIcon(":/resources/yolov5LOGO.png"));
    ToYolov5Btn->setIconSize(QSize(300,300));
    ToYolov5Btn->setFont(font);
    ToYolov5Btn->setText("YOLOv5检测");
    ToYolov5Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    vbox1->addWidget(ToYolov5Btn,0,Qt::AlignCenter);
    v5Widget->setLayout(vbox1);


    QWidget* v8Widget =new QWidget(this);
    QVBoxLayout* vbox2 = new QVBoxLayout;
    ToYolov8Btn = new QToolButton(this);
    ToYolov8Btn->setIcon(QIcon(":/resources/yolov8LOGO.png"));
    ToYolov8Btn->setIconSize(QSize(300,300));
    ToYolov8Btn->setFont(font);
    ToYolov8Btn->setText("YOLOv8检测");
    ToYolov8Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    vbox2->addWidget(ToYolov8Btn,0,Qt::AlignCenter);
    v8Widget->setLayout(vbox2);

    QHBoxLayout* hbox =new QHBoxLayout;
    hbox->addWidget(v5Widget);
    hbox->addWidget(v8Widget);
    this->setLayout(hbox);
}
