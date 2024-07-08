/****************************************************************************
** Meta object code from reading C++ file 'gravitycalculatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gravity_Calculator/gravitycalculatordialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gravitycalculatordialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS = QtMocHelpers::stringData(
    "GravityCalculatorDialog",
    "getMass1",
    "",
    "strMass1",
    "getMass2",
    "strMass2",
    "getDistance",
    "strDistance",
    "doCompute",
    "doClear"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[24];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[12];
    char stringdata7[12];
    char stringdata8[10];
    char stringdata9[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS_t qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "GravityCalculatorDialog"
        QT_MOC_LITERAL(24, 8),  // "getMass1"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 8),  // "strMass1"
        QT_MOC_LITERAL(43, 8),  // "getMass2"
        QT_MOC_LITERAL(52, 8),  // "strMass2"
        QT_MOC_LITERAL(61, 11),  // "getDistance"
        QT_MOC_LITERAL(73, 11),  // "strDistance"
        QT_MOC_LITERAL(85, 9),  // "doCompute"
        QT_MOC_LITERAL(95, 7)   // "doClear"
    },
    "GravityCalculatorDialog",
    "getMass1",
    "",
    "strMass1",
    "getMass2",
    "strMass2",
    "getDistance",
    "strDistance",
    "doCompute",
    "doClear"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGravityCalculatorDialogENDCLASS[] = {

 // content:
      12,       // revision
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
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       6,    1,   50,    2, 0x0a,    5 /* Public */,
       8,    0,   53,    2, 0x0a,    7 /* Public */,
       9,    0,   54,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GravityCalculatorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGravityCalculatorDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GravityCalculatorDialog, std::true_type>,
        // method 'getMass1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getMass2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getDistance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'doCompute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doClear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GravityCalculatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GravityCalculatorDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getMass1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->getMass2((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->getDistance((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->doCompute(); break;
        case 4: _t->doClear(); break;
        default: ;
        }
    }
}

const QMetaObject *GravityCalculatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GravityCalculatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGravityCalculatorDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GravityCalculatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
