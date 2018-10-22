#ifndef ZEEI_WM_DATAQUERY_H
#define ZEEI_WM_DATAQUERY_H

#include <QWidget>
#include "oss/common/utime.h"
//#include "oss/utils/dsm/dsmpub.h"
#include "dbpage.h"
#include "global.h"
#include <QDebug>
class DbHpler;
namespace Ui {
class ZEEI_WM_DataQuery;
}

class ZEEI_WM_DataQuery : public QWidget
{
    Q_OBJECT
    
public:
    explicit ZEEI_WM_DataQuery(QWidget *parent = 0);
    ~ZEEI_WM_DataQuery();

    void initPage();
    void initForm();
    void initFidCmb();
    
private:
    Ui::ZEEI_WM_DataQuery *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称
    QString columnValue;
    const QString starttime;
    const QString endtime;

    QListWidget *pTypeListWidget;  //自定义comboBox的List
    QLineEdit *pLineEdit;          //自定义comboBox的LineEDit
    bool bSelected;                //自定义comboBox的判断是否选择
    bool bShowPopup;               //自定义conboBox是否下拉
    QString strSelectedText;       //自定义comboBox的选择内容
    appdas_param m_dasparam;
    factor_map m_fidmaps[MAX_DAQ_ITEM];

    int select_fcount;


private slots:
    void showChanged(int index);
    void textChanged(const QString &text);                  //因子选择内容改变
    void stateChanged(int state);                           //因子选择Check状态改变
private slots:
    void on_btnSelect_clicked();
    void on_cmbMode_currentIndexChanged(int index);
};

#endif // ZEEI_WM_DATAQUERY_H
