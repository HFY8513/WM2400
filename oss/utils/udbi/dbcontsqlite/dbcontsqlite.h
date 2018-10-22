#pragma once
#include "oss/utils/udbi/dbcont/dbcont.h"
#include "oss/thirds/sqltie/sqlite3.h"



class dbcontsqlite : public dbcont
{
public:
    dbcontsqlite();
    virtual ~dbcontsqlite();
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
    int formatter(sqlite3_value* input_val, dbcont_colval* output_val);

public:
    sqlite3* m_sqlite;
};

