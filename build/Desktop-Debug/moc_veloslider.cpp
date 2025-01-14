/****************************************************************************
** Meta object code from reading C++ file 'veloslider.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../traincontrol/veloslider.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'veloslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10veloSliderE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10veloSliderE = QtMocHelpers::stringData(
    "veloSlider",
    "sendRampPaintEvent",
    "",
    "sendScalePaintEvent",
    "sendTimeValueChanged",
    "onStopButton",
    "onTimeValue",
    "time",
    "onValueChanged",
    "onTimer",
    "onColorTimer",
    "onScalePaintEvent",
    "onRampPaintEvent"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10veloSliderE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    0,   76,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    1,   78,    2, 0x0a,    5 /* Public */,
       8,    0,   81,    2, 0x08,    7 /* Private */,
       9,    0,   82,    2, 0x08,    8 /* Private */,
      10,    0,   83,    2, 0x08,    9 /* Private */,
      11,    0,   84,    2, 0x08,   10 /* Private */,
      12,    0,   85,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject veloSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN10veloSliderE.offsetsAndSizes,
    qt_meta_data_ZN10veloSliderE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10veloSliderE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<veloSlider, std::true_type>,
        // method 'sendRampPaintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendScalePaintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendTimeValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStopButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTimeValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onColorTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onScalePaintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRampPaintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void veloSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<veloSlider *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendRampPaintEvent(); break;
        case 1: _t->sendScalePaintEvent(); break;
        case 2: _t->sendTimeValueChanged(); break;
        case 3: _t->onStopButton(); break;
        case 4: _t->onTimeValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onValueChanged(); break;
        case 6: _t->onTimer(); break;
        case 7: _t->onColorTimer(); break;
        case 8: _t->onScalePaintEvent(); break;
        case 9: _t->onRampPaintEvent(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (veloSlider::*)();
            if (_q_method_type _q_method = &veloSlider::sendRampPaintEvent; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (veloSlider::*)();
            if (_q_method_type _q_method = &veloSlider::sendScalePaintEvent; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (veloSlider::*)();
            if (_q_method_type _q_method = &veloSlider::sendTimeValueChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *veloSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *veloSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10veloSliderE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int veloSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void veloSlider::sendRampPaintEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void veloSlider::sendScalePaintEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void veloSlider::sendTimeValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
