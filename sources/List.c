#include "list.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //    functions for sirvicing of List   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int List_Ctor (List_t *list, const char * list_name)
{
    assert (list);
    assert (list_name);
    list->data      = (data_t *) calloc (INITSIZE, sizeof (data_t));
    list->next      = (int *)    calloc (INITSIZE, sizeof (int));
    list->prev      = (int *)    calloc (INITSIZE, sizeof (int));
    list->name      = list_name;
    list->capacity  = INITSIZE;
    list->insertion = 0;
    list->free      = 1;

    for (int i = 1; i < INITSIZE - 1; i++)
    {
        list->next[i] = i + 1;
        list->prev[i] = -1;
    }
    list->next[INITSIZE - 1] = 0;
    list->prev[INITSIZE - 1] = -1;

    assert (list->data);
    assert (list->next);
    assert (list->prev);

    return 0;
}

int List_Dtor (List_t *list)
{
    free (list->data);
    free (list->next);
    free (list->prev);
    return NO_ERROR;
}

//   extracting a list on fixed size
int List_Resup (List_t *list)
{
    assert (list);
    unsigned size = list->capacity;
    list->data    = (data_t *) realloc (list->data, INCR_KOEF * (list->capacity) * sizeof(data_t));
    list->next    = (int *)    realloc (list->next, INCR_KOEF * (list->capacity) * sizeof(int));
    list->prev    = (int *)    realloc (list->prev, INCR_KOEF * (list->capacity) * sizeof(int));

    list->capacity *= INCR_KOEF;

    for (int i = size - 1; i < list->capacity; i++)
    {
        list->next[i] = i + 1;
        list->prev[i] = -1;
    }
    list->next[list->capacity - 1] = 0;

    return NO_ERROR;
}

int List_Insrt (List_t *list, int mode, int insrt_ptr, data_t insrt_val)
{
    assert (list);
    if ((list->insertion) > CRIT_KOEF * (list->capacity))
    {
        List_Resup (list);
    }

    assert (list);

    int Free         = list->free;
    list->data[Free] = insrt_val;
    list->free       = list->next[Free];

    if (mode == NEXT || mode == JUST)
    {
        list->next[Free]                  = list->next[insrt_ptr];
        list->prev[Free]                  = insrt_ptr;
        list->prev[list->next[insrt_ptr]] = Free;
        list->next[insrt_ptr]             = Free;
    }
    else if (mode == PREV)
    {
        list->prev[Free]                  = list->prev[insrt_ptr];
        list->next[Free]                  = insrt_ptr;
        list->next[list->prev[insrt_ptr]] = Free;
        list->prev[insrt_ptr]             = Free;
    }

    (list->insertion)++;

    return NO_ERROR;
}

int List_Delete (List_t *list, int del_ptr)
{
    assert (list);

    list->data[del_ptr]             = 0;
    list->next[list->prev[del_ptr]] = list->next[del_ptr];
    list->prev[list->next[del_ptr]] = list->prev[del_ptr];

    list->next[del_ptr] = list->free;
    list->prev[del_ptr] = -1;
    list->free          = del_ptr;
    list->insertion    -= 1;
    return NO_ERROR;
}

void List_Print (List_t list)
{
    printf("\t\tNAME: %s\n", list.name);

    for (int i = 0; i < list.capacity; i++)
    {
        printf("---------\n");
        printf("DATA: %lf\n", list.data[i]);
        printf("NEXT: %d\n", list.next[i]);
        printf("PREV: %d\n", list.prev[i]);
        printf("FREE: %d\n", list.free);
        printf("INSERTION: %u\n", list.insertion);
        printf("CAPACITY: %u\n", list.capacity);
        printf("---------\n\n\n");
    }
}
