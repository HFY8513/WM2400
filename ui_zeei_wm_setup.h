/********************************************************************************
** Form generated from reading UI file 'zeei_wm_setup.ui'
**
** Created: Thu Oct 18 13:29:43 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEEI_WM_SETUP_H
#define UI_ZEEI_WM_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "wm_setup_das.h"

QT_BEGIN_NAMESPACE

class Ui_ZEEI_WM_SETUP
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetLeftConfig;
    QVBoxLayout *verticalLayout_3;
    QToolButton *tbtnConfig1;
    QToolButton *tbtnConfig2;
    QToolButton *tbtnConfig3;
    QToolButton *tbtnConfig4;
    QToolButton *tbtnConfig5;
    QToolButton *tbtnConfig6;
    QToolButton *tbtnConfig7;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_1;
    QLineEdit *led_stationName;
    QLineEdit *led_rtdint;
    QLabel *label_4;
    QLineEdit *led_minuteint;
    QLabel *label_5;
    QLineEdit *led_dbIP;
    QLineEdit *led_dbName;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *led_dbuser;
    QLineEdit *led_dbPort;
    QLabel *label_9;
    QLineEdit *led_dbpwd;
    QLineEdit *led_dataPeriod;
    QLabel *label_2;
    QPushButton *btn_base_save;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QTableWidget *tabw_site;
    WM_SETUP_DAS *page3;
    QWidget *page4;
    QGridLayout *gridLayout_3;
    QTableView *tabv_dts;
    QWidget *page5;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QLineEdit *led_groupfilter;
    QLabel *label_11;
    QLineEdit *led_fidfilter;
    QLabel *label_12;
    QLineEdit *led_showmode;
    QPushButton *btn_gui_save;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page6;
    QGridLayout *gridLayout_6;
    QTableView *tableView_3;
    QWidget *page7;
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QWidget *ZEEI_WM_SETUP)
    {
        if (ZEEI_WM_SETUP->objectName().isEmpty())
            ZEEI_WM_SETUP->setObjectName(QString::fromUtf8("ZEEI_WM_SETUP"));
        ZEEI_WM_SETUP->resize(1440, 800);
        gridLayout = new QGridLayout(ZEEI_WM_SETUP);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetLeftConfig = new QWidget(ZEEI_WM_SETUP);
        widgetLeftConfig->setObjectName(QString::fromUtf8("widgetLeftConfig"));
        widgetLeftConfig->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(widgetLeftConfig);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tbtnConfig1 = new QToolButton(widgetLeftConfig);
        tbtnConfig1->setObjectName(QString::fromUtf8("tbtnConfig1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbtnConfig1->sizePolicy().hasHeightForWidth());
        tbtnConfig1->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        tbtnConfig1->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig1);

        tbtnConfig2 = new QToolButton(widgetLeftConfig);
        tbtnConfig2->setObjectName(QString::fromUtf8("tbtnConfig2"));
        sizePolicy.setHeightForWidth(tbtnConfig2->sizePolicy().hasHeightForWidth());
        tbtnConfig2->setSizePolicy(sizePolicy);
        tbtnConfig2->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig2);

        tbtnConfig3 = new QToolButton(widgetLeftConfig);
        tbtnConfig3->setObjectName(QString::fromUtf8("tbtnConfig3"));
        sizePolicy.setHeightForWidth(tbtnConfig3->sizePolicy().hasHeightForWidth());
        tbtnConfig3->setSizePolicy(sizePolicy);
        tbtnConfig3->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig3);

        tbtnConfig4 = new QToolButton(widgetLeftConfig);
        tbtnConfig4->setObjectName(QString::fromUtf8("tbtnConfig4"));
        sizePolicy.setHeightForWidth(tbtnConfig4->sizePolicy().hasHeightForWidth());
        tbtnConfig4->setSizePolicy(sizePolicy);
        tbtnConfig4->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig4);

        tbtnConfig5 = new QToolButton(widgetLeftConfig);
        tbtnConfig5->setObjectName(QString::fromUtf8("tbtnConfig5"));
        sizePolicy.setHeightForWidth(tbtnConfig5->sizePolicy().hasHeightForWidth());
        tbtnConfig5->setSizePolicy(sizePolicy);
        tbtnConfig5->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig5);

        tbtnConfig6 = new QToolButton(widgetLeftConfig);
        tbtnConfig6->setObjectName(QString::fromUtf8("tbtnConfig6"));
        sizePolicy.setHeightForWidth(tbtnConfig6->sizePolicy().hasHeightForWidth());
        tbtnConfig6->setSizePolicy(sizePolicy);
        tbtnConfig6->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig6);

        tbtnConfig7 = new QToolButton(widgetLeftConfig);
        tbtnConfig7->setObjectName(QString::fromUtf8("tbtnConfig7"));
        sizePolicy.setHeightForWidth(tbtnConfig7->sizePolicy().hasHeightForWidth());
        tbtnConfig7->setSizePolicy(sizePolicy);
        tbtnConfig7->setFont(font);

        verticalLayout_3->addWidget(tbtnConfig7);

        verticalSpacer_4 = new QSpacerItem(20, 417, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout->addWidget(widgetLeftConfig, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(ZEEI_WM_SETUP);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout_8 = new QGridLayout(page1);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(10, -1, -1, -1);
        label_1 = new QLabel(page1);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMinimumSize(QSize(0, 30));
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_1, 0, 0, 1, 1);

        led_stationName = new QLineEdit(page1);
        led_stationName->setObjectName(QString::fromUtf8("led_stationName"));
        led_stationName->setMinimumSize(QSize(0, 30));
        led_stationName->setFont(font);
        led_stationName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(led_stationName, 0, 1, 1, 1);

        led_rtdint = new QLineEdit(page1);
        led_rtdint->setObjectName(QString::fromUtf8("led_rtdint"));
        led_rtdint->setMinimumSize(QSize(0, 30));
        led_rtdint->setFont(font);

        gridLayout_2->addWidget(led_rtdint, 1, 1, 1, 1);

        label_4 = new QLabel(page1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        led_minuteint = new QLineEdit(page1);
        led_minuteint->setObjectName(QString::fromUtf8("led_minuteint"));
        led_minuteint->setMinimumSize(QSize(0, 30));
        led_minuteint->setFont(font);

        gridLayout_2->addWidget(led_minuteint, 3, 1, 1, 1);

        label_5 = new QLabel(page1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setTextFormat(Qt::PlainText);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        led_dbIP = new QLineEdit(page1);
        led_dbIP->setObjectName(QString::fromUtf8("led_dbIP"));
        led_dbIP->setMinimumSize(QSize(0, 30));
        led_dbIP->setFont(font);

        gridLayout_2->addWidget(led_dbIP, 5, 1, 1, 1);

        led_dbName = new QLineEdit(page1);
        led_dbName->setObjectName(QString::fromUtf8("led_dbName"));
        led_dbName->setMinimumSize(QSize(0, 30));
        led_dbName->setFont(font);

        gridLayout_2->addWidget(led_dbName, 4, 1, 1, 1);

        label_3 = new QLabel(page1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(page1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(page1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(page1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 7, 0, 1, 1);

        led_dbuser = new QLineEdit(page1);
        led_dbuser->setObjectName(QString::fromUtf8("led_dbuser"));
        led_dbuser->setMinimumSize(QSize(0, 30));
        led_dbuser->setFont(font);

        gridLayout_2->addWidget(led_dbuser, 7, 1, 1, 1);

        led_dbPort = new QLineEdit(page1);
        led_dbPort->setObjectName(QString::fromUtf8("led_dbPort"));
        led_dbPort->setMinimumSize(QSize(0, 30));
        led_dbPort->setFont(font);

        gridLayout_2->addWidget(led_dbPort, 6, 1, 1, 1);

        label_9 = new QLabel(page1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 8, 0, 1, 1);

        led_dbpwd = new QLineEdit(page1);
        led_dbpwd->setObjectName(QString::fromUtf8("led_dbpwd"));
        led_dbpwd->setMinimumSize(QSize(0, 30));
        led_dbpwd->setFont(font);
        led_dbpwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(led_dbpwd, 8, 1, 1, 1);

        led_dataPeriod = new QLineEdit(page1);
        led_dataPeriod->setObjectName(QString::fromUtf8("led_dataPeriod"));
        led_dataPeriod->setMinimumSize(QSize(0, 30));
        led_dataPeriod->setFont(font);

        gridLayout_2->addWidget(led_dataPeriod, 2, 1, 1, 1);

        label_2 = new QLabel(page1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        btn_base_save = new QPushButton(page1);
        btn_base_save->setObjectName(QString::fromUtf8("btn_base_save"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_base_save->sizePolicy().hasHeightForWidth());
        btn_base_save->setSizePolicy(sizePolicy1);
        btn_base_save->setFont(font);

        verticalLayout_2->addWidget(btn_base_save);


        gridLayout_8->addLayout(verticalLayout_2, 0, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(404, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(404, 779, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 0, 2, 1);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabw_site = new QTableWidget(page2);
        tabw_site->setObjectName(QString::fromUtf8("tabw_site"));

        gridLayout_4->addWidget(tabw_site, 0, 0, 1, 1);

        stackedWidget->addWidget(page2);
        page3 = new WM_SETUP_DAS();
        page3->setObjectName(QString::fromUtf8("page3"));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        gridLayout_3 = new QGridLayout(page4);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        tabv_dts = new QTableView(page4);
        tabv_dts->setObjectName(QString::fromUtf8("tabv_dts"));

        gridLayout_3->addWidget(tabv_dts, 0, 0, 1, 1);

        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QString::fromUtf8("page5"));
        gridLayout_9 = new QGridLayout(page5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(404, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_10 = new QLabel(page5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        led_groupfilter = new QLineEdit(page5);
        led_groupfilter->setObjectName(QString::fromUtf8("led_groupfilter"));
        led_groupfilter->setFont(font);

        gridLayout_5->addWidget(led_groupfilter, 0, 1, 1, 1);

        label_11 = new QLabel(page5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout_5->addWidget(label_11, 1, 0, 1, 1);

        led_fidfilter = new QLineEdit(page5);
        led_fidfilter->setObjectName(QString::fromUtf8("led_fidfilter"));
        led_fidfilter->setFont(font);

        gridLayout_5->addWidget(led_fidfilter, 1, 1, 1, 1);

        label_12 = new QLabel(page5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        led_showmode = new QLineEdit(page5);
        led_showmode->setObjectName(QString::fromUtf8("led_showmode"));
        led_showmode->setFont(font);

        gridLayout_5->addWidget(led_showmode, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        btn_gui_save = new QPushButton(page5);
        btn_gui_save->setObjectName(QString::fromUtf8("btn_gui_save"));
        btn_gui_save->setFont(font);

        verticalLayout->addWidget(btn_gui_save);


        gridLayout_9->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(404, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        stackedWidget->addWidget(page5);
        page6 = new QWidget();
        page6->setObjectName(QString::fromUtf8("page6"));
        gridLayout_6 = new QGridLayout(page6);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableView_3 = new QTableView(page6);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));

        gridLayout_6->addWidget(tableView_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page6);
        page7 = new QWidget();
        page7->setObjectName(QString::fromUtf8("page7"));
        gridLayout_7 = new QGridLayout(page7);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tabWidget = new QTabWidget(page7);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setIconSize(QSize(32, 32));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout_7->addWidget(tabWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(page7);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(ZEEI_WM_SETUP);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ZEEI_WM_SETUP);
    } // setupUi

    void retranslateUi(QWidget *ZEEI_WM_SETUP)
    {
        ZEEI_WM_SETUP->setWindowTitle(QApplication::translate("ZEEI_WM_SETUP", "Form", 0, QApplication::UnicodeUTF8));
        tbtnConfig1->setText(QApplication::translate("ZEEI_WM_SETUP", "\345\237\272\346\234\254\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig2->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\265\213\347\202\271\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig3->setText(QApplication::translate("ZEEI_WM_SETUP", "\351\207\207\351\233\206\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig4->setText(QApplication::translate("ZEEI_WM_SETUP", "\344\274\240\350\276\223\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig5->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\230\276\347\244\272\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig6->setText(QApplication::translate("ZEEI_WM_SETUP", "\350\266\205\346\240\207\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tbtnConfig7->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\211\251\345\261\225\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("ZEEI_WM_SETUP", "\347\253\231\347\202\271\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ZEEI_WM_SETUP", "\345\210\206\351\222\237\344\277\235\345\255\230\351\227\264\351\232\224(\345\210\206):", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZEEI_WM_SETUP", "\345\256\236\346\227\266\344\277\235\345\255\230\351\227\264\351\232\224(\347\247\222):", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\225\260\346\215\256\345\272\223IP:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\225\260\346\215\256\345\272\223PORT:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZEEI_WM_SETUP", "\345\256\236\346\227\266\351\207\207\351\233\206\351\227\264\351\232\224(\347\247\222):", 0, QApplication::UnicodeUTF8));
        btn_base_save->setText(QApplication::translate("ZEEI_WM_SETUP", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\230\276\347\244\272\345\210\206\347\273\204", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\230\276\347\244\272\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ZEEI_WM_SETUP", "\346\230\276\347\244\272\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        btn_gui_save->setText(QApplication::translate("ZEEI_WM_SETUP", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ZEEI_WM_SETUP", "\345\233\240\345\255\220\345\256\232\344\271\211", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ZEEI_WM_SETUP", "\345\233\240\345\255\220\350\275\254\346\215\242", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ZEEI_WM_SETUP", "\345\233\240\345\255\220\346\240\274\345\274\217\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZEEI_WM_SETUP: public Ui_ZEEI_WM_SETUP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEEI_WM_SETUP_H
