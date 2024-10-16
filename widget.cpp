#include "widget.h"
#include "ui_widget.h"
#include "UI/mainwidget.h"

#include <QVBoxLayout>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setStyleSheet("background-color:rgba(173,216,230,0.5)"); //rgba(255,128,123,0.5)
    QVBoxLayout* vbox = new QVBoxLayout;
    MainWidget* mainWidget = new MainWidget();
    qDebug()<<"nihao";
    vbox->addWidget(mainWidget);
    this->setLayout(vbox);
}

Widget::~Widget()
{
    delete ui;
}
