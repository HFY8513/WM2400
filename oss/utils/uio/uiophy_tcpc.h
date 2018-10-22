#pragma once

#include "uiophy_io.h"


typedef struct uiophy_tcpcparam{
	char host[256];
	int port;
	bool udpflag;
}uiophy_tcpcparam;



class uiophy_tcpc : public uiophy_io  
{
private:
    uiophy_tcpcparam m_param;


public:
	virtual int init(void* service);
	virtual int setparam(const char* name, void* param);
	virtual int handle_timeout();

	virtual int connect();
	virtual int disconnect();
	virtual int write(int lane, const unsigned char* buf, int size);
	virtual int read(int lane, unsigned char* buf, int size);

public:
	uiophy_tcpc();
	virtual ~uiophy_tcpc();
};
