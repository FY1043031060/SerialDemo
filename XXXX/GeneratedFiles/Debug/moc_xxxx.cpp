/****************************************************************************
** Meta object code from reading C++ file 'xxxx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../xxxx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xxxx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecvData_t {
    QByteArrayData data[7];
    char stringdata[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvData_t qt_meta_stringdata_RecvData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RecvData"
QT_MOC_LITERAL(1, 9, 11), // "textChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "strTemp"
QT_MOC_LITERAL(4, 30, 3), // "run"
QT_MOC_LITERAL(5, 34, 14), // "onComboClicked"
QT_MOC_LITERAL(6, 49, 5) // "index"

    },
    "RecvData\0textChanged\0\0strTemp\0run\0"
    "onComboClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void RecvData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecvData *_t = static_cast<RecvData *>(_o);
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->onComboClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RecvData::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvData::textChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RecvData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RecvData.data,
      qt_meta_data_RecvData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RecvData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RecvData.stringdata))
        return static_cast<void*>(const_cast< RecvData*>(this));
    return QObject::qt_metacast(_clname);
}

int RecvData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RecvData::textChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_XXXX_t {
    QByteArrayData data[7];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XXXX_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XXXX_t qt_meta_stringdata_XXXX = {
    {
QT_MOC_LITERAL(0, 0, 4), // "XXXX"
QT_MOC_LITERAL(1, 5, 15), // "onComboxChoosed"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "index"
QT_MOC_LITERAL(4, 28, 19), // "onSendButtonClicked"
QT_MOC_LITERAL(5, 48, 13), // "onTextChanged"
QT_MOC_LITERAL(6, 62, 7) // "strTemp"

    },
    "XXXX\0onComboxChoosed\0\0index\0"
    "onSendButtonClicked\0onTextChanged\0"
    "strTemp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XXXX[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void XXXX::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XXXX *_t = static_cast<XXXX *>(_o);
        switch (_id) {
        case 0: _t->onComboxChoosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onSendButtonClicked(); break;
        case 2: _t->onTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject XXXX::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_XXXX.data,
      qt_meta_data_XXXX,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XXXX::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XXXX::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XXXX.stringdata))
        return static_cast<void*>(const_cast< XXXX*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int XXXX::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
