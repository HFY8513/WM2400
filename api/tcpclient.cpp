#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    port = 6000;
    host="127.0.0.1";
    isOk = false;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    if (!isOk) {
        tcpSocket->abort();
        tcpSocket->connectToHost(host,port);
    } else {
        tcpSocket->abort();
    }


}

void TcpClient::connected()
{
    isOk = true;
    qDebug()<<"tcp已连接";
}

void TcpClient::disconnected()
{
    isOk = false;
    tcpSocket->abort();
    qDebug()<<"tcp已断开";

}

void TcpClient::readData()
{
    //    QByteArray data = tcpSocket->readAll();
    //    if (data.length() <= 0) {
    //        return;
    //    }

    //    QString buffer;
    //    if (App::HexReceiveTcpClient) {
    //        buffer = QUIHelper::byteArrayToHexStr(data);
    //    } else if (App::AsciiTcpClient) {
    //        buffer = QUIHelper::byteArrayToAsciiStr(data);
    //    } else {
    //        buffer = QString(data);
    //    }

    //    append(1, buffer);

    //    //自动回复数据,可以回复的数据是以;隔开,每行可以带多个;所以这里不需要继续判断
    //    if (App::DebugTcpClient) {
    //        int count = App::Keys.count();
    //        for (int i = 0; i < count; i++) {
    //            if (App::Keys.at(i) == buffer) {
    //                sendData(App::Values.at(i));
    //                break;
    //            }
    //        }
    //    }
}

void TcpClient::sendData(const QString &data)
{
    QByteArray buffer;
//    if (App::HexSendTcpClient) {
//        buffer = QUIHelper::hexStrToByteArray(data);
//    } else if (App::AsciiTcpClient) {
//        buffer = QUIHelper::asciiStrToByteArray(data);
//    } else {
        buffer = data.toLatin1();
//    }

    tcpSocket->write(buffer);
    qDebug()<<"发送成功";
}

void TcpClient::cmdctrl(int cmdid)
{
    qDebug()<<cmdid;
//    msgcp = "QN=20040516010101001;ST=" + reqinfo.st + ";CN=5005;PW=123456;MN=" + reqinfo.stationid
//            + ";Flag=1;CP=&&" + reqinfo.obj + "=" + reqinfo.cmdid;

//    if (reqinfo.inval && reqinfo.inval !== "")
//    {
//        msgcp += (";" + reqinfo.inval + "&&");
//    }
//    else
//    {
//        msgcp += "&&";
//    }

//    var tempbuf = new Buffer(msgcp, "utf8");
//    var msgdata = new Buffer(tempbuf.length+6+6);

//    var crc = ukit.CRC16_GB(tempbuf);
//    var hexcrc = crc.toString(16).toUpperCase();


//    tempbuf.copy(msgdata, 6, 0, tempbuf.length);
//    msgdata.write("##"+ukit.ossnumfixpre(tempbuf.length,4), 0, encoding="utf8");
    //    msgdata.write(ukit.ossnumfixpre(hexcrc, 4) + "\r\n", 6+tempbuf.length, encoding="utf8");
}

void TcpClient::sysctrl(rtreqinfo reqinfo)
{
    //打包
       //##0083QN=20040516010101001;ST=32;CN=5005;PW=123456;MN=1;Flag=1;CP=&&CEMS=4101;Param=So2&&C601

//       if(reqinfo.type ==  "point")
//       {
//         msgcp += "QN=20180116010101001;ST=";
//         msgcp += reqinfo.st ;
//         msgcp += ";CN=5005;PW=123456;MN=1"+ ";Flag=1;CP=&&";

//         for(int i =0;i<reqinfo.item;i++)
//         {
//           if(i == (reqinfo.item - 1))
//           {

//               msgcp += reqinfo.item[i].fid  + "=" + reqinfo.item[i].val + "&&";
//               continue;
//           }
//           msgcp += reqinfo.item[i].fid  + "=" + reqinfo.item[i].val +";";
//         }

//       }
//       else if(reqinfo.type == "process")
//       {
//           msgcp = "QN=20180116010101001;ST=" + reqinfo.st + ";CN=5005;PW=123456;MN=1" + ";Flag=1;CP=&&WMS=4003;D4000=" + reqinfo.item[0] + "&&";
//       }
//       else if(reqinfo.type == "paramsSetting")
//       {
//           /*if(reqinfo.item[0].fid  == "T0016")
//           {
//               msgcp = "QN=20180116010101001;ST=" + reqinfo.st + ";CN=5005;PW=123456;MN=1" + ";Flag=1;CP=&&WMS=4003;" + "T0016" + "=" +reqinfo.item[0].val+ ";T0017" + "=" +reqinfo.item[0].val+ ";T0018" + "=" +reqinfo.item[0].val+ ";T0024" + "=" +reqinfo.item[0].val+ ";T0025" + "=" +reqinfo.item[0].val+"&&";
//           }
//           else*/
//           if(reqinfo.item == 2)
//               msgcp = "QN=20180116010101001;ST=" + reqinfo.st + ";CN=5005;PW=123456;MN=1" + ";Flag=1;CP=&&WMS=4003;" + reqinfo.item[0].fid + "=" +reqinfo.item[0].val+ ";" + reqinfo.item[1].fid + "=" +reqinfo.item[1].val+"&&";
//           else
//               msgcp = "QN=20180116010101001;ST=" + reqinfo.st + ";CN=5005;PW=123456;MN=1" + ";Flag=1;CP=&&WMS=4003;" + reqinfo.item[0].fid + "=" +reqinfo.item[0].val+ "&&";

//       }
}
