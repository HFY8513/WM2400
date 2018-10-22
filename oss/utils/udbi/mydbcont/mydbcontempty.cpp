
#include "mydbcont.h"

static const dbcont_dtmap at_dtmap[] = {
        {MYSQL_TYPE_NULL, USQL_TYPE_NULL},

        {MYSQL_TYPE_BIT, USQL_TYPE_BIT},
        {MYSQL_TYPE_TINY, USQL_TYPE_INT8},
        {MYSQL_TYPE_SHORT, USQL_TYPE_INT16},
        {MYSQL_TYPE_LONG, USQL_TYPE_INT32},
        {MYSQL_TYPE_LONGLONG, USQL_TYPE_INT64},
        {MYSQL_TYPE_DECIMAL, USQL_TYPE_DECIMAL},
        {MYSQL_TYPE_FLOAT, USQL_TYPE_FLOAT},
        {MYSQL_TYPE_DOUBLE, USQL_TYPE_DOUBLE},
        {MYSQL_TYPE_TIMESTAMP, USQL_TYPE_TIMESTAMP},
        {MYSQL_TYPE_DATETIME, USQL_TYPE_DATETIME},
        {MYSQL_TYPE_STRING, USQL_TYPE_CHAR},
        {MYSQL_TYPE_VAR_STRING, USQL_TYPE_CHAR},
        {MYSQL_TYPE_BLOB, USQL_TYPE_BLOB}
};


mydbcont::mydbcont()
{   
    m_initflag = false;
    m_contflag = false;
    memset(&m_param, 0 ,sizeof(m_param));
}

mydbcont::~mydbcont()
{

}

int mydbcont::setparam(dbcont_param* param)
{
    return 0;
}

int mydbcont::open()
{
    return 0;
}

int mydbcont::close()
{    
    return 0;
}

int mydbcont::reset()
{    
    return 0;
}

int mydbcont::transbegin()
{
    return 0;
}

int mydbcont::trans(const char* sql)
{
    return 0;
}

int mydbcont::transcommit()
{
    return 0;
}

dbcont_res mydbcont::query(const char* sql, int* errid, bool need_res)
{   
    return 0;
}

dbcont_res mydbcont::procedure(const char* sql, int* errid, bool need_res)
{
    return 0;
}

int mydbcont::closeres(dbcont_res res)
{
    return 0;
}

int mydbcont::getcolcount(dbcont_res res)
{
    return 0;
}

int mydbcont::getrowcount(dbcont_res res)
{    
    return 0;
}

dbcont_row mydbcont::fetchrow(dbcont_res res)
{
    dbcont_row row_data;

    row_data.col_set = NULL;
    row_data.data_set = NULL;
    row_data.size_set = NULL;

    return row_data;
}

dbcont_colval mydbcont::getcoldata(dbcont_row row_data, int colnr)
{   
    dbcont_colval val;
    memset(&val, 0, sizeof(val));
    return val;
}


int mydbcont::getcolum(dbcont_res res, int col_nr, dbcont_col* colum)
{    
    return 0;
}

int mydbcont::getcolnr(dbcont_res res, const char* col_name)
{    
    return 0;
}


bool mydbcont::isconnected()
{
    return m_contflag;
}

int mydbcont::formatter(dbcont_colval* input_val)
{    
    return 0;
}
