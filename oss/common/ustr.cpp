#include <math.h>

#include "upub.h"
#include "ustr.h"

char* comm_strtok(char* buf, const char* div, char** out_ptr)
{
    int div_len = 0;
    char* ret = NULL;
    char* p = NULL;

    div_len = strlen(div);
    
    if (out_ptr == NULL)
    {
        return NULL;
    }
    
    if (buf != NULL)
    {
        p = buf;
    }
    else if (*out_ptr != NULL)
    {
        p = *out_ptr;
    }
    else 
    {
        return NULL;
    }

    ret = strstr(p, div);
    if (ret != NULL)
    {
        ret[0] = 0;
        *out_ptr = (ret+div_len);
    }
    else
    {
        *out_ptr = NULL;
    }
    ret = p;

    return ret;
}

int comm_divstr(char* src, const char* div, strarray* dst)
{
    int count = 0;
    char* buf=src;
    char* p = NULL;
    char* outer_ptr=NULL;
    
    if( src == NULL || div == NULL || dst == NULL)
    {
        return -1;
    }
       
   if( strlen(src) == 0 || strlen(div) == 0)
    {
        return -2;
    }

    while((p = comm_strtok (buf, div, &outer_ptr))!=NULL)
    {
        if (count >= MAX_DIV_NUM)
        {
            break;
        }
    
        dst->ptr[count] = p;
        count++;

        buf=NULL;
    }
    
    dst->num = count;
        
    return count;
}

int comm_crc16_t212(unsigned char* buf, unsigned int len)
{
	int i,j;
	unsigned int icrc = 0;
	unsigned char  bTemp = 0;
	unsigned char bHight = 255;
	unsigned char bLow = 255;
	int iFlag = 0;
	icrc = bHight*256+bLow;
	i = 0;
	while(i < len)
	{
		bTemp = buf[i];
		bHight = icrc/256;
		icrc = bTemp^bHight;
		j=0;
		iFlag = 0;
		while(j<8)
		{
			iFlag = icrc % 2;
			icrc = icrc>>1;
			if(iFlag)
			{
				icrc = icrc^40961;
			}
			j++;
		}
		i++;
	}
	return icrc;
}

int comm_crc16_modbus(unsigned char* buf, unsigned int len)
{
    unsigned int crc=0xFFFF;
    unsigned int i,j;

    for (j = 0; j < len; j++)
    {
    	crc=crc^*buf++;
        for(i = 0; i<8; i++)
        {
        	if ((crc&0x0001) > 0)
        	{
        		crc=crc>>1;
        		crc=crc^0xa001;
        	}
        	else
        	{
        		crc = crc>>1;
        	}		
        }
    }
	
    crc = ((crc>>8) | ((crc&0xFF) << 8));
	
	return crc;
}


int comm_crc8_szy206(unsigned char* buf, unsigned int len)
{
	int off = 0;
    unsigned char temp = 0;
    unsigned char crc = 0;

    while (off < len)
    {
        crc ^= buf[off];
        for (int i = 0; i < 8; i++)
        {
            if ((crc & 0x80) == 0x80)
            {
                crc = ((crc << 1) ^ 0xe5);
            }
            else
            {
                crc = (crc << 1);
            }
        }

        off++;
    }

    temp = crc;

    return (temp);
}


int comm_hex(unsigned char* data, int data_len, char* hex, int hex_size)
{
    int ret_len = 0;
	int i = 0;
	const char hextab[] = "0123456789ABCDEF";

    if (hex_size < (data_len*2))
    {
        return -1;
    }

	for(i = 0; i < data_len; i++)
	{
		unsigned char ch = data[i];
		unsigned char ch_hi = hextab[(ch >> 4) & 0x0f];
		unsigned char ch_low = hextab[ch & 0x0f];

		hex[i*2] = (char)ch_hi;
		hex[i*2 + 1] = (char)ch_low;
	}
    
    return hex_size;
}

int comm_unhex(unsigned char* data, int data_len, char* hex, int hex_size)
{
    int ret_len = 0;
	unsigned int i = 0;
    unsigned int hi_low = 0;
    unsigned int bi = 0;
    unsigned char a[2];

    if ((hex_size > (data_len*2)) || ((hex_size&1) != 0))
    {
        return -1;
    }

	for(i = 0; i < hex_size; i++)
	{
    	hi_low = (i&1);
        bi = (i>>1);
    
    	if(hex[i]>='0' && hex[i]<='9')
        {
            a[hi_low]=hex[i]-'0';
        }
        else if (hex[i]>='A' && hex[i]<='Z')
        {
            a[hi_low]=hex[i]-'A'+10;
        }
        else if (hex[i]>='a' && hex[i]<='z')
        {
            a[hi_low]=hex[i]-'a'+10;
        }
        else
        {
            a[hi_low] = 0;
        }

        if (hi_low == 1)
        {
            data[bi] = ((a[0]&0xf)<<4) + (a[1]&0xf);
        }
	}
    
    return (hex_size/2);
}

int comm_compataf(char* afbuf)
{
    char* p;
    char* q;
    int len = 0;
    
    len = strlen(afbuf);
    p = strstr(afbuf,".");

    if (p != NULL)
    {
        q = afbuf+len-1;
        while((q!= p) && (*q == '0'))
        {
            *q = 0;
            q--;
        }

        if (q == p)
        {
            *q = 0;
        }
    }

    return 0;
}

int common_fcs(unsigned char* data, int length)
{
    unsigned char x = 0;
    
    x = data[0];
    
    for (int i = 1; i<length; i++)
    {
        x = x^data[i];
    }
    
    return x;

}


int comm_n2bcd(unsigned int n, unsigned char* bcd_data, int bcd_size)
{
	unsigned int div = 1;
	unsigned char byte = 0;
	unsigned char hi = 0;
	unsigned char low = 0;

	if ((bcd_size > 5) || (bcd_size <= 0))
	{
		return -1;
	}

	for(int i=0; i<bcd_size; i++)
	{
		div = pow(100, i);
		byte = ((n / div) % 100);
		hi =  (byte / 10);
		low = (byte % 10);
		bcd_data[i] = ((hi << 4) | low);
	}

	return 0;
}
