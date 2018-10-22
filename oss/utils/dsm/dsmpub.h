#pragma once
#include "oss/common/utime.h"


/* support small factor count for wince platform. */
#ifdef _WIN32_WCE
#define MAX_DAQ_ITEM 512
#else
#define MAX_DAQ_ITEM 1024
#endif
    
#define MAX_DAQ_FIDSIZE 16

#define DM_SITE_MAXNUM 		32
#define DM_SYSTEM_MAXNUM    8
#define DM_RTU_MAXNUM 		32

#define DM_ALARM_MAXNUM     	64
#define DM_STATE_MAXNUM     	64
#define DM_QCTASK_MAXNUM        	128

#define DM_GROUP_MAXNUM 		100
#define DM_FID_MAXNUM 		    	10000
#define DM_INST_MAXNUM 		100

#define DM_FACTOR_MAXNUM 		MAX_DAQ_ITEM
#define DM_FACTOR_UPDATE_MAXNUM (DM_FACTOR_MAXNUM*2)
#define DM_FACTORPERIOD_MAXNUM 	32

#define DM_PACKET_MAXSIZE 		(0x10000)
#define DM_PACKET_NORSIZE 		UIO_LOGICBUF_SIZE

#define DM_PACKET_MAXPNO 	    	64
#define DM_FILEPATH_SIZE 	    	512
#define DM_CHANNAME_SIZE 	    	128
#define DM_MODULENAME_SIZE   	128
#define DM_EXPRULE_SIZE   		512
#define DM_DESTEXT_SIZE   		128

#define MAX_NUMFMT_SIZE             16


#define DM_FIDDATA_STRAT                0
#define DM_FIDPARAM_STRAT             900
#define DM_FIDCONDITION_STRAT      1000
#define DM_FIDUSER_STRAT                1100


typedef enum{                      //system state define
    
    SYS_IDLE = 0,
    SYS_STATE_MEASURING = 1,
    SYS_STATE_CALIBRATE = 2,
    SYS_STATE_WASH = 3,
    SYS_STATE_MAINTAIN = 4,

    SYS_STATE_NORMAL = 100,
    SYS_STATE_FAULT = 101,

   SYS_STATE_MAX
}SYS_STATE;

typedef enum{                      //dev state define
    
    DEV_STATE_IDLE = 0,
    DEV_STATE_MEASURING,
    DEV_STATE_CALIBRATE,
    DEV_STATE_WASH,

    DEV_STATE_MAINTAIN,
    DEV_STATE_OFFLINE,
    
    DEV_STATE_NORMAL = 100,
    DEV_STATE_FAULT = 101,
    
    DEV_STATE_MAX
}DEV_BASESTATE;


typedef enum{                      //цАцЎчБЛх
    
    DM_AVGTYPE_M = 0,
    DM_AVGTYPE_H,
    DM_AVGTYPE_D,
    DM_AVGTYPE_O,

    DM_AVGTYPE_MAX,
    
    DM_DATA_R = 10,
    DM_DATA_P,
    DM_DATA_U,
    DM_DATA_P2,
    
    /*УЈ?У ????УЙ?ЮМ*/
    DM_ACC_M = 20,
    DM_ACC_H,
    DM_ACC_D,
    /*??У ????УЙ?ЮМ*/
    DM_ACC_O,
    
    DM_ACC_MAX
}DM_DATA_TYPE;

typedef enum{                         //хш­ІчБЛх
    
    DM_ALARM_D = 0,
    DM_ALARM_E,

    DM_ALARM_MAX
}DM_ALARM_TYPE;

typedef enum{                         //хш­ІчБЛх
    
    DM_STATETYPE_WORKSTATE = 1,
    DM_STATETYPE_PARAMSTATE = 2,

    DM_STATETYPE_MAX
}DM_STATE_TYPE;

typedef enum{
    
    DM_AVGCALC_POLICY_MEM = 0,
    DM_AVGCALC_POLICY_DB_SINGLEFID,
    DM_AVGCALC_POLICY_DB_MULTIFID,
    DM_AVGCALC_POLICY_MAX
}DM_AVGCALCPOLICY_TYPE;

typedef enum{
    
    DM_AVGCALC_MODE_NORMAL = 0,
    DM_AVGCALC_MODE_API,
    DM_AVGCALC_MODE_AQI,
    DM_AVGCALC_MODE_CEMS,
    DM_AVGCALC_MODE_WMS,
    
    DM_AVGCALC_MODE_MAX
}DM_AVGCALCMODE_TYPE;

typedef enum{
    
    DM_DATA_TIMEMODE_NORMAL = 0,
    DM_DATA_TIMEMODE_DEVSRC,
    DM_DATA_TIMEMODE_PERIOD,

    DM_DATA_TIMEMODE_MAX
}DM_DATATIMEMODE_TYPE;

typedef enum{                    
    
    IO_INF_COM = 0,
    IO_INF_NET = 1,
    IO_INF_CHIP = 2,

   IO_INF_MAX
}IO_INF_TYPE;

typedef struct ussrtv{                     //щщх х­чЛц
    char fid[MAX_DAQ_FIDSIZE];
    double val;
    double origval;
    unsigned char state;
    usstime dtime;
    
    unsigned char decimalbits;      //Ъ§жЕИёЪНЁЃШчN14.2БэЪО14ЮЛећЪ§2ЮЛаЁЪ§

}ussrtv;

typedef struct ussrtvlist {                // щщх х­шЁЈ
    bool used;
    usstime dtime;
    ussrtv rtv_set[MAX_DAQ_ITEM];
    int rtv_cnt;
} ussrtvlist;

typedef struct alarmch{
    
    char alarm_str[DM_DESTEXT_SIZE];
    char model[DM_MODULENAME_SIZE];
    unsigned int alarm_code;
    unsigned int ch; 
    unsigned char type;
}alarmch;

typedef struct dsm_cprtv{
    char fid[MAX_DAQ_FIDSIZE];
    usstime time;
    double v;
    float k;
    unsigned int t:12;
    unsigned int st:12;
    unsigned int s:8;
}dsm_cprtv;


typedef struct dsm_avg{
    
    char fid[MAX_DAQ_FIDSIZE];
    double avg;
    double min;
    double max;
    double cou;
	int vaildcount;
    unsigned char state;
    unsigned char rsv[3];
    usstime avg_time;
}dsm_avg;

typedef struct dsm_arqrecord{
    int data_type;
    usstime start_time;
    usstime end_time;
}dsm_arqrecord;

typedef struct dsm_alarmrecord{
    char alarm_src[DM_MODULENAME_SIZE];
    char alarm_str[DM_DESTEXT_SIZE];
    unsigned int alarm_code;
    usstime start_time;
    usstime end_time;
}dsm_alarmrecord;

typedef struct dsm_staterecord{
    char state_src[DM_MODULENAME_SIZE];
    char state_valuetext[DM_DESTEXT_SIZE];
    unsigned int state_code;
    unsigned int state_type;
    usstime start_time;
    usstime end_time;
}dsm_staterecord;

typedef struct dsm_avgtrig{
    bool isperiod;
    bool istrigged;
    char fid[MAX_DAQ_FIDSIZE];
	usstime start_time;
	usstime end_time;
	usstime data_time;
	int timecount;
	int devperiod;
	int calcperiod;
}dsm_avgtrig;

/*
У?D?УтВУЌ?У­ТЈ1yУВ????УЁУЈ?oЫУЊy??ЮМ?яПЁ?2?УЌ????УК?УЁ1??Ы?D,
У­ТЈ1ycompletedТБУЊУЊ?УЉ?УВ???УЊТБ??ТЗ??ТЇУВ??-УЊ???яПЁ??УЊDУ­У­a2????ЫD?УЊТБ??21УЊy
У­ТЈ1ylostТБУЊУЊ?УЊ?ТЗ?УГDУЈТБУЊТЇ
*/
typedef struct dsm_rtdcpresult{
    bool updated;
    bool lost;
    bool completed;
    dsm_arqrecord arq_record;
    dsm_cprtv cprtv_set[DM_FACTOR_UPDATE_MAXNUM];
    int cprtv_cnt;
}dsm_rtdcpresult;

typedef struct dsm_rtdresult{
    bool updated;
	usstime time;
    ussrtv rtv_set[DM_FACTOR_MAXNUM];
    int rtv_cnt; 
}dsm_rtdresult;

typedef struct dsm_avgresult{
	bool updated;
	usstime start_time;
    dsm_avg avg_set[DM_FACTOR_MAXNUM];
    int avg_cnt;
}dsm_avgresult;

typedef struct dsm_ruleresult{
	bool updated;
	usstime time;
    dsm_alarmrecord alarm_set[DM_ALARM_MAXNUM];
    int alarm_cnt;
    
}dsm_ruleresult;

typedef struct dsm_alramresult{
	bool updated;
	usstime time;
    dsm_alarmrecord hisalarm_set[DM_ALARM_MAXNUM];
    int hisalarm_cnt;
}dsm_alramresult;

typedef struct dsm_stateresult{
	bool updated;
	usstime time;
       dsm_staterecord hisstate_set[DM_STATE_MAXNUM];
       int hisstate_cnt;
}dsm_stateresult;

typedef struct dsm_rtdlast{
    usstime time;
    ussrtv rtv_set[DM_FACTOR_MAXNUM];
    int rtv_cnt;    
}dsm_rtdlast;

typedef struct dsm_acclast{
    usstime start_time;
    usstime end_time;
    usstime time;
    dsm_avg avg_set[DM_FACTOR_MAXNUM];
    int avg_cnt;
    int state;
}dsm_acclast;

typedef struct dsm_alarmlast{
	usstime time;
    dsm_alarmrecord alarm_set[DM_ALARM_MAXNUM];
    int alarm_cnt;
    
}dsm_alarmlast;

typedef struct dsm_statelast{
    usstime time;
    dsm_staterecord state_set[DM_STATE_MAXNUM];
    int state_cnt;
    
}dsm_statelast;




typedef struct dsm_divpkt{
	int pnum;
	int pos;
	int num;
}dsm_divpkt;

typedef struct dsm_period{
    char fid[MAX_DAQ_FIDSIZE];
	int devperiod;
}dsm_period;

typedef struct dsm_qctask{
    int stationid;
    char fid[MAX_DAQ_FIDSIZE];
    usstime start_time;
    usstime end_time;
    unsigned char mark;

}dsm_qctask;

typedef struct dsm_dtrecord{
    int tchid;
    usstime time;
}dsm_dtrecord;

typedef struct dsm_ctrlreq{

    int       cmdid;
    char    obj[DM_MODULENAME_SIZE];
    char    inval[512];
}dsm_ctrlreq;

typedef struct dsm_ctrlres{
    int    exertn;
    char qn[32];
    char outval[512];
}dsm_ctrlres;

int dsm_strtoufid(const char* strfid, unsigned int* mygid, unsigned int* myfid, unsigned int* myinstid);

