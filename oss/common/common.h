#pragma once

#include "loadcsv.h"
#include "utime.h"
#include "ucsv.h"
#include "upub.h"
#include "ustr.h"
#include "utime.h"
#include "utrace.h"
//#include "uque.h"

int common_trace(int level, const char* module, bool condition, const char* fmt, ...);
int common_log(int level, const char* fmt, ...);
