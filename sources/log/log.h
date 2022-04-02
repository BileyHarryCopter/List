//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

#define logassert(expresion, file, func, numb_er, name_er, list)    \
{                                                                   \
    if (!expression)                                                \
    {                                                               \
        LogAssert (expresion, file, func, numb_er, name_er, list);  \
        ListDtor (list);                                            \
        exit (EXIT_FAILURE);                                        \
    }                                                               \
}

#include "../includes/errors.h"

int LogDump   (const char * name_func, const int numb,     const char * name, List_t *list);
int LogAssert (bool expression,        const char * name_func,
                                       const int numb,
                                       const char * name, List_t *list);
