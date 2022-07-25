/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../main_window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 9), // "moveByKey"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 7), // "Qt::Key"
QT_MOC_LITERAL(30, 3), // "key"
QT_MOC_LITERAL(34, 9), // "stopByKey"
QT_MOC_LITERAL(44, 10), // "keyPressed"
QT_MOC_LITERAL(55, 11), // "keyReleased"
QT_MOC_LITERAL(67, 16), // "changeSpeedLabel"
QT_MOC_LITERAL(84, 5) // "speed"

    },
    "MainWindow\0moveByKey\0\0Qt::Key\0key\0"
    "stopByKey\0keyPressed\0keyReleased\0"
    "changeSpeedLabel\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    1,   47,    2, 0x06,    3 /* Public */,
       6,    1,   50,    2, 0x06,    5 /* Public */,
       7,    1,   53,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   56,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveByKey((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 1: _t->stopByKey((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 2: _t->keyPressed((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 3: _t->keyReleased((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1]))); break;
        case 4: _t->changeSpeedLabel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::moveByKey)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::stopByKey)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::keyPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::keyReleased)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MainWindow::moveByKey(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::stopByKey(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::keyPressed(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::keyReleased(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
