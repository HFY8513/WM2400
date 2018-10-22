/********************************************************************************
** Form generated from reading UI file 'zeei_wm_devctrl.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEEI_WM_DEVCTRL_H
#define UI_ZEEI_WM_DEVCTRL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZEEI_WM_DEVCTRL
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
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *page2;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *page3;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QWidget *tab_10;
    QWidget *tab_11;

    void setupUi(QWidget *ZEEI_WM_DEVCTRL)
    {
        if (ZEEI_WM_DEVCTRL->objectName().isEmpty())
            ZEEI_WM_DEVCTRL->setObjectName(QString::fromUtf8("ZEEI_WM_DEVCTRL"));
        ZEEI_WM_DEVCTRL->resize(1440, 800);
        gridLayout_2 = new QGridLayout(ZEEI_WM_DEVCTRL);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widgetLeftConfig = new QWidget(ZEEI_WM_DEVCTRL);
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

        verticalSpacer_4 = new QSpacerItem(20, 417, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout_2->addWidget(widgetLeftConfig, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(ZEEI_WM_DEVCTRL);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout = new QGridLayout(page1);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(page1);
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

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout_3 = new QGridLayout(page2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget_2 = new QTabWidget(page2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setFont(font);
        tabWidget_2->setStyleSheet(QString::fromUtf8(""));
        tabWidget_2->setIconSize(QSize(32, 32));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());

        gridLayout_3->addWidget(tabWidget_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        gridLayout_4 = new QGridLayout(page3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget_3 = new QTabWidget(page3);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setFont(font);
        tabWidget_3->setStyleSheet(QString::fromUtf8(""));
        tabWidget_3->setIconSize(QSize(32, 32));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget_3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        tabWidget_3->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        tabWidget_3->addTab(tab_11, QString());

        gridLayout_4->addWidget(tabWidget_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page3);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(ZEEI_WM_DEVCTRL);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ZEEI_WM_DEVCTRL);
    } // setupUi

    void retranslateUi(QWidget *ZEEI_WM_DEVCTRL)
    {
        ZEEI_WM_DEVCTRL->setWindowTitle(QApplication::translate("ZEEI_WM_DEVCTRL", "Form", 0, QApplication::UnicodeUTF8));
        tbtnConfig1->setText(QApplication::translate("ZEEI_WM_DEVCTRL", "\345\210\206\346\236\220\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        tbtnConfig2->setText(QApplication::translate("ZEEI_WM_DEVCTRL", "\347\225\231\346\240\267\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        tbtnConfig3->setText(QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\345\215\225\345\205\203", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ZEEI_WM_DEVCTRL", "\344\273\252\345\231\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ZEEI_WM_DEVCTRL", "\344\273\252\345\231\250\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ZEEI_WM_DEVCTRL", "\344\273\252\345\231\250\345\221\212\350\255\246", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("ZEEI_WM_DEVCTRL", "\347\225\231\346\240\267\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("ZEEI_WM_DEVCTRL", "\347\225\231\346\240\267\350\256\260\345\275\225  ", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\346\265\201\347\250\213\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\350\256\276\345\244\207\347\273\264\346\212\244", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\344\273\252\350\277\220\350\241\214\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QApplication::translate("ZEEI_WM_DEVCTRL", "\350\264\250\346\216\247\344\273\252\345\221\212\350\255\246\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZEEI_WM_DEVCTRL: public Ui_ZEEI_WM_DEVCTRL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEEI_WM_DEVCTRL_H
