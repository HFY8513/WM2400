#pragma once
#include "../dbcont/dbcont.h"
#include "./include/mysql.h"



class mydbcont : public dbcont
{
public:
    mydbcont();
    virtual ~mydbcont();
    virtual int setparam(dbcont_param* param);
    
    virtual int open();
    virtual int close();
    virtual int reset();
    
    virtual int transbegin();
    virtual int trans(const char* sql);
    virtual int transcommit();
    
    virtual dbcont_res query(const char* sql, int* errid, bool need_res);
    virtual dbcont_res procedure(const char* sql, int* errid, bool need_res);

    virtual int closeres(dbcont_res res);

    virtual int getcolcount(dbcont_res res);
    virtual int getrowcount(dbcont_res res);
    virtual dbcont_row fetchrow(dbcont_res res);
    virtual int getcolum(dbcont_res res, int colnr,dbcont_col* colum);
    
    virtual dbcont_colval getcoldata(dbcont_row row_data, int colnr);
    virtual int getcolnr(dbcont_res res, const char* col_name);
    virtual bool isconnected();
    int formatter(dbcont_colval* input_val);

public:
    MYSQL m_mysql;
};

