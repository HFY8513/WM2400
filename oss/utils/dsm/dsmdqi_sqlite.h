#pragma once

#include "dsmdqi.h"


/*针对不同的数据库,可以建立不同的dqi接口实现类*/
class dqi_sqlite: public dqi
{
public:
    dqi_sqlite();
    virtual ~dqi_sqlite();
    
    virtual int init(dbcont_param* dbparam);

};
