#ifndef LIST
#define LIST

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE  10
#define CRIT_KOEF 0.6
#define INCR_KOEF 2
#define FLEXSIZE 1000

enum errors {
  NO_ERROR = 0,
  ERROR,
  DAMP_ERROR
};

enum modes {
  NEXT = 1,
  PREV,
  JUST
};

enum sizes {
    NAMESIZE = 50
};

typedef double data_t;
typedef struct List_t List_t;

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
List_t *ListCtor      (char * name_list);
int ListDtor          (List_t *list);
int ListResup         (List_t *list);
int ListDelete        (List_t *list, int del_ptr);
int ListInsrt         (List_t *list, int mode, int insrt_ptr, data_t insrt_val);
int GraphDump         (List_t *list);
int LogToPhys         (List_t *list, int log_pos);
int PhysToLog         (List_t *list, int phys_pos);
int ListLinearisation (List_t *list);

void ListPrint        (List_t list);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

#endif
