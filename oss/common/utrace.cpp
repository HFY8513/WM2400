#include <stdarg.h>
#include <sys/stat.h>
#include "oss/common/utime.h"
#include "oss/common/upub.h"
#include "utrace.h"
#include <QDateTime>
#include <QTime>
utrace::utrace()
{
    memset(m_filename, 0, sizeof(m_filename));
    memset(m_wbuf, 0, sizeof(m_wbuf));

    m_level = TRACE_NONE;
}

utrace::~utrace()
{

}

int utrace::init(const char* filename,TRACE_LEVEL level)
{
	/*
	char szPath[512];
	memset(szPath, 0x00, sizeof(szPath));
    

	if (0 != osp_getappdir(szPath,sizeof(szPath)))
    {   
        return -1;
    }

    if ((strlen(szPath) + strlen(filename)) < 512)
    {
        strcpy(m_filename, szPath);
        strcat(m_filename, filename);

        m_level = level;
        
        return 0;
    }
    */

    strcpy(m_filename, filename);

    m_level = level;

    return -1;
}


int utrace::write(TRACE_LEVEL level,const char *fmt, ...)
{
	FILE* pStream = NULL;	

    char pref[256];
	usstime now_time;
	va_list argptr;
	int cnt;

    if (level < m_level)
    {
        return -1;
    }
    
    m_wbuf[0] = 0;
    
	va_start(argptr, fmt);
	cnt = vsprintf(m_wbuf, fmt, argptr);
	va_end(argptr);

#ifdef USE_LINUX
	struct stat buf;
	memset(&buf, 0x00, sizeof(struct stat));
	stat(m_filename, &buf);
#else	
	struct _stat buf;
	memset(&buf, 0x00, sizeof(struct _stat));
	_stat(m_filename, &buf);
#endif

	if((buf.st_size / (1024 * 1024)) > UTRACE_MAX_FILESIZE)
	{
		pStream = fopen(m_filename, "w");
	}
	else
	{
		pStream = fopen(m_filename, "a+");
	}
	if(NULL == pStream)
	{
		return -2;
	}
    
	//写时间
	memset(pref, 0x00, sizeof(pref));	
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    sprintf(pref,"%s",current_date.toStdString().c_str());
//	now_time = osp_gettime(NULL);
//	sprintf(pref,"%04d-%02d-%02d %02d:%02d:%02d",now_time.year,now_time.month,now_time.day,
//        now_time.hour,now_time.minute,now_time.second);

    switch(level)
	{
	case TRACE_DEBUG:
		strcat(pref, "[DEBUG] ");
		break;
	case TRACE_INFO:
		strcat(pref, "[INFO] ");
		break;
	case TRACE_ERROR:
		strcat(pref, "[ERROR]");
		break;
	case TRACE_WARNING:
		strcat(pref, "[WARN]");
		break;

    default:
        strcat(pref, "[DEBUG]");
		break;

	}
    
	fwrite(pref, 1, strlen(pref), pStream);
	fwrite(m_wbuf, 1, strlen(m_wbuf), pStream);
	fwrite("\r\n", 1, sizeof("\r\n"), pStream);
	fclose(pStream);

    return 0;
}

