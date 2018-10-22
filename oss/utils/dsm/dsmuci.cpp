
#include "dsmuci.h"

#define UCI_CONTU_GETBOOL(param, valnode, name, idx)                                                       \
                if (!(valnode.isMember(#name) && valnode[#name].isBool()))                                      \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    continue;                                                                                                                  \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asBool();                                                                            \
                }

                
#define UCI_CONTU_GETINT(param, valnode, name, idx)                                                       \
                if (!(valnode.isMember(#name) && valnode[#name].isInt()))                                      \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    continue;                                                                                                                  \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asInt();                                                                             \
                }
                
#define UCI_CONTU_GETDOUBLE(param, valnode, name, idx)                                                   \
                if (!(valnode.isMember(#name) && valnode[#name].isDouble()))                                  \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    continue;                                                                                                                  \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asDouble();                                                                      \
                }
                
#define UCI_CONTU_GETSTR(param, valnode, name, idx)                                                         \
                if (!(valnode.isMember(#name) && valnode[#name].isString()))                                  \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    continue;                                                                                                                  \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    strncpy(param, valnode[#name].asCString(), sizeof(param)-1);                                  \
                }

#define UCI_DEFAULT_GETBOOL(param, valnode, name, idx, defaultval)                                  \
                if (!(valnode.isMember(#name) && valnode[#name].isBool()))                                      \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    param = defaultval;                                                                                                 \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asBool();                                                                            \
                }

                
#define UCI_DEFAULT_GETINT(param, valnode, name, idx, defaultval)                                  \
                if (!(valnode.isMember(#name) && valnode[#name].isInt()))                                      \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    param = defaultval;                                                                                                \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asInt();                                                                             \
                }
                
#define UCI_DEFAULT_GETDOUBLE(param, valnode, name, idx, defaultval)                             \
                if (!(valnode.isMember(#name) && valnode[#name].isDouble()))                                  \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    param = defaultval;                                                                                                 \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    param = valnode[#name].asDouble();                                                                      \
                }
                
#define UCI_DEFAULT_GETSTR(param, valnode, name, idx, defaultval)                                    \
                if (!(valnode.isMember(#name) && valnode[#name].isString()))                                  \
                {                                                                                                                                   \
                    m_utrace->write(TRACE_ERROR, "parse %s[%d].%s fail!", #valnode, idx, #name);       \
                    strncpy(param, defaultval, sizeof(param)-1);                                                            \
                }                                                                                                                                   \
                else                                                                                                                               \
                {                                                                                                                                    \
                    strncpy(param, valnode[#name].asCString(), sizeof(param)-1);                                \
                }

uci::uci()
{
	m_utrace = NULL;
	memset(m_appdir, 0, sizeof(m_appdir));
}

uci::~uci()
{

}
    
int uci::init(utrace* ucitrace, const char* myappdir)
{
	if (ucitrace == NULL)
	{
		return -3;
	}

	m_utrace = ucitrace;

	strncpy(m_appdir, myappdir, sizeof(m_appdir)-1);

	return 0;
}


int uci::readdas(appdas_param* param)
{
	ifstream ifs;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"das.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value fchlist;
		Json::Value devlist;
		Json::Value uiotcp;
		Json::Value uiocom;
		
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse das.json fail!");
			
			ifs.close();

			return -2;
		}

		if (!(root.isMember("fchlist") && root["fchlist"].isArray()))
		{
			ret = -3;
		}

		if (!(root.isMember("uiotcp") && root["uiotcp"].isArray()))
		{
			ret = -4;
		}

		if (!(root.isMember("uiocom") && root["uiocom"].isArray()))
		{
			ret = -5;
		}
		
		if (!(root.isMember("devlist") && root["devlist"].isArray()))
		{
			ret = -6;
		}

		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse das.json err=%d!", ret);
			
			ifs.close();
			return ret;
		}

              UCI_DEFAULT_GETINT(param->param.dataperiod, root, dataperiod, 0, 10);
              
		param->param.timemode = DM_DATA_TIMEMODE_NORMAL;
		
		uiocom = root["uiocom"];
		uiotcp = root["uiotcp"];
		fchlist = root["fchlist"];
		devlist = root["devlist"];
		
		param->devcount = getdevlist(devlist, param->devparams, DAS_DEV_MAXNUM);
		param->fchcount = getfchlist(fchlist, param->fchparams, DAS_FCH_MAXNUM);
		param->uiotcpcount = getuiotcp(uiotcp, param->uiotcpparams, DAS_UIOPHYTCPC_MAXNUM);
		param->uiocomcount = getuiocom(uiocom, param->uiocomparams, DAS_UIOPHYCOM_MAXNUM);
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse das.json except!");
		
		ret = -7;

	}

	if (ifs.is_open())
	{
		ifs.close();
	}
    

    return ret;
}


int uci::writedas(appdas_param* param)
{
    ifstream ifs;
    int ret = 0;
    char cfgpath[DM_FILEPATH_SIZE];


    strcpy(cfgpath, m_appdir);
    strcat(cfgpath, USS_APPDIR_CFG);
    strcat(cfgpath,"das.json");

    try
    {
        ifs.open(cfgpath);
        if (!ifs.is_open())
        {
            m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);
            return -1;
        }
        Json::Reader readerDas;
        Json::Value rootDas;
        if (!readerDas.parse(ifs, rootDas,false))
        {
            m_utrace->write(TRACE_ERROR, "parse main.json fail!");
            ifs.close();
            return -2;
        }
        //dataperiod
        rootDas["dataperiod"] =  Json::Value(param->param.dataperiod);

        //com
        Json::Value arrayCom = rootDas["uiocom"];
        Json::Value arrayComNew;
//        int nArrayCom = arrayCom.size();
        for(int i = 0; i < param->uiocomcount; i++)
        {
            arrayComNew[i] = rootDas["uiocom"][i];
        }
        for(int i = 0 ;i < param->uiocomcount ; i++)
        {
            arrayComNew[i]["logicname"] = Json::Value(param->uiocomparams[i].logicname);
            arrayComNew[i]["phyname"]	= Json::Value(param->uiocomparams[i].phyname);
            arrayComNew[i]["baud_rate"] = Json::Value(param->uiocomparams[i].param.baud_rate);
            arrayComNew[i]["byte_size"] = Json::Value(param->uiocomparams[i].param.byte_size);
            arrayComNew[i]["parity"]	= Json::Value(param->uiocomparams[i].param.parity);

            if(param->uiocomparams[i].param.stop_bits == 1)
            {
                param->uiocomparams[i].param.stop_bits = 0;
            }
            else if(param->uiocomparams[i].param.stop_bits == 1.5)
            {
                param->uiocomparams[i].param.stop_bits = 1;
            }
            else if(param->uiocomparams[i].param.stop_bits == 2)
            {
                param->uiocomparams[i].param.stop_bits = 2;
            }
            arrayComNew[i]["stop_bits"] = Json::Value(param->uiocomparams[i].param.stop_bits);
        }

        rootDas["uiocom"].clear();
        for (int i = 0 ;i < param->uiocomcount ; i++)
        {
            rootDas["uiocom"].append(arrayComNew[i]);
        }

        //net
        Json::Value arrayNet = rootDas["uiotcp"];
        Json::Value arrayNetNew;
        int nArrayNet = arrayNet.size();
        for(int i = 0; i < param->uiotcpcount; i++)
        {
            arrayNetNew[i] = rootDas["uiotcp"][i];
        }
        for(int i = 0 ;i < param->uiotcpcount ; i++)
        {
            arrayNetNew[i]["logicname"] = Json::Value(param->uiotcpparams[i].logicname);
            arrayNetNew[i]["host"]	    = Json::Value(param->uiotcpparams[i].param.host);
            arrayNetNew[i]["port"]      = Json::Value(param->uiotcpparams[i].param.port);
        }

        rootDas["uiotcp"].clear();
        for (int i = 0 ;i < param->uiotcpcount ; i++)
        {
            rootDas["uiotcp"].append(arrayNetNew[i]);
        }

        //设备
        Json::Value arrayDev = rootDas["devlist"];
        Json::Value arrayDevNew;
        int nArraDev = arrayDev.size();
        for(int i = 0; i < param->devcount; i++)
        {
            arrayDevNew[i] = rootDas["devlist"][i];
        }
        for(int i = 0 ;i < param->devcount ; i++)
        {
            arrayDevNew[i]["name"]      = Json::Value(param->devparams[i].name);
            arrayDevNew[i]["model"]	    = Json::Value(param->devparams[i].model);
            arrayDevNew[i]["protocol"]  = Json::Value(param->devparams[i].protocol);
            arrayDevNew[i]["inftype"]   = Json::Value(param->devparams[i].inftype);
            arrayDevNew[i]["logicname"] = Json::Value(param->devparams[i].logicname);
            if (param->devparams[i].devperiod)
            {
                arrayDevNew[i]["devperiod"] = Json::Value(param->devparams[i].devperiod);
            }
            else
                arrayDevNew[i]["devperiod"] = Json::Value(10);

            arrayDevNew[i]["addr"]      = Json::Value(param->devparams[i].addr);
        //	arrayDevNew[i]["devtype"]   = param->devparams[i].devtype;

            if (param->devparams[i].devtype)
            {
                arrayDevNew[i]["devtype"] = Json::Value(param->devparams[i].devtype);
            }
            else
                arrayDevNew[i]["devtype"]   = Json::Value(0);
            //arrayDevNew[i]["capacity"]  = Json::Value(param->devparams[i].devtype).capacity);
            arrayDevNew[i]["capacity"]  = Json::Value(1);
        }

        rootDas["devlist"].clear();
        for (int i = 0 ;i < param->devcount ; i++)
        {
            rootDas["devlist"].append(arrayDevNew[i]);
        }

        //因子
        Json::Value arrayFac = rootDas["fchlist"];
        Json::Value arrayFacNew;

        for(int i = 0; i < param->fchcount; i++)
        {
            arrayFacNew[i] = rootDas["fchlist"][i];
        }
        for(int i = 0 ;i < param->fchcount; i++)
        {
            arrayFacNew[i]["stationid"]      = Json::Value(param->fchparams[i].stationid);
        //    arrayFacNew[i]["stationid"]      = Json::Value(1);//一拖N再修改
            //根据facname来匹配fid
//            for ( int j = 0; j < 1024 ; j++)
//            {
//                CString str2;
//                str2.Format("%s",ItemName[j].item_name);
//                if ( m_Factorpage.s_FactorInfo[i].sFacName == str2)
//                {
//                    m_Factorpage.s_FactorInfo[i].sFacFid.Format("%s",ItemName[j].item_id);
//                    break;
//                }
//            }
            arrayFacNew[i]["fid"]	         = Json::Value(param->fchparams[i].fid);
            arrayFacNew[i]["devname"]        = Json::Value(param->fchparams[i].devname);
            arrayFacNew[i]["channel"]        = Json::Value(param->fchparams[i].channel);
            arrayFacNew[i]["unit"]			 = Json::Value(param->fchparams[i].unit);
            if (param->fchparams[i].rangeflag == false)
            {
                arrayFacNew[i]["rangeflag"]      = Json::Value(false);
                arrayFacNew[i]["devmin"]		 = Json::Value(0.0);
                arrayFacNew[i]["devmax"]		 = Json::Value(0.0);
                arrayFacNew[i]["rangemin"]		 = Json::Value(0.0);
                arrayFacNew[i]["rangemax"]		 = Json::Value(0.0);
            }
            else
            {
                arrayFacNew[i]["rangeflag"]      = Json::Value(true);
                arrayFacNew[i]["devmin"]		 = Json::Value(param->fchparams[i].devmin);
                arrayFacNew[i]["devmax"]		 = Json::Value(param->fchparams[i].devmax);
                arrayFacNew[i]["rangemin"]		 = Json::Value(param->fchparams[i].rangemin);
                arrayFacNew[i]["rangemax"]		 = Json::Value(param->fchparams[i].rangemax);
            }
            if (param->fchparams[i].slopeflag == false)
            {
                arrayFacNew[i]["slopeflag"]		 = Json::Value(false);
                arrayFacNew[i]["slope"]			 = Json::Value(1);
                arrayFacNew[i]["intercept"]      = Json::Value(0.00);
            }
            else
            {
                arrayFacNew[i]["slopeflag"]		 = Json::Value(true);
                arrayFacNew[i]["slope"]			 = Json::Value(param->fchparams[i].slope);
                arrayFacNew[i]["intercept"]      = Json::Value(param->fchparams[i].intercept);
            }

        }

        rootDas["fchlist"].clear();
        for (int i = 0 ;i < param->fchcount ; i++)
        {
            rootDas["fchlist"].append(arrayFacNew[i]);
        }
        ifs.close();

        std::ofstream o_file(cfgpath);
        Json::StyledWriter fw;
        fw.write(rootDas);

        o_file<<fw.write(rootDas);
        o_file.close();
    }
    catch(...)
    {
        m_utrace->write(TRACE_ERROR, "parse main.json except!");
        ret = -7;
    }
    return 0;
}

int uci::readdts(appdts_param* param)
{
	ifstream ifs;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"dts.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value tchlist;
		Json::Value uiotcp;
		Json::Value uiocom;
		
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse dts.json fail!");
			
			ifs.close();
			return -2;
		}

		if (!(root.isMember("tchlist") && root["tchlist"].isArray()))
		{
			ret = -3;
		}

		if (!(root.isMember("uiotcp") && root["uiotcp"].isArray()))
		{
			ret = -4;
		}

		if (!(root.isMember("uiocom") && root["uiocom"].isArray()))
		{
			ret = -5;
		}

		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse dts.json err=%d!", ret);

			ifs.close();
			return ret;
		}
		
		uiocom = root["uiocom"];
		uiotcp = root["uiotcp"];
		tchlist = root["tchlist"];

		param->tchcount = gettchlist(tchlist, param->tchparams, DTS_TCH_MAXNUM);
		param->uiotcpcount = getuiotcp(uiotcp, param->uiotcpparams, DTS_UIOPHYCOM_MAXNUM);
		param->uiocomcount = getuiocom(uiocom, param->uiocomparams, DTS_UIOPHYTCPC_MAXNUM);
		
		param->param.reserve = 0;
	    
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse dts.json except!");
		ret = -6;
	}

	if (ifs.is_open())
	{
		ifs.close();
	}
    

    return ret;
}

int uci::writedts(appdts_param* param)
{
    ifstream ifs;
    int ret = 0;
    char cfgpath[DM_FILEPATH_SIZE];


    strcpy(cfgpath, m_appdir);
    strcat(cfgpath, USS_APPDIR_CFG);
    strcat(cfgpath,"dts.json");

    try
    {
        ifs.open(cfgpath);
        if (!ifs.is_open())
        {
            m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);
            return -1;
        }
        Json::Reader readerDts;
        Json::Value rootDts;
        if (!readerDts.parse(ifs, rootDts,false))
        {
            m_utrace->write(TRACE_ERROR, "parse main.json fail!");
            ifs.close();
            return -2;
        }
        //trans
        Json::Value arrayTrans = rootDts["tchlist"];
        Json::Value arrayTransNew;
        for(int i = 0; i < param->tchcount; i++)
        {
            arrayTransNew[i] = rootDts["tchlist"][i];
        }
        for(int i = 0 ;i < param->tchcount ; i++)
        {
            arrayTransNew[i]["stationid"]      = Json::Value(param->tchparams[i].stationid);
            arrayTransNew[i]["protocol"]       = Json::Value(param->tchparams[i].protocol);
            arrayTransNew[i]["inftype"]		   = Json::Value(param->tchparams[i].inftype);
            arrayTransNew[i]["logicname"]      = Json::Value(param->tchparams[i].logicname);
            arrayTransNew[i]["tchid"]	       = Json::Value(param->tchparams[i].tchid);
            arrayTransNew[i]["mn"]		       = Json::Value(param->tchparams[i].mn);
            arrayTransNew[i]["pw"]			   = Json::Value(param->tchparams[i].pw);
            arrayTransNew[i]["minuteint"]	   = Json::Value(param->tchparams[i].minuteint);
            arrayTransNew[i]["rtdint"]		   = Json::Value(param->tchparams[i].rtdint);
            arrayTransNew[i]["delaytime"]	   = Json::Value(param->tchparams[i].delaytime);
            arrayTransNew[i]["retranstime"]	   = Json::Value(param->tchparams[i].retranstime);
            arrayTransNew[i]["flowunit"]	   = Json::Value(param->tchparams[i].flowunit);
        }

        rootDts["tchlist"].clear();
        for (int i = 0 ;i < param->tchcount ; i++)
        {
            rootDts["tchlist"].append(arrayTransNew[i]);
        }
        //COM
        Json::Value arrayTransCOM = rootDts["uiocom"];
        Json::Value arrayTransCOMNew;
        for(int i = 0; i < param->uiocomcount; i++)
        {
            arrayTransCOMNew[i] = rootDts["uiocom"][i];
        }
        for(int i = 0 ;i < param->uiocomcount; i++)
        {
            arrayTransCOMNew[i]["logicname"]       = Json::Value(param->uiocomparams[i].logicname);
            arrayTransCOMNew[i]["phyname"]		  = Json::Value(param->uiocomparams[i].phyname);
            arrayTransCOMNew[i]["baud_rate"]	      = Json::Value(param->uiocomparams[i].param.baud_rate);
            arrayTransCOMNew[i]["byte_size"]       = Json::Value(param->uiocomparams[i].param.byte_size);
            arrayTransCOMNew[i]["parity"]		  = Json::Value(param->uiocomparams[i].param.parity);
            arrayTransCOMNew[i]["stop_bits"]       = Json::Value(param->uiocomparams[i].param.stop_bits);
        }

        rootDts["uiocom"].clear();
        for (int i = 0 ;i < param->uiocomcount ; i++)
        {
            rootDts["uiocom"].append(arrayTransCOMNew[i]);
        }
        //net
        Json::Value arrayTransNET = rootDts["uiotcp"];
        Json::Value arrayTransNETNew;
        for(int i = 0; i < param->uiotcpcount; i++)
        {
            arrayTransNETNew[i] = rootDts["uiotcp"][i];
        }
        for(int i = 0 ;i < param->uiotcpcount ; i++)
        {
            arrayTransNETNew[i]["logicname"]    = Json::Value(param->uiotcpparams[i].logicname);
            arrayTransNETNew[i]["host"]		   = Json::Value(param->uiotcpparams[i].param.host);
            arrayTransNETNew[i]["port"]	       = Json::Value(param->uiotcpparams[i].param.port);
        }

        rootDts["uiotcp"].clear();
        for (int i = 0 ;i < param->uiotcpcount ; i++)
        {
            rootDts["uiotcp"].append(arrayTransNETNew[i]);
        }

        ifs.close();

        std::ofstream o_file(cfgpath);
        Json::StyledWriter fw;
        fw.write(rootDts);

        o_file<<fw.write(rootDts);
        o_file.close();
    }
    catch(...)
    {
        m_utrace->write(TRACE_ERROR, "parse main.json except!");
        ret = -7;
    }
	return 0;
}

int uci::readdpc(appdpc_param* param)
{
	dpcparam readcfg;
	ifstream ifs;
	char cfgpath[DM_FILEPATH_SIZE];
	int ret = 0;
	int count = 0;

	memset(&readcfg, 0, sizeof(readcfg));


	readcfg.rtdint = 60;
	readcfg.minuteint = 10;
    
    	param->param = readcfg;

	/*read dpc config*/
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"dpc.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;

		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse dpc.json fail!");

		    	ifs.close();
			return -2;
		}

              UCI_DEFAULT_GETINT(readcfg.minuteint, root, minuteint, 0, 10);
              UCI_DEFAULT_GETINT(readcfg.rtdint, root, rtdint, 0, 60);
       
           	param->param = readcfg;

	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse dpc.json except!");
		ret = -7;
	}

	if (ifs.is_open())
	{
	    ifs.close();
	}
        
	return ret;
}

int uci::writedpc(appdpc_param* param)
{
    dpcparam readcfg;
    ifstream ifs;
    char cfgpath[DM_FILEPATH_SIZE];
    int ret = 0;

    memset(&readcfg, 0, sizeof(readcfg));

    /*read dpc config*/
    strcpy(cfgpath, m_appdir);
    strcat(cfgpath, USS_APPDIR_CFG);
    strcat(cfgpath,"dpc.json");
    try
    {
        ifs.open(cfgpath);
        if (!ifs.is_open())
        {
            m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);
            return -1;
        }
        Json::Reader readerDPC;
        Json::Value rootDPC;
        if (!readerDPC.parse(ifs, rootDPC,false))
        {
            m_utrace->write(TRACE_ERROR, "parse main.json fail!");
            ifs.close();
            return -2;
        }
        //instid
        //rootDPC["instid"] =  Json::Value(param->param.avgpolicy);

        //minuteint
        rootDPC["minuteint"] =  Json::Value(param->param.minuteint);

        //rtdint
        rootDPC["rtdint"] =  Json::Value(param->param.rtdint);

        ifs.close();

        std::ofstream o_file(cfgpath);
        Json::StyledWriter fw;
        fw.write(rootDPC);

        o_file<<fw.write(rootDPC);
        o_file.close();
    }
    catch(...)
    {
        m_utrace->write(TRACE_ERROR, "parse main.json except!");
        ret = -7;
    }
    return 0;
}

int uci::readmain(appmain_param* param)
{
	ifstream ifs;
    appmain_param mainparam;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	/*read main config*/
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"main.json");

    memset(&mainparam, 0 ,sizeof(mainparam));

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value sitelist;
		Json::Value db;
        
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse main.json fail!");

			ifs.close();
			return -2;
		}

		/*read sitelist params*/
		if (!(root.isMember("sitelist") && root["sitelist"].isArray()))
		{
			ret = -3;
		}

		if (!(root.isMember("db") && root["db"].isObject()))
		{
			ret = -4;
		}

		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse main.json err=%d!", ret);

			ifs.close();
			return ret;			
		}
		
		db = root["db"];
		sitelist = root["sitelist"];

		getdb(db, &mainparam.dbparam);
		mainparam.mnodecount = getsitelist(sitelist, mainparam.mnodeparams, DM_SITE_MAXNUM);

              UCI_DEFAULT_GETSTR(mainparam.model, root, model, 0,  "");
              UCI_DEFAULT_GETSTR(mainparam.name, root, name, 0,  "");
              UCI_DEFAULT_GETBOOL(mainparam.usecmdserver, root, usecmdserver, 0,  false);
              UCI_DEFAULT_GETINT(mainparam.cmdport, root, cmdport, 0, 9300);
              UCI_DEFAULT_GETSTR(mainparam.dbmode, root, dbmode, 0,  "");
              
              *param = mainparam;
              
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse main.json except!");

		ret = -7;
	}

	if (ifs.is_open())
	{
	    ifs.close();
	}
    

    return ret;
}

int uci::writemain(appmain_param* param)
{
    ifstream ifsMain;
    appmain_param mainparam;
    int ret = 0;
    char cfgpath[DM_FILEPATH_SIZE];


    /*read main config*/
    strcpy(cfgpath, m_appdir);
    strcat(cfgpath, USS_APPDIR_CFG);
    strcat(cfgpath,"main.json");

    memset(&mainparam, 0 ,sizeof(mainparam));
    try
    {
        ifsMain.open(cfgpath);
        if (!ifsMain.is_open())
        {
            m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);
            return -1;
        }
        Json::Reader readerMAIN;
        Json::Value rootMAIN;
        if (!readerMAIN.parse(ifsMain, rootMAIN,false))
        {
            m_utrace->write(TRACE_ERROR, "parse main.json fail!");
            ifsMain.close();
            return -2;
        }
        //name
        rootMAIN["name"] =  Json::Value(param->name);

        //model
        rootMAIN["model"] =  Json::Value(param->model);
//        int m_sysid = param->mnodeparams[0].sysid;
//        if ( m_sysid == 31)
//        {
//            rootMAIN["model"] =  Json::Value("cems");
//        }
//        else if ( m_sysid == 22 || m_sysid == 39 || m_sysid == 99 || m_sysid == 100 || m_sysid == 101)
//        {
//            rootMAIN["model"] =  Json::Value("aqms");
//        }
//        else if ( m_sysid == 21 || m_sysid == 32 || m_sysid == 33 || m_sysid == 34)
//        {
//            rootMAIN["model"] =  Json::Value("wms");
//        }
//        else if ( m_sysid == 102)
//        {
//            rootMAIN["model"] =  Json::Value("vocs");
//        }

        //sitelist  (stationid) sysid avgmode
        Json::Value arraySite = rootMAIN["sitelist"];
        Json::Value arraySiteNew;
        unsigned int i;
        for( i = 0; i < param->mnodecount; i++)
        {
            arraySiteNew[i] = rootMAIN["sitelist"][i];
        }

        for ( i = 0; i < param->mnodecount; i++)
        {
            arraySiteNew[i]["name"]			= Json::Value(param->mnodeparams[i].name);
            arraySiteNew[i]["stationid"]    = Json::Value(param->mnodeparams[i].stationid);
            arraySiteNew[i]["sysid"] = Json::Value(param->mnodeparams[i].sysid);
        }
        rootMAIN["sitelist"].clear();
        for ( i = 0; i < param->mnodecount; i++)
        {
            rootMAIN["sitelist"].append(arraySiteNew[i]);
        }

//        arraySiteNew[i]["avgmode"]		= Json::Value(_ttoi(m_Stationpage.s_StationInfo[i].sStationAvgMode));


        //db
        Json::Value arraySQL = rootMAIN["db"];
        Json::Value arraySQLNew;

        arraySQLNew["host"] = Json::Value(param->dbparam.server_name);
        arraySQLNew["port"] = Json::Value(param->dbparam.server_port);
        arraySQLNew["user"] = Json::Value(param->dbparam.user_name);
        arraySQLNew["password"] = Json::Value(param->dbparam.user_passwd);
        arraySQLNew["database"] = Json::Value(param->dbparam.db_name);

        rootMAIN["db"].clear();
        rootMAIN["db"] = Json::Value(arraySQLNew);

        ifsMain.close();

        std::ofstream o_file(cfgpath);
        Json::StyledWriter fw;
        fw.write(rootMAIN);

        o_file<<fw.write(rootMAIN);
        o_file.close();
    }
    catch(...)
    {
        m_utrace->write(TRACE_ERROR, "parse main.json except!");
        ret = -7;
    }
	return 0;
}

int uci::readcems(appcems_param* param)
{

	ifstream ifs;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"cems.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value systemlist;
		Json::Value modelnodelist;
		
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse cems.json fail!");
			
			ifs.close();
			return -2;
		}

		if (!(root.isMember("systemlist") && root["systemlist"].isArray()))
		{
			ret = -3;
		}

		if (!(root.isMember("modelnodelist") && root["modelnodelist"].isArray()))
		{
			ret = -4;
		}

		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse cems.json err=%d!", ret);

			ifs.close();
			return ret;
		}
		
		systemlist = root["systemlist"];
		modelnodelist = root["modelnodelist"];
		param->systemcount = getcemslist(systemlist, param->systemparams, DM_SYSTEM_MAXNUM);
		param->modelnodecount = getcemsmnodelist(modelnodelist, param->modelnodeparams, DM_SITE_MAXNUM);
	    
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse cems.json except!");
		ret = -6;
	}

	if (ifs.is_open())
	{
		ifs.close();
	}
    

    return ret;
}

int uci::writecems(appcems_param* param)
{
	return 0;
}

int uci::readwms(appwms_param* param)
{
	ifstream ifs;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"wms.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value systemlist;
		Json::Value modelnodelist;
		
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse cems.json fail!");
			
			ifs.close();
			return -2;
		}

		if (!(root.isMember("systemlist") && root["systemlist"].isArray()))
		{
			ret = -3;
		}

		if (!(root.isMember("modelnodelist") && root["modelnodelist"].isArray()))
		{
			ret = -4;
		}

		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse cems.json err=%d!", ret);

			ifs.close();
			return ret;
		}
		
		systemlist = root["systemlist"];
		modelnodelist = root["modelnodelist"];
		param->systemcount = getwmslist(systemlist, param->systemparams, DM_SYSTEM_MAXNUM);
		param->modelnodecount = getmnodelist(modelnodelist, param->modelnodeparams, DM_SITE_MAXNUM);
	    
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse cems.json except!");
		ret = -6;
	}

	if (ifs.is_open())
	{
		ifs.close();
	}
    

    return ret;
}

int uci::writewms(appwms_param* param)
{
	return 0;
}

int uci::readdcs(appdcs_param* param)
{
	ifstream ifs;
       appdcs_param dcsparam;
	int ret = 0;
	char cfgpath[DM_FILEPATH_SIZE];

    
	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"dcs.json");

       memset(&dcsparam, 0 ,sizeof(dcsparam));
       dcsparam.fchcount = 0;
       dcsparam.dcsmode[0] = 0;
       
       *param = dcsparam;
        
	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
		Json::Value fchlist;
		
		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse dcs.json fail!");
			
			ifs.close();

			return -2;
		}

		if (!(root.isMember("fchlist") && root["fchlist"].isArray()))
		{
			ret = -3;
		}


		if (ret != 0)
		{
			m_utrace->write(TRACE_ERROR, "parse dcs.json err=%d!", ret);
			
			ifs.close();
			return ret;
		}

		if (!(root.isMember("dcsmode") && root["dcsmode"].isString()))
		{
			m_utrace->write(TRACE_ERROR, "parse das.dcsmode fail!");
			strcpy(dcsparam.dcsmode, "");
		}
		else
		{
        	        strncpy(dcsparam.dcsmode, root["dcsmode"].asCString(), sizeof(dcsparam.dcsmode)-1);
		}

		fchlist = root["fchlist"];
		
		dcsparam.fchcount = getfchlist(fchlist, dcsparam.fchparams, DAS_FCH_MAXNUM);
		
	       *param = dcsparam;
	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse dcs.json except!");
		
		ret = -7;

	}

	if (ifs.is_open())
	{
		ifs.close();
	}
    

    return ret;
}

int uci::writedcs(appdcs_param* param)
{
    return 0;
}

int uci::readprop(appprop_param* param)
{
	appprop_param readcfg;
	ifstream ifs;
	char cfgpath[DM_FILEPATH_SIZE];
	int ret = 0;
	int count = 0;

	memset(&readcfg, 0, sizeof(readcfg));

	readcfg.cpmode[0] = 0;
	readcfg.avgpolicy = DM_AVGCALC_POLICY_MEM;
	readcfg.avgcalc = true;
	readcfg.rtdroute = false;
	readcfg.rulealarm = false;
	readcfg.rulecalc = false;
	readcfg.ufidflag = false;
	readcfg.qcflag = false;

    	readcfg.timemode = DM_DATA_TIMEMODE_NORMAL;
       readcfg.periodcount = 0;
       readcfg.avgmode = DM_AVGCALC_MODE_NORMAL;
       
   	*param = readcfg;

	strcpy(cfgpath, m_appdir);
	strcat(cfgpath, USS_APPDIR_CFG);
	strcat(cfgpath,"prop.json");

	try
	{
		ifs.open(cfgpath);

		if (!ifs.is_open())
		{
			m_utrace->write(TRACE_ERROR, "open %s fail!", cfgpath);

			return -1;
		}

		Json::Reader reader;
		Json::Value root;
    		Json::Value periodset;

		if (!reader.parse(ifs, root, false))
		{
			m_utrace->write(TRACE_ERROR, "parse prop.json fail!");

		    	ifs.close();
			return -2;
		}

              UCI_DEFAULT_GETINT(readcfg.timemode, root, timemode, 0, DM_DATA_TIMEMODE_NORMAL);

              UCI_DEFAULT_GETINT(readcfg.avgpolicy, root, avgpolicy, 0, DM_AVGCALC_POLICY_MEM);
              UCI_DEFAULT_GETSTR(readcfg.cpmode, root, cpmode, 0, "");
              UCI_DEFAULT_GETBOOL(readcfg.rtdroute, root, rtdroute, 0,  false);
              UCI_DEFAULT_GETBOOL(readcfg.rulealarm, root, rulealarm, 0,  false);
              UCI_DEFAULT_GETBOOL(readcfg.rulecalc, root, rulecalc, 0,  false);
              UCI_DEFAULT_GETBOOL(readcfg.qcflag, root, qcflag, 0,  false);
              UCI_DEFAULT_GETBOOL(readcfg.avgcalc, root, avgcalc, 0,  true);
              
              UCI_DEFAULT_GETSTR(readcfg.project, root, project, 0, "");
              UCI_DEFAULT_GETINT(readcfg.avgmode, root, avgmode, 0, DM_AVGCALC_MODE_NORMAL);


		if (!(root.isMember("periodset") && root["periodset"].isArray()))
		{
			m_utrace->write(TRACE_ERROR, "parse prop.periodset fail!");
			readcfg.periodcount = 0;
		}
		else
    		{
                  periodset = root["periodset"];
    		    readcfg.periodcount = getperiodset(periodset, readcfg.periodset, DM_FACTORPERIOD_MAXNUM);
              }
              
              /*如果timemode是正常模式，则不处理周期数据*/
              if (readcfg.timemode == DM_DATA_TIMEMODE_NORMAL)
              {
			readcfg.periodcount = 0;
              }
        
           	*param = readcfg;

	}
	catch(...)
	{
		m_utrace->write(TRACE_ERROR, "parse prop.json except!");
		ret = -7;
	}

	if (ifs.is_open())
	{
	    ifs.close();
	}
        
	return ret;
}

int uci::writeprop(appprop_param* param)
{
    return 0;
}
    
int uci::getdb(Json::Value& db, dbcont_param* dbparam)
{
	dbcont_param dbcfg = {"127.0.0.1", "zendb", "root", "zeei", 3306};

        UCI_DEFAULT_GETINT(dbcfg.server_port, db, port, 0, 3306);
        UCI_DEFAULT_GETSTR(dbcfg.server_name, db, host, 0, "127.0.0.1");
        UCI_DEFAULT_GETSTR(dbcfg.user_name, db, user, 0, "root");
        UCI_DEFAULT_GETSTR(dbcfg.user_passwd, db, password, 0, "zeei");
        UCI_DEFAULT_GETSTR(dbcfg.db_name, db, database, 0, "zendb");

	
	*dbparam = dbcfg;
	
	return 0;
}

int uci::setdb(Json::Value& db, dbcont_param* dbparam)
{
	
	return 0;
}

int uci::getsitelist(Json::Value& mnodelist, mnode_param* mnodelistparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value siteinfo;
	mnode_param sitecfg;
		
	readcount = mnodelist.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            siteinfo = mnodelist[i];

            UCI_CONTU_GETINT(sitecfg.stationid, siteinfo, stationid, i);
            UCI_CONTU_GETINT(sitecfg.sysid, siteinfo, sysid, i);
            
            UCI_DEFAULT_GETSTR(sitecfg.name, siteinfo, name, i, "");
            //UCI_DEFAULT_GETINT(sitecfg.avgmode, siteinfo, avgmode, i, DM_AVGCALC_MODE_NORMAL);
            sitecfg.avgmode = DM_AVGCALC_MODE_NORMAL;
            
            if (sitecfg.stationid >= DM_SITE_MAXNUM)
            {
                continue;
            }

            mnodelistparam[validcount] = sitecfg;

            validcount++;
	}

	return validcount;
	
}

int uci::setsitelist(Json::Value& mnodelist, mnode_param* mnodelistparam,  int count)
{
	return 0;
}


int uci::getuiocom(Json::Value& uiocomlist, uiocom_param* uiocomlistparam,  int count)
{
    int readcount = 0;
    int validcount = 0;
    Json::Value uiocomch;
    uiocom_param uiocomchparam;

    readcount = uiocomlist.size();

    for(int i=0; i<readcount; i++)
    {
        if (validcount >= count)
        {
            break;
        }

        uiocomch = uiocomlist[i];

        UCI_CONTU_GETSTR(uiocomchparam.logicname, uiocomch, logicname, i);
        UCI_CONTU_GETSTR(uiocomchparam.phyname, uiocomch, phyname, i);
        UCI_CONTU_GETINT(uiocomchparam.param.baud_rate, uiocomch, baud_rate, i);
        UCI_CONTU_GETINT(uiocomchparam.param.byte_size, uiocomch, byte_size, i);
        UCI_CONTU_GETINT(uiocomchparam.param.parity, uiocomch, parity, i);
        UCI_CONTU_GETINT(uiocomchparam.param.stop_bits, uiocomch, stop_bits, i);

        uiocomlistparam[validcount] = uiocomchparam;

        validcount++;
    	
    }

    return validcount;
}

int uci::setuiocom(Json::Value& uiocomlist, uiocom_param* uiocomlistparam,  int count)
{
	return 0;
}

int uci::getuiotcp(Json::Value& uiotcplist, uiotcp_param* uiotcplistparam,  int count)
{
    int readcount = 0;
    int validcount = 0;
    Json::Value uiotcpch;
    uiotcp_param uiotcpchparam;

    readcount = uiotcplist.size();

    for(int i=0; i<readcount; i++)
    {
        if (validcount >= count)
        {
        	break;
        }
        	
        uiotcpch = uiotcplist[i];

        UCI_CONTU_GETSTR(uiotcpchparam.logicname, uiotcpch, logicname, i);
        UCI_CONTU_GETSTR(uiotcpchparam.param.host, uiotcpch, host, i);
        UCI_CONTU_GETINT(uiotcpchparam.param.port, uiotcpch, port, i);
        UCI_DEFAULT_GETBOOL(uiotcpchparam.param.udpflag, uiotcpch, udpflag, i, false);

        uiotcplistparam[validcount] = uiotcpchparam;
    	
        validcount++;
    }

    return validcount;
}


int uci::setuiotcp(Json::Value& uiotcplist, uiotcp_param* uiotcplistparam,  int count)
{
	return 0;
}


int uci::getdevlist(Json::Value& devlist, dev_param* devlistparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	
	dev_param devparam;
	Json::Value devinfo;
	
	readcount = devlist.size();
            
	for(int i=0; i<readcount; i++)
	{
		if (validcount >= count)
		{
			break;
		}
			
		devinfo = devlist[i];
		memset(&devparam, 0 ,sizeof(devparam));
        
              UCI_CONTU_GETSTR(devparam.logicname, devinfo, logicname, i);
              UCI_CONTU_GETSTR(devparam.name, devinfo, name, i);
              UCI_CONTU_GETSTR(devparam.model, devinfo, model, i);
              UCI_CONTU_GETSTR(devparam.protocol, devinfo, protocol, i);
              UCI_CONTU_GETINT(devparam.devperiod, devinfo, devperiod, i);
              UCI_CONTU_GETINT(devparam.inftype, devinfo, inftype, i);
              UCI_CONTU_GETINT(devparam.devtype, devinfo, devtype, i);
              UCI_CONTU_GETINT(devparam.capacity, devinfo, capacity, i);
              UCI_CONTU_GETINT(devparam.addr, devinfo, addr, i);

		devlistparam[validcount] = devparam;
		validcount++;

	}

	return validcount;
}

int uci::setdevlist(Json::Value& devlist, dev_param* devlistparam,  int count)
{
	return 0;
}

int uci::getfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	
	fch_param fchparam;
	Json::Value fchinfo;
	
	readcount = fchlist.size();

	for(int i=0; i<readcount; i++)
	{
		if (validcount >= count)
		{
			break;
		}
		
		fchinfo = fchlist[i];
    		memset(&fchparam, 0 ,sizeof(fchparam));

              UCI_CONTU_GETSTR(fchparam.fid, fchinfo, fid, i);
              UCI_CONTU_GETSTR(fchparam.devname, fchinfo, devname, i);
              //UCI_CONTU_GETSTR(fchparam.name, fchinfo, name, i);
              
              UCI_CONTU_GETBOOL(fchparam.rangeflag, fchinfo, rangeflag, i);
              UCI_CONTU_GETBOOL(fchparam.slopeflag, fchinfo, slopeflag, i);
              
              UCI_CONTU_GETINT(fchparam.channel, fchinfo, channel, i);
              UCI_CONTU_GETINT(fchparam.stationid, fchinfo, stationid, i);
              
              UCI_DEFAULT_GETINT(fchparam.systemid, fchinfo, systemid, i, -1);
              UCI_DEFAULT_GETBOOL(fchparam.rangelimit, fchinfo, rangelimit, i, false);

              UCI_CONTU_GETDOUBLE(fchparam.slope, fchinfo, slope, i);
              UCI_CONTU_GETDOUBLE(fchparam.intercept, fchinfo, intercept, i);
              UCI_CONTU_GETDOUBLE(fchparam.devmin, fchinfo, devmin, i);
              UCI_CONTU_GETDOUBLE(fchparam.devmax, fchinfo, devmax, i);
              UCI_CONTU_GETDOUBLE(fchparam.rangemin, fchinfo, rangemin, i);
              UCI_CONTU_GETDOUBLE(fchparam.rangemax, fchinfo, rangemax, i);
              
              UCI_DEFAULT_GETSTR(fchparam.unit, fchinfo, unit, i, "");

		fchlistparam[validcount] = fchparam;

		validcount++;

	}

	return validcount;
}


int uci::getsysfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	
	fch_param fchparam;
	Json::Value fchinfo;
	
	readcount = fchlist.size();

	for(int i=0; i<readcount; i++)
	{
		if (validcount >= count)
		{
			break;
		}
		
		fchinfo = fchlist[i];
    		memset(&fchparam, 0 ,sizeof(fchparam));

              UCI_CONTU_GETSTR(fchparam.fid, fchinfo, fid, i);
              
              UCI_CONTU_GETBOOL(fchparam.slopeflag, fchinfo, slopeflag, i);
              
              UCI_DEFAULT_GETBOOL(fchparam.rangelimit, fchinfo, rangelimit, i, false);

              UCI_CONTU_GETDOUBLE(fchparam.slope, fchinfo, slope, i);
              UCI_CONTU_GETDOUBLE(fchparam.intercept, fchinfo, intercept, i);
              UCI_CONTU_GETDOUBLE(fchparam.devmin, fchinfo, devmin, i);
              UCI_CONTU_GETDOUBLE(fchparam.devmax, fchinfo, devmax, i);

		fchlistparam[validcount] = fchparam;

		validcount++;

	}

	return validcount;
}

int uci::setfchlist(Json::Value& fchlist, fch_param* fchlistparam,  int count)
{
	return 0;
}
        
int uci::gettchlist(Json::Value& tchlist, dtp_param* tchlistparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	
	dtp_param tchparam;
	Json::Value tchinfo;
	
	readcount = tchlist.size();

        for(int i=0; i<readcount; i++)
        {
            if (validcount >= count)
            {
                break;
            }

            tchinfo = tchlist[i];
            memset(&tchparam, 0 ,sizeof(tchparam));

            UCI_CONTU_GETSTR(tchparam.mn, tchinfo, mn, i);
            UCI_CONTU_GETSTR(tchparam.pw, tchinfo, pw, i);
            UCI_CONTU_GETSTR(tchparam.protocol, tchinfo, protocol, i);
            UCI_CONTU_GETSTR(tchparam.logicname, tchinfo, logicname, i);

            UCI_CONTU_GETINT(tchparam.minuteint, tchinfo, minuteint, i);
            UCI_CONTU_GETINT(tchparam.rtdint, tchinfo, rtdint, i);
            UCI_CONTU_GETINT(tchparam.tchid, tchinfo, tchid, i);
            UCI_CONTU_GETINT(tchparam.stationid, tchinfo, stationid, i);
            UCI_CONTU_GETINT(tchparam.inftype, tchinfo, inftype, i);


            UCI_DEFAULT_GETINT(tchparam.retranstime, tchinfo, retranstime, i, 0);
            UCI_DEFAULT_GETINT(tchparam.delaytime, tchinfo, delaytime, i, 0);
            UCI_DEFAULT_GETSTR(tchparam.flowunit, tchinfo, flowunit, i, "");

            tchlistparam[validcount] = tchparam;

            validcount++;

	}

	return validcount;
}


int uci::settchlist(Json::Value& tchlist, dtp_param* tchlistparam,  int count)
{
	return 0;
}

int uci::getperiodset(Json::Value& periodset, dsm_period* periodsetparam,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value myperiod;
	dsm_period periodparam;
		
	readcount = periodset.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            myperiod = periodset[i];
            
            UCI_CONTU_GETINT(periodparam.devperiod, myperiod, devperiod, i);
            UCI_CONTU_GETSTR(periodparam.fid, myperiod, fid, i);

            periodsetparam[validcount] = periodparam;

            validcount++;
	}

	return validcount;
	
}

int uci::setperiodset(Json::Value& periodset, dsm_period* periodsetparam,  int count)
{
	return 0;
}

int uci::getcemsmnodelist(Json::Value& modelnodelist, cemsmnode_param* modelnodeparams,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value siteinfo;
	cemsmnode_param sitecfg;
		
	readcount = modelnodelist.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            siteinfo = modelnodelist[i];
            memset(&sitecfg, 0, sizeof(sitecfg));
            
            UCI_CONTU_GETINT(sitecfg.stationid, siteinfo, stationid, i);
            UCI_CONTU_GETINT(sitecfg.systemid, siteinfo, systemid, i);
            UCI_CONTU_GETINT(sitecfg.antiblowint, siteinfo, antiblowint, i);
            UCI_CONTU_GETINT(sitecfg.antiblowtime, siteinfo, antiblowtime, i);
            UCI_CONTU_GETINT(sitecfg.pressuremode, siteinfo, pressuremode, i);
            UCI_CONTU_GETDOUBLE(sitecfg.dilutionratio, siteinfo, dilutionratio, i);
            UCI_CONTU_GETDOUBLE(sitecfg.sectionarea, siteinfo, sectionarea, i);
            UCI_CONTU_GETDOUBLE(sitecfg.pitottube_k, siteinfo, pitottube_k, i);
            UCI_CONTU_GETDOUBLE(sitecfg.speed_k, siteinfo, speed_k, i);
            UCI_CONTU_GETDOUBLE(sitecfg.molecularweight, siteinfo, molecularweight, i);

            UCI_CONTU_GETSTR(sitecfg.epcmodule, siteinfo, epcmodule, i);
            UCI_DEFAULT_GETSTR(sitecfg.antiblowprobe, siteinfo, antiblowprobe, i, "");
            UCI_DEFAULT_GETSTR(sitecfg.antiblowpitot, siteinfo, antiblowpitot, i, "");
            UCI_DEFAULT_GETINT(sitecfg.antiblowch, siteinfo, antiblowch, i, -1);
            UCI_CONTU_GETINT(sitecfg.so2calich, siteinfo, so2calich, i);
            UCI_CONTU_GETINT(sitecfg.noxcalich, siteinfo, noxcalich, i);
            UCI_CONTU_GETINT(sitecfg.zerocalich, siteinfo, zerocalich, i);
            UCI_CONTU_GETINT(sitecfg.samplech, siteinfo, samplech, i);
                        
            UCI_CONTU_GETBOOL(sitecfg.humidityagent, siteinfo, humidityagent, i);
            UCI_CONTU_GETBOOL(sitecfg.o2ratioagent, siteinfo, o2ratioagent, i);
            UCI_CONTU_GETDOUBLE(sitecfg.humidity, siteinfo, humidity, i);
            UCI_CONTU_GETDOUBLE(sitecfg.o2ratio, siteinfo, o2ratio, i);
            
            UCI_CONTU_GETBOOL(sitecfg.stopboiler, siteinfo, stopboiler, i);
            UCI_CONTU_GETINT(sitecfg.stopfactormode, siteinfo, stopfactormode, i);
            UCI_CONTU_GETDOUBLE(sitecfg.stopspeed, siteinfo, stopspeed, i);
            UCI_CONTU_GETDOUBLE(sitecfg.stopo2ratio, siteinfo, stopo2ratio, i);
            UCI_CONTU_GETDOUBLE(sitecfg.stoptemperature, siteinfo, stoptemperature, i);
   
            
            if (sitecfg.stationid >= DM_SITE_MAXNUM)
            {
                continue;
            }

            modelnodeparams[validcount] = sitecfg;

            validcount++;
	}

	return validcount;
	
}

int uci::setcemsmnodelist(Json::Value& modelnodelist, cemsmnode_param* modelnodeparams,  int count)
{
	return 0;
}

int uci::getcemslist(Json::Value& systemlist, cems_param* systemparams,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value cemsinfo;
       Json::Value fchlist;
	cems_param cemsparam;
		
	readcount = systemlist.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            cemsinfo = systemlist[i];
            
            UCI_CONTU_GETINT(cemsparam.systemid, cemsinfo, systemid, i);
            UCI_CONTU_GETINT(cemsparam.measuretype, cemsinfo, measuretype, i);
            UCI_CONTU_GETINT(cemsparam.measuerint, cemsinfo, measuerint, i);
            
            UCI_CONTU_GETDOUBLE(cemsparam.airexcess_k, cemsinfo, airexcess_k, i);
            UCI_CONTU_GETDOUBLE(cemsparam.pressureratiolimit, cemsinfo, pressureratiolimit, i);
            UCI_CONTU_GETDOUBLE(cemsparam.localpressure, cemsinfo, localpressure, i);
            
            UCI_CONTU_GETBOOL(cemsparam.localpressureagent, cemsinfo, localpressureagent, i);
            UCI_CONTU_GETSTR(cemsparam.name, cemsinfo, name, i);

            fchlist = cemsinfo["fchlist"];
            cemsparam.fchcount= getsysfchlist(fchlist, cemsparam.fchparams, DAS_SYSTEMFID_MAXNUM);
            
            systemparams[validcount] = cemsparam;

            validcount++;
	}

	return validcount;
	
}

int uci::setcemslist(Json::Value& systemlist, cems_param* systemparams,  int count)
{
	return 0;
}


int uci::getwmslist(Json::Value& systemlist, wms_param* systemparams,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value wmsinfo;
	wms_param wmsparam;
		
	readcount = systemlist.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            wmsinfo = systemlist[i];
            
            memset(&wmsparam, 0, sizeof(wmsparam));

            UCI_CONTU_GETINT(wmsparam.systemid, wmsinfo, systemid, i);
            UCI_CONTU_GETINT(wmsparam.measuretype, wmsinfo, measuretype, i);
            UCI_CONTU_GETINT(wmsparam.measuerint, wmsinfo, measuerint, i);
            UCI_CONTU_GETINT(wmsparam.measuertime, wmsinfo, measuertime, i);
            UCI_CONTU_GETSTR(wmsparam.name, wmsinfo, name, i);
            UCI_CONTU_GETSTR(wmsparam.epcmodule, wmsinfo, epcmodule, i);

            UCI_CONTU_GETBOOL(wmsparam.usemeasuretrig, wmsinfo, usemeasuretrig, i);
            UCI_CONTU_GETINT(wmsparam.trigmode, wmsinfo, trigmode, i);
            UCI_CONTU_GETDOUBLE(wmsparam.trigflowlimt, wmsinfo, trigflowlimt, i);
            UCI_CONTU_GETSTR(wmsparam.trigtimerange, wmsinfo, trigtimerange, i);

            UCI_CONTU_GETBOOL(wmsparam.usesampler, wmsinfo, usesampler, i);
            UCI_CONTU_GETINT(wmsparam.samplemode, wmsinfo, samplemode, i);
            UCI_CONTU_GETDOUBLE(wmsparam.samplequantity, wmsinfo, samplequantity, i);
            UCI_CONTU_GETDOUBLE(wmsparam.samplerate, wmsinfo, samplerate, i);
            UCI_CONTU_GETSTR(wmsparam.sampler, wmsinfo, sampler, i);

            systemparams[validcount] = wmsparam;

            validcount++;
	}

	return validcount;
	
}

int uci::setwmslist(Json::Value& systemlist, wms_param* systemparams,  int count)
{
	return 0;
}

int uci::getmnodelist(Json::Value& modelnodelist, modelnode_param* modelnodeparams,  int count)
{
	int readcount = 0;
	int validcount = 0;
	Json::Value siteinfo;
	modelnode_param sitecfg;
		
	readcount = modelnodelist.size();

	for(int i=0; i<readcount; i++)
	{
            if (validcount >= count)
            {
                break;
            }
            	
            siteinfo = modelnodelist[i];

            memset(&sitecfg, 0, sizeof(sitecfg));
            
            UCI_CONTU_GETINT(sitecfg.stationid, siteinfo, stationid, i);
            UCI_CONTU_GETINT(sitecfg.systemid, siteinfo, systemid, i);
            
            if (sitecfg.stationid >= DM_SITE_MAXNUM)
            {
                continue;
            }

            modelnodeparams[validcount] = sitecfg;

            validcount++;
	}

	return validcount;
	
}

int uci::setmnodelist(Json::Value& modelnodelist, modelnode_param* modelnodeparams,  int count)
{
	return 0;
}


