#include "upub.h"
#include "utime.h"
#include <QDateTime>
#include <QDate>
#include <QTime>

int comm_timediff(usstime t2, usstime t1)
{
    int stamp_diff = 0;

    stamp_diff = comm_time2timestamp(t2) - comm_time2timestamp(t1);
    
    return stamp_diff;
}

int comm_timein(usstime t, usstime start_time, usstime end_time)
{
    int ret = 0;

    if (comm_timediff(t,start_time) < 0)
    {
        return -1;
    }
    if (comm_timediff(t,end_time) >= 0)
    {
        return 1;
    }

    return 0;
}

usstime comm_timespan(usstime t, int day, int hour, int minute, int second)
{
    usstime rettime;
    int mystamp = 0;

    mystamp = comm_time2timestamp(t);

    mystamp += ((day*24*3600) + (hour*3600) + (minute*60) + second);
    
    rettime = comm_timestamp2time(mystamp);
        
    return rettime;
}

int comm_time2timestamp(usstime t)
{
//    struct tm mytm;
//    time_t mystamp;
    
//    mytm.tm_year=t.year-1900;
//    mytm.tm_mon=t.month-1;
//    mytm.tm_mday=t.day;
//    mytm.tm_hour=t.hour;
//    mytm.tm_min=t.minute;
//    mytm.tm_sec=t.second;
//    mytm.tm_isdst=0;
//    mystamp=mktime(&mytm);
    QDateTime datetime;   //获取当前时间
    QDate date;
    QTime time;
    date.setYMD(t.year,t.month,t.day);
    time.setHMS(t.hour,t.minute,t.second);
    datetime.setTime(time);
    datetime.setDate(date);
    int timeT = datetime.toTime_t();   //将当前时间转为时间戳
    return timeT;
}

usstime comm_timestamp2time(int timestamp)
{
    usstime t;
    time_t mytmstamp;
    struct tm *mytm;
    
    mytmstamp = timestamp;
    mytm = localtime(&mytmstamp);
    
    t.year = mytm->tm_year+1900;
    t.month = mytm->tm_mon+1;
    t.day = mytm->tm_mday;
    t.hour = mytm->tm_hour;
    t.minute = mytm->tm_min;
    t.second = mytm->tm_sec;

    return t;
}

usstime comm_timeround_hour(usstime t, int downup)
{
    usstime rettime;

    rettime = t;
    
    rettime.minute = 0;
    rettime.second = 0;

    if (downup != 0)
    {
        rettime = comm_timespan(rettime, 0,1,0,0);
    }
        
    return rettime;    
}

usstime comm_timeround_month(usstime t, int downup)
{
    usstime rettime;

    rettime = t;
    
    rettime.minute = 0;
    rettime.second = 0;
    rettime.hour = 0;
    rettime.day = 1;

    if (downup != 0)
    {

        if (rettime.month >= 12)
        {
            rettime.year += 1;
            rettime.month = 1;
        }
        else
        {
            rettime.month += 1;
        }
    }
        
    return rettime;    
}

usstime comm_timeround(usstime t, int round_sec, int downup)
{
    usstime rettime;
	int divnum = 0;

	if (round_sec == 0)
	{
		return t;
	}
    rettime = t;

	divnum = ((rettime.hour*3600)+(rettime.minute*60)+rettime.second)/round_sec;

	rettime.hour = 0;
    rettime.minute = 0;
    rettime.second = 0;

    if (downup == 0)
    {
        rettime = comm_timespan(rettime, 0,0,0,divnum*round_sec);
    }
	else
	{
		divnum += 1;
        rettime = comm_timespan(rettime, 0,0,0,divnum*round_sec);
	}
        
    return rettime;    
}

int comm_strtotime(const char* strtime, usstime* t)
{
    usstime mytime;
    int time_ret[6] = {0,0,0,0,0,0};

    if (6 != sscanf(strtime,"%4d%2d%2d%2d%2d%2d", &time_ret[0], &time_ret[1], &time_ret[2], 
        &time_ret[3], &time_ret[4], &time_ret[5]))
    {
        return -1;
    }
    mytime.year = time_ret[0];
    mytime.month= time_ret[1];
    mytime.day= time_ret[2];
    mytime.hour = time_ret[3];
    mytime.minute= time_ret[4];
    mytime.second = time_ret[5];   

    *t = mytime;

    return 0;   
}

int comm_strtotime2(const char* strtime, usstime* t)
{
    usstime mytime;
    int time_ret[6] = {0,0,0,0,0,0};

    if (6 != sscanf(strtime,"%4d-%2d-%2d %2d:%2d:%2d", &time_ret[0], &time_ret[1], &time_ret[2], 
        &time_ret[3], &time_ret[4], &time_ret[5]))
    {
        return -1;
    }
    mytime.year = time_ret[0];
    mytime.month= time_ret[1];
    mytime.day= time_ret[2];
    mytime.hour = time_ret[3];
    mytime.minute= time_ret[4];
    mytime.second = time_ret[5];   

    *t = mytime;

    return 0;   
}

int comm_timetostr(usstime* t, char* strtime)
{
    sprintf(strtime, "%04d%02d%02d%02d%02d%02d", t->year,t->month,t->day, t->hour,t->minute,t->second);

    return 0;   
}
