#include "dsmdqi.h"
#include "dsmt212.h"
dqi::dqi()
{
    m_db = NULL;
}

dqi::~dqi()
{
    if (m_db != NULL)
    {
        delete m_db;
    }
}

int dqi::init(dbcont_param* dbparam)
{
    dbcontsqlite* db = new dbcontsqlite;
    m_db = (dbcont*)db;

    if (m_db == NULL)
    {
        return -1;
    }

    m_db->setparam(dbparam);

    if (m_db->open() != 0)
    {
        return -2;
    }
    return 0;
}

int dqi::loadrtdlast(int stationid, dsm_rtdlast* rtdlast)
{
    dbcont_res res = NULL;
    dbcont_row row;
    dbcont_colval val_ltime;
    dbcont_colval val_data;

    int count = 0;
    int query_ret = 0;
    int max_count = sizeof(rtdlast->rtv_set)/sizeof(ussrtv);

    char sqlbuf[DQI_SQLBUF_SIZE];
    gbt212_pkt pkt;


    sprintf(sqlbuf, "select * from rdms_t_lastdata where Nid=%d order by Time desc", stationid);

    rtdlast->rtv_cnt = 0;

    try{
        res = m_db->query(sqlbuf, NULL, true);
        if (res != NULL)
        {
            count = m_db->getrowcount(res);

            for(int i=0; i<count; i++)
            {
                int rtv_count = 0;
                usstime pkttime;

                row = m_db->fetchrow(res);
                val_ltime = m_db->getcoldata(row, m_db->getcolnr(res, "Time"));

                /*锚1贸?锚卤??脳?D?渭?貌?矛?????渭?锚卤??脳梅?a??矛?锚卤??,铆?锚卤1y??貌貌?a貌貌脳贸卤??眉貌y?e渭?脿煤锚路貌?谩?锚y?Y*/
                if (i == 0)
                {
                    rtdlast->time = val_ltime.val.tm;
                }
                else if (comm_timediff(rtdlast->time, val_ltime.val.tm) != 0)
                {
                    continue;
                }

                val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Data"));

                pkt.data[0] = 0;
                if (gbt212_decode(val_data.var, &pkt) != 0)
                {
                    continue;
                }

                rtv_count = gbt212_unpack_rtd(pkt.data, &pkttime, (rtdlast->rtv_set+rtdlast->rtv_cnt), (max_count-rtdlast->rtv_cnt));

                if (rtv_count > 0)

                {
                    rtdlast->rtv_cnt += rtv_count;
                }

            }
            m_db->closeres(res);
        }
    }
    catch(...)
    {

        query_ret = -1;

        if (res != NULL)
        {
            m_db->closeres(res);
        }
    }

    if ( count== 0)
    {
        query_ret = -1;
    }

    return query_ret;

}
int dqi::loadavgtime(int type,int stationid, QString starttime,QString endtime,usstime* avgtime)
{
    usstime mytime;
    dbcont_res res = NULL;
    int query_ret = 0;
    int count  = 0;
    dbcont_row row;
    dbcont_colval val_time;

    const char* stime = NULL;
    const char* etime = NULL;

    string sstr = starttime.toStdString();
    stime = sstr.c_str();
    string estr = endtime.toStdString();
    etime = estr.c_str();
    char sqlbuf[DQI_SQLBUF_SIZE];
    const char* tablename = NULL;
    switch(type)
    {
    case DM_DATA_R:
        tablename = "rdms_t_data";
        break;
    case DM_AVGTYPE_M:
        tablename = "udms_t_avgminute";
        break;
    case DM_AVGTYPE_H:
        tablename = "udms_t_avghour";
        break;
    case DM_AVGTYPE_D:
        tablename = "udms_t_avgday";
        break;
    case 2041:
        tablename = "udms_t_avgmonth";
        break;
    default:
        break;
    }

    sprintf(sqlbuf, "select * from %s where Nid=%d AND Time >= '%s' AND Time < '%s' order by Time asc", tablename,stationid,stime,etime);
    try{
        res = m_db->query(sqlbuf, NULL, true);
        if (res != NULL)
        {
            count = m_db->getrowcount(res);
            if(count > 0)
            {
                for(int i=0; i<count; i++)
                {
                    row = m_db->fetchrow(res);
                    val_time = m_db->getcoldata(row, m_db->getcolnr(res, "Time"));
                    mytime = val_time.val.tm;
                    avgtime[i] = mytime;
                }
            }
            m_db->closeres(res);
        }
    }
    catch(...)
    {

        query_ret = -1;

        if (res != NULL)
        {
            m_db->closeres(res);
        }
    }
    return count;
}
int dqi::loadavg(int type,int stationid, const usstime& sqltime,dsm_avg* avgresult)
{
    dbcont_res res = NULL;
    int query_ret = 0;
    int count  = 0;
    dbcont_row row;

    dbcont_colval val_data;
    dbcont_colval val_mark;
    dbcont_colval val_inst;
    dbcont_colval val_time;
    dbcont_colval val_gid;
    dbcont_colval val_fid;

    dsm_avg avg_data;

    char sqlbuf[DQI_SQLBUF_SIZE];
    const char* tablename = NULL;
    switch(type)
    {
    case DM_AVGTYPE_M:
        tablename = "udms_t_avgminute";
        break;
    case DM_AVGTYPE_H:
        tablename = "udms_t_avghour";
        break;
    case DM_AVGTYPE_D:
        tablename = "udms_t_avgday";
        break;
    default:
        break;
    }
    char mytime[20]={0};
    sprintf(mytime,"%04d-%02d-%02d %02d:%02d:%02d",sqltime.year,sqltime.month,sqltime.day,
            sqltime.hour,sqltime.minute,sqltime.second);

    sprintf(sqlbuf, "select * from %s where Nid=%d AND Time = '%s' order by Time asc", tablename,stationid,mytime);
    try{
        res = m_db->query(sqlbuf, NULL, true);
        if (res != NULL)
        {
            count = m_db->getrowcount(res);
            if(count > 0)
            {
                for(int i=0; i<count; i++)
                {
                    memset(&avg_data, 0, sizeof(avg_data));
                    row = m_db->fetchrow(res);
                    avg_data.avg_time = sqltime;
                    val_time = m_db->getcoldata(row, m_db->getcolnr(res, "Time"));
                    val_mark = m_db->getcoldata(row, m_db->getcolnr(res, "State"));
                    val_gid = m_db->getcoldata(row, m_db->getcolnr(res, "Gid"));
                    val_fid = m_db->getcoldata(row, m_db->getcolnr(res, "Fid"));
                    val_inst = m_db->getcoldata(row, m_db->getcolnr(res, "Inst"));

                    val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Avg"));
                    avg_data.avg = val_data.val.dou;
                    val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Min"));
                    avg_data.min = val_data.val.dou;
                    val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Max"));
                    avg_data.max = val_data.val.dou;
                    val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Cou"));
                    avg_data.cou = val_data.val.dou;

                    if (val_inst.val.i32 == 0)
                    {
                        sprintf(avg_data.fid, "U%02d%04d", val_gid.val.i32, val_fid.val.i32);
                    }
                    else
                    {
                        sprintf(avg_data.fid, "U%02d%02d%04d", val_inst.val.i32, val_gid.val.i32, val_fid.val.i32);
                    }
                    avg_data.state= (unsigned char)val_mark.val.i32;
                    avg_data.state = (avg_data.state&0x7f);
                    avgresult[i] = avg_data;
                }
            }
            m_db->closeres(res);
        }
    }
    catch(...)
    {

        query_ret = -1;

        if (res != NULL)
        {
            m_db->closeres(res);
        }
    }
    return count;
}

int dqi::loadrtdresult(int type, int stationid, const usstime &sqltime, dsm_rtdresult *result)
{
    dbcont_res res = NULL;
    int query_ret = 0;
    int count  = 0;
    dbcont_row row;

    dbcont_colval val_data;
    dbcont_colval val_mark;
    dbcont_colval val_inst;
    dbcont_colval val_time;
    dbcont_colval val_gid;
    dbcont_colval val_fid;

    ussrtv myrtv;

    char sqlbuf[DQI_SQLBUF_SIZE];
    const char* tablename = "rdms_t_data";
    char mytime[20]={0};
    sprintf(mytime,"%04d-%02d-%02d %02d:%02d:%02d",sqltime.year,sqltime.month,sqltime.day,
            sqltime.hour,sqltime.minute,sqltime.second);

    sprintf(sqlbuf, "select * from %s where Nid=%d AND Time = '%s' order by Time asc", tablename,stationid,mytime);
    try{
        res = m_db->query(sqlbuf, NULL, true);
        if (res != NULL)
        {
            count = m_db->getrowcount(res);
            if(count > 0)
            {
                for(int i=0; i<count; i++)
                {
                    memset(&myrtv, 0, sizeof(myrtv));
                    row = m_db->fetchrow(res);
                    myrtv.dtime = sqltime;
                    val_time = m_db->getcoldata(row, m_db->getcolnr(res, "Time"));
                    val_mark = m_db->getcoldata(row, m_db->getcolnr(res, "State"));
                    val_gid = m_db->getcoldata(row, m_db->getcolnr(res, "Gid"));
                    val_fid = m_db->getcoldata(row, m_db->getcolnr(res, "Fid"));
                    val_inst = m_db->getcoldata(row, m_db->getcolnr(res, "Inst"));

                    val_data = m_db->getcoldata(row, m_db->getcolnr(res, "Value"));
                    myrtv.val = val_data.val.dou;

                    if (val_inst.val.i32 == 0)
                    {
                        sprintf(myrtv.fid, "U%02d%04d", val_gid.val.i32, val_fid.val.i32);
                    }
                    else
                    {
                        sprintf(myrtv.fid, "U%02d%02d%04d", val_inst.val.i32, val_gid.val.i32, val_fid.val.i32);
                    }
                    myrtv.state= (unsigned char)val_mark.val.i32;
                    myrtv.state = (myrtv.state&0x7f);
                    result->rtv_set[i] = myrtv;
                }
            }
            result->rtv_cnt = count;
            m_db->closeres(res);
        }
    }
    catch(...)
    {

        query_ret = -1;

        if (res != NULL)
        {
            m_db->closeres(res);
        }
    }
    return count;
}
