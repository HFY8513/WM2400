/*ljh
#include "../mydbcont/mydbcont.h"

dbcont* dbcont_init(const char* type, dbcont_param* param)
{
	dbcont* db = NULL;

	if (strcmp(type, "mysql"))
	{
		db = (dbcont*)(new mydbcont);
		if (db != NULL)
		{
			db->setparam(param);
		}
	}

	return db;
}*/
