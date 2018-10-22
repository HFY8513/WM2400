#ifndef ZEEI_WM_INIT_H
#define ZEEI_WM_INIT_H

#include <QObject>

class ZEEI_WM_Init : public QObject
{
    Q_OBJECT
public:
    static ZEEI_WM_Init *Instance();
    explicit ZEEI_WM_Init(QObject *parent = 0);

    void start();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static ZEEI_WM_Init *self;

signals:

public slots:
};

#endif // ZEEI_WM_INIT_H
