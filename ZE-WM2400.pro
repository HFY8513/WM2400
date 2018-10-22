#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T09:08:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZE-WM2400
TEMPLATE = app

DEFINES -= UNICODE

SOURCES += main.cpp\
    zeei_wm_home.cpp \
    zeei_wm_dataquery.cpp \
    zeei_wm_init.cpp \
    zeei_wm_setup.cpp \
    wm_setup_das.cpp\
    zeei_wm_db.cpp \
    iconhelper.cpp \
    zeei_wm_sysctrl.cpp \
    zeei_wm_devctrl.cpp \
    oss/thirds/json/json_writer.cpp \
    oss/thirds/json/json_value.cpp \
    oss/thirds/json/json_reader.cpp \
    oss/utils/dsm/dsmuci.cpp \
    oss/utils/dsm/dsmt212.cpp \
    oss/utils/dsm/dsmpub.cpp \
    oss/utils/dsm/dsmdqi_sqlite.cpp \
    oss/utils/dsm/dsmdqi.cpp \
    oss/common/utrace.cpp \
    oss/common/utime.cpp \
    oss/common/ustr.cpp \
    oss/common/ucsv.cpp \
    oss/common/time.c \
    oss/common/loadcsv.cpp \
    oss/utils/udbi/dbcont/dbcont.cpp \
    oss/utils/udbi/dbcontsqlite/dbcontsqlite.cpp \
    oss/thirds/sqltie/sqlite3.c \
    global.cpp \
    oss/utils/dsm/dsmdqi_mysql.cpp \
    oss/thirds/qcustomplot/qcustomplot.cpp \
    dbpage.cpp


HEADERS  += zeei_wm_home.h \
    zeei_wm_dataquery.h \
    zeei_wm_init.h \
    zeei_wm_setup.h \
    wm_setup_das.h\
    zeei_wm_db.h \
    iconhelper.h \
    zeei_wm_sysctrl.h \
    zeei_wm_devctrl.h \
    oss/thirds/json/json_tool.h \
    oss/thirds/json/json_batchallocator.h \
    oss/thirds/json/json/writer.h \
    oss/thirds/json/json/version.h \
    oss/thirds/json/json/value.h \
    oss/thirds/json/json/reader.h \
    oss/thirds/json/json/json.h \
    oss/thirds/json/json/forwards.h \
    oss/thirds/json/json/features.h \
    oss/thirds/json/json/config.h \
    oss/thirds/json/json/autolink.h \
    oss/thirds/json/json/assertions.h \
    oss/utils/dsm/dsmuci.h \
    oss/utils/dsm/dsmt212.h \
    oss/utils/dsm/dsmpub.h \
    oss/utils/dsm/dsmparam.h \
    oss/utils/dsm/dsmdqi_sqlite.h \
    oss/utils/dsm/dsmdqi.h \
    oss/utils/dsm/dsm.h \
    oss/common/utrace.h \
    oss/common/utime.h \
    oss/common/ustr.h \
    oss/common/upub.h \
    oss/common/ucsv.h \
    oss/common/loadcsv.h \
    oss/utils/udbi/udbi.h \
    oss/utils/udbi/dbcont/dbcont.h \
    oss/utils/udbi/dbcontsqlite/dbcontsqlite.h \
    oss/utils/uio/uiophy_tcpc.h \
    oss/utils/uio/uiophy_io.h \
    oss/utils/uio/uiophy_com.h \
    oss/utils/uio/uio.h \
    oss/thirds/sqltie/sqlite3ext.h \
    oss/thirds/sqltie/sqlite3.h \
    global.h \
    oss/utils/dsm/dsmdqi_mysql.h \
    oss/thirds/qcustomplot/qcustomplot.h \
    dbpage.h

FORMS    += zeei_wm_home.ui \
    zeei_wm_dataquery.ui \
    zeei_wm_setup.ui \
    wm_setup_das.ui \
    zeei_wm_sysctrl.ui \
    zeei_wm_devctrl.ui \
    dbpage.ui

RESOURCES += \
    image.qrc \
    qss.qrc
