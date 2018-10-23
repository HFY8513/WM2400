#include "app.h"

char App::g_appdir[512];

QString App::ConfigFile = "config.ini";
QString App::SendFileName = "send.txt";
QString App::DeviceFileName = "device.txt";

appdas_param  App::g_dasparam;
appdts_param  App::g_dtsparam;
appmain_param App::g_mainparam;
appwms_param  App::g_wmsparam;

extern utrace g_qttrace;


int App::initApp()
{
    int ret = 0;
    QString dir = QDir::currentPath();
    dir.append("/");
    QByteArray ba = dir.toLatin1();
    strcpy(g_appdir,ba.data());

    uci myuci;
    if (myuci.init(&g_qttrace, g_appdir) != 0)
    {
        return -1;
    }

    memset(&g_mainparam, 0, sizeof(g_mainparam));
    if (myuci.readmain(&g_mainparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"mainjson loadconfig fail!");
        ret = -2;
    }

    memset(&g_dasparam,0,sizeof(g_dasparam));
    if(myuci.readdas(&g_dasparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"dasjson loadconfig fail!");
        ret = -3;
    }

    memset(&g_dtsparam,0,sizeof(g_dtsparam));
    if(myuci.readdts(&g_dtsparam) != 0)
    {
        g_qttrace.write(TRACE_INFO,"dtsjson loadconfig fail!");
        ret = -4;
    }

    if(QLatin1String(g_mainparam.model) == "wms")
    {
        memset(&g_wmsparam,0,sizeof(g_wmsparam));
        if(myuci.readwms(&g_wmsparam) != 0)
        {
            g_qttrace.write(TRACE_INFO,"wmsjson loadconfig fail!");
            ret = -5;
        }
    }

    return ret;
}

void App::readConfig()
{
    if (!checkConfig()) {
        return;
    }

}

void App::writeConfig()
{

}

void App::newConfig()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#endif
    writeConfig();
}

bool App::checkConfig()
{
    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(App::ConfigFile);
    if (file.size() == 0) {
        newConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");

            if (list.count() == 2) {
                if (list.at(1) == "") {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            newConfig();
            return false;
        }
    } else {
        newConfig();
        return false;
    }

    return true;
}
QStringList App::Intervals = QStringList();
QStringList App::Datas = QStringList();
QStringList App::Keys = QStringList();
QStringList App::Values = QStringList();
void App::readSendData()
{
    //读取发送数据列表
    App::Datas.clear();
    QString fileName = QString("%1/%2").arg(QDir::currentPath()).arg(App::SendFileName);
    QFile file(fileName);
    qDebug()<<fileName;
    if (file.size() > 0 && file.open(QFile::ReadOnly | QIODevice::Text)) {
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.trimmed();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            if (!line.isEmpty()) {
                App::Datas.append(line);
            }
        }

        file.close();
    }
}

void App::readDeviceData()
{
    //读取转发数据列表
    App::Keys.clear();
    App::Values.clear();
    QString fileName = QString("%1/%2").arg(QDir::currentPath()).arg(App::DeviceFileName);
    QFile file(fileName);
    if (file.size() > 0 && file.open(QFile::ReadOnly | QIODevice::Text)) {
        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.trimmed();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            if (!line.isEmpty()) {
                QStringList list = line.split(";");
                QString key = list.at(0);
                QString value;
                for (int i = 1; i < list.count(); i++) {
                    value += QString("%1;").arg(list.at(i));
                }

                //去掉末尾分号
                value = value.mid(0, value.length() - 1);
                App::Keys.append(key);
                App::Values.append(value);
            }
        }

        file.close();
    }
}
