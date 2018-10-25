#include "zeei_wm_home.h"
#include "zeei_wm_init.h"

#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QtSql>
#include <QWidget>
#include <qdebug.h>

#include "global.h"
#include "app.h"
#include "tcpclient.h"
utrace g_qttrace;
char m_appdir[512];     //当前工作路径

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

    //打开数据库,整个应用程序可用
    App::initApp();
    strcpy(m_appdir,App::g_appdir);
    g_qttrace.init("D:\\ZE_WM2400\\data\\sys.log",TRACE_DEBUG);
    QSqlDatabase dbConn;
    if(QLatin1String(App::g_mainparam.dbmode) == "")
    {
        dbConn = QSqlDatabase::addDatabase("QMYSQL");
        dbConn.setHostName(App::g_mainparam.dbparam.server_name);
        dbConn.setDatabaseName(App::g_mainparam.dbparam.db_name); // 数据库
        dbConn.setUserName(App::g_mainparam.dbparam.user_name); // 用户名
        dbConn.setPassword(App::g_mainparam.dbparam.user_passwd); // 用户的密码
    }
    else
    {
        dbConn = QSqlDatabase::addDatabase("QSQLITE");
        dbConn.setDatabaseName(qApp->applicationDirPath() + "/zendb.db");
    }

    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!";
    }

    ZEEI_WM_HOME w;
    w.show();
    
    return a.exec();
}
