#pragma once

#include "dbcont/dbcont.h"

//#include "mydbcont/mydbcont.h"
#include "dbcontsqlite/dbcontsqlite.h"


dbcont* dbcont_init(const char* type, dbcont_param* param);
