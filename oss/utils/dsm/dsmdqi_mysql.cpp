
#include "dsmt212.h"
#include "dsmdqi_mysql.h"
#include "oss/utils/udbi/mydbcont/mydbcont.h"

dqi_mysql::dqi_mysql()
{
}

dqi_mysql::~dqi_mysql()
{

}

int dqi_mysql::init(dbcont_param* dbparam, utrace* dqitrace)
{
//    mydbcont* db = new mydbcont;
//    char logdir[DM_FILEPATH_SIZE];

//    m_db = (dbcont*)db;

//    if (m_db == NULL)
//    {
//        return -1;
//    }

//    m_db->setparam(dbparam);

//    if (m_db->open() != 0)
//    {
//        return -2;
//    }

//    if (dqitrace == NULL)
//    {
//        return -3;
//    }

////  /  m_utrace = dqitrace;

    return 0;
}


