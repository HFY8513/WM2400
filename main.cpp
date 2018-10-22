#include "zeei_wm_home.h"
#include "zeei_wm_init.h"

#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QtSql>
#include <QWidget>
#include <QDir>
#include <qdebug.h>
#include "global.h"
#include "oss/utils/dsm/dsmdqi_sqlite.h"
#include "oss/utils/dsm/dsmdqi_mysql.h"
#include "oss/utils/dsm/dsmuci.h"
#include "oss/utils/dsm/dsmparam.h"
#include "oss/utils/udbi/dbcont/dbcont.h"

extern dqi* mydqi;
char dbmode[DM_MODULENAME_SIZE];
appmain_param mainparam;
utrace g_qttrace;
int sysid;  //系统id
char m_appdir[512];     //当前工作路径

int mydqiinit(utrace* mytrace)
{

    uci myuci;
    dbcont_param m_dbparam;
    dsm_rtdlast m_rtdlastdata;
    memset(&mainparam, 0, sizeof(mainparam));

    if (myuci.init(mytrace, m_appdir) != 0)
    {
        return -2;
    }

    if (myuci.readmain(&mainparam) != 0)
    {
        mytrace->write(TRACE_INFO,"dsmtk loadconfig fail!");
        return -3;
    }

    mytrace->write(TRACE_INFO,"dsmtk loadconfig success!");

    strncpy(dbmode, mainparam.dbmode, sizeof(dbmode)-1);
    m_dbparam = mainparam.dbparam;

    sysid = mainparam.mnodeparams[0].sysid;

    if (strcmp(dbmode, "sqlite") == 0)
    {
        mydqi = new dqi_sqlite;
    }
    else
    {
        mydqi = new dqi_mysql;
    }

    if (mydqi->init(&m_dbparam) != 0)
    {
        return -4;
    }
    qDebug()<<"连接sqlite成功！";
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

    //加载样式表
    QFile file(":/res/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

    a.setFont(QFont("Microsoft Yahei", 9));
    ZEEI_WM_Init::Instance()->start();

    QString dir = QDir::currentPath();
    dir.append("/");
    QByteArray ba = dir.toLatin1();
    strcpy(m_appdir,ba.data());
    g_qttrace.init("D:\\ZE-WM2400-build-desktop-Qt_4_8_4__4_8_4____\\data\\sys.log",TRACE_DEBUG);
    if(mydqiinit(&g_qttrace) != 0);
//        qDebug()<<"连接数据库失败，可能没有main.json或者数据库不存在！";

    //打开数据库,整个应用程序可用
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QMYSQL");
    dbConn.setHostName(mainparam.dbparam.server_name);
    dbConn.setDatabaseName(mainparam.dbparam.db_name); // 数据库
    dbConn.setUserName(mainparam.dbparam.user_name); // 用户名
    dbConn.setPassword(mainparam.dbparam.user_passwd); // 用户的密码

   // dbConn.setDatabaseName(qApp->applicationDirPath() + "/zendb.db");
    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!";
    }

    ZEEI_WM_HOME w;
    w.show();
    
    return a.exec();
}
