#include <stdarg.h>
#include "common.h"

static int g_tracelevel = 3;
static char g_tracebuf[0x4000];

extern usstime osp_gettime(unsigned short* ms);

int common_trace(int level, const char* module, bool condition, const char* fmt, ...)
{
    char pref[256];
    int prefsize = 0;
	usstime now_time;
	va_list argptr;

    if (level < g_tracelevel)
    {
        return -1;
    }

    if (!condition)
    {
    	return -2;
    }
    
    g_tracebuf[0] = 0;

	memset(pref, 0x00, sizeof(pref));	
    
    now_time = osp_gettime(NULL);
	sprintf(pref,"%04d-%02d-%02d %02d:%02d:%02d",now_time.year,now_time.month,now_time.day,
        now_time.hour,now_time.minute,now_time.second);

    switch(level)
	{
	case 0:
		strcat(pref, "[DEBUG] ");
		break;
	case 1:
		strcat(pref, "[INFO] ");
		break;
	case 2:
		strcat(pref, "[WARN]");
		break;
	case 3:
		strcat(pref, "[ERROR]");
		break;

    default:
        strcat(pref, "[DEBUG]");
		break;
	}

	strcat(pref, "[");
	strcat(pref, module);
	strcat(pref, "] ");

	prefsize = strlen(pref);

    strcpy(g_tracebuf, pref);

	va_start(argptr, fmt);
	vsprintf(g_tracebuf+prefsize, fmt, argptr);
	va_end(argptr);

    strcat(g_tracebuf, "\r\n");

    printf(g_tracebuf);

    return 0;
}


int common_log(int level, const char* fmt, ...)
{
    char pref[256];
    int prefsize = 0;
	usstime now_time;
	va_list argptr;

    if (level < g_tracelevel)
    {
        return -1;
    }
    
    g_tracebuf[0] = 0;

	memset(pref, 0x00, sizeof(pref));	
    
    now_time = osp_gettime(NULL);
	sprintf(pref,"%04d-%02d-%02d %02d:%02d:%02d",now_time.year,now_time.month,now_time.day,
        now_time.hour,now_time.minute,now_time.second);

    switch(level)
	{
	case 0:
		strcat(pref, "[DEBUG] ");
		break;
	case 1:
		strcat(pref, "[INFO] ");
		break;
	case 2:
		strcat(pref, "[WARN]");
		break;
	case 3:
		strcat(pref, "[ERROR]");
		break;

    default:
        strcat(pref, "[DEBUG]");
		break;
	}

	strcat(pref, "[");
	strcat(pref, "NA");
	strcat(pref, "] ");

	prefsize = strlen(pref);

    strcpy(g_tracebuf, pref);

	va_start(argptr, fmt);
	vsprintf(g_tracebuf+prefsize, fmt, argptr);
	va_end(argptr);

    strcat(g_tracebuf, "\r\n");

    printf(g_tracebuf);

    return 0;
}
