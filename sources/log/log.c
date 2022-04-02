//  реализация функции записи в логфайл
//  функция её вызова
#include "log.h"


int LogAssert (bool expression, const char * name_func, const int numb, const char * name, List_t *list)
{
    if (!expression)
    {
        printf ("There are some errors in the program... Check the \"Logfile\" in the directory \"sources/log/\"\n");
        LogDump (name_func, numb, name, list);
    }
    return NO_ERROR;
}

int LogDump (const char * name_func, const int numb, const char * name, List_t *list)
{
    FILE * logfile = fopen ("Logfile", "w");
    fseek (logfile, 0L, SEEK_SET);

    if (numb == NULL_PTR_ERROR)
    {
        fprintf (logfile, "Name of the list: null\n");
        fprintf (logfile, "Called  function: %s\n", name_func);
        fprintf (logfile, "Number of  error: %d\n", NULL_PTR_ERROR);
        fprintf (logfile, "Name   of  error: %s\n", ERROR_NAMES[NULL_PTR_ERROR]);
        return NULL_PTR_ERROR;
    }

    fprintf (logfile, "Name of the list: %s\n", list->name);
    fprintf (logfile, "Called  function: %s\n", name_func);

    switch (numb)
    {
        case INSERT_ERROR:
            {
                fprintf (logfile, "Number of  error: %d\n", NULL_PTR_ERROR);
                fprintf (logfile, "Name   of  error: %s\n", ERROR_NAMES[NULL_PTR_ERROR]);
                return INSERT_ERROR;
            };
        case LINEAR_ERROR:
            {
                fprintf (logfile, "Number of  error: %d\n", LINEAR_ERROR);
                fprintf (logfile, "Name   of  error: %s\n", ERROR_NAMES[LINEAR_ERROR]);
                return LINEAR_ERROR;
            };
        case DELETE_ERROR:
            {
                fprintf (logfile, "Number of  error: %d\n",DELETE_ERROR);
                fprintf (logfile, "Name   of  error: %s\n", ERROR_NAMES[DELETE_ERROR]);
                return DELETE_ERROR;
            };
        case EMPTY_ERROR:
            {
                fprintf (logfile, "Number of  error: %d\n", EMPTY_ERROR);
                fprintf (logfile, "Name   of  error: %s\n", ERROR_NAMES[EMPTY_ERROR]);
                return EMPTY_ERROR;
            };
        default:
            {
                fprintf (logfile, "OH MAY!\n");
                fpritnf (logfile, "You can find new error for my progrmam.\n");
                fpritnf (logfile, "I am grateful and very please you write about the problem on my GitHub repo:\n");
                fpritnf (logfile, "https://github.com/BileyHarryCopter/List/issues\n");
                break;
            }
    }

    fclose (logfile);
    return NO_ERROR;
}
