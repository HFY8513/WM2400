#ifndef ZEEI_WM_SYSCTRL_H
#define ZEEI_WM_SYSCTRL_H

#include <QWidget>
#include "iconhelper.h"
#include <QDebug>
#include "oss/utils/dsm/dsmparam.h"
#include "oss/utils/dsm/dsmuci.h"
#include "oss/common/loadcsv.h"
#include "global.h"
#include "dbpage.h"
namespace Ui {
class ZEEI_WM_SYSCTRL;
}

class ZEEI_WM_SYSCTRL : public QWidget
{
    Q_OBJECT
    
public:
    explicit ZEEI_WM_SYSCTRL(QWidget *parent = 0);
    ~ZEEI_WM_SYSCTRL();
    
    void initSysCfg();
private:
    Ui::ZEEI_WM_SYSCTRL *ui;
    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;
    appmain_param m_mainparam;
    appdas_param  m_dasparam;
    appwms_param  m_wmsparam;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合

private slots:
     void initLeftConfig();
     void leftConfigClick();
     void on_pbtn_query_clicked();
};

#endif // ZEEI_WM_SYSCTRL_H
