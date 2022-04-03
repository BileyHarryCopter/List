#include "../includes/standarts.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
#define logassert(express, file, func, numb_error, name_list)                  \
{                                                                              \
    if (!(express))                                                            \
    {                                                                          \
        return LogAssert (func, numb_error, name_list);                        \
    }                                                                          \
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int LogDump   (const char * name_func, const int numb, const char * name_list);
int LogAssert (const char * name_func, const int numb, const char * name_list);
