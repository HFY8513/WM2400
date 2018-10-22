/********************************************************************************
** Form generated from reading UI file 'dbpage.ui'
**
** Created: Mon Oct 22 11:31:11 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBPAGE_H
#define UI_DBPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DbPage
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QFrame *frameBottom;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtn_first;
    QPushButton *pbtn_pre;
    QPushButton *pbtn_next;
    QPushButton *pbtn_last;
    QLabel *lab_result;
    QLabel *lab_pageCount;
    QLabel *lab_resultCount;
    QLabel *lab_pageCurrent;
    QLabel *labResultCurrent;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *DbPage)
    {
        if (DbPage->objectName().isEmpty())
            DbPage->setObjectName(QString::fromUtf8("DbPage"));
        DbPage->resize(872, 622);
        gridLayout = new QGridLayout(DbPage);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(DbPage);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font;
        font.setPointSize(11);
        tableView->setFont(font);
        tableView->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        frameBottom = new QFrame(DbPage);
        frameBottom->setObjectName(QString::fromUtf8("frameBottom"));
        frameBottom->setMouseTracking(false);
        frameBottom->setAutoFillBackground(false);
        frameBottom->setStyleSheet(QString::fromUtf8("Qlabel{color: rgb(255, 255, 255);}\n"
"QFrame{background:#292F38;}\n"
""));
        frameBottom->setFrameShape(QFrame::Box);
        frameBottom->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frameBottom);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbtn_first = new QPushButton(frameBottom);
        pbtn_first->setObjectName(QString::fromUtf8("pbtn_first"));
        pbtn_first->setMinimumSize(QSize(50, 0));
        pbtn_first->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(pbtn_first);

        pbtn_pre = new QPushButton(frameBottom);
        pbtn_pre->setObjectName(QString::fromUtf8("pbtn_pre"));
        pbtn_pre->setMinimumSize(QSize(50, 0));
        pbtn_pre->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(pbtn_pre);

        pbtn_next = new QPushButton(frameBottom);
        pbtn_next->setObjectName(QString::fromUtf8("pbtn_next"));
        pbtn_next->setMinimumSize(QSize(50, 0));
        pbtn_next->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(pbtn_next);

        pbtn_last = new QPushButton(frameBottom);
        pbtn_last->setObjectName(QString::fromUtf8("pbtn_last"));
        pbtn_last->setMinimumSize(QSize(50, 0));
        pbtn_last->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(pbtn_last);

        lab_result = new QLabel(frameBottom);
        lab_result->setObjectName(QString::fromUtf8("lab_result"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab_result->sizePolicy().hasHeightForWidth());
        lab_result->setSizePolicy(sizePolicy);
        lab_result->setMinimumSize(QSize(0, 25));
        lab_result->setFocusPolicy(Qt::StrongFocus);
        lab_result->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lab_result->setFrameShape(QFrame::Box);
        lab_result->setFrameShadow(QFrame::Sunken);
        lab_result->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab_result);

        lab_pageCount = new QLabel(frameBottom);
        lab_pageCount->setObjectName(QString::fromUtf8("lab_pageCount"));
        sizePolicy.setHeightForWidth(lab_pageCount->sizePolicy().hasHeightForWidth());
        lab_pageCount->setSizePolicy(sizePolicy);
        lab_pageCount->setMinimumSize(QSize(0, 25));
        lab_pageCount->setFocusPolicy(Qt::WheelFocus);
        lab_pageCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lab_pageCount->setFrameShape(QFrame::Box);
        lab_pageCount->setFrameShadow(QFrame::Sunken);
        lab_pageCount->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab_pageCount);

        lab_resultCount = new QLabel(frameBottom);
        lab_resultCount->setObjectName(QString::fromUtf8("lab_resultCount"));
        sizePolicy.setHeightForWidth(lab_resultCount->sizePolicy().hasHeightForWidth());
        lab_resultCount->setSizePolicy(sizePolicy);
        lab_resultCount->setMinimumSize(QSize(0, 25));
        lab_resultCount->setFocusPolicy(Qt::StrongFocus);
        lab_resultCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lab_resultCount->setFrameShape(QFrame::Box);
        lab_resultCount->setFrameShadow(QFrame::Sunken);
        lab_resultCount->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab_resultCount);

        lab_pageCurrent = new QLabel(frameBottom);
        lab_pageCurrent->setObjectName(QString::fromUtf8("lab_pageCurrent"));
        sizePolicy.setHeightForWidth(lab_pageCurrent->sizePolicy().hasHeightForWidth());
        lab_pageCurrent->setSizePolicy(sizePolicy);
        lab_pageCurrent->setMinimumSize(QSize(0, 25));
        lab_pageCurrent->setFocusPolicy(Qt::StrongFocus);
        lab_pageCurrent->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lab_pageCurrent->setFrameShape(QFrame::Box);
        lab_pageCurrent->setFrameShadow(QFrame::Sunken);
        lab_pageCurrent->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab_pageCurrent);

        labResultCurrent = new QLabel(frameBottom);
        labResultCurrent->setObjectName(QString::fromUtf8("labResultCurrent"));
        sizePolicy.setHeightForWidth(labResultCurrent->sizePolicy().hasHeightForWidth());
        labResultCurrent->setSizePolicy(sizePolicy);
        labResultCurrent->setMinimumSize(QSize(0, 25));
        labResultCurrent->setFocusPolicy(Qt::StrongFocus);
        labResultCurrent->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labResultCurrent->setFrameShape(QFrame::Box);
        labResultCurrent->setFrameShadow(QFrame::Sunken);
        labResultCurrent->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labResultCurrent);

        label_5 = new QLabel(frameBottom);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_5);

        spinBox = new QSpinBox(frameBottom);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(9999);

        horizontalLayout->addWidget(spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(frameBottom, 1, 0, 1, 1);


        retranslateUi(DbPage);

        QMetaObject::connectSlotsByName(DbPage);
    } // setupUi

    void retranslateUi(QWidget *DbPage)
    {
        DbPage->setWindowTitle(QApplication::translate("DbPage", "Form", 0, QApplication::UnicodeUTF8));
        pbtn_first->setText(QApplication::translate("DbPage", "\347\254\254\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pbtn_pre->setText(QApplication::translate("DbPage", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pbtn_next->setText(QApplication::translate("DbPage", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pbtn_last->setText(QApplication::translate("DbPage", "\346\234\253\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        lab_result->setText(QString());
        lab_pageCount->setText(QString());
        lab_resultCount->setText(QString());
        lab_pageCurrent->setText(QString());
        labResultCurrent->setText(QString());
        label_5->setText(QApplication::translate("DbPage", "\345\215\225\351\241\265\346\230\276\347\244\272\346\235\241\346\225\260:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DbPage: public Ui_DbPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBPAGE_H
