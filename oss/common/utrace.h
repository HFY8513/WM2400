#pragma once

typedef enum
{
	TRACE_DEBUG = 0,
	TRACE_INFO,
	TRACE_WARNING,
	TRACE_ERROR,
	TRACE_NONE
}TRACE_LEVEL;

/*文件大小单位MB*/
#define UTRACE_MAX_FILESIZE 32
#define UTRACE_MAX_BUFSIZE 0x10000

class utrace
{
public:
	utrace();
	~utrace();
    int write(TRACE_LEVEL level, const char* fmt, ... );
	int init(const char* filename,TRACE_LEVEL level);
private:
    char m_filename[512];
    char m_wbuf[UTRACE_MAX_BUFSIZE];
    int m_level;
};

