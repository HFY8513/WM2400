/********************************************************************************
** Form generated from reading UI file 'wm_setup_das.ui'
**
** Created: Tue Oct 23 10:26:31 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WM_SETUP_DAS_H
#define UI_WM_SETUP_DAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WM_SETUP_DAS
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedDas;
    QWidget *page_1;
    QGridLayout *gridLayout_2;
    QTableView *tabv_com;
    QLabel *label_2;
    QLabel *label_3;
    QTableView *tabv_tcp;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QTableView *tabv_dev;
    QWidget *page_3;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QTableView *tabv_fid;

    void setupUi(QWidget *WM_SETUP_DAS)
    {
        if (WM_SETUP_DAS->objectName().isEmpty())
            WM_SETUP_DAS->setObjectName(QString::fromUtf8("WM_SETUP_DAS"));
        WM_SETUP_DAS->resize(939, 627);
        gridLayout = new QGridLayout(WM_SETUP_DAS);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidget = new QTreeWidget(WM_SETUP_DAS);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        treeWidget->setFont(font);
        treeWidget->setItemsExpandable(false);
        treeWidget->setExpandsOnDoubleClick(true);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        stackedDas = new QStackedWidget(WM_SETUP_DAS);
        stackedDas->setObjectName(QString::fromUtf8("stackedDas"));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        gridLayout_2 = new QGridLayout(page_1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabv_com = new QTableView(page_1);
        tabv_com->setObjectName(QString::fromUtf8("tabv_com"));
        QFont font1;
        font1.setPointSize(13);
        tabv_com->setFont(font1);

        gridLayout_2->addWidget(tabv_com, 1, 0, 1, 1);

        label_2 = new QLabel(page_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(page_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        tabv_tcp = new QTableView(page_1);
        tabv_tcp->setObjectName(QString::fromUtf8("tabv_tcp"));
        tabv_tcp->setFont(font1);

        gridLayout_2->addWidget(tabv_tcp, 3, 0, 1, 1);

        stackedDas->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        tabv_dev = new QTableView(page_2);
        tabv_dev->setObjectName(QString::fromUtf8("tabv_dev"));
        tabv_dev->setFont(font1);

        gridLayout_4->addWidget(tabv_dev, 1, 0, 1, 1);

        stackedDas->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_5 = new QGridLayout(page_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        tabv_fid = new QTableView(page_3);
        tabv_fid->setObjectName(QString::fromUtf8("tabv_fid"));
        tabv_fid->setFont(font1);

        gridLayout_5->addWidget(tabv_fid, 1, 0, 1, 1);

        stackedDas->addWidget(page_3);

        gridLayout->addWidget(stackedDas, 0, 1, 1, 1);


        retranslateUi(WM_SETUP_DAS);

        QMetaObject::connectSlotsByName(WM_SETUP_DAS);
    } // setupUi

    void retranslateUi(QWidget *WM_SETUP_DAS)
    {
        WM_SETUP_DAS->setWindowTitle(QApplication::translate("WM_SETUP_DAS", "Form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("WM_SETUP_DAS", "\351\207\207\351\233\206\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("WM_SETUP_DAS", "\346\265\213\347\202\2711", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("WM_SETUP_DAS", "COM1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("WM_SETUP_DAS", "\350\256\276\345\244\2071", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("WM_SETUP_DAS", "\345\233\240\345\255\2201", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("WM_SETUP_DAS", "TCP1", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("WM_SETUP_DAS", "\344\270\262\345\217\243\350\256\276\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WM_SETUP_DAS", "\347\275\221\345\217\243\350\256\276\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WM_SETUP_DAS", "\350\256\276\345\244\207\351\205\215\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("WM_SETUP_DAS", "\345\233\240\345\255\220\351\205\215\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WM_SETUP_DAS: public Ui_WM_SETUP_DAS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WM_SETUP_DAS_H
