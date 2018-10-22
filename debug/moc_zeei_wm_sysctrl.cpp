/****************************************************************************
** Meta object code from reading C++ file 'zeei_wm_sysctrl.h'
**
** Created: Mon Oct 22 11:31:29 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zeei_wm_sysctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zeei_wm_sysctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZEEI_WM_SYSCTRL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      34,   16,   16,   16, 0x08,
      52,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ZEEI_WM_SYSCTRL[] = {
    "ZEEI_WM_SYSCTRL\0\0initLeftConfig()\0"
    "leftConfigClick()\0on_pbtn_query_clicked()\0"
};

void ZEEI_WM_SYSCTRL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZEEI_WM_SYSCTRL *_t = static_cast<ZEEI_WM_SYSCTRL *>(_o);
        switch (_id) {
        case 0: _t->initLeftConfig(); break;
        case 1: _t->leftConfigClick(); break;
        case 2: _t->on_pbtn_query_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ZEEI_WM_SYSCTRL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZEEI_WM_SYSCTRL::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZEEI_WM_SYSCTRL,
      qt_meta_data_ZEEI_WM_SYSCTRL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZEEI_WM_SYSCTRL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZEEI_WM_SYSCTRL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZEEI_WM_SYSCTRL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZEEI_WM_SYSCTRL))
        return static_cast<void*>(const_cast< ZEEI_WM_SYSCTRL*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZEEI_WM_SYSCTRL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
