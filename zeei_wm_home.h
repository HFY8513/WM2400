#ifndef ZEEI_WM_HOME_H
#define ZEEI_WM_HOME_H

#include <QMainWindow>
class QToolButton;
namespace Ui {
class ZEEI_WM_HOME;
}

class ZEEI_WM_HOME : public QWidget
{
    Q_OBJECT
    
public:
    explicit ZEEI_WM_HOME(QWidget *parent = 0);
    ~ZEEI_WM_HOME();
    
private:
    Ui::ZEEI_WM_HOME *ui;

    QList<int> pixCharMain;
    QList<QToolButton *> btnsMain;

    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;

private slots:
    void timerUpdate();//时间跟新
    void initForm();
    void buttonClick();
    void initLeftMain();
    void leftMainClick();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

};

#endif // ZEEI_WM_HOME_H
