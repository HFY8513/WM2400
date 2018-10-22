#pragma once
#include "global.h"
#include "dsmpub.h"
#include "oss/utils/udbi/dbcont/dbcont.h"
#include "oss/utils/udbi/dbcontsqlite/dbcontsqlite.h"

#define DQI_VAR_STATIC static
#define DQI_SQLBUF_SIZE 0x10000

/*针对不同的数据库,可以建立不同的dqi接口实现类*/
class dqi
{
public:
    dqi();
    virtual ~dqi();
    
    virtual int init(dbcont_param* dbparam);

    int loadrtdlast(int stationid, dsm_rtdlast* rtdlast);
    int loadavgtime(int type,int stationid, QString starttime,QString endtime,usstime* avgtime);
    int loadavg(int type,int stationid, const usstime& sqltime,dsm_avg* avgresult);

    int loadrtdresult(int type,int stationid, const usstime& sqltime,dsm_rtdresult* result);
    
protected:
    dbcont* m_db; 
};

