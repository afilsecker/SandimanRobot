/****************************************************************************
** Meta object code from reading C++ file 'application.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../application.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Application_t {
    const uint offsetsAndSize[20];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Application_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Application_t qt_meta_stringdata_Application = {
    {
QT_MOC_LITERAL(0, 11), // "Application"
QT_MOC_LITERAL(12, 18), // "loginResultRecieve"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 6), // "result"
QT_MOC_LITERAL(39, 12), // "moveByButton"
QT_MOC_LITERAL(52, 12), // "stopByButton"
QT_MOC_LITERAL(65, 9), // "moveByKey"
QT_MOC_LITERAL(75, 7), // "Qt::Key"
QT_MOC_LITERAL(83, 3), // "key"
QT_MOC_LITERAL(87, 9) // "stopByKey"

    },
    "Application\0loginResultRecieve\0\0result\0"
    "moveByButton\0stopByButton\0moveByKey\0"
    "Qt::Key\0key\0stopByKey"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Application[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    0,   47,    2, 0x0a,    3 /* Public */,
       5,    0,   48,    2, 0x0a,    4 /* Public */,
       6,    1,   49,    2, 0x0a,    5 /* Public */,
       9,    1,   52,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Application *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginResultRecieve((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->moveByButton(); break;
        case 2: _t->stopByButton(); break;
        case 3: _t->moveByKey((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 4: _t->stopByKey((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Application::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Application.offsetsAndSize,
    qt_meta_data_Application,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Application_t
, QtPrivate::TypeAndForceComplete<Application, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>


>,
    nullptr
} };


const QMetaObject *Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Application::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Application.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
