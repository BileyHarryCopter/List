#ifndef LOG
#define LOG

#include "../list/list.h"
#include "../includes/standarts.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
#define logassert(express, file, func, numb_error, list)                       \
{                                                                              \
    if (!(express))                                                            \
    {                                                                          \
        LogAssert (func, numb_error, list);                                    \
        ListDtor (list);                                                       \
        exit (EXIT_FAILURE);                                                   \
    }                                                                          \
}
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int LogDump   (const char * name_func, const int numb, struct List_t *list);
int LogAssert (const char * name_func, const int numb, struct List_t *list);

#endif
