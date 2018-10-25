#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork>
#include <global.h>
class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    int port;
    QString host;

    bool isOk;
    QTcpSocket *tcpSocket;
    QString msgcp;
public:
    void cmdctrl(int cmdid);
    void sysctrl(rtreqinfo reqinfo);
private slots:
    void connected();
    void disconnected();
    void readData();
    void sendData(const QString &data);

signals:

public slots:
};

#endif // TCPCLIENT_H
