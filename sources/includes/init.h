#ifndef INIT
#define INIT
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
            //  incapsulation an initialization of the structer //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
struct List_t {
  data_t       *data;
  int          *next;
  int          *prev;
  char         *name;
  unsigned     capacity;
  int          fict;
  int          free;
  int          insertion;
  FILE         *dampfile;
};
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//


#endif
