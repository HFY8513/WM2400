/********************************************************************************
** Form generated from reading UI file 'zeei_wm_home.ui'
**
** Created: Mon Oct 22 11:31:11 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEEI_WM_HOME_H
#define UI_ZEEI_WM_HOME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <zeei_wm_devctrl.h>
#include "zeei_wm_dataquery.h"
#include "zeei_wm_setup.h"
#include "zeei_wm_sysctrl.h"

QT_BEGIN_NAMESPACE

class Ui_ZEEI_WM_HOME
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnData;
    QToolButton *btnConfig;
    QToolButton *btnSysCtrl;
    QToolButton *btnDevMan;
    QToolButton *btnSysMan;
    QToolButton *btnRunFix;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QStackedWidget *stackedWidget;
    ZEEI_WM_DataQuery *page1;
    ZEEI_WM_SETUP *page2;
    ZEEI_WM_SYSCTRL *page3;
    ZEEI_WM_DEVCTRL *page4;
    QWidget *page5;
    QVBoxLayout *verticalLayout_2;
    QLabel *lab5;
    QWidget *page6;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetLeftMain;
    QVBoxLayout *verticalLayout_3;
    QToolButton *tbtnMain1;
    QToolButton *tbtnMain2;
    QToolButton *tbtnMain3;
    QSpacerItem *verticalSpacer_3;
    QLabel *lab6;
    QWidget *widgetBottom;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelTime;

    void setupUi(QWidget *ZEEI_WM_HOME)
    {
        if (ZEEI_WM_HOME->objectName().isEmpty())
            ZEEI_WM_HOME->setObjectName(QString::fromUtf8("ZEEI_WM_HOME"));
        ZEEI_WM_HOME->resize(1440, 900);
        gridLayout = new QGridLayout(ZEEI_WM_HOME);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetTitle = new QWidget(ZEEI_WM_HOME);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setMinimumSize(QSize(0, 0));
        widgetTitle->setBaseSize(QSize(0, 0));
        widgetTitle->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setEnabled(true);
        labIco->setMinimumSize(QSize(30, 30));
        labIco->setBaseSize(QSize(0, 0));
        labIco->setStyleSheet(QString::fromUtf8("image: url(:/res/image/bg-brand.png);"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setStyleSheet(QString::fromUtf8(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        widgetTop->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnData = new QToolButton(widgetTop);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/image/home/micon02.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnData);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/image/home/micon05.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon1);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);

        btnSysCtrl = new QToolButton(widgetTop);
        btnSysCtrl->setObjectName(QString::fromUtf8("btnSysCtrl"));
        sizePolicy1.setHeightForWidth(btnSysCtrl->sizePolicy().hasHeightForWidth());
        btnSysCtrl->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/image/home/micon06.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSysCtrl->setIcon(icon2);
        btnSysCtrl->setChecked(false);
        btnSysCtrl->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnSysCtrl);

        btnDevMan = new QToolButton(widgetTop);
        btnDevMan->setObjectName(QString::fromUtf8("btnDevMan"));
        sizePolicy1.setHeightForWidth(btnDevMan->sizePolicy().hasHeightForWidth());
        btnDevMan->setSizePolicy(sizePolicy1);
        btnDevMan->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/image/home/micon09.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDevMan->setIcon(icon3);
        btnDevMan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnDevMan);

        btnSysMan = new QToolButton(widgetTop);
        btnSysMan->setObjectName(QString::fromUtf8("btnSysMan"));
        sizePolicy1.setHeightForWidth(btnSysMan->sizePolicy().hasHeightForWidth());
        btnSysMan->setSizePolicy(sizePolicy1);
        btnSysMan->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/image/home/micon07.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSysMan->setIcon(icon4);
        btnSysMan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnSysMan);

        btnRunFix = new QToolButton(widgetTop);
        btnRunFix->setObjectName(QString::fromUtf8("btnRunFix"));
        sizePolicy1.setHeightForWidth(btnRunFix->sizePolicy().hasHeightForWidth());
        btnRunFix->setSizePolicy(sizePolicy1);
        btnRunFix->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/image/home/micon12.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRunFix->setIcon(icon5);
        btnRunFix->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnRunFix);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);


        horizontalLayout_2->addWidget(widgetMenu);


        gridLayout->addWidget(widgetTitle, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(ZEEI_WM_HOME);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new ZEEI_WM_DataQuery();
        page1->setObjectName(QString::fromUtf8("page1"));
        stackedWidget->addWidget(page1);
        page2 = new ZEEI_WM_SETUP();
        page2->setObjectName(QString::fromUtf8("page2"));
        stackedWidget->addWidget(page2);
        page3 = new ZEEI_WM_SYSCTRL();
        page3->setObjectName(QString::fromUtf8("page3"));
        stackedWidget->addWidget(page3);
        page4 = new ZEEI_WM_DEVCTRL();
        page4->setObjectName(QString::fromUtf8("page4"));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QString::fromUtf8("page5"));
        verticalLayout_2 = new QVBoxLayout(page5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lab5 = new QLabel(page5);
        lab5->setObjectName(QString::fromUtf8("lab5"));
        QFont font;
        font.setPointSize(50);
        lab5->setFont(font);
        lab5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lab5);

        stackedWidget->addWidget(page5);
        page6 = new QWidget();
        page6->setObjectName(QString::fromUtf8("page6"));
        horizontalLayout = new QHBoxLayout(page6);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widgetLeftMain = new QWidget(page6);
        widgetLeftMain->setObjectName(QString::fromUtf8("widgetLeftMain"));
        widgetLeftMain->setMaximumSize(QSize(100, 16777215));
        verticalLayout_3 = new QVBoxLayout(widgetLeftMain);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tbtnMain1 = new QToolButton(widgetLeftMain);
        tbtnMain1->setObjectName(QString::fromUtf8("tbtnMain1"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbtnMain1->sizePolicy().hasHeightForWidth());
        tbtnMain1->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnMain1);

        tbtnMain2 = new QToolButton(widgetLeftMain);
        tbtnMain2->setObjectName(QString::fromUtf8("tbtnMain2"));
        sizePolicy3.setHeightForWidth(tbtnMain2->sizePolicy().hasHeightForWidth());
        tbtnMain2->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnMain2);

        tbtnMain3 = new QToolButton(widgetLeftMain);
        tbtnMain3->setObjectName(QString::fromUtf8("tbtnMain3"));
        tbtnMain3->setEnabled(true);
        sizePolicy3.setHeightForWidth(tbtnMain3->sizePolicy().hasHeightForWidth());
        tbtnMain3->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnMain3);

        verticalSpacer_3 = new QSpacerItem(20, 471, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(widgetLeftMain);

        lab6 = new QLabel(page6);
        lab6->setObjectName(QString::fromUtf8("lab6"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lab6->sizePolicy().hasHeightForWidth());
        lab6->setSizePolicy(sizePolicy4);
        lab6->setFont(font);
        lab6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab6);

        stackedWidget->addWidget(page6);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        widgetBottom = new QWidget(ZEEI_WM_HOME);
        widgetBottom->setObjectName(QString::fromUtf8("widgetBottom"));
        widgetBottom->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"border-radius:0px;\n"
"padding:5px;\n"
"color:#DCDCDC;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #3366FF,stop:1 #3366FF);"));
        horizontalLayout_5 = new QHBoxLayout(widgetBottom);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widgetBottom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        label_3 = new QLabel(widgetBottom);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        label_4 = new QLabel(widgetBottom);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(widgetBottom);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(400, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        labelTime = new QLabel(widgetBottom);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setFont(font1);
        labelTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(labelTime);


        gridLayout->addWidget(widgetBottom, 2, 0, 1, 1);


        retranslateUi(ZEEI_WM_HOME);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ZEEI_WM_HOME);
    } // setupUi

    void retranslateUi(QWidget *ZEEI_WM_HOME)
    {
        ZEEI_WM_HOME->setWindowTitle(QApplication::translate("ZEEI_WM_HOME", "ZEEI_WM_HOME", 0, QApplication::UnicodeUTF8));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnData->setText(QApplication::translate("ZEEI_WM_HOME", "\346\225\260\346\215\256\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btnConfig->setText(QApplication::translate("ZEEI_WM_HOME", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btnSysCtrl->setText(QApplication::translate("ZEEI_WM_HOME", "\347\263\273\347\273\237\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        btnDevMan->setText(QApplication::translate("ZEEI_WM_HOME", "\350\256\276\345\244\207\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btnSysMan->setText(QApplication::translate("ZEEI_WM_HOME", "\347\263\273\347\273\237\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btnRunFix->setText(QApplication::translate("ZEEI_WM_HOME", "\350\277\220\350\220\245\347\273\264\346\212\244", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("ZEEI_WM_HOME", "\346\234\200\345\260\217\345\214\226", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("ZEEI_WM_HOME", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        btnMenu_Max->setText(QString());
        lab5->setText(QApplication::translate("ZEEI_WM_HOME", "\347\263\273\347\273\237\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        tbtnMain1->setText(QApplication::translate("ZEEI_WM_HOME", "\345\271\263\345\217\260\350\241\245\344\274\240", 0, QApplication::UnicodeUTF8));
        tbtnMain2->setText(QApplication::translate("ZEEI_WM_HOME", "\346\225\260\346\215\256\346\240\270\345\257\271", 0, QApplication::UnicodeUTF8));
        tbtnMain3->setText(QApplication::translate("ZEEI_WM_HOME", "\350\257\212\346\226\255\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        lab6->setText(QApplication::translate("ZEEI_WM_HOME", "\350\277\220\350\220\245\347\273\264\346\212\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZEEI_WM_HOME", "\347\263\273\347\273\237\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZEEI_WM_HOME", "\346\255\243\345\270\270\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ZEEI_WM_HOME", "\345\275\223\345\211\215\350\255\246\345\221\212:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ZEEI_WM_HOME", "0\344\270\252", 0, QApplication::UnicodeUTF8));
        labelTime->setText(QApplication::translate("ZEEI_WM_HOME", "2018-9-16 16\357\274\23251\357\274\23236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZEEI_WM_HOME: public Ui_ZEEI_WM_HOME {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEEI_WM_HOME_H
