/****************************************************************************
** Meta object code from reading C++ file 'mainGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainGUI_t {
    QByteArrayData data[11];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainGUI_t qt_meta_stringdata_mainGUI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "mainGUI"
QT_MOC_LITERAL(1, 8, 15), // "faseTapeDestape"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "handleButton0"
QT_MOC_LITERAL(4, 39, 13), // "handleButton1"
QT_MOC_LITERAL(5, 53, 13), // "handleButton2"
QT_MOC_LITERAL(6, 67, 13), // "handleButton3"
QT_MOC_LITERAL(7, 81, 13), // "handleButton4"
QT_MOC_LITERAL(8, 95, 13), // "handleButton5"
QT_MOC_LITERAL(9, 109, 13), // "handleButton6"
QT_MOC_LITERAL(10, 123, 13) // "handleButton7"

    },
    "mainGUI\0faseTapeDestape\0\0handleButton0\0"
    "handleButton1\0handleButton2\0handleButton3\0"
    "handleButton4\0handleButton5\0handleButton6\0"
    "handleButton7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->faseTapeDestape(); break;
        case 1: _t->handleButton0(); break;
        case 2: _t->handleButton1(); break;
        case 3: _t->handleButton2(); break;
        case 4: _t->handleButton3(); break;
        case 5: _t->handleButton4(); break;
        case 6: _t->handleButton5(); break;
        case 7: _t->handleButton6(); break;
        case 8: _t->handleButton7(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mainGUI::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_mainGUI.data,
    qt_meta_data_mainGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
