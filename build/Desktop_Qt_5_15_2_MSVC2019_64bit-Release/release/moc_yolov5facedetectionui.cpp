/****************************************************************************
** Meta object code from reading C++ file 'yolov5facedetectionui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/yolov5facedetectionui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yolov5facedetectionui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_YOLOv5FaceDetectionUI_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YOLOv5FaceDetectionUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YOLOv5FaceDetectionUI_t qt_meta_stringdata_YOLOv5FaceDetectionUI = {
    {
QT_MOC_LITERAL(0, 0, 21), // "YOLOv5FaceDetectionUI"
QT_MOC_LITERAL(1, 22, 9), // "selectImg"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "selectWeightFile"
QT_MOC_LITERAL(4, 50, 16), // "selectConfigFile"
QT_MOC_LITERAL(5, 67, 16), // "runYoloDetection"
QT_MOC_LITERAL(6, 84, 17), // "showDetectedImage"
QT_MOC_LITERAL(7, 102, 7), // "cv::Mat"
QT_MOC_LITERAL(8, 110, 5) // "frame"

    },
    "YOLOv5FaceDetectionUI\0selectImg\0\0"
    "selectWeightFile\0selectConfigFile\0"
    "runYoloDetection\0showDetectedImage\0"
    "cv::Mat\0frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YOLOv5FaceDetectionUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void YOLOv5FaceDetectionUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<YOLOv5FaceDetectionUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectImg(); break;
        case 1: _t->selectWeightFile(); break;
        case 2: _t->selectConfigFile(); break;
        case 3: _t->runYoloDetection(); break;
        case 4: _t->showDetectedImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject YOLOv5FaceDetectionUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_YOLOv5FaceDetectionUI.data,
    qt_meta_data_YOLOv5FaceDetectionUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *YOLOv5FaceDetectionUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YOLOv5FaceDetectionUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_YOLOv5FaceDetectionUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int YOLOv5FaceDetectionUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
