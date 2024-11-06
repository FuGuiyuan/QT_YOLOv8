QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algo/ObjectDetectorFactory.cpp \
    Algo/datasettings.cpp \
    Algo/yolov5detector.cpp \
    Algo/yolov8detector.cpp \
    UI/mainwidget.cpp \
    UI/objectdetectorthread.cpp \
    UI/yolov5facedetectionui.cpp \
    UI/yolov8facedetectionui.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Algo/AlgoInterface.h \
    Algo/ObjectDetectorFactory.h \
    Algo/datasettings.h \
    Algo/yolov5detector.h \
    Algo/yolov8detector.h \
    UI/mainwidget.h \
    UI/objectdetectorthread.h \
    UI/yolov5facedetectionui.h \
    UI/yolov8facedetectionui.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8
msvc:QMAKE_CXXFLAGS += -source-charset:utf-8

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../opencv-4.8.0/opencv/build/x64/vc16/lib/ -lopencv_world480
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../opencv-4.8.0/opencv/build/x64/vc16/lib/ -lopencv_world480d
else:unix: LIBS += -L$$PWD/../../../opencv-4.8.0/opencv/build/x64/vc16/lib/ -lopencv_world480

INCLUDEPATH += $$PWD/../../../opencv-4.8.0/opencv/build/include
DEPENDPATH += $$PWD/../../../opencv-4.8.0/opencv/build/include
