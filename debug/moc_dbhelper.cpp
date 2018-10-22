/****************************************************************************
** Meta object code from reading C++ file 'dbhelper.h'
**
** Created: Sat Oct 13 14:40:44 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dbhelper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbhelper.h' doesn't include <QObject>."
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
static const uint qt_meta_data_DbHepler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      58,   10,    9,    9, 0x05,
     114,  103,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     147,  143,    9,    9, 0x08,
     165,  143,    9,    9, 0x08,
     185,  103,    9,    9, 0x08,
     219,    9,    9,    9, 0x08,
     227,    9,    9,    9, 0x08,
     238,    9,    9,    9, 0x08,
     245,    9,    9,    9, 0x08,
     405,  252,    9,    9, 0x0a,
     718,  574,    9,    9, 0x2a,
     888,  879,    9,    9, 0x0a,
     916,  909,    9,    9, 0x0a,
     943,  934,    9,    9, 0x0a,
     970,  960,    9,    9, 0x0a,
    1005,  992,    9,    9, 0x0a,
    1039, 1030,    9,    9, 0x0a,
    1069, 1060,    9,    9, 0x0a,
    1099, 1090,    9,    9, 0x0a,
    1127, 1120,    9,    9, 0x0a,
    1160, 1146,    9,    9, 0x0a,
    1194, 1182,    9,    9, 0x0a,
    1238, 1225,    9,    9, 0x0a,
    1284, 1266,    9,    9, 0x0a,
    1327, 1310,    9,    9, 0x0a,
    1374, 1356,    9,    9, 0x0a,
    1400,    9,    9,    9, 0x0a,
    1418,    9,    9,    9, 0x0a,
    1437,    9,    9,    9, 0x0a,
    1450,    9,    9,    9, 0x0a,
    1475, 1463,    9,    9, 0x0a,
    1531,    9,    9,    9, 0x0a,
    1553,    9,    9,    9, 0x0a,
    1591, 1571,    9,    9, 0x0a,
    1631,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DbHepler[] = {
    "DbHepler\0\0pageCurrent,pageCount,resultCount,resultCurrent\0"
    "receivePage(quint32,quint32,quint32,quint32)\0"
    "count,msec\0receiveCount(quint32,double)\0"
    "sql\0bindData(QString)\0showCurrve(QString)\0"
    "slot_receiveCount(quint32,double)\0"
    "first()\0previous()\0next()\0last()\0"
    "qcustomWidget,tableView,labPageCount,labPageCurrent,labResultCount,lab"
    "ResultCurrent,labResult,labInfo,btnFirst,btnPre,btnNext,btnLast,countN"
    "ame,connName\0"
    "setControl(QCustomPlot*,QTableView*,QLabel*,QLabel*,QLabel*,QLabel*,QL"
    "abel*,QLabel*,QAbstractButton*,QAbstractButton*,QAbstractButton*,QAbst"
    "ractButton*,QString,QString)\0"
    "qcustomWidget,tableView,labPageCount,labPageCurrent,labResultCount,lab"
    "ResultCurrent,labResult,labInfo,btnFirst,btnPre,btnNext,btnLast,countN"
    "ame\0"
    "setControl(QCustomPlot*,QTableView*,QLabel*,QLabel*,QLabel*,QLabel*,QL"
    "abel*,QLabel*,QAbstractButton*,QAbstractButton*,QAbstractButton*,QAbst"
    "ractButton*,QString)\0"
    "connName\0setConnName(QString)\0dbType\0"
    "setDbType(DbType)\0showType\0setShowMode(int)\0"
    "tableName\0setTableName(QString)\0"
    "selectColumn\0setSelectColumn(QString)\0"
    "orderSql\0setOrderSql(QString)\0whereSql\0"
    "setWhereSql(QString)\0groupSql\0"
    "setGroupSql(QString)\0fidSql\0"
    "setFidSql(QString)\0resultCurrent\0"
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
    "select()\0"
};

void DbHepler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DbHepler *_t = static_cast<DbHepler *>(_o);
        switch (_id) {
        case 0: _t->receivePage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 1: _t->receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->bindData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showCurrve((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slot_receiveCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->first(); break;
        case 6: _t->previous(); break;
        case 7: _t->next(); break;
        case 8: _t->last(); break;
        case 9: _t->setControl((*reinterpret_cast< QCustomPlot*(*)>(_a[1])),(*reinterpret_cast< QTableView*(*)>(_a[2])),(*reinterpret_cast< QLabel*(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4])),(*reinterpret_cast< QLabel*(*)>(_a[5])),(*reinterpret_cast< QLabel*(*)>(_a[6])),(*reinterpret_cast< QLabel*(*)>(_a[7])),(*reinterpret_cast< QLabel*(*)>(_a[8])),(*reinterpret_cast< QAbstractButton*(*)>(_a[9])),(*reinterpret_cast< QAbstractButton*(*)>(_a[10])),(*reinterpret_cast< QAbstractButton*(*)>(_a[11])),(*reinterpret_cast< QAbstractButton*(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14]))); break;
        case 10: _t->setControl((*reinterpret_cast< QCustomPlot*(*)>(_a[1])),(*reinterpret_cast< QTableView*(*)>(_a[2])),(*reinterpret_cast< QLabel*(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4])),(*reinterpret_cast< QLabel*(*)>(_a[5])),(*reinterpret_cast< QLabel*(*)>(_a[6])),(*reinterpret_cast< QLabel*(*)>(_a[7])),(*reinterpret_cast< QLabel*(*)>(_a[8])),(*reinterpret_cast< QAbstractButton*(*)>(_a[9])),(*reinterpret_cast< QAbstractButton*(*)>(_a[10])),(*reinterpret_cast< QAbstractButton*(*)>(_a[11])),(*reinterpret_cast< QAbstractButton*(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13]))); break;
        case 11: _t->setConnName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setDbType((*reinterpret_cast< const DbType(*)>(_a[1]))); break;
        case 13: _t->setShowMode((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 14: _t->setTableName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setSelectColumn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setOrderSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->setWhereSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->setGroupSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->setFidSql((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        case 34: _t->select(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DbHepler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DbHepler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DbHepler,
      qt_meta_data_DbHepler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DbHepler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DbHepler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DbHepler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DbHepler))
        return static_cast<void*>(const_cast< DbHepler*>(this));
    return QObject::qt_metacast(_clname);
}

int DbHepler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void DbHepler::receivePage(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DbHepler::receiveCount(quint32 _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
