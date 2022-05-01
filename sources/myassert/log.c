#include "log.h"

#include "err_ass.h"
#include "init.h"

int LogAssert(const char *name_func, const int numb, List_t *list) {
  printf("There are some errors in the program... Check the \"Logfile\" in the "
         "directory \"logs/\"\n");
  LogDump(name_func, numb, list);
  return ERROR;
}

int LogDump(const char *name_func, const int numb, List_t *list) {
  FILE *logfile = fopen("sources/myassert/Logfile", "w");
  assert(logfile);
  fseek(logfile, 0L, SEEK_SET);

  if (numb == NULL_PTR_ERROR) {
    fprintf(logfile, "Name of the list: null\n");
    fprintf(logfile, "Called  function: %s\n", name_func);
    fprintf(logfile, "Number of  error: %d\n", NULL_PTR_ERROR);
    fprintf(logfile, "Reason of  error: %s\n",
            ERROR_NAMES.names[NULL_PTR_ERROR]);
    return NULL_PTR_ERROR;
  }

  fprintf(logfile, "Name of the list: %s\n", list->name);
  fprintf(logfile, "Called  function: %s\n", name_func);

  switch (numb) {
  case INSERT_ERROR: {
    fprintf(logfile, "Number of  error: %d\n", INSERT_ERROR);
    fprintf(logfile, "Reason of  error: %s\n", ERROR_NAMES.names[INSERT_ERROR]);
    return INSERT_ERROR;
  };
  case DELETE_UNEXISTED: {
    fprintf(logfile, "Number of  error: %d\n", DELETE_UNEXISTED);
    fprintf(logfile, "Reason of  error: %s\n",
            ERROR_NAMES.names[DELETE_UNEXISTED]);
    return DELETE_EMPTY;
  };
  case DELETE_EMPTY: {
    fprintf(logfile, "Number of  error: %d\n", DELETE_EMPTY);
    fprintf(logfile, "Reason of  error: %s\n", ERROR_NAMES.names[DELETE_EMPTY]);
    return DELETE_EMPTY;
  };
  case DELETE_FICT: {
    fprintf(logfile, "Number of  error: %d\n", DELETE_FICT);
    fprintf(logfile, "Reason of  error: %s\n", ERROR_NAMES.names[DELETE_FICT]);
    return DELETE_FICT;
  };
  case LINEAR_ERROR: {
    fprintf(logfile, "Number of  error: %d\n", LINEAR_ERROR);
    fprintf(logfile, "Reason of  error: %s\n", ERROR_NAMES.names[LINEAR_ERROR]);
    return LINEAR_ERROR;
  };
  case FIND_UNEXISTED: {
    fprintf(logfile, "Number of  error: %d\n", FIND_UNEXISTED);
    fprintf(logfile, "Reason of  error: %s\n",
            ERROR_NAMES.names[FIND_UNEXISTED]);
    return LINEAR_ERROR;
  };
  case DOT_ERROR: {
    fprintf(logfile, "Number of  error: %d\n", DOT_ERROR);
    fprintf(logfile, "Reason of  error: %s\n", ERROR_NAMES.names[DOT_ERROR]);
    return DOT_ERROR;
  };
  default: {
    fprintf(logfile, "OH MAY!\n");
    fprintf(logfile, "You can find new error for my progrmam.\n");
    fprintf(logfile, "I am grateful and very please you write about the "
                     "problem on my GitHub repo:\n");
    fprintf(logfile, "https://github.com/BileyHarryCopter/List/issues\n");
    break;
  }
  }

  fclose(logfile);
  return NO_ERROR;
}
