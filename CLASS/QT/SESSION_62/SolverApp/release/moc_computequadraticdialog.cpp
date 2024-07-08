/****************************************************************************
** Meta object code from reading C++ file 'computequadraticdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../computequadraticdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'computequadraticdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS = QtMocHelpers::stringData(
    "ComputeQuadraticDialog",
    "readTextBox_1",
    "",
    "str",
    "readTextBox_2",
    "readTextBox_3",
    "doCompute"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[23];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[14];
    char stringdata5[14];
    char stringdata6[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS_t qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "ComputeQuadraticDialog"
        QT_MOC_LITERAL(23, 13),  // "readTextBox_1"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 3),  // "str"
        QT_MOC_LITERAL(42, 13),  // "readTextBox_2"
        QT_MOC_LITERAL(56, 13),  // "readTextBox_3"
        QT_MOC_LITERAL(70, 9)   // "doCompute"
    },
    "ComputeQuadraticDialog",
    "readTextBox_1",
    "",
    "str",
    "readTextBox_2",
    "readTextBox_3",
    "doCompute"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSComputeQuadraticDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       4,    1,   41,    2, 0x0a,    3 /* Public */,
       5,    1,   44,    2, 0x0a,    5 /* Public */,
       6,    0,   47,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ComputeQuadraticDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSComputeQuadraticDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ComputeQuadraticDialog, std::true_type>,
        // method 'readTextBox_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'readTextBox_2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'readTextBox_3'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'doCompute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ComputeQuadraticDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ComputeQuadraticDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readTextBox_1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->readTextBox_2((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->readTextBox_3((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->doCompute(); break;
        default: ;
        }
    }
}

const QMetaObject *ComputeQuadraticDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComputeQuadraticDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSComputeQuadraticDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ComputeQuadraticDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
