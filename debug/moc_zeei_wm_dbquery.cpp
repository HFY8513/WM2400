/****************************************************************************
** Meta object code from reading C++ file 'zeei_wm_dbquery.h'
**
** Created: Thu Oct 25 17:20:52 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zeei_wm_dbquery.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zeei_wm_dbquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZEEI_WM_DbQuery[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,
      45,   40,   16,   16, 0x08,
      72,   66,   16,   16, 0x08,
      90,   16,   16,   16, 0x08,
     113,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ZEEI_WM_DbQuery[] = {
    "ZEEI_WM_DbQuery\0\0index\0showChanged(int)\0"
    "text\0textChanged(QString)\0state\0"
    "stateChanged(int)\0on_btnSelect_clicked()\0"
    "on_cmbMode_currentIndexChanged(int)\0"
};

void ZEEI_WM_DbQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZEEI_WM_DbQuery *_t = static_cast<ZEEI_WM_DbQuery *>(_o);
        switch (_id) {
        case 0: _t->showChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnSelect_clicked(); break;
        case 4: _t->on_cmbMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ZEEI_WM_DbQuery::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZEEI_WM_DbQuery::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZEEI_WM_DbQuery,
      qt_meta_data_ZEEI_WM_DbQuery, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZEEI_WM_DbQuery::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZEEI_WM_DbQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZEEI_WM_DbQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZEEI_WM_DbQuery))
        return static_cast<void*>(const_cast< ZEEI_WM_DbQuery*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZEEI_WM_DbQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
