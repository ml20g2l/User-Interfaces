/****************************************************************************
** Meta object code from reading C++ file 'control_button.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../2811_cw2-master-release/control_button.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'control_button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_control_button_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_control_button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_control_button_t qt_meta_stringdata_control_button = {
    {
QT_MOC_LITERAL(0, 0, 14) // "control_button"

    },
    "control_button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_control_button[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void control_button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject control_button::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_control_button.data,
    qt_meta_data_control_button,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *control_button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *control_button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_control_button.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int control_button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_play_pause_button_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_play_pause_button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_play_pause_button_t qt_meta_stringdata_play_pause_button = {
    {
QT_MOC_LITERAL(0, 0, 17), // "play_pause_button"
QT_MOC_LITERAL(1, 18, 10), // "pause_play"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "play_pause_button\0pause_play\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_play_pause_button[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void play_pause_button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<play_pause_button *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pause_play(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject play_pause_button::staticMetaObject = { {
    QMetaObject::SuperData::link<control_button::staticMetaObject>(),
    qt_meta_stringdata_play_pause_button.data,
    qt_meta_data_play_pause_button,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *play_pause_button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *play_pause_button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_play_pause_button.stringdata0))
        return static_cast<void*>(this);
    return control_button::qt_metacast(_clname);
}

int play_pause_button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = control_button::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_dark_lightmode_button_t {
    QByteArrayData data[5];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dark_lightmode_button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dark_lightmode_button_t qt_meta_stringdata_dark_lightmode_button = {
    {
QT_MOC_LITERAL(0, 0, 21), // "dark_lightmode_button"
QT_MOC_LITERAL(1, 22, 14), // "dark_lightMode"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "QVBoxLayout*"
QT_MOC_LITERAL(4, 51, 6) // "layout"

    },
    "dark_lightmode_button\0dark_lightMode\0"
    "\0QVBoxLayout*\0layout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dark_lightmode_button[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void dark_lightmode_button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dark_lightmode_button *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dark_lightMode((*reinterpret_cast< QVBoxLayout*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVBoxLayout* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dark_lightmode_button::staticMetaObject = { {
    QMetaObject::SuperData::link<control_button::staticMetaObject>(),
    qt_meta_stringdata_dark_lightmode_button.data,
    qt_meta_data_dark_lightmode_button,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dark_lightmode_button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dark_lightmode_button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dark_lightmode_button.stringdata0))
        return static_cast<void*>(this);
    return control_button::qt_metacast(_clname);
}

int dark_lightmode_button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = control_button::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_full_smallscreen_button_t {
    QByteArrayData data[3];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_full_smallscreen_button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_full_smallscreen_button_t qt_meta_stringdata_full_smallscreen_button = {
    {
QT_MOC_LITERAL(0, 0, 23), // "full_smallscreen_button"
QT_MOC_LITERAL(1, 24, 16), // "full_smallScreen"
QT_MOC_LITERAL(2, 41, 0) // ""

    },
    "full_smallscreen_button\0full_smallScreen\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_full_smallscreen_button[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void full_smallscreen_button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<full_smallscreen_button *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->full_smallScreen(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject full_smallscreen_button::staticMetaObject = { {
    QMetaObject::SuperData::link<control_button::staticMetaObject>(),
    qt_meta_stringdata_full_smallscreen_button.data,
    qt_meta_data_full_smallscreen_button,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *full_smallscreen_button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *full_smallscreen_button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_full_smallscreen_button.stringdata0))
        return static_cast<void*>(this);
    return control_button::qt_metacast(_clname);
}

int full_smallscreen_button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = control_button::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
