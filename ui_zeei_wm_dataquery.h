/********************************************************************************
** Form generated from reading UI file 'zeei_wm_dataquery.ui'
**
** Created: Thu Oct 18 14:42:04 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEEI_WM_DATAQUERY_H
#define UI_ZEEI_WM_DATAQUERY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>
#include <dbpage.h>

QT_BEGIN_NAMESPACE

class Ui_ZEEI_WM_DataQuery
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetLeft;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QDateTimeEdit *dteBegin;
    QLabel *label_2;
    QDateTimeEdit *dteEnd;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_10;
    QCheckBox *checkBox;
    QPushButton *btnSelect;
    QComboBox *cmbNId;
    QComboBox *cmbShow;
    QComboBox *cmbMode;
    QComboBox *cmbFid;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    DbPage *dbPage;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QCustomPlot *customPlot;

    void setupUi(QWidget *ZEEI_WM_DataQuery)
    {
        if (ZEEI_WM_DataQuery->objectName().isEmpty())
            ZEEI_WM_DataQuery->setObjectName(QString::fromUtf8("ZEEI_WM_DataQuery"));
        ZEEI_WM_DataQuery->resize(1440, 800);
        gridLayout = new QGridLayout(ZEEI_WM_DataQuery);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 2, 0);
        widgetLeft = new QWidget(ZEEI_WM_DataQuery);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(190, 0));
        widgetLeft->setMaximumSize(QSize(190, 16777215));
        widgetLeft->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widgetLeft);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widgetLeft);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        dteBegin = new QDateTimeEdit(widgetLeft);
        dteBegin->setObjectName(QString::fromUtf8("dteBegin"));
        dteBegin->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(10);
        dteBegin->setFont(font1);
        dteBegin->setStyleSheet(QString::fromUtf8("QTimeEdit::up-button{\n"
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
        dteBegin->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        gridLayout_2->addWidget(dteBegin, 0, 1, 1, 2);

        label_2 = new QLabel(widgetLeft);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        dteEnd = new QDateTimeEdit(widgetLeft);
        dteEnd->setObjectName(QString::fromUtf8("dteEnd"));
        dteEnd->setMinimumSize(QSize(0, 30));
        dteEnd->setFont(font1);
        dteEnd->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        gridLayout_2->addWidget(dteEnd, 1, 1, 1, 2);

        label_11 = new QLabel(widgetLeft);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        label_3 = new QLabel(widgetLeft);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(widgetLeft);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        label_10 = new QLabel(widgetLeft);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        checkBox = new QCheckBox(widgetLeft);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font2;
        font2.setPointSize(13);
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8(""));
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        checkBox->setTristate(false);

        gridLayout_2->addWidget(checkBox, 6, 0, 1, 3);

        btnSelect = new QPushButton(widgetLeft);
        btnSelect->setObjectName(QString::fromUtf8("btnSelect"));
        btnSelect->setMinimumSize(QSize(80, 50));
        btnSelect->setFont(font2);

        gridLayout_2->addWidget(btnSelect, 7, 0, 1, 3);

        cmbNId = new QComboBox(widgetLeft);
        cmbNId->setObjectName(QString::fromUtf8("cmbNId"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbNId->sizePolicy().hasHeightForWidth());
        cmbNId->setSizePolicy(sizePolicy1);
        cmbNId->setFont(font2);
        cmbNId->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(cmbNId, 5, 1, 1, 2);

        cmbShow = new QComboBox(widgetLeft);
        cmbShow->setObjectName(QString::fromUtf8("cmbShow"));
        cmbShow->setFont(font2);

        gridLayout_2->addWidget(cmbShow, 2, 1, 1, 2);

        cmbMode = new QComboBox(widgetLeft);
        cmbMode->setObjectName(QString::fromUtf8("cmbMode"));
        cmbMode->setFont(font2);

        gridLayout_2->addWidget(cmbMode, 3, 1, 1, 2);

        cmbFid = new QComboBox(widgetLeft);
        cmbFid->setObjectName(QString::fromUtf8("cmbFid"));
        sizePolicy1.setHeightForWidth(cmbFid->sizePolicy().hasHeightForWidth());
        cmbFid->setSizePolicy(sizePolicy1);
        cmbFid->setFont(font2);
        cmbFid->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(cmbFid, 4, 1, 1, 2);

        verticalSpacer = new QSpacerItem(40, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 3);


        gridLayout->addWidget(widgetLeft, 0, 0, 2, 1);

        stackedWidget = new QStackedWidget(ZEEI_WM_DataQuery);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        dbPage = new DbPage();
        dbPage->setObjectName(QString::fromUtf8("dbPage"));
        stackedWidget->addWidget(dbPage);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(page_2);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        gridLayout_4->addWidget(customPlot, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(ZEEI_WM_DataQuery);

        QMetaObject::connectSlotsByName(ZEEI_WM_DataQuery);
    } // setupUi

    void retranslateUi(QWidget *ZEEI_WM_DataQuery)
    {
        ZEEI_WM_DataQuery->setWindowTitle(QApplication::translate("ZEEI_WM_DataQuery", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ZEEI_WM_DataQuery", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        dteBegin->setDisplayFormat(QApplication::translate("ZEEI_WM_DataQuery", "yy/M/d H:mm:ss", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZEEI_WM_DataQuery", "\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        dteEnd->setDisplayFormat(QApplication::translate("ZEEI_WM_DataQuery", "yy/M/d H:mm:ss", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ZEEI_WM_DataQuery", "\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZEEI_WM_DataQuery", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ZEEI_WM_DataQuery", "\345\233\240\345\255\220", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ZEEI_WM_DataQuery", "\346\265\213\347\202\271", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ZEEI_WM_DataQuery", "\346\230\276\347\244\272\346\225\260\346\215\256\346\240\207\350\257\206", 0, QApplication::UnicodeUTF8));
        btnSelect->setText(QApplication::translate("ZEEI_WM_DataQuery", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZEEI_WM_DataQuery: public Ui_ZEEI_WM_DataQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEEI_WM_DATAQUERY_H
