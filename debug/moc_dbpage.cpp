/****************************************************************************
** Meta object code from reading C++ file 'dbpage.h'
**
** Created: Tue Oct 23 15:32:02 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dbpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DbCountThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   55,   14,   14, 0x0a,
      89,   85,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DbCountThread[] = {
    "DbCountThread\0\0count,msec\0"
    "receiveCount(quint32,double)\0connName\0"
    "setConnName(QString)\0sql\0setSql(QString)\0"
};

void DbCountThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DbCountThread *_t = static_cast<DbCountThread *>(_o);
        switch (_id) {
        case 0: _t->receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DbCountThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DbCountThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DbCountThread,
      qt_meta_data_DbCountThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DbCountThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DbCountThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DbCountThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DbCountThread))
        return static_cast<void*>(const_cast< DbCountThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DbCountThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DbCountThread::receiveCount(quint32 _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DbPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   48,    7,    7, 0x08,
      70,   48,    7,    7, 0x08,
      90,    8,    7,    7, 0x08,
     124,    7,    7,    7, 0x08,
     132,    7,    7,    7, 0x08,
     143,    7,    7,    7, 0x08,
     150,    7,    7,    7, 0x08,
     162,  157,    7,    7, 0x08,
     191,    7,    7,    7, 0x0a,
     223,  200,    7,    7, 0x0a,
     270,  256,    7,    7, 0x2a,
     304,  295,    7,    7, 0x0a,
     332,  325,    7,    7, 0x0a,
     360,  351,    7,    7, 0x0a,
     387,  377,    7,    7, 0x0a,
     422,  409,    7,    7, 0x0a,
     456,  447,    7,    7, 0x0a,
     486,  477,    7,    7, 0x0a,
     516,  507,    7,    7, 0x0a,
     551,  537,    7,    7, 0x0a,
     585,  573,    7,    7, 0x0a,
     629,  616,    7,    7, 0x0a,
     675,  657,    7,    7, 0x0a,
     718,  701,    7,    7, 0x0a,
     765,  747,    7,    7, 0x0a,
     791,    7,    7,    7, 0x0a,
     809,    7,    7,    7, 0x0a,
     828,    7,    7,    7, 0x0a,
     841,    7,    7,    7, 0x0a,
     866,  854,    7,    7, 0x0a,
     922,    7,    7,    7, 0x0a,
     944,    7,    7,    7, 0x0a,
     982,  962,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DbPage[] = {
    "DbPage\0\0count,msec\0receiveCount(quint32,double)\0"
    "sql\0bindData(QString)\0showCurrve(QString)\0"
    "slot_receiveCount(quint32,double)\0"
    "first()\0previous()\0next()\0last()\0arg1\0"
    "on_spinBox_valueChanged(int)\0select()\0"
    "qcustomWidget,connName\0"
    "setControl(QCustomPlot*,QString)\0"
    "qcustomWidget\0setControl(QCustomPlot*)\0"
    "connName\0setConnName(QString)\0dbType\0"
    "setDbType(DbType&)\0showType\0"
    "setShowMode(int)\0tableName\0"
    "setTableName(QString)\0selectColumn\0"
    "setSelectColumn(QString)\0orderSql\0"
    "setOrderSql(QString)\0whereSql\0"
    "setWhereSql(QString)\0groupSql\0"
    "setGroupSql(QString)\0resultCurrent\0"
    "setResultCurrent(int)\0columnNames\0"
    "setColumnNames(QList<QString>)\0"
    "columnWidths\0setColumnWidths(QList<int>)\0"
    "insertColumnIndex\0setInsertColumnIndex(int)\0"
    "insertColumnName\0setInsertColumnName(QString)\0"
    "insertColumnWidth\0setInsertColumnWidth(int)\0"
    "initQcustomPlot()\0selectionChanged()\0"
    "mousePress()\0mouseWheel()\0x,y,fidname\0"
    "addRandomGraph(QVector<double>,QVector<double>,QString)\0"
    "removeSelectedGraph()\0removeAllGraphs()\0"
    "plottable,dataIndex\0"
    "graphClicked(QCPAbstractPlottable*,int)\0"
};

void DbPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DbPage *_t = static_cast<DbPage *>(_o);
        switch (_id) {
        case 0: _t->receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->bindData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->showCurrve((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slot_receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->first(); break;
        case 5: _t->previous(); break;
        case 6: _t->next(); break;
        case 7: _t->last(); break;
        case 8: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->select(); break;
        case 10: _t->setControl((*reinterpret_cast< QCustomPlot*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->setControl((*reinterpret_cast< QCustomPlot*(*)>(_a[1]))); break;
        case 12: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setDbType((*reinterpret_cast< DbType(*)>(_a[1]))); break;
        case 14: _t->setShowMode((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 15: _t->setTableName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setSelectColumn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->setOrderSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->setWhereSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->setGroupSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->setResultCurrent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setColumnNames((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        case 22: _t->setColumnWidths((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 23: _t->setInsertColumnIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setInsertColumnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->setInsertColumnWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->initQcustomPlot(); break;
        case 27: _t->selectionChanged(); break;
        case 28: _t->mousePress(); break;
        case 29: _t->mouseWheel(); break;
        case 30: _t->addRandomGraph((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 31: _t->removeSelectedGraph(); break;
        case 32: _t->removeAllGraphs(); break;
        case 33: _t->graphClicked((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DbPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DbPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DbPage,
      qt_meta_data_DbPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DbPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DbPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DbPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DbPage))
        return static_cast<void*>(const_cast< DbPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int DbPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void DbPage::receiveCount(quint32 _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
