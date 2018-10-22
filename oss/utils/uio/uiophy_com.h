#pragma once

#include "uiophy_io.h"


typedef struct uiophy_comparam{
	int parity;
	int stop_bits;
	int byte_size;
	int baud_rate;
}uiophy_comparam;



class uiophy_com : public uiophy_io  
{
private:
    uiophy_comparam m_param;



public:
	virtual int init(void* service);
	virtual int setparam(const char* name, void* param);
	virtual int handle_timeout();

	virtual int connect();
	virtual int disconnect();
	virtual int write(int lane, const unsigned char* buf, int size);
	virtual int read(int lane, unsigned char* buf, int size);

public:
	uiophy_com();
	virtual ~uiophy_com();
};
