#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QToolButton>
class MainWidget:public QWidget
{
    Q_OBJECT
public:
    MainWidget();

    void initUI();

private:
    QToolButton* ToYolov5Btn;
    QToolButton* ToYolov8Btn;
};

#endif // MAINWIDGET_H
