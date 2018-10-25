#ifndef GLOBAL_H
#define GLOBAL_H
#include <QDir>
#include <QDateTime>

#include <oss/utils/dsm/dsmparam.h>
#include <oss/utils/dsm/dsmuci.h>
#include "oss/utils/dsm/dsmdqi.h"
#include "oss/common/utime.h"
#include "oss/common/loadcsv.h"

#include "oss/utils/udbi/dbcont/dbcont.h"

typedef struct AddStationMsg{
    QString stationidedit;
    QString stationnameedit;
    QString sysidedit;
}AddStaMsg;

typedef struct AddComMsg{
    QString addcomnameedit;
    QString addcomnumbox;
    QString addcombaudratebox;
    QString addcomdatabitbox;
    QString addcomcheckbitbox;
    QString addcomstopbitbox;
}AddComMsg;

typedef struct AddDevMsg{
    QString devnameedit;
    QString devtypebox;
    QString porttypebox;
    QString portnamebox;
    QString devaddredit;
    QString devperiodedit;
}AddDevMsg;


typedef struct cfgmap{
    int id;
    char type[50];
    char modleid[20];
}cfgmap;

static const cfgmap g_cfg[] = {
    {31,"烟气站配置模板(HORIBA)","cems_horiba"},
    {31,"烟气站配置模板(KN)","cems_kn"},
    {22,"空气站配置模板(HORIBA)","aqms_horiba"},
    {22,"空气站配置模板(KN)","aqms_kn"},
    {32,"污染源水(ZEEI)","wmsps_zeei"},
    {21,"地表水站(ZEEI)","wmses_zeei"},
    {101,"超级站配置模板","sups_craes"},
    {51,"工况配置模板(OPC)","ipms_opc"}
};

static const char* comnum[] = {
    "COM1",
    "COM2",
    "COM3",
    "COM4",
    "COM5",
    "COM6",
    "COM7",
    "COM8"
};
static QString str="helo";
static const char* baudrate[] = {
    "1200",
    "2400",
    "4800",
    "9600",
    "19200",
    "38400",
    "57600",
    "115200"
};
static const char* databit[] = {
    "8",
    "7",
    "6",
    "5"
};
static const char* checkbit[] = {
    "None",
    "Odd",
    "Even",
    "Mark",
    "Space"
};
static const char* stopbit[] = {
    "1",
    "1.5",
    "2"
};
static const char* flowunit[] = {
    "默认",
    "m3/h",
    "m3/s",
    "L/s",
    "使用配置文件"
};
extern AddStaMsg addstamsg;
extern AddComMsg addcommsg;
extern AddDevMsg adddevmsg;

int convertfidrule(char* strfid);
int convertgidrule(char* strfid);
usstime gettime();

enum DbType {
    DbType_Sqlite,      //sqlite数据库
    DbType_MySql,     //mysql数据库
    DbType_SqlServer   //sqlserver数据库
};
enum COMBType {
    COMB_COM,
    COMB_BRATE,
    COMB_DATABIT,
    COMB_CHECKBIT,
    COMB_STOPBIT,
    COMB_UNIT
};
enum ShowType {
    SHOW_DATA,
    SHOW_CURVE
};

typedef struct rtreqinfo{
    char st[10];
    char stationid[50];
    int  sysid;
    char querymode[10];
    int  querytype;
    int  queryint;
    char begintime[30];
    char endtime[30];
    int item[10];
    char type[10];
}rtreqinfo;

#endif // GLOBAL_H
