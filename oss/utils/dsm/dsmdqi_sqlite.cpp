
#include "dsmt212.h"
#include "dsmdqi_sqlite.h"
#include <qdebug.h>

dqi_sqlite::dqi_sqlite()
{
}

dqi_sqlite::~dqi_sqlite()
{

}

int dqi_sqlite::init(dbcont_param* dbparam)
{
    dbcontsqlite* db = new dbcontsqlite;
    char dbdir[DM_FILEPATH_SIZE];

    m_db = (dbcont*)db;

    if (m_db == NULL)
    {
        return -1;
    }
    if (getappdirex(dbdir, sizeof(dbdir), 1) != 0)
    {
        return -1;
    }
    if (strstr(dbparam->db_name, ".db") == NULL)
    {
        strcat(dbdir, "data\\zendb.db");
        strcpy(dbparam->db_name, dbdir);
    }

    m_db->setparam(dbparam);
    if (m_db->open() != 0)
    {
        return -2;
    }

    return 0;
}


