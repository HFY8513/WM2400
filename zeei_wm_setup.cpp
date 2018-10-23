#include "zeei_wm_setup.h"
#include "ui_zeei_wm_setup.h"
#include <QTextCodec>
#include <QDebug>
extern utrace g_qttrace;
extern char m_appdir[512];

ZEEI_WM_SETUP::ZEEI_WM_SETUP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZEEI_WM_SETUP)
{
    ui->setupUi(this);

    ui->widgetLeftConfig->setProperty("flag", "left");
    this->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));
    this->initPage();
    this->initLeftConfig();

}

ZEEI_WM_SETUP::~ZEEI_WM_SETUP()
{
    delete ui;
}
void ZEEI_WM_SETUP::initPage()
{
    m_mainparam = App::g_mainparam;
    m_dtsparam  = App::g_dtsparam;
//    memccpy(&m_mainparam,&(App::g_mainparam),sizeof(appmain_param));
    //readJson();
    initMainPage();
    initSitePage();
    initDtsPage();
}

void ZEEI_WM_SETUP::initMainPage()
{
    ui->led_stationName->setText(m_mainparam.name);
    ui->led_dataPeriod->setText(m_mainparam.name);
    ui->led_rtdint->setText(m_mainparam.name);
    ui->led_minuteint->setText(m_mainparam.name);
    ui->led_dbName->setText(m_mainparam.dbparam.db_name);
    ui->led_dbIP->setText(m_mainparam.dbparam.server_name);
    ui->led_dbPort->setText(QString::number(m_mainparam.dbparam.server_port));
    ui->led_dbuser->setText(m_mainparam.dbparam.user_name);
    ui->led_dbpwd->setText(m_mainparam.dbparam.user_passwd);
}

void ZEEI_WM_SETUP::initSitePage()
{
    ui->tabw_site->setColumnCount(3);
    ui->tabw_site->setHorizontalHeaderLabels(QStringList()<<tr("测点ID")<<tr("测点名称")<<tr("系统ID"));
    QHeaderView* headerView = ui->tabw_site->horizontalHeader(); //表头字体左对齐
    headerView->setDefaultAlignment(Qt::AlignLeft);

    ui->tabw_site->verticalHeader()->setVisible(false);

    ui->tabw_site->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//使列完全填充并平分
    ui->tabw_site->setSelectionBehavior(QAbstractItemView::SelectRows);   //选整行
    ui->tabw_site->setSelectionMode(QAbstractItemView::SingleSelection);   //只能单行选

    ui->tabw_site->setRowCount(m_mainparam.mnodecount);
    for(int i = 0;i < m_mainparam.mnodecount;i++)
    {
        ui->tabw_site->setItem(i,0,new QTableWidgetItem(QString::number(m_mainparam.mnodeparams[i].stationid, 10)));
        ui->tabw_site->setItem(i,1,new QTableWidgetItem(m_mainparam.mnodeparams[i].name));
        ui->tabw_site->setItem(i,2,new QTableWidgetItem(QString::number(m_mainparam.mnodeparams[i].sysid, 10)));
    }

}

void ZEEI_WM_SETUP::initDtsPage()
{
    QList<QString> columnNames; //字段名集合
    columnNames<<tr("传输ID")<<tr("传输通道名称")<<tr("测点名称")<<tr("MN")<<tr("密码")<<tr("传输类型")<<tr("通道信息")<<tr("传输协议")<<tr("分钟间隔")<<tr("实时间隔");

    QStandardItemModel  *item_model = new QStandardItemModel(m_dtsparam.tchcount,columnNames.count());
    for (int i = 0; i < 9; i++) {
        item_model->setHeaderData(i, Qt::Horizontal, columnNames.at(i));
    }
    for(int i = 0;i<m_dtsparam.tchcount;i++)
    {
        item_model->setItem(i,0,new QStandardItem(QString::number(m_dtsparam.tchparams[i].tchid)));
        item_model->setItem(i,1,new QStandardItem(m_dtsparam.tchparams[i].logicname));
        item_model->setItem(i,2,new QStandardItem(QString::number(m_dtsparam.tchparams[i].inftype)));
        item_model->setItem(i,3,new QStandardItem(m_dtsparam.tchparams[i].mn));
        item_model->setItem(i,4,new QStandardItem(m_dtsparam.tchparams[i].pw));
        item_model->setItem(i,5,new QStandardItem(QString::number(m_dtsparam.tchparams[i].inftype)));
        item_model->setItem(i,6,new QStandardItem(m_dtsparam.uiotcpparams[i].param.host));
        item_model->setItem(i,7,new QStandardItem(QString::number(m_dtsparam.tchparams[i].avgmode)));
        item_model->setItem(i,8,new QStandardItem(QString::number(m_dtsparam.tchparams[i].minuteint)));
        item_model->setItem(i,9,new QStandardItem(QString::number(m_dtsparam.tchparams[i].rtdint)));
    }

    ui->tabv_dts->setModel(item_model);          // 关联view与model
    ui->tabv_dts->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度

    ui->tabv_dts-> setColumnWidth(0, 45);//设置固定宽度
}

void ZEEI_WM_SETUP::initGuiPage()
{

}


void ZEEI_WM_SETUP::initLeftConfig()
{
    pixCharConfig << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    btnsConfig << ui->tbtnConfig1 << ui->tbtnConfig2 << ui->tbtnConfig3 << ui->tbtnConfig4 << ui->tbtnConfig5 << ui->tbtnConfig6 << ui->tbtnConfig7;

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(leftConfigClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftConfig, btnsConfig, pixCharConfig, 10, 20, 15, "left", 5);

    ui->tbtnConfig1->click();
}


void ZEEI_WM_SETUP::leftConfigClick()
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

    if (name == "基本设置") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "测点设置") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "采集设置") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "传输设置") {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "显示设置") {
        ui->stackedWidget->setCurrentIndex(4);
    } else if (name == "超标设置") {
        ui->stackedWidget->setCurrentIndex(5);
    } else if (name == "扩展设置") {
        ui->stackedWidget->setCurrentIndex(6);
    }
}

int ZEEI_WM_SETUP::readJson()
{
    uci myuci;
    char appdir[DM_FILEPATH_SIZE];
    strcpy(appdir,m_appdir);

    if (myuci.init(&g_qttrace, appdir) != 0)
    {
        return -2;
    }

    memset(&m_mainparam, 0, sizeof(m_mainparam));
    if (myuci.readmain(&m_mainparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"mainjson loadconfig fail!");
        return -3;
    }

    memset(&m_dtsparam,0,sizeof(m_dtsparam));
    if(myuci.readdts(&m_dtsparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"dtsjson loadconfig fail!");
        return -4;
    }
    return 0;
}



void ZEEI_WM_SETUP::on_btn_base_save_clicked()
{

}


