#pragma once

using namespace std;

#include <iostream>
#include <fstream>  
#include <sstream>  

#include <deque>
#include <vector>
#include <stack>

#include <string>  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FLOAT_MAX (3.4e+38)
#define FLOAT_MIN (3.4e-38)
#define DOUBLE_MAX (1.7e+308)
#define DOUBLE_MIN (1.7e-308)

typedef enum ussvtype { 
	USS_VTYPE_NULL = 0,
	USS_VTYPE_BOOL,
	USS_VTYPE_INT32,
	USS_VTYPE_UINT32,
	USS_VTYPE_DOUBLE
}ussvtype;

typedef struct ussvar {
    ussvtype vt;
    
    union {
        bool bol;
        signed int i32;
        unsigned int u32;
        double dou;
    }val;
} ussvar;