#ifndef WM_SETUP_DAS_H
#define WM_SETUP_DAS_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "oss/utils/dsm/dsmuci.h"
#include "oss/utils/dsm/dsmparam.h"
#include "oss/utils/uio/uiophy_com.h"
#include "oss/common/loadcsv.h"
#include "global.h"
#include <QItemDelegate>
#include <QComboBox>
#include <QList>

class ItemDelegate:public QItemDelegate
{
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void setComType(COMBType _type);
 private:
     COMBType m_type; //字段名集合
};


namespace Ui {
class WM_SETUP_DAS;
}

class WM_SETUP_DAS : public QWidget
{
    Q_OBJECT
    
public:
    explicit WM_SETUP_DAS(QWidget *parent = 0);
    ~WM_SETUP_DAS();
    
private slots:
    void checkself(QTreeWidgetItem *item ,int column);

private:
    void initPage();
    void initFrom();
    void initComTable();
    void initTcpTable();
    void initDevTable();
    void initFidTable();

private:
    Ui::WM_SETUP_DAS *ui;

    appmain_param m_mainparam;
    appdas_param m_dasparam;
    dtplist_map m_fidmaps[MAX_DAQ_ITEM];

signals:



};

#endif // WM_SETUP_DAS_H
