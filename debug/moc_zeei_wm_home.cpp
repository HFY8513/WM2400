/****************************************************************************
** Meta object code from reading C++ file 'zeei_wm_home.h'
**
** Created: Sat Oct 13 12:27:23 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zeei_wm_home.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zeei_wm_home.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZEEI_WM_HOME[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      28,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      53,   13,   13,   13, 0x08,
      68,   13,   13,   13, 0x08,
      84,   13,   13,   13, 0x08,
     109,   13,   13,   13, 0x08,
     134,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ZEEI_WM_HOME[] = {
    "ZEEI_WM_HOME\0\0timerUpdate()\0initForm()\0"
    "buttonClick()\0initLeftMain()\0"
    "leftMainClick()\0on_btnMenu_Min_clicked()\0"
    "on_btnMenu_Max_clicked()\0"
    "on_btnMenu_Close_clicked()\0"
};

void ZEEI_WM_HOME::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZEEI_WM_HOME *_t = static_cast<ZEEI_WM_HOME *>(_o);
        switch (_id) {
        case 0: _t->timerUpdate(); break;
        case 1: _t->initForm(); break;
        case 2: _t->buttonClick(); break;
        case 3: _t->initLeftMain(); break;
        case 4: _t->leftMainClick(); break;
        case 5: _t->on_btnMenu_Min_clicked(); break;
        case 6: _t->on_btnMenu_Max_clicked(); break;
        case 7: _t->on_btnMenu_Close_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ZEEI_WM_HOME::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZEEI_WM_HOME::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZEEI_WM_HOME,
      qt_meta_data_ZEEI_WM_HOME, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZEEI_WM_HOME::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZEEI_WM_HOME::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZEEI_WM_HOME::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZEEI_WM_HOME))
        return static_cast<void*>(const_cast< ZEEI_WM_HOME*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZEEI_WM_HOME::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
