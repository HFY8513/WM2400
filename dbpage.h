#ifndef DBPAGE_H
#define DBPAGE_H

#include <QWidget>
#include <QtGui>
#include <QtSql>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#include "global.h"
#include "oss/thirds/qcustomplot/qcustomplot.h"
#include <QMenu>
#include "oss/thirds/qcustomplot/qcustomplot.h"
//自定义模型设置列居中和右对齐
class SqlQueryModel: public QSqlQueryModel
{
public:
    explicit SqlQueryModel(QObject *parent = 0);

protected:
    QVariant data(const QModelIndex &index, int role) const;

private:
    bool allCenter;                 //所有居中
    QList<int> alignCenterColumn;   //居中对齐列
    QList<int> alignRightColumn;    //右对齐列

public:
    void setAllCenter(bool allCenter);
    void setAlignCenterColumn(const QList<int> &alignCenterColumn);
    void setAlignRightColumn(const QList<int> &alignRightColumn);
};

//计算复合条件的记录总行数,以便分页
class DbCountThread : public QThread
{
    Q_OBJECT
public:
    explicit DbCountThread(QObject *parent = 0);

private:
    QString connName;   //数据库连接名称
    QString sql;        //要执行的查询语句

protected:
    void run();

signals:
    void receiveCount(quint32 count, double msec);

public slots:
    void setConnName(const QString &connName);
    void setSql(const QString &sql);

};
namespace Ui {
    class DbPage;
}
class DbPage : public QWidget
{
    Q_OBJECT

public:
    explicit DbPage(QWidget *parent = 0);
    ~DbPage();

private slots:
    //绑定sql语句到表格
    void bindData(const QString &sql);
    void showCurrve(const QString &sql);
    void slot_receiveCount(quint32 count, double msec);    //收到记录行数

    void first();               //第一页
    void previous();            //上一页
    void next();                //下一页
    void last();                //末一页

    void on_spinBox_valueChanged(int arg1);

signals:
    void receiveCount(quint32 count, double msec);

public slots:
    void select();
    //设置需要显示数据的表格,数据翻页对应的按钮
    void setControl(QCustomPlot *qcustomWidget,
                     const QString &connName = "qt_sql_default_connection");
    void setConnName(const QString &connName);
    void setDbType(DbType &dbType);
    void setShowMode(const int &showType);
    void setTableName(const QString &tableName);
    void setSelectColumn(const QString &selectColumn);

    void setOrderSql(const QString &orderSql);
    void setWhereSql(const QString &whereSql);
    void setGroupSql(const QString &groupSql);

    void setResultCurrent(int resultCurrent);
    void setColumnNames(const QList<QString> &columnNames);
    void setColumnWidths(const QList<int> &columnWidths);
    void setInsertColumnIndex(int insertColumnIndex);
    void setInsertColumnName(const QString &insertColumnName);
    void setInsertColumnWidth(int insertColumnWidth);

    void initQcustomPlot();
    void selectionChanged();
    void mousePress();
    void mouseWheel();
    void addRandomGraph(QVector<double> x,QVector<double> y,QString fidname);
    void removeSelectedGraph();
    void removeAllGraphs();
    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

private:
    Ui::DbPage *ui;

    int startIndex;             //分页开始索引,每次翻页都变动
    QString tempSql;            //临时SQL语句
    QString sql;                //sql语句
    SqlQueryModel *queryModel;  //查询模型

    QLabel *lab_resultCurrent;   //每页记录数标签
    QLabel *lab_info;            //总页数当前页总记录数每页记录数

    QCustomPlot *customPlot;

    QString countName;          //统计表行数用字段
    QString connName;           //所使用的数据库连接名
    DbType dbType;              //数据库类型

    quint32 pageCurrent;        //当前第几页
    quint32 pageCount;          //总页数
    quint32 resultCount;        //总记录数
    quint32 resultCurrent;      //每页显示记录数

    QString tableName;          //表名
    QString selectColumn;       //要查询的字段集合
    QString orderSql;           //排序语句
    QString whereSql;           //条件语句
    QString groupSql;           //时间语句

    QList<QString> columnNames; //列名集合
    QList<int> columnWidths;    //列宽集合

    int insertColumnIndex;      //插入的列的索引位置
    QString insertColumnName;   //插入的列的标题
    int insertColumnWidth;      //插入的列的宽度
    int fidcount;
    int showType;
};
#endif // DBPAGE_H
