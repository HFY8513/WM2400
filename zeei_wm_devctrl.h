#ifndef ZEEI_WM_DEVCTRL_H
#define ZEEI_WM_DEVCTRL_H

#include <QWidget>
#include <iconhelper.h>
namespace Ui {
class ZEEI_WM_DEVCTRL;
}

class ZEEI_WM_DEVCTRL : public QWidget
{
    Q_OBJECT
    
public:
    explicit ZEEI_WM_DEVCTRL(QWidget *parent = 0);
    ~ZEEI_WM_DEVCTRL();
    
private:
    Ui::ZEEI_WM_DEVCTRL *ui;
    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;

private slots:
     void initLeftConfig();
     void leftConfigClick();
};

#endif // ZEEI_WM_DEVCTRL_H
