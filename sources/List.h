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

typedef struct {
  data_t      *data;
  int         *next;
  int         *prev;
  char        *name;
  unsigned     capacity;
  int          fict;
  int          free;
  int          insertion;
  FILE *       dampfile;
} List_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int List_Dtor(List_t *list);
int List_Ctor(List_t *list, const char * name_list);
int List_Resup(List_t *list);
int List_Delete(List_t *list, int del_ptr);
int List_Insrt(List_t *list, int mode, int insrt_ptr, data_t insrt_val);
int Graph_Dump (List_t list);
void List_Print(List_t list);
int Log_to_Phys (List_t *list, int log_pos);
int List_Linearisation (List_t *list);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
