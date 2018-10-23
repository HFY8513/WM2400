#include "dbpage.h"
#include "ui_dbpage.h"

#include "oss/common/loadcsv.h"
#include "oss/utils/dsm/dsmpub.h"
extern   factor_map select_fidmaps[MAX_DAQ_ITEM];
SqlQueryModel::SqlQueryModel(QObject *parent) : QSqlQueryModel(parent)
{
    allCenter = false;
    alignCenterColumn.clear();
    alignRightColumn.clear();
}

QVariant SqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if (allCenter) {
        if(role == Qt::TextAlignmentRole ) {
            value = Qt::AlignCenter;
        }
    } else {
        //逐个从列索引中查找是否当前列在其中
        int column = index.column();
        bool existCenter = alignCenterColumn.contains(column);
        bool existRight = alignRightColumn.contains(column);

        if(role == Qt::TextAlignmentRole) {
            if (existCenter) {
                value = Qt::AlignCenter;
            }

            if (existRight) {
                value = (QVariant)(Qt::AlignVCenter | Qt::AlignRight);
            }
        }
    }

    return value;
}

void SqlQueryModel::setAllCenter(bool allCenter)
{
    this->allCenter = allCenter;
}

void SqlQueryModel::setAlignCenterColumn(const QList<int> &alignCenterColumn)
{
    this->alignCenterColumn = alignCenterColumn;
}

void SqlQueryModel::setAlignRightColumn(const QList<int> &alignRightColumn)
{
    this->alignRightColumn = alignRightColumn;
}


void DbPage::initQcustomPlot()
{
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);

    customPlot->yAxis->setRange(0, 200);
    customPlot->yAxis->setSubTicks(true);
     customPlot->xAxis->setSubTicks(true);
    //    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    //    customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    //    customPlot->xAxis->setDateTimeSpec(Qt::LocalTime);
    //    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    //    textTicker->set
    //    textTicker->setSubTickCount(5);
    //    textTicker->addTick(0.0, "yt");
    //    textTicker->addTick(1.0, "Bacteria");
    //    textTicker->addTick(2.0, "Protozoa");
    //    textTicker->addTick(3.0, "Chromista");
    //    textTicker->addTick(4.0, "Plants");
    //    textTicker->addTick(5.0, "Fungi");
    //    textTicker->addTick(6.0, "Animals");
    //    textTicker->addTick(8.0, "Vogons");
    //    customPlot->xAxis->setTicker(textTicker);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);

    // dateTicker->setDateTimeSpec(Qt::UTC);
    customPlot->xAxis->setTicker(dateTicker);
    customPlot->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDate(2018,9,22)),QCPAxisTickerDateTime::dateTimeToKey(QDate(2018,9,23)));
    //customPlot->xAxis->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDate::currentDate()),QCPAxisTickerDateTime::dateTimeToKey(QDate::currentDate().addDays(1)));
    dateTicker->setDateTimeFormat("hh:mm");

    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));

    customPlot->axisRect()->setupFullAxesBox();

    customPlot->legend->setVisible(true);

    customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

    connect(customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));

    customPlot->rescaleAxes();
    customPlot->replot();
}

void DbPage::selectionChanged()
{

    // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
            customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        customPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        customPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
            customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        customPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        customPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // synchronize selection of graphs with selection of corresponding legend items:
    for (int i=0; i<customPlot->graphCount(); ++i)
    {
        QCPGraph *graph = customPlot->graph(i);
        QCPPlottableLegendItem *item = customPlot->legend->itemWithPlottable(graph);
        if (item->selected() || graph->selected())
        {
            item->setSelected(true);
            graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
        }
    }
}

void DbPage::mousePress()
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void DbPage::mouseWheel()
{
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void DbPage::addRandomGraph(QVector<double> x, QVector<double> y, QString fidname)
{

    for(int i=0;i<y.size();i++)
        qDebug()<<x[i]<<"---->"<<y[i];
    qDebug()<<"----------------"<<customPlot->graphCount();

    customPlot->addGraph();

    customPlot->graph()->setName(fidname);
    customPlot->graph()->setData(x, y);
    customPlot->graph()->setLineStyle((QCPGraph::LineStyle)(1));

    customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(1.5);
    customPlot->graph()->setPen(graphPen);
    customPlot->replot();
}

void DbPage::removeSelectedGraph()
{
    if (customPlot->selectedGraphs().size() > 0)
    {
        customPlot->removeGraph(customPlot->selectedGraphs().first());
        customPlot->replot();
    }
}

void DbPage::removeAllGraphs()
{
    customPlot->clearGraphs();
    customPlot->replot();
}


void DbPage::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
    // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
    // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
    double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
    QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
    qDebug()<<message;
}


DbCountThread::DbCountThread(QObject *parent) : QThread(parent)
{
    connName = "qt_sql_default_connection";
    sql = "select 1";

    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void DbCountThread::run()
{
    //计算用时
    QDateTime dtStart = QDateTime::currentDateTime();

    QSqlQuery query(QSqlDatabase::database(connName));
    query.exec(sql);
    query.next();
    int count = query.value(0).toInt();

    QDateTime dtEnd = QDateTime::currentDateTime();
    double msec = dtStart.msecsTo(dtEnd);
    emit receiveCount(count, msec);
}

void DbCountThread::setConnName(const QString &connName)
{
    this->connName = connName;
}

void DbCountThread::setSql(const QString &sql)
{
    this->sql = sql;
}

DbPage::DbPage(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::DbPage)
{
    ui->setupUi(this);

    startIndex = 0;
    tempSql = "";
    sql = "";
    queryModel = new SqlQueryModel;

    pageCurrent = 0;
    pageCount = 0;
    resultCount = 0;
    ui->spinBox->setValue(30);
    resultCurrent = ui->spinBox->text().toInt();

    lab_resultCurrent = 0;
    lab_info = 0;

    countName = "*";
    connName = "qt_sql_default_connection";
    dbType = DbType_MySql;

    tableName = "";
    selectColumn = "*";
    orderSql = "";
    whereSql = "";
    columnNames.clear();
    columnWidths.clear();

    insertColumnIndex = -1;
    insertColumnName = "";
    insertColumnWidth = 50;

    //挂载翻页按钮事件

    //    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    //    ui->tableMain->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    //    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);
    connect(ui->pbtn_first, SIGNAL(clicked()), this, SLOT(first()));
    connect(ui->pbtn_pre, SIGNAL(clicked()), this, SLOT(previous()));
    connect(ui->pbtn_next, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->pbtn_last, SIGNAL(clicked()), this, SLOT(last()));
}

DbPage::~DbPage()
{
    delete ui;
}

void DbPage::slot_receiveCount(quint32 count, double msec)
{

    if (ui->lab_result != 0) {
        ui->lab_result->setText(QString("查询用时 %1 秒").arg(QString::number(msec / 1000, 'f', 3)));
    }

    resultCount = count;

    int yushu = resultCount % resultCurrent;

    //不存在余数,说明是整行,例如300%5==0
    if (yushu == 0) {
        if (resultCount > 0 && resultCount < resultCurrent) {
            pageCount = 1;
        } else {
            pageCount = resultCount / resultCurrent;
        }
    } else {
        pageCount = (resultCount / resultCurrent) + 1;
    }

    //如果只有一页数据,则翻页按钮不可用
    if (pageCount <= 1) {
        ui->pbtn_first->setEnabled(false);
        ui->pbtn_last->setEnabled(false);
        ui->pbtn_next->setEnabled(false);
        ui->pbtn_pre->setEnabled(false);
    } else {
        ui->pbtn_first->setEnabled(true);
        ui->pbtn_last->setEnabled(true);
        ui->pbtn_next->setEnabled(true);
        ui->pbtn_pre->setEnabled(true);
    }

    //tempSql = QString("select %1 from %2 %3 order by %4").arg(selectColumn).arg(tableName).arg(whereSql).arg(orderSql);
    tempSql = QString("select %1 from %2 %3  %4").arg(selectColumn).arg(tableName).arg(whereSql).arg(groupSql);
    sql = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg(resultCurrent); //组织分页SQL语句
    qDebug()<<sql;
    fidcount = 0;
    while(select_fidmaps[fidcount].fid != NULL) {fidcount++;}
    if(showType==SHOW_DATA){
        bindData(sql);
    }else{
        showCurrve(sql);
    }
}

void DbPage::bindData(const QString &sql)
{
//    int row=0;
//    int rowcount = 0;

    QSqlQuery query(QSqlDatabase::database(connName));
    query.exec(sql);

    queryModel->setQuery(sql, QSqlDatabase::database(connName));
    ui->tableView->setModel(queryModel);

    //设置列标题和列宽度
    for (int i = 0; i < columnNames.count(); i++) {
        queryModel->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
        if(i<columnWidths.count())
            ui->tableView->setColumnWidth(i, columnWidths.at(i));
    }

    //QStandardItemModel *data_model = new QStandardItemModel();
    //利用setModel()方法将数据模型与Qui->tableView绑定
    //ui->tableView->setModel(data_model);

//    while (query.next())
//    {
//        QSqlRecord r = query.record();
//        data_model->setItem(row, 0, new QStandardItem(r.field(r.field(4).name()).value().toDateTime().toString("yyyy-MM-dd hh:mm:ss")));
//        for(int i=0;i<fidcount;i++)
//        {
//            if(select_fidmaps[i].fid==r.field(r.field(2).name()).value())
//                data_model->setItem(row, 1+i, new QStandardItem(r.field(r.field(5).name()).value().toString()));
//        }
//        rowcount++;

//        if(rowcount == fidcount)
//        {
//            rowcount=0;
//            row++;
//        }
//    }

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (ui->lab_pageCurrent != 0) {
        ui->lab_pageCurrent->setText(QString("第 %1 页").arg(pageCurrent));
    }

    if (ui->lab_pageCount != 0) {
        ui->lab_pageCount->setText(QString("共 %1 页").arg(pageCount));
    }

    if (ui->lab_resultCount != 0) {
        ui->lab_resultCount->setText(QString("共 %1 条").arg(resultCount));
    }

    if (lab_resultCurrent != 0) {
        lab_resultCurrent->setText(QString("每页 %1 条").arg(resultCurrent));
    }

    if (lab_info != 0) {
        lab_info->setText(QString("共 %1 条  每页 %2 条  共 %3 页  第 %4 页").arg(resultCount).arg(resultCurrent).arg(pageCount).arg(pageCurrent));
    }
}

void DbPage::showCurrve(const QString &sql)
{
    tempSql = QString("select %1 from %2 %3  %4").arg(selectColumn).arg(tableName).arg(whereSql).arg(groupSql);
    QString sql1 = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg("2880"); //组织分页SQL语句

    customPlot->clearGraphs();
    customPlot->replot();
    QVector<double> x(2880);


    for(int i=0; i<fidcount; i++)
    {
        QSqlQuery query(QSqlDatabase::database(connName));
        query.exec(sql1);
        QVector<double> y(2880);
        int ycount=0;
        int xcount=0;

        if(i==0)
        {
            while (query.next())
            {
                QSqlRecord r = query.record();
                x[xcount++] = r.field(r.field(i).name()).value().toDateTime().toTime_t();
                y[ycount++] = r.field(r.field(i+1).name()).value().toDouble();
            }
        }
        else
        {
            while (query.next())
            {
                QSqlRecord r = query.record();
                y[ycount++] = r.field(r.field(i+1).name()).value().toDouble();
            }
        }

        addRandomGraph(x,y,columnNames.at(i+1));
        y.clear();
    }
    x.clear();
}

void DbPage::first()
{
    if (pageCount > 1) {
        startIndex = 0;
        pageCurrent = 1;
        sql = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg(resultCurrent);
        bindData(sql);
        ui->pbtn_last->setEnabled(true);
        ui->pbtn_next->setEnabled(true);
    }

    ui->pbtn_first->setEnabled(false);
    ui->pbtn_pre->setEnabled(false);
}

void DbPage::previous()
{
    if (pageCurrent > 1) {
        pageCurrent--;
        startIndex -= resultCurrent;
        sql = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg(resultCurrent);
        bindData(sql);
        ui->pbtn_last->setEnabled(true);
        ui->pbtn_next->setEnabled(true);
    }

    if (pageCurrent == 1) {
        ui->pbtn_first->setEnabled(false);
        ui->pbtn_pre->setEnabled(false);
    }
}

void DbPage::next()
{
    if (pageCurrent < pageCount) {
        pageCurrent++;
        startIndex += resultCurrent;
        sql = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg(resultCurrent);
        bindData(sql);
        ui->pbtn_first->setEnabled(true);
        ui->pbtn_pre->setEnabled(true);
    }

    if (pageCurrent == pageCount) {
        ui->pbtn_last->setEnabled(false);
        ui->pbtn_next->setEnabled(false);
    }
}

void DbPage::last()
{
    if (pageCount > 0) {
        startIndex = (pageCount - 1) * resultCurrent;
        pageCurrent = pageCount;
        sql = QString("%1 limit %2,%3;").arg(tempSql).arg(startIndex).arg(resultCurrent);
        bindData(sql);
        ui->pbtn_first->setEnabled(true);
        ui->pbtn_pre->setEnabled(true);
    }

    ui->pbtn_last->setEnabled(false);
    ui->pbtn_next->setEnabled(false);
}

void DbPage::select()
{
    //重置开始索引
    startIndex = 0;
    pageCurrent = 1;

    //假设只有一页
    //slot_receiveCount(resultCurrent, 0);

    //全部禁用按钮,文本显示正在查询...
    ui->pbtn_first->setEnabled(false);
    ui->pbtn_last->setEnabled(false);
    ui->pbtn_next->setEnabled(false);
    ui->pbtn_pre->setEnabled(false);

    QString info = "正在查询...";

    if (lab_info != 0) {
        lab_info->setText(info);
    }

    if (ui->lab_pageCurrent != 0) {
        ui->lab_pageCurrent->setText(info);
    }

    if (ui->lab_pageCount != 0) {
        ui->lab_pageCount->setText(info);
    }

    if (ui->lab_resultCount != 0) {
        ui->lab_resultCount->setText(info);
    }

    if (lab_resultCurrent != 0) {
        lab_resultCurrent->setText(info);
    }

    if (ui->lab_result != 0) {
        ui->lab_result->setText(info);
    }

    //开始分页绑定数据前,计算好总数据量以及行数
    QString countSql = QString("select %1 from %2 %3  %4").arg(selectColumn).arg(tableName).arg(whereSql).arg(groupSql);
    tempSql = QString("select count(%1) from (%2)%3").arg(countName).arg(countSql).arg("temp");

    qDebug()<<tempSql;
    //采用线程执行查询复合条件的记录行数
    DbCountThread *dbCountThread = new DbCountThread(this);
    //绑定查询结果信号槽,一旦收到结果则立即执行
    connect(dbCountThread, SIGNAL(receiveCount(quint32, double)), this, SLOT(slot_receiveCount(quint32, double)));

    //设置数据库连接名称和查询语句,并启动线程
    dbCountThread->setConnName(connName);
    dbCountThread->setSql(tempSql);
    dbCountThread->start();
}

//设置显示数据的表格控件,当前翻页信息的标签控件等
void DbPage::setControl(QCustomPlot *qcustomWidget, const QString &connName)
{
    this->customPlot = qcustomWidget;
    this->connName = connName;
    this->ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    initQcustomPlot();
}

void DbPage::setConnName(const QString &connName)
{
    this->connName = connName;
}

void DbPage::setDbType(DbType &dbType)
{
    this->dbType = dbType;
}

void DbPage::setShowMode(const int &showType)
{
    this->showType = showType;
}

void DbPage::setTableName(const QString &tableName)
{
    this->tableName = tableName;
}

void DbPage::setSelectColumn(const QString &selectColumn)
{
    this->selectColumn = selectColumn;
}

void DbPage::setOrderSql(const QString &orderSql)
{
    this->orderSql = orderSql;
}

void DbPage::setWhereSql(const QString &whereSql)
{
    this->whereSql = whereSql;
}

void DbPage::setGroupSql(const QString &groupSql)
{
    this->groupSql = groupSql;
}

void DbPage::setResultCurrent(int resultCurrent)
{
    this->resultCurrent = resultCurrent;
}

void DbPage::setColumnNames(const QList<QString> &columnNames)
{
    this->columnNames = columnNames;
}

void DbPage::setColumnWidths(const QList<int> &columnWidths)
{
    this->columnWidths = columnWidths;
}

void DbPage::setInsertColumnIndex(int insertColumnIndex)
{
    this->insertColumnIndex = insertColumnIndex;
}

void DbPage::setInsertColumnName(const QString &insertColumnName)
{
    this->insertColumnName = insertColumnName;
}

void DbPage::setInsertColumnWidth(int insertColumnWidth)
{
    this->insertColumnWidth = insertColumnWidth;
}

void DbPage::on_spinBox_valueChanged(int arg1)
{
    this->resultCurrent = arg1;
}
