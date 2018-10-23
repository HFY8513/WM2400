/********************************************************************************
** Form generated from reading UI file 'zeei_wm_sysctrl.ui'
**
** Created: Tue Oct 23 16:19:47 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEEI_WM_SYSCTRL_H
#define UI_ZEEI_WM_SYSCTRL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <dbpage.h>

QT_BEGIN_NAMESPACE

class Ui_ZEEI_WM_SYSCTRL
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetLeftConfig;
    QVBoxLayout *verticalLayout_3;
    QToolButton *tbtnConfig1;
    QToolButton *tbtnConfig2;
    QToolButton *tbtnConfig3;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *led_measuerint;
    QLabel *label_2;
    QLineEdit *led_measuertime;
    QLabel *label_3;
    QComboBox *cmb_epcmodule;
    QLabel *label_4;
    QComboBox *cmb_measuretype;
    QLabel *label_5;
    QLineEdit *led_dailystarttime;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QComboBox *cmb_electrodemode;
    QLabel *label_9;
    QLineEdit *led_electrodetime;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QComboBox *cmb_trigmode;
    QLabel *label_7;
    QLineEdit *led_trigflowlimt;
    QPushButton *pbtn_save;
    QSpacerItem *verticalSpacer;
    QWidget *page2;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QWidget *page3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QDateTimeEdit *dte_begin;
    QLabel *label_10;
    QDateTimeEdit *dte_end;
    QPushButton *pbtn_query;
    QPushButton *pbtn_out;
    QSpacerItem *horizontalSpacer;
    DbPage *dbPage;

    void setupUi(QWidget *ZEEI_WM_SYSCTRL)
    {
        if (ZEEI_WM_SYSCTRL->objectName().isEmpty())
            ZEEI_WM_SYSCTRL->setObjectName(QString::fromUtf8("ZEEI_WM_SYSCTRL"));
        ZEEI_WM_SYSCTRL->resize(1440, 800);
        gridLayout_2 = new QGridLayout(ZEEI_WM_SYSCTRL);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetLeftConfig = new QWidget(ZEEI_WM_SYSCTRL);
        widgetLeftConfig->setObjectName(QString::fromUtf8("widgetLeftConfig"));
        widgetLeftConfig->setMaximumSize(QSize(190, 16777215));
        verticalLayout_3 = new QVBoxLayout(widgetLeftConfig);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
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

        verticalSpacer_4 = new QSpacerItem(20, 417, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout_2->addWidget(widgetLeftConfig, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(ZEEI_WM_SYSCTRL);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout_6 = new QGridLayout(page1);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(page1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        led_measuerint = new QLineEdit(groupBox);
        led_measuerint->setObjectName(QString::fromUtf8("led_measuerint"));
        led_measuerint->setMinimumSize(QSize(0, 30));
        led_measuerint->setFont(font);

        gridLayout->addWidget(led_measuerint, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        led_measuertime = new QLineEdit(groupBox);
        led_measuertime->setObjectName(QString::fromUtf8("led_measuertime"));
        led_measuertime->setMinimumSize(QSize(0, 30));
        led_measuertime->setFont(font);

        gridLayout->addWidget(led_measuertime, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cmb_epcmodule = new QComboBox(groupBox);
        cmb_epcmodule->setObjectName(QString::fromUtf8("cmb_epcmodule"));
        cmb_epcmodule->setFont(font);

        gridLayout->addWidget(cmb_epcmodule, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cmb_measuretype = new QComboBox(groupBox);
        cmb_measuretype->setObjectName(QString::fromUtf8("cmb_measuretype"));
        cmb_measuretype->setFont(font);

        gridLayout->addWidget(cmb_measuretype, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        led_dailystarttime = new QLineEdit(groupBox);
        led_dailystarttime->setObjectName(QString::fromUtf8("led_dailystarttime"));
        led_dailystarttime->setMinimumSize(QSize(0, 30));
        led_dailystarttime->setFont(font);

        gridLayout->addWidget(led_dailystarttime, 4, 1, 1, 1);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(page1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 30));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        cmb_electrodemode = new QComboBox(groupBox_3);
        cmb_electrodemode->setObjectName(QString::fromUtf8("cmb_electrodemode"));
        cmb_electrodemode->setFont(font);

        gridLayout_5->addWidget(cmb_electrodemode, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 30));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        led_electrodetime = new QLineEdit(groupBox_3);
        led_electrodetime->setObjectName(QString::fromUtf8("led_electrodetime"));
        led_electrodetime->setMinimumSize(QSize(0, 30));
        led_electrodetime->setFont(font);

        gridLayout_5->addWidget(led_electrodetime, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(page1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        cmb_trigmode = new QComboBox(groupBox_2);
        cmb_trigmode->setObjectName(QString::fromUtf8("cmb_trigmode"));
        cmb_trigmode->setFont(font);

        gridLayout_3->addWidget(cmb_trigmode, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        led_trigflowlimt = new QLineEdit(groupBox_2);
        led_trigflowlimt->setObjectName(QString::fromUtf8("led_trigflowlimt"));
        led_trigflowlimt->setMinimumSize(QSize(0, 30));
        led_trigflowlimt->setFont(font);

        gridLayout_3->addWidget(led_trigflowlimt, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 2, 1, 1);

        pbtn_save = new QPushButton(page1);
        pbtn_save->setObjectName(QString::fromUtf8("pbtn_save"));
        pbtn_save->setFont(font);

        gridLayout_6->addWidget(pbtn_save, 1, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 536, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 1, 1, 1);

        stackedWidget->addWidget(page1);
        pbtn_save->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        tableWidget = new QTableWidget(page2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem27);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 640, 603, 142));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        tableWidget_2 = new QTableWidget(page2);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem32);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_2->setItem(0, 4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 2, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 3, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_2->setItem(1, 4, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 2, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 3, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 4, __qtablewidgetitem50);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(630, 640, 603, 142));
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(46);
        tableWidget_2->verticalHeader()->setHighlightSections(true);
        tableWidget_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_2->verticalHeader()->setStretchLastSection(false);
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        gridLayout_4 = new QGridLayout(page3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(page3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font1;
        font1.setPointSize(9);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_11);

        dte_begin = new QDateTimeEdit(page3);
        dte_begin->setObjectName(QString::fromUtf8("dte_begin"));
        dte_begin->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setPointSize(10);
        dte_begin->setFont(font2);
        dte_begin->setStyleSheet(QString::fromUtf8("QTimeEdit::up-button{\n"
"image:url(:/qss/psblack/add_top.png);\n"
"width:10px;\n"
"height:10px;\n"
"padding:2px 5px 0px 0px;\n"
"}\n"
"QTimeEdit::down-button{\n"
"image:url(:/qss/psblack/add_bottom.png);\n"
"width:10px;\n"
"height:10px;\n"
"padding:0px 5px 2px 0px;\n"
"}\n"
"\n"
"QTimeEdit::up-button:pressed{\n"
"top:-2px;\n"
"}\n"
"  \n"
"QTimeEdit::down-button:pressed{\n"
"bottom:-2px;\n"
"}"));
        dte_begin->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dte_begin);

        label_10 = new QLabel(page3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_10);

        dte_end = new QDateTimeEdit(page3);
        dte_end->setObjectName(QString::fromUtf8("dte_end"));
        dte_end->setMinimumSize(QSize(0, 30));
        dte_end->setFont(font2);
        dte_end->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dte_end);

        pbtn_query = new QPushButton(page3);
        pbtn_query->setObjectName(QString::fromUtf8("pbtn_query"));
        pbtn_query->setMinimumSize(QSize(80, 50));
        pbtn_query->setFont(font);

        horizontalLayout->addWidget(pbtn_query);

        pbtn_out = new QPushButton(page3);
        pbtn_out->setObjectName(QString::fromUtf8("pbtn_out"));
        pbtn_out->setMinimumSize(QSize(80, 50));
        pbtn_out->setFont(font);

        horizontalLayout->addWidget(pbtn_out);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        dbPage = new DbPage(page3);
        dbPage->setObjectName(QString::fromUtf8("dbPage"));

        gridLayout_4->addWidget(dbPage, 1, 0, 1, 1);

        stackedWidget->addWidget(page3);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(ZEEI_WM_SYSCTRL);

        QMetaObject::connectSlotsByName(ZEEI_WM_SYSCTRL);
    } // setupUi

    void retranslateUi(QWidget *ZEEI_WM_SYSCTRL)
    {
        ZEEI_WM_SYSCTRL->setWindowTitle(QApplication::translate("ZEEI_WM_SYSCTRL", "Form", 0, QApplication::UnicodeUTF8));
        tbtnConfig1->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\263\273\347\273\237\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        tbtnConfig2->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\265\201\347\250\213\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        tbtnConfig3->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\265\201\347\250\213\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\270\270\347\224\250\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\253\231\346\265\213\351\207\217\345\221\250\346\234\237(\345\260\217\346\227\266):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\210\206\346\236\220\346\227\266\351\225\277(\345\210\206\351\222\237):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "PLC\350\256\276\345\244\207:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\263\273\347\273\237\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\221\250\346\234\237\350\265\267\347\202\271(\346\225\264\347\202\271):", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ZEEI_WM_SYSCTRL", "\351\253\230\347\272\247\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\351\207\207\351\233\206\346\250\241\345\274\217:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\344\272\224\345\217\202\345\210\266\346\240\267\346\227\266\351\225\277(\345\210\206\351\222\237):", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\265\213\351\207\217\350\247\246\345\217\221", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\350\247\246\345\217\221\346\250\241\345\274\217:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\236\254\346\227\266\346\265\201\351\207\217\345\244\247\344\272\216(L/s):", 0, QApplication::UnicodeUTF8));
        pbtn_save->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\344\277\235\345\255\230\345\271\266\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\263\273\347\273\237\345\267\245\344\275\234/\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\211\213\345\212\250/\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\262\211\346\262\231\347\274\270\350\277\233\346\240\267\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 3);
        ___qtablewidgetitem12->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\224\265\346\236\201\346\241\266\350\277\233\346\240\267\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 4);
        ___qtablewidgetitem13->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\210\266\346\240\267\346\263\265(\351\232\224\350\206\234\346\263\265)\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\270\205\346\264\227\346\200\273\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\344\273\252\350\241\250\345\220\257\345\212\250\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 2);
        ___qtablewidgetitem16->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "1#\351\207\207\346\240\267\346\263\265\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 3);
        ___qtablewidgetitem17->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "2#\351\207\207\346\240\267\346\263\265\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 4);
        ___qtablewidgetitem18->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\262\211\346\262\231\347\274\270\346\216\222\346\260\264\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\224\265\346\236\201\346\241\266\346\216\222\346\260\264\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\251\272\345\216\213\346\234\272\346\200\273\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 2);
        ___qtablewidgetitem21->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\212\240\350\215\257\346\263\265\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 3);
        ___qtablewidgetitem22->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "1#\351\207\207\346\240\267\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 4);
        ___qtablewidgetitem23->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "2#\351\207\207\346\240\267\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\240\267\346\260\264\346\235\257\346\216\222\346\260\264\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\262\211\347\240\202\347\274\270\346\270\205\346\264\227\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\350\277\207\346\273\244\345\231\250\346\270\205\346\264\227\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 3);
        ___qtablewidgetitem27->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\240\267\346\260\264\346\235\257\346\270\205\346\264\227\351\230\200\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem28->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem29->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem30->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem31->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem32->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\345\210\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem33->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem34->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem35->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\266\246\346\264\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_2->item(0, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\350\277\233\346\240\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_2->item(0, 2);
        ___qtablewidgetitem38->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\265\213\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_2->item(0, 3);
        ___qtablewidgetitem39->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\270\205\346\264\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_2->item(0, 4);
        ___qtablewidgetitem40->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\351\242\204\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\270\205\346\260\264\346\265\270\346\266\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_2->item(1, 1);
        ___qtablewidgetitem42->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\205\250\346\265\201\347\250\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_2->item(1, 2);
        ___qtablewidgetitem43->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\251\272\351\227\262", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_2->item(1, 3);
        ___qtablewidgetitem44->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_2->item(1, 4);
        ___qtablewidgetitem45->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem46->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\221\250\346\234\237\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_2->item(2, 1);
        ___qtablewidgetitem47->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\350\201\224\347\263\273\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_2->item(2, 2);
        ___qtablewidgetitem48->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\272\224\346\200\245\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_2->item(2, 3);
        ___qtablewidgetitem49->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\350\264\250\346\216\247\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_2->item(2, 4);
        ___qtablewidgetitem50->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\351\235\242\346\235\277\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

        label_11->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        dte_begin->setDisplayFormat(QApplication::translate("ZEEI_WM_SYSCTRL", "yy/M/d H:mm:ss", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        dte_end->setDisplayFormat(QApplication::translate("ZEEI_WM_SYSCTRL", "yy/M/d H:mm:ss", 0, QApplication::UnicodeUTF8));
        pbtn_query->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        pbtn_out->setText(QApplication::translate("ZEEI_WM_SYSCTRL", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZEEI_WM_SYSCTRL: public Ui_ZEEI_WM_SYSCTRL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEEI_WM_SYSCTRL_H
