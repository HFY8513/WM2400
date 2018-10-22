#include "global.h"


AddStaMsg addstamsg;
AddComMsg addcommsg;
AddDevMsg adddevmsg;
fch_param addfacmsg;
appdts_param adddtsmsg;
dqi* mydqi;


int convertfidrule(char* strfid)
{
    int uid = 0;
    int gid = 0;
    int fid = 0;
    int ret = 0;

    uid = atoi(strfid+1);
    gid = ((uid/10000)%100);
    fid =  (uid%10000);
    return fid;
}
int convertgidrule(char* strfid)
{
    int uid = 0;
    int gid = 0;
    int fid = 0;
    int ret = 0;

    uid = atoi(strfid+1);
    gid = ((uid/10000)%100);
    fid =  (uid%10000);
    return gid;
}
usstime gettime()
{
    usstime now_time;
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString datetime = current_date_time.toString("yyyyMMddhhmmss");
    QString year = datetime.mid(0,4);
    QString month = datetime.mid(4,2);
    QString day = datetime.mid(6,2);
    QString hour = datetime.mid(8,2);
    QString minute = datetime.mid(10,2);
    QString second = datetime.mid(12,2);
    now_time.year = atoi(year.toLatin1().data());
    now_time.month = atoi(month.toLatin1().data());
    now_time.day = atoi(day.toLatin1().data());
    now_time.hour = atoi(hour.toLatin1().data());
    now_time.minute = atoi(minute.toLatin1().data());
    now_time.second = atoi(second.toLatin1().data());
    return now_time;
}
