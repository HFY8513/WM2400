#ifndef APP_H
#define APP_H
#include <qdebug.h>
#include "global.h"

#include "oss/utils/dsm/dsmuci.h"
#include "oss/utils/dsm/dsmparam.h"
#include "oss/utils/udbi/dbcont/dbcont.h"
class App
{
public:
    static char g_appdir[512];

    static appdas_param  g_dasparam;
    static appdts_param  g_dtsparam;
    static appmain_param g_mainparam;
    static appwms_param  g_wmsparam;

    static QString ConfigFile;          //配置文件路径
    static QString SendFileName;        //发送配置文件名
    static QString DeviceFileName;      //模拟设备数据文件名
    static QStringList Intervals;
    static QStringList Datas;
    static QStringList Keys;
    static QStringList Values;

    static int initApp();
    //读写配置参数及其他操作
    static void readConfig();           //读取配置参数
    static void writeConfig();          //写入配置参数
    static void newConfig();            //以初始值新建配置文件
    static bool checkConfig();          //校验配置文件

    static void readSendData();
    static void readDeviceData();
};

#endif // APP_H
