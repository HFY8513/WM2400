#include "zeei_wm_dbquery.h"
#include "ui_zeei_wm_dbquery.h"

extern dqi* mydqi;
extern utrace g_qttrace;
extern char m_appdir[512];

factor_map select_fidmaps[MAX_DAQ_ITEM];

ZEEI_WM_DbQuery::ZEEI_WM_DbQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZEEI_WM_DbQuery)
{
    ui->setupUi(this);
    this->initPage();
    this->initForm();
    this->initFidCmb();
}

ZEEI_WM_DbQuery::~ZEEI_WM_DbQuery()
{
    delete ui;
}

void ZEEI_WM_DbQuery::initPage()
{
    ui->widgetLeft->setProperty("form", "dbQueryLeft");
    connect(ui->cmbShow, SIGNAL(currentIndexChanged(int)), this, SLOT(showChanged(int)));

    QStringList showList;
    showList <<"表格" <<"曲线";
    ui->cmbShow->addItems(showList);

    QStringList modeList;
    modeList <<"实时数据" <<"日数据" <<"周期数据" <<"五参数据" <<"标识数据";
    ui->cmbMode->addItems(modeList);
    ui->cmbMode->setView(new QListView()); //这样才能是qss样式表中的下拉选项高度设置生效

    ui->cmbNId->addItem("未命名测点1");

    ui->dteBegin->setDate(QDate::currentDate().addDays(-30));
    ui->dteEnd->setDateTime(QDateTime::currentDateTime());
}

void ZEEI_WM_DbQuery::initForm()
{    
    columnNames.clear();
    columnWidths.clear();
    columnValue = "Value";
    tableName = "rdms_t_data";
    countName = "Time";

    //设置需要显示数据的表格和翻页的按钮
    //ui->dbPage->setDbType(DbType_MySql);
    ui->dbPage->setControl(ui->customPlot);
}

void ZEEI_WM_DbQuery::initFidCmb()
{
    uci myuci;
    char appdir[DM_FILEPATH_SIZE];
    strcpy(appdir,m_appdir);

    if (myuci.init(&g_qttrace, appdir) != 0)
    {
        qDebug()<<-2;
    }

    memset(&m_dasparam, 0, sizeof(m_dasparam));

    if (myuci.readdas(&m_dasparam) != 0)
    {
        //return -7;
    }

    int m_fcount=0;
    for(int i = 0;i<m_dasparam.fchcount;i++)
    {
        factor_map fidmaps[MAX_DAQ_ITEM];
        int cursysid = 32;
        int fcount = i_loadfactormap(fidmaps,cursysid);

        for(int j = 0;j < fcount;j++)
        {
            if(convertfidrule(m_dasparam.fchparams[i].fid)==fidmaps[j].fid)
            {
                memcpy(&m_fidmaps[m_fcount++],&fidmaps[j],sizeof(factor_map));
                break;
            }
        }
    }

    pTypeListWidget = new QListWidget(this);
    pLineEdit = new QLineEdit(this);

    for (int i = 0; i < m_fcount; ++i)
    {
        QListWidgetItem *pItem = new QListWidgetItem(pTypeListWidget);
        pTypeListWidget->addItem(pItem);
        pItem->setData(Qt::UserRole, i);
        pItem->setSizeHint(QSize(50,45));

        QCheckBox *pCheckBox = new QCheckBox(this);

        pCheckBox->setText(gbktoutf8(m_fidmaps[i].fac_name));
        pCheckBox->setStyleSheet("font: 13pt \"等线\"");

        pTypeListWidget->addItem(pItem);
        pTypeListWidget->setItemWidget(pItem, pCheckBox);
        connect(pCheckBox, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));
    }

    ui->cmbFid->setModel(pTypeListWidget->model());
    ui->cmbFid->setView(pTypeListWidget);
    ui->cmbFid->setLineEdit(pLineEdit);
    pLineEdit->setReadOnly(true);

    QListWidgetItem *pItem = pTypeListWidget->item(0);
    QWidget *pWidget = pTypeListWidget->itemWidget(pItem);
    QCheckBox *pCheckBox = (QCheckBox *)pWidget;
    pCheckBox->setChecked(true);

    connect(pLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(textChanged(const QString &)));

    pLineEdit->installEventFilter(this);     //加载事件过滤器
    //ui->dateEdit->setCurrentSectionIndex(2);
    //ui->dateEdit->setCalendarPopup(true);  // 日历弹出
}

void ZEEI_WM_DbQuery::on_btnSelect_clicked()
{
    qDebug()<<"query";
    QString strBegin = ui->dteBegin->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strEnd = ui->dteEnd->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString fidsql =  "";
    columnNames.clear();
    columnWidths.clear();
    columnNames.append("数据时间");
    columnWidths.append(200);

    for(int i=0; i<select_fcount; i++)
    {
        if (i != 0) fidsql += " , ";
        columnNames.append(gbktoutf8(select_fidmaps[i].fac_name));
        QString fidCoum=QString("MAX(CASE Fid WHEN '%1' THEN %2 ELSE 0 END ) '%3'").arg(select_fidmaps[i].fid).arg(columnValue).arg(gbktoutf8(select_fidmaps[i].fac_name));
        fidsql += fidCoum;
    }

    QString selectColumn = "Time, "+fidsql;
    //绑定数据到表格
    QString nidSql = "where Nid=1";
    QString timeSql=QString(" AND Time >= '%1' AND Time < '%2'").arg(strBegin).arg(strEnd);

    ui->dbPage->setTableName(tableName);
    ui->dbPage->setSelectColumn(selectColumn);
    ui->dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    ui->dbPage->setWhereSql(nidSql+timeSql);
    ui->dbPage->setGroupSql("Group by Time");

    ui->dbPage->setShowMode(ui->cmbShow->currentIndex());
    ui->dbPage->setColumnNames(columnNames);
    ui->dbPage->setColumnWidths(columnWidths);
    ui->dbPage->select();
}

void ZEEI_WM_DbQuery::showChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

//区域选择Check状态改变
void ZEEI_WM_DbQuery::stateChanged(int state)
{
    bSelected = true;
    QString strSelectedData("");
    strSelectedText.clear();
    //QObject *object = QObject::sender();
    //QCheckBox *pSenderCheckBox = static_cast<QCheckBox*>(object);
    int nCount = pTypeListWidget->count();
    select_fcount = 0;
    for (int i = 0; i < nCount; ++i)
    {
        QListWidgetItem *pItem = pTypeListWidget->item(i);
        QWidget *pWidget = pTypeListWidget->itemWidget(pItem);
        QCheckBox *pCheckBox = (QCheckBox *)pWidget;
        if (pCheckBox->isChecked())
        {
            memcpy(&select_fidmaps[select_fcount++],&m_fidmaps[i],sizeof(factor_map));
            QString strText = pCheckBox->text();
            strSelectedData.append(strText).remove(" ").append(",");
        }
    }
    if (strSelectedData.endsWith(","))
        strSelectedData.remove(strSelectedData.count() - 1, 1);

    if (!strSelectedData.isEmpty())
    {
        //ui->cmbFid->setEditText(strSelectedData);
        strSelectedText = strSelectedData;
        pLineEdit->setText(strSelectedData);
        pLineEdit->setToolTip(strSelectedData);
    }
    else
    {
        pLineEdit->clear();
    }

    bSelected = false;
}


//区域选择内容改变
void ZEEI_WM_DbQuery::textChanged(const QString &text)
{
    if (!bSelected)
        pLineEdit->setText(strSelectedText);
}

void ZEEI_WM_DbQuery::on_cmbMode_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        tableName = "rdms_t_data";  //实时数据
        break;
    case 1:
        tableName = "udms_t_avgday"; //日数据
        columnValue = "Avg";
        break;
    case 2:
        tableName = "rdms_t_dataperiod";//type=14 五参数据
        //select * from rdms_t_dataperiod where Nid=1 and Type=14 and Time >= '2018-10-01 00:00:00' and Time < '2018-10-02 00:00:00' order by Time asc
        break;
    case 3:
        tableName = "rdms_t_dataperiod";  //type=11 周期数据
        //select * from rdms_t_dataperiod where Nid=1 and Type=11 and Time >= '2018-10-01 00:00:00' and Time < '2018-10-02 00:00:00' order by Time asc
        break;
    case 4:
        tableName = "rdms_t_data"; //标识数据
         //select * from rdms_t_data where Nid=1 and Time >= '2018-10-01 00:00:00' and Time < '2018-10-02 00:00:00' and ( State=0 or State=98 or State=99 ) and ( (Gid=0 and Fid=1) ) order by Time, Fid, Gid asc
        break;
    default:
        break;
    }
}
