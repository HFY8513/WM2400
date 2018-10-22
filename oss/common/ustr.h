#pragma once


#define MAX_DIV_NUM 1024

typedef struct strarray{
    char* ptr[MAX_DIV_NUM];
    int num;
}strarray;

char* comm_strtok(char* buf, const char* div, char** out_ptr);

int comm_divstr(char* src, const char* div, strarray* dst);
int comm_crc16_t212(unsigned char* buf, unsigned int len);
int comm_crc16_modbus(unsigned char* buf, unsigned int len);
int comm_crc8_szy206(unsigned char* buf, unsigned int len);

/*精简浮点字符串，截掉末尾0*/
int comm_compataf(char* afbuf);

int comm_hex(unsigned char* data, int data_len, char* hex, int hex_size);
int comm_unhex(unsigned char* data, int data_len, char* hex, int hex_size);

int common_fcs(unsigned char* data, int length);
int comm_n2bcd(unsigned int n, unsigned char* bcd_data, int bcd_size);
