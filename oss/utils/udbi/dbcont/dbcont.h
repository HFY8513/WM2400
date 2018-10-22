#pragma once

#include "oss/common/upub.h"
#include "oss/common/utime.h"

typedef enum dbcont_coltype { 
	USQL_TYPE_NULL = 0,
	USQL_TYPE_BIT,
	USQL_TYPE_INT8,
	USQL_TYPE_INT16,
	USQL_TYPE_INT32,
	USQL_TYPE_INT64,
	USQL_TYPE_DECIMAL, 
	USQL_TYPE_FLOAT,
	USQL_TYPE_DOUBLE,
	USQL_TYPE_TIMESTAMP,
	USQL_TYPE_DATETIME,
	USQL_TYPE_CHAR,
	USQL_TYPE_BINARY,
	USQL_TYPE_BLOB,
}dbcont_coltype;

typedef usstime dbcont_time;

typedef void*  dbcont_res;

typedef struct dbcont_row
{
    char** data_set;
    void*  col_set;
    unsigned int* size_set;
}dbcont_row;

typedef struct dbcont_colval {
    dbcont_coltype vt;
    unsigned int size;
    char* var;
    
    union {
        signed int i32;
        signed long long i64;

        float flo;
        double dou;
        dbcont_time tm;
        unsigned int tmstamp;
    }val;
} dbcont_colval;

typedef struct dbcont_col {
    char name[128];
    unsigned int name_length;
    unsigned int data_length;
    unsigned int decimals;          /*decimals时的小数点位数*/
    dbcont_coltype data_type;
} dbcont_col;


typedef struct dbcont_param {
	char    server_name[256];
	char    db_name[512];
	char    user_name[64];
	char	user_passwd[64];
	
	short	server_port;
	short	client_flag;
} dbcont_param;

typedef struct dbcont_dtmap {
    int db_type;
    dbcont_coltype uni_type;
} dbcont_dtmap;


typedef struct dbcont_rowimpl {
    int col_num;

    dbcont_colval* colval_set;
} dbcont_rowimpl;

typedef struct dbcont_resimpl
{
    int row_id;
    int col_num;
    dbcont_col* col_set;
    vector<dbcont_rowimpl> row_set;
}dbcont_resimpl;


class dbcont  
{
public:
    dbcont() { 
        m_contflag = false; 
        m_initflag = false; 
        memset(&m_param, 0, sizeof(m_param)); 
    };
    virtual ~dbcont(){};
    
    virtual int setparam(dbcont_param* param) = 0;
    virtual int open() = 0;
    virtual int close() = 0;
    virtual int reset() = 0;

    virtual int transbegin() = 0;
    virtual int trans(const char* sql) = 0;
    virtual int transcommit() = 0;
    
    virtual dbcont_res query(const char* sql, int* errid, bool need_res) = 0;
    virtual dbcont_res procedure(const char* sql, int* errid, bool need_res) = 0;

    virtual int closeres(dbcont_res res) = 0;

    virtual int getcolcount(dbcont_res res) = 0;
    virtual int getrowcount(dbcont_res res) = 0;
    virtual dbcont_row fetchrow(dbcont_res res) = 0;
    virtual int getcolum(dbcont_res res, int colnr,dbcont_col* colum) = 0;

    /*获取值和值格式化字符串*/
    virtual dbcont_colval getcoldata(dbcont_row row_data, int colnr) = 0;
    virtual int getcolnr(dbcont_res res, const char* col_name) = 0;

    virtual bool isconnected() = 0;

    bool  m_contflag;
    bool  m_initflag;
    dbcont_param m_param;
};

