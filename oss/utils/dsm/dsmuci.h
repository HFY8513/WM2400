#pragma once
#include "oss/common/utrace.h"
#include "oss/thirds/json/json/json.h"
#include "dsmpub.h"
#include "dsmparam.h"

class uci
{
public:
	uci();
	virtual ~uci();

	int init(utrace* ucitrace, const char* myappdir);

	int readdas(appdas_param* param);
	int writedas(appdas_param* param);

	int readdts(appdts_param* param);
    int writedts(appdts_param* param);

	int readdpc(appdpc_param* param);
	int writedpc(appdpc_param* param);

	int readmain(appmain_param* param);
	int writemain(appmain_param* param);

	int readcems(appcems_param* param);
	int writecems(appcems_param* param);

	int readwms(appwms_param* param);
	int writewms(appwms_param* param);
	
    int readdcs(appdcs_param* param);
	int writedcs(appdcs_param* param);
    
    int readprop(appprop_param* param);
	int writeprop(appprop_param* param);
private:
	int getdb(Json::Value& db, dbcont_param* dbparam);
	int setdb(Json::Value& db, dbcont_param* dbparam);
	int getsitelist(Json::Value& mnodelist, mnode_param* mnodelistparam,  int count);
	int setsitelist(Json::Value& mnodelist, mnode_param* mnodelistparam,  int count);
    int getuiocom(Json::Value& uiocomlist, uiocom_param* uiocomlistparam,  int count);
	int setuiocom(Json::Value& uiocomlist, uiocom_param* uiocomlistparam,  int count);
	int getuiotcp(Json::Value& uiotcplist, uiotcp_param* uiotcplistparam,  int count);
    int setuiotcp(Json::Value& uiotcplist, uiotcp_param* uiotcplistparam,  int count);
	int getdevlist(Json::Value& devlist, dev_param* devlistparam,  int count);
	int setdevlist(Json::Value& devlist, dev_param* devlistparam,  int count);
	int getfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count);
	int getsysfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count);
	int setfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count);
	int gettchlist(Json::Value& tchlist, dtp_param* tchlistparam,  int count);
	int settchlist(Json::Value& tchlist, dtp_param* tchlistparam,  int count);
	int getperiodset(Json::Value& periodset, dsm_period* periodsetparam,  int count);
	int setperiodset(Json::Value& periodset, dsm_period* periodsetparam,  int count);
	int setcemslist(Json::Value& systemlist, cems_param* systemparams,  int count);
	int getcemslist(Json::Value& systemlist, cems_param* systemparams,  int count);
	int setcemsmnodelist(Json::Value& modelnodelist, cemsmnode_param* modelnodeparams,  int count);
	int getcemsmnodelist(Json::Value& modelnodelist, cemsmnode_param* modelnodeparams,  int count);

	int setwmslist(Json::Value& systemlist, wms_param* systemparams,  int count);
	int getwmslist(Json::Value& systemlist, wms_param* systemparams,  int count);
	int setmnodelist(Json::Value& modelnodelist, modelnode_param* modelnodeparams,  int count);
	int getmnodelist(Json::Value& modelnodelist, modelnode_param* modelnodeparams,  int count);
    
private:
	utrace* m_utrace;
    	char m_appdir[DM_FILEPATH_SIZE];
};




