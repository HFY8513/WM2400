#pragma execution_character_set("utf-8")
#include "zeei_wm_home.h"
#include "ui_zeei_wm_home.h"
#include "iconhelper.h"

ZEEI_WM_HOME::ZEEI_WM_HOME(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZEEI_WM_HOME)
{
    ui->setupUi(this);
    this->initForm();
    this->initLeftMain();
    //this->initLeftConfig();
}

ZEEI_WM_HOME::~ZEEI_WM_HOME()
{
    delete ui;
}

void ZEEI_WM_HOME::initForm()
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf073), 30);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    //ui->widgetMenu->setVisible(false);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->widgetBottom->setProperty("form","bottom");
    ui->labTitle->setText("微型水站站点软件");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
    this->setWindowTitle(ui->labTitle->text());

    //ui->stackedWidget->setStyleSheet("QLabel{font:60pt;}");

    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }


    ui->btnData->click();

    ui->widgetLeftMain->setProperty("flag", "left");
    //ui->widgetLeftConfig->setProperty("flag", "left");
    ui->page2->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(20));
    ui->page6->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));
}

void ZEEI_WM_HOME::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    if (name == "数据查询") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "参数设置") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "系统控制") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "设备管理") {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "系统管理") {
        ui->stackedWidget->setCurrentIndex(4);
    } else if (name == "运营维护") {
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void ZEEI_WM_HOME::initLeftMain()
{
    pixCharMain << 0xf030 << 0xf03e << 0xf247;
    btnsMain << ui->tbtnMain1 << ui->tbtnMain2 << ui->tbtnMain3;

    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        btnsMain.at(i)->setCheckable(true);
        btnsMain.at(i)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btnsMain.at(i), SIGNAL(clicked(bool)), this, SLOT(leftMainClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftMain, btnsMain, pixCharMain, 15, 35, 25, "left", 4);

    ui->tbtnMain1->click();
}


void ZEEI_WM_HOME::leftMainClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    int count = btnsMain.count();
    for (int i = 0; i < count; i++) {
        if (btnsMain.at(i) == b) {
            btnsMain.at(i)->setChecked(true);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), false)));
        } else {
            btnsMain.at(i)->setChecked(false);
            btnsMain.at(i)->setIcon(QIcon(IconHelper::Instance()->getPixmap(btnsMain.at(i), true)));
        }
    }

    ui->lab6->setText(name);
}



void ZEEI_WM_HOME::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void ZEEI_WM_HOME::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
//        location = this->geometry();
//        this->setGeometry(qApp->desktop()->availableGeometry());
        this->showFullScreen();
    }

    this->setProperty("canMove", max);
    max = !max;
}

void ZEEI_WM_HOME::on_btnMenu_Close_clicked()
{
    close();
}

void ZEEI_WM_HOME::timerUpdate(){
    QDateTime time = QDateTime::currentDateTime();
    ui->labelTime->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
}


