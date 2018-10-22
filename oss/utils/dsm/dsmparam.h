#pragma once

#include "dsmpub.h"
#include "oss/utils/udbi/dbcont/dbcont.h"
#include "oss/utils/uio/uiophy_com.h"
#include "oss/utils/uio/uiophy_tcpc.h"

#define USS_DATADIR_DASDATA                 "data/"
#define USS_DATADIR_LOGS                    "data/logs/"

#define USS_APPDIR_CFG                      "config/"
#define USS_APPDIR_BIN                      "bin/"
#define USS_APPDIR_SCRIPT                   "script/"

#define USS_APPDIR_CFGVAR                   "config/var/"
#define USS_APPDIR_CFGCONST                 "config/const/"
#define USS_APPDIR_CFGFEATURE               "config/feature/"

#define DAS_FCH_MAXNUM MAX_DAQ_ITEM
#define DAS_DEV_MAXNUM 64
#define DAS_UIOLOGICCH_MAXNUM 64
#define DAS_UIOPHYCOM_MAXNUM 32
#define DAS_UIOPHYTCPC_MAXNUM 32
#define DAS_UIOBUF_SIZE UIO_LOGICBUF_SIZE
#define DAS_SYSTEMFID_MAXNUM 32

#define DTS_TCH_MAXNUM 64
#define DTS_UIOLOGICCH_MAXNUM DTS_TCH_MAXNUM
#define DTS_UIOPHYCOM_MAXNUM DTS_TCH_MAXNUM
#define DTS_UIOPHYTCPC_MAXNUM DTS_TCH_MAXNUM

#define DCS_REGFCH_MAXNUM 16

typedef struct mnode_param
{
	char 	name[DM_MODULENAME_SIZE];
	int    	sysid;
    int     stationid;
    int 	avgmode;
}mnode_param;

typedef struct uiocom_param
{
	char 	logicname[DM_CHANNAME_SIZE];
	char 	phyname[DM_CHANNAME_SIZE];
	uiophy_comparam param;
}uiocom_param;

typedef struct uiotcp_param
{
	char 	logicname[DM_CHANNAME_SIZE];
	uiophy_tcpcparam param;
}uiotcp_param;

typedef struct dev_param
{
	int 		inftype; 					//接口类型
	int 		addr; 					//RS485地址
	int 		devtype; 				//设备所属设备类型,区别是PLC,ADM,采样器,标定仪,分析仪
	int 		devperiod;				//设备数据周期
	unsigned int capacity;			//设备能力
	char 	model[DM_MODULENAME_SIZE];			//设备厂家型号
  	char 	name[DM_MODULENAME_SIZE];			//设备实例名字
  	char 	protocol[DM_MODULENAME_SIZE];		//设备协议名字
	char 	logicname[DM_CHANNAME_SIZE];		//通信链路逻辑通道名

}dev_param;

typedef struct fch_param
{
	char 	fid[MAX_DAQ_FIDSIZE];
	char 	unit[16];
	char 	name[32];

	char 	devname[DM_MODULENAME_SIZE];
	int 		channel;
	int     	stationid;
	int     	systemid;

	bool 	rangeflag;				/*range convert*/
	bool 	slopeflag;				/*slope convert*/
	bool 	rangelimit;				/*range limit*/

	double	devmin;
	double	devmax;
	double	rangemin;
	double	rangemax;
	double	slope;
	double	intercept;
}fch_param;

typedef struct dtp_param
{
	char 	mn[32];
    char    pw[32];
	char 	logicname[DM_CHANNAME_SIZE];		//通信链路逻辑通道名
  	char 	protocol[DM_MODULENAME_SIZE];		//协议名字
  	
	int     	sysid;
	int     	stationid;

	/*0:normal,1:API,2:AQI*/
	int 		avgmode;

	/*均值延后上传时长*/
	int 		delaytime;
	/*均值重新上传间隔*/
	int 		retranstime;

	int 		tchid;
	int 		minuteint;
	int 		rtdint;
	int 		inftype;

       /*单位小时*/
	int 		periodint;
       /*单位分钟*/
	int 		measuertime;
    
       char        flowunit[32];
}dtp_param;

typedef struct dasparam{
    bool           usecmdserver;
    int             dataperiod;		//数据采集周期,单位是秒
    int     		timemode;		//数据时间模式.0:采集时间,1:周期时间,2:仪器时间
}dasparam;

typedef struct dtsparam{
	int 	reserve;

}dtsparam;

typedef struct dpcparam{
    char            cpmode[32];
    bool            rtdroute;
    bool            rulecalc;
    bool            rulealarm;
    bool            avgcalc;
    
    bool            ufidflag;
    bool            qcflag;
    
    int             minuteint;
    int             rtdint;
    int             avgpolicy;
}dpcparam;

typedef struct cems_param
{
    int             systemid;
    char          name[DM_MODULENAME_SIZE];
    
    double      airexcess_k;              //标准空气过量系数
    double      pressureratiolimit;    //压比门限设置
    bool         localpressureagent;
    double      localpressure;           //当地大气压
    int            measuretype;          //系统类型.0稀释法,1直抽法
    int             measuerint;              // 1拖N烟道切换周期单位分钟
    int fchcount;
    fch_param fchparams[DAS_SYSTEMFID_MAXNUM];

}cems_param;

typedef struct cemsmnode_param
{
    int     	stationid;
    int 		systemid;
    
    double      pitottube_k;              //皮托管系数
    double      speed_k;                   //速度场系数
    double      sectionarea;              //烟道截面积
    double      dilutionratio;             //稀释比

    int      pressuremode;          //采集压力模式  0绝压采集,1表压 

    double      molecularweight;      //烟气分子量

    bool         humidityagent;
    double      humidity;                   //输入湿度
    bool         o2ratioagent;
    double      o2ratio;                             //输入含氧量

    int             antiblowint;              //反吹间隔单位分钟
    int             antiblowtime;           //反吹持续时长单位分钟

    bool 	      stopboiler;
    int            stopfactormode;           
    double      stopo2ratio;           
    double      stopspeed;           
    double      stoptemperature;           

    int            so2calich;
    int            noxcalich;
    int            zerocalich;
    int            samplech;
    int 	     antiblowch;

    char         epcmodule[DM_MODULENAME_SIZE];
    char         antiblowprobe[DM_MODULENAME_SIZE];
    char         antiblowpitot[DM_MODULENAME_SIZE];
}cemsmnode_param;

typedef struct wms_param
{
    int           systemid;
    char          name[DM_MODULENAME_SIZE];

    /*系统测量参数*/
    int           measuretype;          //系统类型.
    int           measuerint;           //系统采水测量周期
    int           measuertime;          //测量出数时间能力
    char          epcmodule[DM_MODULENAME_SIZE];

    /*采水触发控制参数*/
    bool          usemeasuretrig;
    int           trigmode;
    double        trigflowlimt;
    char          trigtimerange[DM_MODULENAME_SIZE];
    

    /*留样参数*/
    bool          usesampler;
    int           samplemode;
    double        samplequantity;
    double        samplerate;
    char          sampler[DM_MODULENAME_SIZE];
}wms_param;


typedef struct modelnode_param
{
	int     	stationid;
	int 		systemid;
}modelnode_param;

typedef struct server_param
{
	char host[256];
	int port;
	int sessioncount;
	int keepalivesec;
}server_param;

typedef struct appdas_param{
	dasparam param;
	
	int devcount;
	int fchcount;
	int uiotcpcount;
	int uiocomcount;
	
	dev_param devparams[DAS_DEV_MAXNUM];
	fch_param fchparams[DAS_FCH_MAXNUM];
	uiocom_param uiocomparams[DAS_UIOPHYCOM_MAXNUM];
    uiotcp_param uiotcpparams[DAS_UIOPHYTCPC_MAXNUM];
	
}appdas_param;

typedef struct appdts_param{
	dtsparam param;
	
	int tchcount;
	int uiotcpcount;
	int uiocomcount;
	
	dtp_param tchparams[DTS_TCH_MAXNUM];
	uiocom_param uiocomparams[DTS_UIOPHYCOM_MAXNUM];
	uiotcp_param 	uiotcpparams[DTS_UIOPHYTCPC_MAXNUM];
	
}appdts_param;

typedef struct appdpc_param{
	dpcparam param;
}appdpc_param;

typedef struct appmain_param{
    char model[DM_MODULENAME_SIZE];
    char name[DM_MODULENAME_SIZE];
    char dbmode[DM_MODULENAME_SIZE];

    int mnodecount;

    bool  usecmdserver;
    int    cmdport;

    dbcont_param dbparam;
    mnode_param mnodeparams[DM_SITE_MAXNUM];
}appmain_param;


typedef struct appcems_param{
    int systemcount;
    cems_param systemparams[DM_SYSTEM_MAXNUM];

    int modelnodecount;
    cemsmnode_param modelnodeparams[DM_SITE_MAXNUM];
}appcems_param;

typedef struct appwms_param{
    int systemcount;
    wms_param systemparams[DM_SYSTEM_MAXNUM];

    int modelnodecount;
    modelnode_param modelnodeparams[DM_SITE_MAXNUM];
}appwms_param;

typedef struct appdcs_param{
	char dcsmode[DM_MODULENAME_SIZE];
	int fchcount;
	fch_param fchparams[DAS_FCH_MAXNUM];
	
}appdcs_param;

typedef struct appprop_param
{
    int timemode;		//数据时间模式.0:采集时间,1:周期时间,2:仪器时间

    int             avgpolicy;
    int             avgmode;
    bool            rtdroute;
    bool            rulecalc;
    bool            rulealarm;
    bool            avgcalc;
    bool            ufidflag;
    bool            qcflag;
    char            cpmode[32];
    char            project[DM_MODULENAME_SIZE];
    
    int periodcount;
    dsm_period periodset[DM_FACTORPERIOD_MAXNUM];
}appprop_param;




