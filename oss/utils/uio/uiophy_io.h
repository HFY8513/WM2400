#pragma once

//#include "../../../common/common.h"

#define UIOPHY_READBUF_MAXSIZE 0x4000

enum {
	E_UIOPHY_IO_READNONE,
	E_UIOPHY_IO_READWAIT,
	E_UIOPHY_IO_READABLE,
	E_UIOPHY_IO_READTIMEOUT
};

class uiophy_io
{
public:
    bool m_initflag;
    bool m_setflag;
    bool m_connected;

    int m_readstate;
    int m_readsize;
    int m_readpos;

protected:
    char m_name[256];
    unsigned char m_readbuf[UIOPHY_READBUF_MAXSIZE];

public:
    void* m_handle;

public:
	virtual int init(void* service) = 0;
	virtual int setparam(const char* name, void* param) = 0;
	virtual int handle_timeout() = 0;

	virtual int connect() = 0;
	virtual int disconnect() = 0;
	virtual int write(int lane, const unsigned char* buf, int size) = 0;
	virtual int read(int lane, unsigned char* buf, int size) = 0;

public:
	uiophy_io(){};
	virtual ~uiophy_io(){};
};
