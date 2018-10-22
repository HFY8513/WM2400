#include "zeei_wm_devctrl.h"
#include "ui_zeei_wm_devctrl.h"

ZEEI_WM_DEVCTRL::ZEEI_WM_DEVCTRL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZEEI_WM_DEVCTRL)
{
    ui->setupUi(this);
    ui->widgetLeftConfig->setProperty("flag", "left");
    this->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(40));
    this->initLeftConfig();
}

ZEEI_WM_DEVCTRL::~ZEEI_WM_DEVCTRL()
{
    delete ui;
}
void ZEEI_WM_DEVCTRL::initLeftConfig()
{
    pixCharConfig << 1 << 2 << 3;
    btnsConfig << ui->tbtnConfig1 << ui->tbtnConfig2 << ui->tbtnConfig3 ;

    int count = btnsConfig.count();
    for (int i = 0; i < count; i++) {
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(leftConfigClick()));
    }

    IconHelper::Instance()->setStyle(ui->widgetLeftConfig, btnsConfig, pixCharConfig, 10, 20, 15, "left", 5);

    ui->tbtnConfig1->click();
}


void ZEEI_WM_DEVCTRL::leftConfigClick()
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

    if (name == "分析单元") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "留样单元") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "质控单元") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "废液单元") {
        ui->stackedWidget->setCurrentIndex(3);
    }
}
