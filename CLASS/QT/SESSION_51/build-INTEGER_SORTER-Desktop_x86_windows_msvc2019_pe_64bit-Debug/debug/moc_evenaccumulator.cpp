/****************************************************************************
** Meta object code from reading C++ file 'evenaccumulator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../INTEGER_SORTER/evenaccumulator.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'evenaccumulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS = QtMocHelpers::stringData(
    "EvenAccumulator",
    "accept",
    "",
    "N",
    "show"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[16];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS_t qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "EvenAccumulator"
        QT_MOC_LITERAL(16, 6),  // "accept"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 1),  // "N"
        QT_MOC_LITERAL(26, 4)   // "show"
    },
    "EvenAccumulator",
    "accept",
    "",
    "N",
    "show"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEvenAccumulatorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       4,    0,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EvenAccumulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEvenAccumulatorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EvenAccumulator, std::true_type>,
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'show'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EvenAccumulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EvenAccumulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accept((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 1: _t->show(); break;
        default: ;
        }
    }
}

const QMetaObject *EvenAccumulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EvenAccumulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEvenAccumulatorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EvenAccumulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
