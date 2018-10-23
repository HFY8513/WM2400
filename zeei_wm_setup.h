#ifndef ZEEI_WM_SETUP_H
#define ZEEI_WM_SETUP_H

#include <QWidget>
#include "iconhelper.h"
#include "oss/utils/dsm/dsmparam.h"
#include "oss/utils/dsm/dsmuci.h"
#include "oss/common/loadcsv.h"
#include "global.h"
#include "app.h"

namespace Ui {
class ZEEI_WM_SETUP;
}

class ZEEI_WM_SETUP : public QWidget
{
    Q_OBJECT
    
public:
    explicit ZEEI_WM_SETUP(QWidget *parent = 0);
    ~ZEEI_WM_SETUP();

private:
    Ui::ZEEI_WM_SETUP *ui;

    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;
    appmain_param m_mainparam;
    appdts_param  m_dtsparam;
    dtplist_map m_fidmaps[MAX_DAQ_ITEM];

    int readJson();
    void initPage();
    void initMainPage();
    void initSitePage();
    void initDtsPage();
    void initGuiPage();

private slots:
     void initLeftConfig();
     void leftConfigClick();

     void on_btn_base_save_clicked();
};

#endif // ZEEI_WM_SETUP_H
