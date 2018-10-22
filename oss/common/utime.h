#pragma once

typedef struct usstime { 
        unsigned char second;     /* 秒 取值区间为[0,59] */ 
        unsigned char minute;     /* 分 - 取值区间为[0,59] */ 
        unsigned char hour;    /* 时 - 取值区间为[0,23] */ 
        unsigned char day;     /* 一个月中的日期 - 取值区间为[1,31] */ 
        unsigned char month;     /* 月份（从一月开始，0代表一月） - 取值区间为[1,12] */ 
        unsigned char rsv ;  
        unsigned short year;    /* 年份 */ 
}usstime; 

int comm_timediff(usstime t2, usstime t1);
int comm_timein(usstime t, usstime start_time, usstime end_time);
int comm_time2timestamp(usstime t);
int comm_strtotime(const char* strtime, usstime* t);
int comm_strtotime2(const char* strtime, usstime* t);
int comm_timetostr(usstime* t, char* strtime);

usstime comm_timestamp2time(int timestamp);
usstime comm_timeround_hour(usstime t, int downup);
usstime comm_timeround(usstime t, int round_sec, int downup);
usstime comm_timespan(usstime t, int day, int hour, int minute, int second);
usstime comm_timeround_month(usstime t, int downup);
