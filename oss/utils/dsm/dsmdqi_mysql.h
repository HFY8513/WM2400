#pragma once

#include "dsmdqi.h"

/*��Բ�ͬ�����ݿ�,���Խ�����ͬ��dqi�ӿ�ʵ����*/
class dqi_mysql : public dqi
{
public:
    dqi_mysql();
    virtual ~dqi_mysql();
    
    virtual int init(dbcont_param* dbparam, utrace *dqitrace);

};

