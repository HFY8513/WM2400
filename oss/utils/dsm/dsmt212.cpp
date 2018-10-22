#include "dsmt212.h"
#include "oss/common/ustr.h"
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*函数返回值表示因子个数*/
int gbt212_unpack_rtd(char* buf, usstime* dtime, ussrtv* item_set, int count)
{
    strarray strs;
    strarray strs_L1;
    strarray strs_L2;
    usstime mytime;
    int time_ret[6] = {0,0,0,0,0,0};

    char* p = NULL;
    char* outer_ptr = NULL;
    int loop;

    p = buf;
    
    outer_ptr = strstr(p, ";");

    if (outer_ptr == NULL)
    {
        return -2;
    }

    outer_ptr[0] = 0;
    outer_ptr++;
    /*if (6 != sscanf(p,"DataTime=%4d%2d%2d%2d%2d%2d", &mytime.year, &mytime.month, &mytime.day,
        &mytime.hour, &mytime.minute, &mytime.second))*/
    if (6 != sscanf(p,"DataTime=%4d%2d%2d%2d%2d%2d", &time_ret[0], &time_ret[1], &time_ret[2], 
        &time_ret[3], &time_ret[4], &time_ret[5]))
    {
        memset(dtime, 0, sizeof(usstime));
        return -3;
    }
    mytime.year = time_ret[0];
    mytime.month= time_ret[1];
    mytime.day= time_ret[2];
    mytime.hour = time_ret[3];
    mytime.minute= time_ret[4];
    mytime.second = time_ret[5];        
    *dtime = mytime;
    
    strs.num = 0;
    
    comm_divstr(outer_ptr, ";", &strs);

    if (strs.num <= 0)
    {
        return 0;
    }
    
    if (strs.num > count)
    {
        strs.num = count;
    }
    
    for (loop=0; loop<strs.num;loop++)
    {
        strs_L1.num = 0;
        comm_divstr(strs.ptr[loop], ",", &strs_L1);

        /*未考虑-ZsRtd折算值，如果考虑还应有strs_L1.num == 3*/
        if ((strs_L1.num >= 1) && (strs_L1.num <= 3))
        {
            strs_L2.num = 0;
            comm_divstr(strs_L1.ptr[0], "-Rtd=", &strs_L2);

            if (strs_L2.num != 2)
            {
                return -5;
            }
            
            item_set[loop].val =atof(strs_L2.ptr[1]);
            strncpy(item_set[loop].fid, strs_L2.ptr[0], (MAX_DAQ_FIDSIZE-1));
            item_set[loop].fid[MAX_DAQ_FIDSIZE-1]=0;
            
            item_set[loop].state='N';
            item_set[loop].dtime = mytime;

            for(int i=1; i<strs_L1.num; i++)
            {
                strs_L2.num = 0;
                comm_divstr(strs_L1.ptr[i], "-Flag=", &strs_L2);
                if (strs_L2.num == 2)
                {
                    item_set[loop].state=*(strs_L2.ptr[1]);
                    continue;
                }
                
                strs_L2.num = 0;
                comm_divstr(strs_L1.ptr[i], "-Time=", &strs_L2);
                if (strs_L2.num == 2)
                {
                    comm_strtotime(strs_L2.ptr[1], &item_set[loop].dtime);
                    continue;
                }
            }

           
        }
        else
        {
            return -4;
        }
    }

    return strs.num;
}


int gbt212_unpack_avg(char* buf, usstime* dtime, dsm_avg* item_set, int count)
{
    strarray strs;
    strarray strs_L1;
    strarray strs_L2;
    usstime mytime;
    int time_ret[6] = {0,0,0,0,0,0};

    char* p = NULL;
    char* outer_ptr = NULL;
    int loop;

    p = buf;
    
    outer_ptr = strstr(p, ";");

    if (outer_ptr == NULL)
    {
        return -2;
    }

    outer_ptr[0] = 0;
    outer_ptr++;

    if (6 != sscanf(p,"DataTime=%4d%2d%2d%2d%2d%2d", &time_ret[0], &time_ret[1], &time_ret[2], 
        &time_ret[3], &time_ret[4], &time_ret[5]))
    {
        memset(dtime, 0, sizeof(usstime));
        return -3;
    }
    mytime.year = time_ret[0];
    mytime.month= time_ret[1];
    mytime.day= time_ret[2];
    mytime.hour = time_ret[3];
    mytime.minute= time_ret[4];
    mytime.second = time_ret[5];        
    *dtime = mytime;
    
    strs.num = 0;
    
    comm_divstr(outer_ptr, ";", &strs);

    if (strs.num <= 0)
    {
        return 0;
    }
    
    if (strs.num > count)
    {
        strs.num = count;
    }
    
    for (loop=0; loop<strs.num;loop++)
    {
        strs_L1.num = 0;
        comm_divstr(strs.ptr[loop], ",", &strs_L1);

        /*未考虑-Zs折算值*/
        if (!((strs_L1.num == 4) || (strs_L1.num == 5) || (strs_L1.num == 6)))
        {
            return -4;
        }

        memset(&item_set[loop], 0, sizeof(item_set[loop]));

        {
            strs_L2.num = 0;
            comm_divstr(strs_L1.ptr[0], "-Cou=", &strs_L2);

            if (strs_L2.num == 2)
            {
                strncpy(item_set[loop].fid, strs_L2.ptr[0], (MAX_DAQ_FIDSIZE-1));
                item_set[loop].fid[MAX_DAQ_FIDSIZE-1]=0;
                item_set[loop].cou =atof(strs_L2.ptr[1]);
            }

            strs_L2.num = 0;
            comm_divstr(strs_L1.ptr[1], "-Min=", &strs_L2);
            if (strs_L2.num == 2)
            {
                item_set[loop].min=atof(strs_L2.ptr[1]);
            }
            
            strs_L2.num = 0;
            comm_divstr(strs_L1.ptr[2], "-Avg=", &strs_L2);
            if (strs_L2.num == 2)
            {
                item_set[loop].avg=atof(strs_L2.ptr[1]);
            }
            
            strs_L2.num = 0;
            comm_divstr(strs_L1.ptr[3], "-Max=", &strs_L2);
            if (strs_L2.num == 2)
            {
                item_set[loop].max=atof(strs_L2.ptr[1]);
            }
            
            item_set[loop].state='N';

            if (strs_L1.num >= 5)
            {
                strs_L2.num = 0;

                comm_divstr(strs_L1.ptr[4], "-Flag=", &strs_L2);
                if (strs_L2.num == 2)
                {
                    item_set[loop].state=*(strs_L2.ptr[1]);
                }
            }
            
            if (strs_L1.num == 6)
            {
                strs_L2.num = 0;
                comm_divstr(strs_L1.ptr[5], "-Cnt=", &strs_L2);
                if (strs_L2.num == 2)
                {
                    item_set[loop].vaildcount =atoi(strs_L2.ptr[1]);
                }
            }
        }

    }

    return strs.num;
}

int gbt212_unpack_alarmstate(char* buf, usstime* dtime, dsm_alarmlast* alarmlist, dsm_statelast* statelist)
{
    strarray strs;
    strarray strs_L1;
    strarray strs_L2;
    usstime mytime;
    int time_ret[6] = {0,0,0,0,0,0};

    char* p = NULL;
    char* outer_ptr = NULL;
    char* tmp_ptr = NULL;
    int loop;
    int alarm_cnt = 0;
    int state_cnt = 0;

    p = buf;
    outer_ptr = strstr(p, ";");

    if (outer_ptr == NULL)
    {
        return -2;
    }


    outer_ptr[0] = 0;
    outer_ptr++;

    if (6 != sscanf(p,"DataTime=%4d%2d%2d%2d%2d%2d", &time_ret[0], &time_ret[1], &time_ret[2], 
        &time_ret[3], &time_ret[4], &time_ret[5]))
    {
        memset(dtime, 0, sizeof(usstime));
        return -3;
    }
    mytime.year = time_ret[0];
    mytime.month= time_ret[1];
    mytime.day= time_ret[2];
    mytime.hour = time_ret[3];
    mytime.minute= time_ret[4];
    mytime.second = time_ret[5];        
    *dtime = mytime;

        
    strs.num = 0;
    
    comm_divstr(outer_ptr, ";", &strs);

    if (strs.num <= 0)
    {
        return 0;
    }
  
    for (loop=0; loop<strs.num;loop++)
    {
        strs_L1.num = 0;
        comm_divstr(strs.ptr[loop], "=", &strs_L1);

        if (strs_L1.num != 2)
        {
            continue;
        }
        
        strs_L2.num = 0;
        if ((alarmlist != NULL) && (strstr(strs_L1.ptr[0], "-A") != NULL))
        {
            if (alarm_cnt >= DM_ALARM_MAXNUM )
            {
                continue;
            }
                    
            comm_divstr(strs_L1.ptr[0], "-A", &strs_L2);
            
             if (strs_L2.num == 2)
            {
                alarmlist->alarm_set[alarm_cnt].start_time = mytime;
                alarmlist->alarm_set[alarm_cnt].alarm_code = atoi(strs_L2.ptr[1]);
                
                strncpy(alarmlist->alarm_set[alarm_cnt].alarm_str, strs_L1.ptr[1], (DM_DESTEXT_SIZE-1));
                alarmlist->alarm_set[alarm_cnt].alarm_str[DM_DESTEXT_SIZE-1] = 0;   

                strncpy(alarmlist->alarm_set[alarm_cnt].alarm_src, strs_L2.ptr[0], (DM_MODULENAME_SIZE-1));
                alarmlist->alarm_set[alarm_cnt].alarm_src[DM_MODULENAME_SIZE-1] = 0;   

                tmp_ptr = strstr(strs_L1.ptr[1], "Time:");
                if (tmp_ptr != NULL)
                {
                    tmp_ptr += 5;
                    comm_strtotime(tmp_ptr, &alarmlist->alarm_set[alarm_cnt].start_time);
                }

                alarm_cnt++;
            }           
        }
        else if ((statelist != NULL) && (strstr(strs_L1.ptr[0], "-S") !=  NULL))
        {
            if (state_cnt >= DM_STATE_MAXNUM )
            {
                continue;
            }
            
            comm_divstr(strs_L1.ptr[0], "-S", &strs_L2);
            
            if (strs_L2.num == 2)
            {
                statelist->state_set[state_cnt].start_time = mytime;
                statelist->state_set[state_cnt].state_type = atoi(strs_L2.ptr[1]);
                statelist->state_set[state_cnt].state_code = atoi(strs_L1.ptr[1]); 
                
                strncpy(statelist->state_set[state_cnt].state_src, strs_L2.ptr[0], (DM_MODULENAME_SIZE-1));
                statelist->state_set[state_cnt].state_src[DM_MODULENAME_SIZE-1] = 0;   

                tmp_ptr = strstr(strs_L1.ptr[1], "{");

                if (tmp_ptr != NULL)
                {
                    strncpy(statelist->state_set[state_cnt].state_valuetext, tmp_ptr, (DM_DESTEXT_SIZE-1));
                    statelist->state_set[state_cnt].state_valuetext[(DM_DESTEXT_SIZE-1)] = 0;   
                }

                tmp_ptr = strstr(strs_L1.ptr[1], "Time:");
                if (tmp_ptr != NULL)
                {
                    tmp_ptr += 5;
                    comm_strtotime(tmp_ptr, &statelist->state_set[state_cnt].start_time);
                }

                state_cnt++;
            }
        }


    }

    if (statelist != NULL)
    {
        statelist->time = mytime;
        statelist->state_cnt= state_cnt;
    }
    if (alarmlist != NULL)
    {
        alarmlist->time = mytime;
        alarmlist->alarm_cnt= alarm_cnt;
    }

    return (alarm_cnt + state_cnt);
}

int gbt212_unpack_dataarq(gbt212_pkt* pkt, dsm_arqrecord* arqrecord)
{
    dsm_arqrecord record;
    char* cp = pkt->data;
    char* pstarttime = NULL;
    char* pendtime = NULL;
    int period = 0;
    char buf[64];

    pstarttime = strstr(cp, "BeginTime=");
    if (pstarttime == NULL)
    {
        return -1;
    }
    memcpy(buf,pstarttime+10,14);
    buf[14] = 0;
    if (comm_strtotime(buf, &record.start_time) != 0)
    {
        return -1;
    }

    pendtime = strstr(cp, "EndTime=");
    if (pendtime == NULL)
    {
        return -2;
    }
    memcpy(buf,pendtime+8,14);
    buf[14] = 0;
    if (comm_strtotime(buf, &record.end_time) != 0)
    {
        return -2;
    }
/*ljh
    if (comm_timediff(record.end_time, record.start_time) <= 0)
    {
        return -3;
    }*/

    if (pkt->cn == 2051)
    {
        record.data_type = DM_AVGTYPE_M;
    }
    else if (pkt->cn == 2061)
    {
        record.data_type = DM_AVGTYPE_H;
    }
    else if (pkt->cn == 2031)
    {
        record.data_type = DM_AVGTYPE_D;
    }
    else if ((pkt->cn == 2011) || (pkt->cn == 2111))
    {
        record.data_type = DM_DATA_R;
    }
    else
    {
        return -4;
    }

    *arqrecord = record;
    return 0;
}


int gbt212_unpack_ctrl(char* buf, dsm_ctrlreq* ctrlcmd)
{
    char cmdbuf[512];
    char* cmd_ptr = NULL;
    char* param_ptr = NULL;
    
    cmd_ptr = strstr(buf, "=");
    
    if (cmd_ptr == NULL)
    {
        return -1;
    }
        
    memset(ctrlcmd, 0 ,sizeof(dsm_ctrlreq));

    param_ptr = strstr(cmd_ptr, ";");

    if (param_ptr != NULL)
    {
        strncpy(ctrlcmd->inval, param_ptr+1, sizeof(ctrlcmd->inval)-1);
    }
    
    if (sizeof(ctrlcmd->obj) > (cmd_ptr-buf))
    {
        memcpy(ctrlcmd->obj, buf, (cmd_ptr-buf));
    }
    else
    {
        ctrlcmd->obj[0] = 0;
    }
    
    ctrlcmd->cmdid = atoi(cmd_ptr+1);

    return 0;
}

int gbt212_pack_arq(usstime start_time,usstime end_time, char* buf, int len)
{
    sprintf(buf, "BeginTime=%04d%02d%02d%02d%02d%02d,EndTime=%04d%02d%02d%02d%02d%02d",
        start_time.year,start_time.month,start_time.day,start_time.hour,start_time.minute,start_time.second,
        end_time.year,end_time.month,end_time.day,end_time.hour,end_time.minute,end_time.second
        );
    
    return 0;
}

int gbt212_pack_avg(usstime start_time, dsm_avg* cpavg_set, int cpavg_count, char* buf, int len, int* atgid)
{
    int loop;
    int gid = 0;
    
    char lastfid[MAX_DAQ_FIDSIZE];
    char tmpbuf[256];
    dsm_avg items[2];
    bool   zsrtd[2];

    
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        start_time.year,start_time.month,start_time.day,start_time.hour,start_time.minute,start_time.second);

    if (atgid == NULL)
    {
        for(loop=0;loop<cpavg_count;loop++)
        {
            sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-Flag=%c",
                cpavg_set[loop].fid, cpavg_set[loop].cou,
                cpavg_set[loop].fid, cpavg_set[loop].min,
                cpavg_set[loop].fid, cpavg_set[loop].avg,
                cpavg_set[loop].fid, cpavg_set[loop].max,
                cpavg_set[loop].fid, cpavg_set[loop].state
                );
            strcat(buf, tmpbuf);
        }

        return 0;
    }

    lastfid[0] = 0;
    zsrtd[0] = false;
    zsrtd[1] = false;
    memset(items, 0 ,sizeof(items));
    
    /*处理cems带有折算的情况*/
    for(loop=0;loop<cpavg_count;loop++)
    {
        gid = atgid[loop];
        
        if ((gid != 0) && (gid != 1) && (gid != 2))
        {
            continue;
        }

        /*因子变化则处理上一次的因子*/
        if (strcmp(cpavg_set[loop].fid, lastfid) != 0)
        {
            strcpy(lastfid, cpavg_set[loop].fid);
            
            if ((zsrtd[0]) && (zsrtd[1]))
            {
                sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-ZsMin=%.3f,%s-ZsAvg=%.3f,%s-ZsMax=%.3f,%s-Flag=%c",
                    items[0].fid, items[0].cou,
                    items[0].fid, items[0].min,
                    items[0].fid, items[0].avg,
                    items[0].fid, items[0].max,
                    
                    items[1].fid, items[1].min,
                    items[1].fid, items[1].avg,
                    items[1].fid, items[1].max,
                    
                    items[0].fid, items[0].state
                    );
                strcat(buf, tmpbuf);
            }
            else if (zsrtd[0])
            {
                sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-Flag=%c",
                    items[0].fid, items[0].cou,
                    items[0].fid, items[0].min,
                    items[0].fid, items[0].avg,
                    items[0].fid, items[0].max,
                    items[0].fid, items[0].state
                    );
                strcat(buf, tmpbuf);
            }
            
            zsrtd[0] = false;
            zsrtd[1] = false;
        }

        if (gid == 2)
        {
            zsrtd[1] = true;
            items[1] = cpavg_set[loop];
        }
        else
        {
            zsrtd[0] = true;
            items[0] = cpavg_set[loop];
        }

    }

    /*处理最后一个因子的折算*/
    if ((zsrtd[0]) && (zsrtd[1]))
    {
        sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-ZsMin=%.3f,%s-ZsAvg=%.3f,%s-ZsMax=%.3f,%s-Flag=%c",
            items[0].fid, items[0].cou,
            items[0].fid, items[0].min,
            items[0].fid, items[0].avg,
            items[0].fid, items[0].max,
            
            items[1].fid, items[1].min,
            items[1].fid, items[1].avg,
            items[1].fid, items[1].max,
            
            items[0].fid, items[0].state
            );
        strcat(buf, tmpbuf);
    }
    else if (zsrtd[0])
    {
        sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-Flag=%c",
            items[0].fid, items[0].cou,
            items[0].fid, items[0].min,
            items[0].fid, items[0].avg,
            items[0].fid, items[0].max,
            items[0].fid, items[0].state
            );
        strcat(buf, tmpbuf);
    }
    
    return 0;
}

int gbt212_pack_acc(usstime start_time, dsm_avg* cpavg_set, int cpavg_count, char* buf, int len)
{
    int loop;
    char tmpbuf[256];
    
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        start_time.year,start_time.month,start_time.day,start_time.hour,start_time.minute,start_time.second);

    for(loop=0;loop<cpavg_count;loop++)
    {
        sprintf(tmpbuf,";%s-Cou=%.3f,%s-Min=%.3f,%s-Avg=%.3f,%s-Max=%.3f,%s-Flag=%c,%s-Cnt=%d",
            cpavg_set[loop].fid, cpavg_set[loop].cou,
            cpavg_set[loop].fid, cpavg_set[loop].min,
            cpavg_set[loop].fid, cpavg_set[loop].avg,
            cpavg_set[loop].fid, cpavg_set[loop].max,
            cpavg_set[loop].fid, cpavg_set[loop].state,
            cpavg_set[loop].fid, cpavg_set[loop].vaildcount
            );
        strcat(buf, tmpbuf);
    }
    return 0;
}

int gbt212_pack_rtd(usstime dtime, ussrtv* item_set, int count, char* buf, int len, int* atgid)
{
    int loop;
    int gid = 0;
    
    char lastfid[MAX_DAQ_FIDSIZE];
    char tmpbuf[256];
    ussrtv items[2];
    bool   zsrtd[2];
        
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        dtime.year,dtime.month,dtime.day,dtime.hour,dtime.minute,dtime.second);

    if (atgid == NULL)
    {
        for(loop=0;loop<count;loop++)
        {
            sprintf(tmpbuf,";%s-Rtd=%.3f,%s-Flag=%c",
                item_set[loop].fid, item_set[loop].val,
                item_set[loop].fid, item_set[loop].state);
            strcat(buf, tmpbuf);
        }

        return 0;
    }

    

    lastfid[0] = 0;
    zsrtd[0] = false;
    zsrtd[1] = false;
    memset(items, 0 ,sizeof(items));
    
    /*处理cems带有折算的情况*/
    for(loop=0;loop<count;loop++)
    {
        gid = atgid[loop];
        
        if ((gid != 0) && (gid != 1) && (gid != 2))
        {
            continue;
        }

        /*因子变化则处理上一次的因子*/
        if (strcmp(item_set[loop].fid, lastfid) != 0)
        {
            strcpy(lastfid, item_set[loop].fid);
            
            if ((zsrtd[0]) && (zsrtd[1]))
            {
               sprintf(tmpbuf,";%s-Rtd=%.3f,%s-ZsRtd=%.3f,%s-Flag=%c",
                    items[0].fid, items[0].val,
                    items[1].fid, items[1].val,
                    items[0].fid, items[0].state);  
                strcat(buf, tmpbuf);
            }
            else if (zsrtd[0])
            {
                sprintf(tmpbuf,";%s-Rtd=%.3f,%s-Flag=%c",
                    items[0].fid, items[0].val,
                    items[0].fid, items[0].state);
                strcat(buf, tmpbuf);
            }
            
            zsrtd[0] = false;
            zsrtd[1] = false;
        }

        if (gid == 2)
        {
            zsrtd[1] = true;
            items[1] = item_set[loop];
        }
        else
        {
            zsrtd[0] = true;
            items[0] = item_set[loop];
        }

    }

    /*处理最后一个因子的折算*/
    if ((zsrtd[0]) && (zsrtd[1]))
    {
       sprintf(tmpbuf,";%s-Rtd=%.3f,%s-ZsRtd=%.3f,%s-Flag=%c",
            items[0].fid, items[0].val,
            items[1].fid, items[1].val,
            items[0].fid, items[0].state);  
        strcat(buf, tmpbuf);
    }
    else if (zsrtd[0])
    {
        sprintf(tmpbuf,";%s-Rtd=%.3f,%s-Flag=%c",
            items[0].fid, items[0].val,
            items[0].fid, items[0].state);
        strcat(buf, tmpbuf);
    }
            
    return 0;
}


int gbt212_pack_rtd2(usstime dtime,ussrtv* item_set, int count, char* buf, int len, int* atgid)
{
    int loop;
    char tmpbuf[256];
        
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        dtime.year,dtime.month,dtime.day,dtime.hour,dtime.minute,dtime.second);

    if (atgid == NULL)
    {
        for(loop=0;loop<count;loop++)
        {
            sprintf(tmpbuf,";%s-Rtd=%.3f,%s-Flag=%c,%s-Time=%04d%02d%02d%02d%02d%02d",
                item_set[loop].fid, item_set[loop].val,
                item_set[loop].fid, item_set[loop].state,
                item_set[loop].fid, item_set[loop].dtime.year,item_set[loop].dtime.month,item_set[loop].dtime.day,item_set[loop].dtime.hour,item_set[loop].dtime.minute,item_set[loop].dtime.second);
            strcat(buf, tmpbuf);
        }

        return 0;
    }
            
    return 0;
}

int gbt212_pack_origrtd(usstime dtime,ussrtv* item_set, int count, char* buf, int len, int* atgid)
{
    int loop;
    char tmpbuf[256];
        
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        dtime.year,dtime.month,dtime.day,dtime.hour,dtime.minute,dtime.second);

    if (atgid == NULL)
    {
        for(loop=0;loop<count;loop++)
        {
            sprintf(tmpbuf,";%s-Rtd=%.3f,%s-Flag=%c,%s-Time=%04d%02d%02d%02d%02d%02d",
                item_set[loop].fid, item_set[loop].origval,
                item_set[loop].fid, item_set[loop].state,
                item_set[loop].fid, item_set[loop].dtime.year,item_set[loop].dtime.month,item_set[loop].dtime.day,item_set[loop].dtime.hour,item_set[loop].dtime.minute,item_set[loop].dtime.second);
            strcat(buf, tmpbuf);
        }

        return 0;
    }
            
    return 0;
}

int gbt212_pack_fidparams(usstime dtime, ussrtv* item_set, int count, char* buf, int len, int* atgid)
{
    int loop;
    int gid = 0;
    
    char lastfid[MAX_DAQ_FIDSIZE];
    char tmpbuf[256];
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        dtime.year,dtime.month,dtime.day,dtime.hour,dtime.minute,dtime.second);

    for(loop=0;loop<count;loop++)
    {
        gid = atgid[loop];
        
        if (gid == 100)
        {
            if (strcmp(item_set[loop].fid, lastfid) != 0)
            {
                strcpy(lastfid, item_set[loop].fid);
                sprintf(tmpbuf,";%s-Info=%.3f",
                    item_set[loop].fid, item_set[loop].val);  
                strcat(buf, tmpbuf);
            }
        }
    }
    return 0;
}
int gbt212_pack_alarmstate(usstime start_time, dsm_alarmlast* alarmlist, dsm_statelast* statelist, char* buf, int len)
{
    int loop;
    char tmpbuf[512];
    
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        start_time.year,start_time.month,start_time.day,start_time.hour,start_time.minute,start_time.second);

    if (statelist != NULL)
    {
        for(loop=0;loop<statelist->state_cnt;loop++)
        {
            sprintf(tmpbuf,";%s-S%02d=%03d%s",statelist->state_set[loop].state_src,statelist->state_set[loop].state_type, 
                statelist->state_set[loop].state_code, statelist->state_set[loop].state_valuetext);

            if ((strlen(buf) + strlen(tmpbuf)) >= len )
            {
                break;
            }
    	
            strcat(buf, tmpbuf);
        }
    }

    if (alarmlist != NULL)
    {
        for(loop=0;loop<alarmlist->alarm_cnt;loop++)
        {
            sprintf(tmpbuf,";%s-A%04d=%s",alarmlist->alarm_set[loop].alarm_src, alarmlist->alarm_set[loop].alarm_code, 
                alarmlist->alarm_set[loop].alarm_str);
            
            if ((strlen(buf) + strlen(tmpbuf) ) >= len )
            {
                break;
            }
    	
            strcat(buf, tmpbuf);
        }
    }
    return 0;
}

int gbt212_pack_alarmstate2(usstime start_time, dsm_alarmlast* alarmlist, dsm_statelast* statelist, char* buf, int len)
{
    int loop;
    char tmpbuf[512];
    char timebuf[32];
    usstime stime;
    
    sprintf(buf, "DataTime=%04d%02d%02d%02d%02d%02d",
        start_time.year,start_time.month,start_time.day,start_time.hour,start_time.minute,start_time.second);

    if (statelist != NULL)
    {
        for(loop=0;loop<statelist->state_cnt;loop++)
        {
            stime = statelist->state_set[loop].start_time;
            timebuf[0] = 0;
            sprintf(timebuf, "{Time:%04d%02d%02d%02d%02d%02d}",
                stime.year,stime.month,stime.day,stime.hour,stime.minute,stime.second);

            sprintf(tmpbuf,";%s-S%02d=%03d%s%s",statelist->state_set[loop].state_src,statelist->state_set[loop].state_type, 
                statelist->state_set[loop].state_code, statelist->state_set[loop].state_valuetext, timebuf);

            if ((strlen(buf) + strlen(tmpbuf)) >= len )
            {
                break;
            }
    	
            strcat(buf, tmpbuf);
        }
    }

    if (alarmlist != NULL)
    {
        for(loop=0;loop<alarmlist->alarm_cnt;loop++)
        {
            stime = alarmlist->alarm_set[loop].start_time;
            timebuf[0] = 0;
            sprintf(timebuf, "{Time:%04d%02d%02d%02d%02d%02d}",
                stime.year,stime.month,stime.day,stime.hour,stime.minute,stime.second);
            
            sprintf(tmpbuf,";%s-A%04d=%s%s",alarmlist->alarm_set[loop].alarm_src, alarmlist->alarm_set[loop].alarm_code, 
                alarmlist->alarm_set[loop].alarm_str, timebuf);
              
            if ((strlen(buf) + strlen(tmpbuf) ) >= len )
            {
                break;
            }
    	
            strcat(buf, tmpbuf);
        }
    }
    
    return 0;
}


int gbt212_pack_9012(dsm_ctrlres* ctrlcmd, char* buf, int len)
{
    if (ctrlcmd->outval[0] == 0)
    {
        sprintf(buf, "QN=%s;ExeRtn=%d",ctrlcmd->qn,ctrlcmd->exertn);
    }
    else
    {
        sprintf(buf, "QN=%s;ExeRtn=%d;%s",ctrlcmd->qn,ctrlcmd->exertn, ctrlcmd->outval);
    }
    
    
    return 0;
}

int gbt212_code(gbt212_pkt* pkt, char* buf, int len, bool checksum)
{
    char tmpbuf[DM_PACKET_MAXSIZE];
    int cp_len = 0;
    int cp_crc = 0;


    if ((pkt->cn >= 9011) && (pkt->cn <= 9022))
    {
        pkt->st = 91;
    }

    switch(pkt->cn)
    {
        case 2011:
        case 2031:
        case 2051:
        case 2061:
        case 2041:
        case 2021:
        case 8051:
            if (pkt->pnum > 1)
            {
                sprintf(tmpbuf, "ST=%d;CN=%d;PW=%s;MN=%s;PNO=%d;PNUM=%d;CP=&&%s&&",
                    pkt->st,pkt->cn,pkt->pw,pkt->mn,
                    pkt->pno,pkt->pnum,
                    pkt->data);
            }
            else
            {
                sprintf(tmpbuf, "ST=%d;CN=%d;PW=%s;MN=%s;CP=&&%s&&",
                    pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);            
            }
            break;

        case 9021:
            sprintf(tmpbuf, "QN=%s;ST=%d;CN=%d;PW=%s;MN=%s;Flag=1;CP=&&%s&&",
                pkt->qn,pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
                    
        case 2111:
            sprintf(tmpbuf, "QN=%s;ST=%d;CN=%d;PW=%s;MN=%s;Flag=0;CP=&&%s&&",
                pkt->qn,pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
            
        case 9011:
        case 9012:
            sprintf(tmpbuf, "ST=%d;CN=%d;PW=%s;MN=%s;Flag=0;CP=&&%s&&",
                pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
        case 5005:
            sprintf(tmpbuf, "ST=%d;CN=%d;PW=%s;MN=%s;Flag=1;CP=&&%s&&",
                pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
	case 3020:
            sprintf(tmpbuf, "ST=%d;QN=%s;CN=%d;PW=%s;MN=%s;CP=&&%s&&",
                pkt->st,pkt->qn,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
            
        default:
            sprintf(tmpbuf, "ST=%d;CN=%d;PW=%s;MN=%s;CP=&&%s&&",
                pkt->st,pkt->cn,pkt->pw,pkt->mn,pkt->data);
            break;
    }
    
	if (checksum)
	{
		cp_len = strlen(tmpbuf);
		cp_crc =  comm_crc16_t212((unsigned char*)tmpbuf, cp_len);

		if ( cp_len > 9999)
		{
			sprintf(buf,"##%06d",cp_len);
		}
		else
		{
			sprintf(buf,"##%04d",cp_len);
		}
		
		strcat(buf, tmpbuf);
		sprintf(tmpbuf, "%04X\r\n", cp_crc);
		strcat(buf, tmpbuf);
	}
	else
	{
	    strcpy(buf,tmpbuf);
	}

    return 0;
}

int gbt212_decode(char* buf, gbt212_pkt* pkt)
{
    strarray strs;
    strarray strs_L1;

    char* pdata_h = NULL;
    char* pdata_t = NULL;
    char* ptr = NULL;
    
    int head_size = 0;
    int data_size = 0;
    int len_size = 0;
    char head_buf[256];
    char crc_buf1[8];
    char crc_buf2[8];
    char len_buf[8];
    
    int cp_len = 0;
    int cp_crc1 = 0;
    int cp_crc2 = 0;
    int buf_len = 0;

    memset(crc_buf1, 0, sizeof(crc_buf1));
    memset(crc_buf2, 0, sizeof(crc_buf2));
    memset(len_buf, 0, sizeof(len_buf));
    
    buf_len = strlen(buf);

    /*长度不能小于12*/
    if (buf_len < 12)
    {
        return -1;
    }

    memcpy(len_buf, buf+2, 6);

    cp_len = atoi(len_buf);

    /*兼容长度大于9999情况，用6位表示*/
    if (cp_len > 9999)
    {
        len_size = 6;
    }
    else
    {
        len_size = 4;
    }

    /*获得长度与数据包总长度不一致*/
    if ((cp_len+len_size+8) != buf_len)
    {
        return -2;
    }
    
    /*数据必须是CR结束*/
    ptr = strstr(buf, "\r\n");
    if ((ptr == NULL) || (ptr < (buf+4)))
    {
        return -3;
    }

    /*比较CRC16*/
    memcpy(crc_buf1, (ptr-4), 4);
    crc_buf1[4] = 0;
    sscanf(crc_buf1, "%04X", &cp_crc1);
    
	cp_crc2 =  comm_crc16_t212((unsigned char*)(buf+len_size+2), cp_len);
    
    if (cp_crc2 != cp_crc1)
    {
        //printf("crc err[%04x][%04x]cp_len=%d\n", cp_crc1,cp_crc2,cp_len);
        return -4;
    }
        
    
    pdata_h = strstr(buf, ";CP=&&");
    if (pdata_h == NULL)
    {
        return -5;
    }
    pdata_t = strstr(pdata_h+6, "&&");
    if (pdata_t == NULL)
    {
        return -6;
    }
    
    head_size = (pdata_h - buf);
    data_size = (pdata_t - pdata_h - 6);

    if ((head_size >= sizeof(head_buf)) || (head_size <= 0))
    {
        return -7;
    }
    
    if ((data_size >= sizeof(pkt->data)) || (data_size < 0))
    {
        return -8;
    }
    
    memcpy(pkt->data, pdata_h+6, data_size);
    pkt->data[data_size] = 0;
    
    memset(head_buf, 0, sizeof(head_buf));
    memcpy(head_buf, buf, head_size);
    
    strs.num = 0;
    comm_divstr(head_buf+6, ";",&strs);

    for(int i=0; i<strs.num; i++)
    {
        strs_L1.num = 0;
        comm_divstr(strs.ptr[i], "=", &strs_L1);

        if (strs_L1.num != 2)
        {
            continue;
        }

        if (strcmp("QN", strs_L1.ptr[0]) == 0)
        {
            strncpy(pkt->qn, strs_L1.ptr[1], sizeof(pkt->qn)-1);
        }
        else if (strcmp("ST", strs_L1.ptr[0]) == 0)
        {
            pkt->st = atoi(strs_L1.ptr[1]);
        }
        else if (strcmp("CN", strs_L1.ptr[0]) == 0)
        {
            pkt->cn = atoi(strs_L1.ptr[1]);
        }
        else if (strcmp("MN", strs_L1.ptr[0]) == 0)
        {
            strncpy(pkt->mn, strs_L1.ptr[1], sizeof(pkt->mn)-1);
        }
        else if (strcmp("PW", strs_L1.ptr[0]) == 0)
        {
            strncpy(pkt->pw, strs_L1.ptr[1], sizeof(pkt->pw)-1);
        }
        else if (strcmp("PNUM", strs_L1.ptr[0]) == 0)
        {
            pkt->pnum= atoi(strs_L1.ptr[1]);
        }
        else if (strcmp("PNO", strs_L1.ptr[0]) == 0)
        {
            pkt->pno = atoi(strs_L1.ptr[1]);
        }
        
    }
  
    return 0;
}

int dsmt212_decode(char* buf,dsmt212_pkt* pkt)
{
    strarray strs;
    char* p = NULL;
    char* outer_ptr = NULL;
    
    strs.num = 0;
    
    comm_divstr(buf, "_-_",&strs);

    if ((strs.num != 3) && (strs.num != 2))
    {
        return -1;
    }

    if (strs.num == 3)
    {
        pkt->cn = atoi(strs.ptr[2]);
    }
    else
    {
        pkt->cn = 0;
    }

  
    p = strstr(strs.ptr[1], "&&");
    if (p == NULL)
    {
        return -2;
    }
    
    p = comm_strtok(p+2, "&&", &outer_ptr);

    if (p == NULL)
    {
        return -3;
    }

    
    pkt->stationid = atoi(strs.ptr[0]);
	if (strlen(p) > 0)
	{
		strncpy(pkt->data, p , sizeof(pkt->data)-1);
	}

    return 0;
}

int dsmt212_code(dsmt212_pkt* pkt, char* buf, int len)
{
    /*没有配置CN的话，表示CN已经包含在Data中了，不用再额外加&&...&&*/
    if (pkt->cn == 0)
    {
        sprintf(buf, "%d_-_%s",pkt->stationid,pkt->data);
    }
    else
    {
        sprintf(buf, "%d_-_&&%s&&_-_%d",pkt->stationid,pkt->data,pkt->cn);
    }

    return 0;
}

int dsmt212_divpkt( int data_count, dsm_divpkt* atpos, int size)
{
    int count = 0;
    
    if (data_count <= 0)
    {
        return -1;
    }

    {
        /*直接按照个数强制分组,每DQI_GROUPELEM_NUM个一个分组*/
        count = ((data_count + (DM_PACKET_MAXPNO-1))/DM_PACKET_MAXPNO);
        if (count > size)
        {
            count = size;
        }
        
        for(int j=0; j<count; j++)
        {
            atpos[j].pnum = j;
            atpos[j].pos = j*DM_PACKET_MAXPNO;

            if (j == (count-1))
            {
                atpos[j].num = (data_count - j*DM_PACKET_MAXPNO);
            }
            else
            {
                atpos[j].num = DM_PACKET_MAXPNO;
            }
        }
    }

    return count;
}


