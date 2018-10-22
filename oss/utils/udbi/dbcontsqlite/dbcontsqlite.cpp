
#include "dbcontsqlite.h"

//#define DBCONT_SQLITE_TRACE common_trace
#define DBCONT_SQLITE_TRACE

dbcontsqlite::dbcontsqlite()
{
    m_sqlite = NULL;

    m_initflag = false;
    m_contflag = false;
    memset(&m_param, 0 ,sizeof(m_param));
}

dbcontsqlite::~dbcontsqlite()
{
    close();
}

int dbcontsqlite::setparam(dbcont_param* param)
{
    if (param == NULL)
    {
        return -1;
    }
    
    m_param = *param;

    m_initflag = true;

    return 0;
}

int dbcontsqlite::open()
{
    int ret = 0;
    int retcode = 0;

    if (!m_initflag)
    {
        return -1;
    }

    
    if (m_contflag)
    {
        return 0;
    }
    
    try 
    {
        //retcode = sqlite3_open(m_param.db_name, &m_sqlite);
        retcode = sqlite3_open_v2(m_param.db_name, &m_sqlite, 
            SQLITE_OPEN_READWRITE | SQLITE_OPEN_FULLMUTEX, NULL);

        if ( retcode == SQLITE_OK )
        {
            m_contflag = true;
            sqlite3_busy_timeout( m_sqlite, 10000);
        }
        else
        {
            ret = -1;
        }
    }
    catch (...)
    {
        ret = -2;
    }


    return ret;
}

int dbcontsqlite::close()
{
    if (!m_contflag)
    {
        return 0;
    }
    
    if (!m_initflag)
    {
        return -1;
    }

    try
    {
        if (m_sqlite != NULL)
        {
            //sqlite3_close(m_sqlite);
            sqlite3_close_v2(m_sqlite);
            m_sqlite = NULL;
        }
    }
    catch (...)
    {
        return -2;
    }
    
    m_contflag = false;
    
    return 0;
}

int dbcontsqlite::reset()
{
    int ret = 0;
    
    close();
    ret = open();
    
    return ret;
}

int dbcontsqlite::transbegin()
{
    return 0;
}

int dbcontsqlite::trans(const char* sql)
{
    int err_no = 0;

    query(sql, &err_no, false);

    return err_no;
}

int dbcontsqlite::transcommit()
{
    return 0;
}

dbcont_res dbcontsqlite::query(const char* sql, int* errid, bool need_res)
{
    sqlite3_stmt* stmt = NULL; 
    dbcont_resimpl* resimpl = NULL;

    int err_no = 0;
    int sqliteret = 0;
    
    sqliteret = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "query sql=%s", sql);

    if (sqliteret != SQLITE_OK)
    {
        DBCONT_SQLITE_TRACE(3, "sqlite", true, "sqlite3_prepare_v2 err=%d [%s]", sqliteret, sql);
        err_no = -1;
    }
    else
    {
        if (!need_res)
        {
            sqliteret = sqlite3_step(stmt);
            if (sqliteret != SQLITE_DONE) 
            {
                DBCONT_SQLITE_TRACE(3, "sqlite", true, "sqlite3_step err=%d", sqliteret);

                err_no = -2;
            }
        }
        else
        {
            DBCONT_SQLITE_TRACE(1, "sqlite", true, "query pre");

            resimpl = new dbcont_resimpl;

            if (resimpl != NULL)
            {
                resimpl->row_id = 0;
                resimpl->col_set = NULL;
                resimpl->col_num = sqlite3_column_count(stmt);

                if (resimpl->col_num > 0)
                {
                    resimpl->col_set = new dbcont_col[resimpl->col_num];
                    for(int i=0; i<resimpl->col_num; i++)
                    {
                        strncpy(resimpl->col_set[i].name, sqlite3_column_name(stmt, i), sizeof(resimpl->col_set[i].name)-1);
                        resimpl->col_set[i].data_type = USQL_TYPE_NULL;
                    }

                    sqliteret = sqlite3_step(stmt);

                    DBCONT_SQLITE_TRACE(3, "sqlite", true, "sqlite3_step err=%d", sqliteret);

                    while(sqliteret == SQLITE_ROW)
                    {
                        dbcont_colval val;
                        dbcont_rowimpl row;
                        sqlite3_value* sqliteval = NULL;

                        row.col_num = resimpl->col_num;
                        row.colval_set = new dbcont_colval[row.col_num];

                        if (row.colval_set != NULL)
                        {
                            for(int colnr=0; colnr<row.col_num; colnr++)
                            {
                                memset(&row.colval_set[colnr], 0, sizeof(val));

                                sqliteval = sqlite3_column_value(stmt, colnr);

                                if (sqliteval != NULL)
                                {
                                    formatter(sqliteval, &row.colval_set[colnr]);
                                }
                            }

                            resimpl->row_set.push_back(row);
                        }

                        sqliteret = sqlite3_step(stmt);

                    }
                }
            }
        }
    }

    if (stmt != NULL)
    {
        sqlite3_finalize(stmt);
    }
    
    if (errid != NULL)
    {
        *errid = err_no;
    }
        
    DBCONT_SQLITE_TRACE(1, "sqlite", true, sql);

    return (dbcont_res)resimpl;
}

dbcont_res dbcontsqlite::procedure(const char* sql, int* errid, bool need_res)
{
    return query(sql,errid, need_res);
}

int dbcontsqlite::closeres(dbcont_res res)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;
    dbcont_rowimpl* rowimpl = NULL;
    int col_num = 0;

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "closeres pre");

    if (resimpl != NULL)
    {
        col_num = resimpl->col_num;

        if (resimpl->col_set != NULL)
        {
            delete[] resimpl->col_set;
        }

        for(int i=0; i<resimpl->row_set.size(); i++)
        {
            rowimpl = &resimpl->row_set[i];

            if (rowimpl->colval_set != NULL)
            {
                for(int colnr=0; colnr<col_num; colnr++)
                {
                    if (rowimpl->colval_set[colnr].var != NULL)
                    {
                        free(rowimpl->colval_set[colnr].var);
                    }
                }

                delete[] rowimpl->colval_set;
            }
        }

        resimpl->row_set.clear();


        delete resimpl;
    }

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "closeres");

    return 0;
}

int dbcontsqlite::getcolcount(dbcont_res res)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;

    int field_count = 0;

    if (resimpl != NULL)
    {
        field_count = resimpl->col_num;
    }

    return field_count;
}

int dbcontsqlite::getrowcount(dbcont_res res)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;

    int rowcount = 0;

    if (resimpl != NULL)
    {
        rowcount = resimpl->row_set.size();
    }

    return rowcount;
}

dbcont_row dbcontsqlite::fetchrow(dbcont_res res)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;
    dbcont_rowimpl* rowimpl = NULL;

    int err_no = 0;
    int rowcount = 0;

    dbcont_row row_data;

    row_data.col_set = NULL;
    row_data.data_set = NULL;
    row_data.size_set = NULL;

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "fetchrow pre");

    if (resimpl != NULL)
    {
        rowcount = resimpl->row_set.size();

        if (resimpl->row_id < rowcount)
        {
            rowimpl = &resimpl->row_set[resimpl->row_id];
            row_data.col_set = (void*)rowimpl;

            resimpl->row_id++;
        }
    }
   
    DBCONT_SQLITE_TRACE(1, "sqlite", true, "fetchrow");

    return row_data;
}

dbcont_colval dbcontsqlite::getcoldata(dbcont_row row_data, int colnr)
{
    dbcont_rowimpl* rowimpl = (dbcont_rowimpl*)row_data.col_set;
    dbcont_colval val;

    int field_count = 0;

    memset(&val, 0, sizeof(val));

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "getcoldata pre");

    if (rowimpl != NULL)
    {
        field_count = rowimpl->col_num;
        if ((colnr >= 0) && (colnr < field_count))
        {
            val = rowimpl->colval_set[colnr];
        }
    }

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "getcoldata");

    return val;
}


int dbcontsqlite::getcolum(dbcont_res res, int col_nr, dbcont_col* colum)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;

    memset(colum, 0, sizeof(dbcont_col));

    if (resimpl == NULL)
    {
        return -1;
    }

    strncpy(colum->name, resimpl->col_set[col_nr].name, sizeof(colum->name)-1);

    return 0;
}

int dbcontsqlite::getcolnr(dbcont_res res, const char* col_name)
{
    dbcont_resimpl* resimpl = (dbcont_resimpl*)res;

    int field_count = 0;
    int col_nr = -1;

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "getcolnr pre");

    if (resimpl != NULL)
    {
        field_count = resimpl->col_num;

        for(int i=0; i<field_count; i++)
        {
            if (strcmp(col_name, resimpl->col_set[i].name) == 0)
            {
                col_nr = i;
                break;
            }
        }
    }

    DBCONT_SQLITE_TRACE(1, "sqlite", true, "getcolnr");

    return col_nr;
}


bool dbcontsqlite::isconnected()
{
    return m_contflag;
}

int dbcontsqlite::formatter(sqlite3_value* input_val, dbcont_colval* output_val)
{
    int time_ret[6] = {0,0,0,0,0,0};
    int vttype = 0;
    char* strvar = NULL;

    vttype = sqlite3_value_type(input_val);

    output_val->var = NULL;
    output_val->vt = USQL_TYPE_NULL;
    output_val->size = USQL_TYPE_NULL;

    switch(vttype)
    {
        case SQLITE_INTEGER:
            output_val->val.i32 = sqlite3_value_int(input_val);
            output_val->vt = USQL_TYPE_INT32;
            break;        

        case SQLITE_FLOAT:
            output_val->val.dou = sqlite3_value_double(input_val);
            output_val->vt = USQL_TYPE_DOUBLE;
            break;   

        case SQLITE_TEXT:
            strvar = (char*)sqlite3_value_text(input_val);
            output_val->vt = USQL_TYPE_CHAR;
            output_val->size = strlen(strvar);
            output_val->var = (char*)malloc(output_val->size+1);

            if (output_val->var != NULL)
            {
                output_val->var[0] = 0;
                strcpy(output_val->var, strvar);

                if (output_val->size == 19) 
                {
                    if ((output_val->var[4] == '-') && (output_val->var[7] == '-')
                        && (output_val->var[10] == ' ') 
                        && (output_val->var[13] == ':') && (output_val->var[16] == ':')
                        )
                    {
                        if (comm_strtotime2(output_val->var, &output_val->val.tm) == 0)
                        {
                            output_val->vt = USQL_TYPE_DATETIME;
                        }
                    }
                }
            }
            break;       

        default:
            break;
    }
    
    return 0;
}
