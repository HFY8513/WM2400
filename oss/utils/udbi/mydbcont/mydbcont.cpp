
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
    
    mysql_init(&m_mysql);
}

mydbcont::~mydbcont()
{

}

int mydbcont::setparam(dbcont_param* param)
{
    if (param == NULL)
    {
        return -1;
    }
    
    m_param = *param;

    m_initflag = true;

    return 0;
}

int mydbcont::open()
{
    int ret = 0;

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
        if(!mysql_real_connect(&m_mysql, 
            m_param.server_name,m_param.user_name,m_param.user_passwd,m_param.db_name,
            m_param.server_port,NULL,0))  
        {  
            ret = -2;
            printf("mysql connect fail!\n");  
        }   
        else
        {
            m_contflag = true;
            my_bool my_true= true;
            mysql_options(&m_mysql, MYSQL_OPT_RECONNECT, &my_true);
            
            printf("mysql connect successfully!\n"); 
        }
    }
    catch (...)
    {
        ret = -1;
    }

    if (ret == 0)
    {
        try
        {
            //if (mysql_query(&m_mysql,"set names gbk"))  

            if (mysql_set_character_set(&m_mysql, "utf8"))  
            {  
                printf("mysql set charset fail!\n");  
            }   
            else
            {
                printf("mysql set charset successfully!\n");   
            }
        }
        catch (...)
        {
            ret = -3;
        }
    }

    return ret;
}

int mydbcont::close()
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
        mysql_close(&m_mysql);  
    }
    catch (...)
    {
        return -2;
    }
    
    m_contflag = false;
    
    return 0;
}

int mydbcont::reset()
{
    int ret = 0;
    
    close();
    ret = open();
    
    return ret;
}

int mydbcont::transbegin()
{
    mysql_autocommit(&m_mysql, 0);
    return 0;
}

int mydbcont::trans(const char* sql)
{
    int err_no = 0;

    err_no = mysql_query(&m_mysql,sql);

    return err_no;
}

int mydbcont::transcommit()
{
    mysql_commit(&m_mysql);
    
    mysql_autocommit(&m_mysql, 1);

    return 0;
}

dbcont_res mydbcont::query(const char* sql, int* errid, bool need_res)
{
    int err_no = 0;
    dbcont_res res = NULL;
    MYSQL_RES* myres = NULL;
    
    err_no = mysql_query(&m_mysql,sql);

    if (err_no == 0)  
    {  
        if (need_res)
        {
            myres = mysql_store_result(&m_mysql);
            res = myres;
        }
        else
        {
            myres = mysql_store_result(&m_mysql);
            if (myres != NULL)
            {
                mysql_free_result((MYSQL_RES*)res);
            }
        }
    }   
    
    if (errid != NULL)
    {
        *errid = err_no;
    }
        
    return res;
}

dbcont_res mydbcont::procedure(const char* sql, int* errid, bool need_res)
{
    return query(sql,errid, need_res);
}

int mydbcont::closeres(dbcont_res res)
{
    if (res == NULL)
    {
        return -1;
    }

    mysql_free_result((MYSQL_RES*)res);

    return 0;
}

int mydbcont::getcolcount(dbcont_res res)
{
    MYSQL_RES* myres = (MYSQL_RES*)res;
    int field_count = 0;
    
    field_count = mysql_num_fields(myres);

    return field_count;
}

int mydbcont::getrowcount(dbcont_res res)
{
    MYSQL_RES* myres = (MYSQL_RES*)res;
    
    return mysql_num_rows(myres);
    
    //return (unsigned int)myres->row_count;
}

dbcont_row mydbcont::fetchrow(dbcont_res res)
{
    MYSQL_ROW record = NULL;
    MYSQL_RES* myres = (MYSQL_RES*)res;
    dbcont_row row_data;

    row_data.col_set = NULL;
    row_data.data_set = NULL;
    row_data.size_set = NULL;
    
    if (myres != NULL)
    {
        record = mysql_fetch_row(myres);
    }
    
    if (record != NULL)
    {
        row_data.size_set = (unsigned int*)mysql_fetch_lengths(myres);
        row_data.data_set = record;
        row_data.col_set = (void*)myres->fields;
    }

    return row_data;
}

dbcont_colval mydbcont::getcoldata(dbcont_row row_data, int colnr)
{
    dbcont_colval val;
    MYSQL_FIELD* field = NULL;
    
    field = (MYSQL_FIELD*)row_data.col_set;

    memset(&val, 0, sizeof(val));
    
    val.var = row_data.data_set[colnr];
    
    if (row_data.size_set != NULL)
    {
        val.size = row_data.size_set[colnr];
    }


    int loop;

    for(loop = 0; loop < sizeof(at_dtmap)/sizeof(dbcont_dtmap); loop++)
    {
        if (field[colnr].type == at_dtmap[loop].db_type)
        {
            val.vt = at_dtmap[loop].uni_type;
            formatter(&val);
        }
    }

    return val;
}


int mydbcont::getcolum(dbcont_res res, int col_nr, dbcont_col* colum)
{
    MYSQL_FIELD* field = NULL;

    field = mysql_fetch_field_direct((MYSQL_RES*)res, col_nr);

    if (field == NULL)
    {
        return -1;
    }
    
    colum->data_length = field->length;
    colum->name_length = field->name_length;
    colum->decimals = field->decimals;
    strncpy(colum->name, field->name, sizeof(colum->name)-1);
    
    /*需要将mysql类型转化为标准类型*/
    colum->data_type = USQL_TYPE_NULL;

    int loop;

    for(loop = 0; loop < sizeof(at_dtmap)/sizeof(dbcont_dtmap); loop++)
    {
        if (field->type == at_dtmap[loop].db_type)
        {
            colum->data_type = at_dtmap[loop].uni_type;
        }
    }
    
    return 0;
}

int mydbcont::getcolnr(dbcont_res res, const char* col_name)
{
    MYSQL_FIELD* field = NULL;
    MYSQL_RES* myres = (MYSQL_RES*)res;
    int field_count = 0;

    if (myres == NULL)
    {
        return -1;
    }
    
    field_count = mysql_num_fields(myres);
    
    field = myres->fields;

    if ((field == NULL) || (field_count == 0 ))
    {
        return -1;
    }
    
    int loop;

    for(loop = 0; loop < field_count; loop++)
    {
        if (strcmp(col_name,field[loop].name) == 0)
        {
            return loop;
        }
    }
    
    return -1;
}


bool mydbcont::isconnected()
{
    return m_contflag;
}

int mydbcont::formatter(dbcont_colval* input_val)
{
    int time_ret[6] = {0,0,0,0,0,0};

    switch(input_val->vt)
    {
        case USQL_TYPE_BIT:
        case USQL_TYPE_INT8:
        case USQL_TYPE_INT16:
        case USQL_TYPE_INT32:
            input_val->val.i32= atoi(input_val->var);
            input_val->vt = USQL_TYPE_INT32;
            break;    

        case USQL_TYPE_INT64:
            sscanf(input_val->var, "%lld", &input_val->val.i64);
            break;

        case USQL_TYPE_FLOAT:
        case USQL_TYPE_DOUBLE:
            input_val->val.dou = atof(input_val->var);
            input_val->vt = USQL_TYPE_DOUBLE;
            break;
            
        case USQL_TYPE_TIMESTAMP:
        case USQL_TYPE_DATETIME:
            sscanf(input_val->var,"%04d-%02d-%02d %02d:%02d:%02d", 
                &time_ret[0], &time_ret[1], &time_ret[2], 
                &time_ret[3], &time_ret[4], &time_ret[5]
                );
                input_val->val.tm.year = time_ret[0];
                input_val->val.tm.month= time_ret[1];
                input_val->val.tm.day= time_ret[2];
                input_val->val.tm.hour = time_ret[3];
                input_val->val.tm.minute= time_ret[4];
                input_val->val.tm.second = time_ret[5];      
                input_val->vt = USQL_TYPE_DATETIME;
            break;

        default:
            break;
    }
    
    return 0;
}
