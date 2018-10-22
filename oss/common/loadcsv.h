#pragma once
#include "ucsv.h"

typedef struct factor_map{
    int sysid;  //系统ID
    int g_fac;  //因子分组
    int fid;    //因子ID
    char fac_name[50];  //因子名称
    char unit[12];  //因子单位
    unsigned char decimalbits;      //数值格式。如N14.2表示14位整数2位小数
}factor_map;

typedef struct cfglist_map{
    int sysid;  //系统ID
    char mode_name[100];  //模式名称
    char mode_id[20];   //模式id
}cfglist_map;

typedef struct systype_map{
    int sysid;  //系统ID
    char sys_name[100];  //系统名称
}systype_map;

typedef struct devlist_map{
    char companyid[50];  //制造商ID
    char devmodel[50];  //设备型号
    int sysid;  //系统id
    int devtype;    //设备类型
    char protocol[50];  //协议id
    int devcapacity;    //设备能力
}devlist_map;

typedef struct dev_map{
    char devmodel[50];  //设备型号
    char porttype[5];    //通道类型
    int portnum;    //通道编号
    char portname[50];    //通道名称
    char portsign[50];  //通道标识
}dev_map;

typedef struct dtplist_map{
    char protocolname[100];  //协议名称
    char protocolid[50];    //协议id
    char model[50];    //通信模式
}dtplist_map;


const char* utf8togbk(char* str);
QString gbktoutf8(char* str);
int i_loadfactormap(factor_map* fidmaps,int sysid);

int i_loadcfglistmap(cfglist_map* fidmaps);

int i_loadsystypemap(systype_map* fidmaps);

int i_loaddevlistmap(devlist_map* fidmaps);

int i_loaddevmap(dev_map* fidmaps,char* curfilename);

int i_loaddtplistmap(dtplist_map* fidmaps);

int getappdirex(char* appdir, int size, int layer);
