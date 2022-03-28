#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE  10
#define CRIT_KOEF 0.6
#define INCR_KOEF 2

enum errors {
  NO_ERROR = 0,
};

enum modes {
  NEXT = 1,
  PREV,
  JUST,
};

typedef double data_t;

typedef struct {
  data_t      *data;
  int         *next;
  int         *prev;
  unsigned int capacity;
  int          free;
  int          insertion;
} List_t;
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int List_Dtor(List_t *list);
int List_Ctor(List_t *list);
int List_Resup(List_t *list);
int List_Delete(List_t *list, int del_ptr);
int List_Insrt(List_t *list, int mode, int insrt_ptr, data_t insrt_val);

void List_Print(List_t list, char *str);
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
