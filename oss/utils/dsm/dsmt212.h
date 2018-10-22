#pragma once

#include "dsmpub.h"

typedef struct dsmt212_pkt{
    int         cn;
    int         stationid;
    char        data[DM_PACKET_MAXSIZE];
}dsmt212_pkt;

typedef struct gbt212_pkt{
    int         cn;
    int         st;
    int         stationid;
    int         pno;
    int         pnum;
    
    char        qn[32];
    char        mn[32];
    char        pw[32];
    char        data[DM_PACKET_MAXSIZE];
}gbt212_pkt;

int dsmt212_decode(char* buf,dsmt212_pkt* pkt);
int dsmt212_code(dsmt212_pkt* pkt, char* buf, int len);
int dsmt212_divpkt(int data_count, dsm_divpkt* atpos, int size);

int gbt212_unpack_rtd(char* buf, usstime* dtime, ussrtv* item_set, int count);
int gbt212_unpack_alarmstate(char* buf, usstime* dtime, dsm_alarmlast* alarmlist, dsm_statelast* statelist);
int gbt212_unpack_avg(char* buf, usstime* dtime, dsm_avg* item_set, int count);
int gbt212_unpack_dataarq(gbt212_pkt* pkt, dsm_arqrecord* arqrecord);
int gbt212_unpack_ctrl(char* buf, dsm_ctrlreq* ctrlcmd);


int gbt212_pack_arq(usstime start_time,usstime end_time, char* buf, int len);
int gbt212_pack_avg(usstime start_time, dsm_avg* cpavg_set, int cpavg_count, char* buf, int len, int* atgid);
int gbt212_pack_rtd(usstime dtime, ussrtv* item_set, int count, char* buf, int len, int* atgid);
int gbt212_pack_rtd2(usstime dtime, ussrtv* item_set, int count, char* buf, int len, int* atgid);
int gbt212_pack_origrtd(usstime dtime,ussrtv* item_set, int count, char* buf, int len, int* atgid);
int gbt212_pack_acc(usstime start_time, dsm_avg* cpavg_set, int cpavg_count, char* buf, int len);
int gbt212_pack_alarmstate(usstime start_time, dsm_alarmlast* alarmlist, dsm_statelast* statelist, char* buf, int len);
int gbt212_pack_fidparams(usstime dtime, ussrtv* item_set, int count, char* buf, int len, int* atgid);
int gbt212_pack_alarmstate2(usstime start_time, dsm_alarmlast* alarmlist, dsm_statelast* statelist, char* buf, int len);

int gbt212_pack_9012(dsm_ctrlres* ctrlcmd, char* buf, int len);

int gbt212_code(gbt212_pkt* pkt, char* buf, int len, bool checksum);
int gbt212_decode(char* buf, gbt212_pkt* pkt);

