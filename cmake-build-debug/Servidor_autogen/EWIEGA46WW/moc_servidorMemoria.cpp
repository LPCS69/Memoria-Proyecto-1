/****************************************************************************
** Meta object code from reading C++ file 'servidorMemoria.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../servidorMemoria.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servidorMemoria.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_servidorMemoria_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_servidorMemoria_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_servidorMemoria_t qt_meta_stringdata_servidorMemoria = {
    {
QT_MOC_LITERAL(0, 0, 15), // "servidorMemoria"
QT_MOC_LITERAL(1, 16, 10), // "paginacion"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "quitar"
QT_MOC_LITERAL(4, 35, 6), // "Enviar"
QT_MOC_LITERAL(5, 42, 6), // "Server"
QT_MOC_LITERAL(6, 49, 7), // "Recibir"
QT_MOC_LITERAL(7, 57, 13) // "buscar_imagen"

    },
    "servidorMemoria\0paginacion\0\0quitar\0"
    "Enviar\0Server\0Recibir\0buscar_imagen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_servidorMemoria[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void servidorMemoria::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<servidorMemoria *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paginacion(); break;
        case 1: _t->quitar(); break;
        case 2: _t->Enviar(); break;
        case 3: _t->Server(); break;
        case 4: _t->Recibir(); break;
        case 5: _t->buscar_imagen(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject servidorMemoria::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_servidorMemoria.data,
    qt_meta_data_servidorMemoria,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *servidorMemoria::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *servidorMemoria::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_servidorMemoria.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int servidorMemoria::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
