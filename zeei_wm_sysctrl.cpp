#include "zeei_wm_sysctrl.h"
#include "ui_zeei_wm_sysctrl.h"
extern utrace g_qttrace;
extern char m_appdir[512];
ZEEI_WM_SYSCTRL::ZEEI_WM_SYSCTRL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZEEI_WM_SYSCTRL)
{
    ui->setupUi(this);
    ui->widgetLeftConfig->setProperty("flag", "left");
    this->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));
    this->initSysCfg();
    this->initLeftConfig();
}

ZEEI_WM_SYSCTRL::~ZEEI_WM_SYSCTRL()
{
    delete ui;
}

void ZEEI_WM_SYSCTRL::initLeftConfig()
{
    ui->dte_begin->setDate(QDate::currentDate().addDays(-30));
    ui->dte_end->setDateTime(QDateTime::currentDateTime());
    pixCharConfig << 1 << 2 << 3 ;
    btnsConfig << ui->tbtnConfig1 << ui->tbtnConfig2 << ui->tbtnConfig3;

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(leftConfigClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftConfig, btnsConfig, pixCharConfig, 10, 20, 15, "left", 5);

    ui->tbtnConfig1->click();
}

void ZEEI_WM_SYSCTRL::initSysCfg()
{
    uci myuci;
    char appdir[DM_FILEPATH_SIZE];
    strcpy(appdir,m_appdir);
    myuci.init(&g_qttrace, appdir);

    memset(&m_mainparam, 0, sizeof(m_mainparam));
    if (myuci.readmain(&m_mainparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"mainjson loadconfig fail!");
    }

    memset(&m_dasparam,0,sizeof(m_dasparam));
    if(myuci.readdas(&m_dasparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"dasjson loadconfig fail!");
    }

    memset(&m_dasparam,0,sizeof(m_dasparam));
    if(myuci.readdas(&m_dasparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"dasjson loadconfig fail!");
    }

    memset(&m_wmsparam,0,sizeof(m_wmsparam));
    if(myuci.readwms(&m_wmsparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"wmsjson loadconfig fail!");
    }

    QStringList typeList;
    typeList <<"常规水站" <<"常规污染源" <<"一企一管";
    ui->cmb_measuretype->addItems(typeList);

    QStringList modeList;
    modeList <<"仪表独立触发" <<"系统周期触发" <<"系统时段触发" <<"系统流量触发";
    ui->cmb_trigmode->addItems(modeList);

    QStringList electrodemodeList;
    electrodemodeList <<"定时采集" <<"信号采集";
    ui->cmb_electrodemode->addItems(electrodemodeList);

    for(int i=0; i<m_wmsparam.systemcount; i++)
    {
        ui->led_measuerint->setText(QString::number(m_wmsparam.systemparams[i].measuerint));
        ui->led_measuertime->setText(QString::number(m_wmsparam.systemparams[i].measuertime));
        ui->cmb_epcmodule->addItem(m_wmsparam.systemparams[i].epcmodule);
        ui->cmb_measuretype->setCurrentIndex(m_wmsparam.systemparams[i].measuretype);
        //ui->led_dailystarttime->setText(m_wmsparam.systemparams[i].dailystarttime);

        ui->cmb_trigmode->setCurrentIndex(m_wmsparam.systemparams[i].trigmode);
        ui->led_trigflowlimt->setText(QString::number(m_wmsparam.systemparams[i].trigflowlimt));

//        ui->cmb_electrodemode->setCurrentIndex(m_wmsparam.systemparams[i].electrodemode);
//        ui->led_electrodetime->setText(m_wmsparam.systemparams[i].electrodetime);
    }

}

void ZEEI_WM_SYSCTRL::leftConfigClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        if (btnsConfig.at(i) == b) {
            btnsConfig.at(i)->setChecked(true);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), false)));
        } else {
            btnsConfig.at(i)->setChecked(false);
            btnsConfig.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsConfig.at(i), true)));
        }
    }

    QList<QToolButton *> tbtns = ui->widgetLeftConfig->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    if (name == "系统参数") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "流程控制") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "流程日志") {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void ZEEI_WM_SYSCTRL::on_pbtn_query_clicked()
{
    QString strBegin = ui->dte_begin->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strEnd = ui->dte_end->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    columnNames.clear();
    columnNames.append("时间");
    columnNames.append("对象");
    columnNames.append("记录");
    columnWidths.clear();
    columnWidths.append(200);

    QString tableName = "ams_t_hislog";
    QString selectColumn = "Time,User,Action";
    QString timeSql = QString(" Where Time >= '%1' AND Time < '%2'").arg(strBegin).arg(strEnd);
    QString orderSql ="order by Time asc";
    ui->dbPage->setTableName(tableName);
    ui->dbPage->setSelectColumn(selectColumn);
    ui->dbPage->setWhereSql(timeSql+" and type =21");
    ui->dbPage->setOrderSql(orderSql);

    ui->dbPage->setColumnNames(columnNames);
    ui->dbPage->setColumnWidths(columnWidths);
    ui->dbPage->select();
}
