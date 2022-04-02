#include "list.h"
#include "../includes/init.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //    functions for sirvicing of List   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
List_t *ListCtor (char * list_name)
{
    assert (list_name);
    List_t *list    = (List_t *) calloc (1, sizeof (List_t));
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

    return list;
}

int ListDtor (List_t *list)
{
    free (list->data);
    free (list->next);
    free (list->prev);
    return NO_ERROR;
}

//  slowly a little
int LogToPhys (List_t *list, int log_pos)
{
    assert (list);
    int phys = 0;

    if (log_pos >= list->insertion)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }

    for (int i = 0; i < log_pos; i++)
    {
        phys = list->next[phys];
    }
    return phys;
}

//  slowly a little
int PhysToLog (List_t *list, int phys_pos)
{
    assert (list);
    int pos, log = 0;

    if (list->prev[phys_pos] == -1)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }

    pos = phys_pos;
    while (list->prev[pos] != 0)
    {
        log++;
        pos = list->prev[pos];
    }
    return log + 1;
}

//   extracting a list on fixed size
int ListResup (List_t *list)
{
    assert (list);
    unsigned size = list->capacity;
    list->data    = (data_t *) realloc (list->data, INCR_KOEF * (list->capacity) * sizeof(data_t));
    list->next    = (int *)    realloc (list->next, INCR_KOEF * (list->capacity) * sizeof(int));
    list->prev    = (int *)    realloc (list->prev, INCR_KOEF * (list->capacity) * sizeof(int));
    list->capacity *= INCR_KOEF;

    for (unsigned i = size - 1; i < list->capacity; i++)
    {
        list->next[i] = i + 1;
        list->prev[i] = -1;
    }
    list->next[list->capacity - 1] = 0;

    return NO_ERROR;
}

int ListInsrt (List_t *list, int mode, int insrt_ptr, data_t insrt_val)
{
    assert (list);

    if (insrt_ptr >= list->capacity)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }
    if (list->prev[insrt_ptr] == -1)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }

    if ((list->insertion) > CRIT_KOEF * (list->capacity))
    {
        ListResup (list);
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

int ListDelete (List_t *list, int del_ptr)
{
    assert (list);

    if (del_ptr >= list->capacity)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }
    if (list->prev[del_ptr] == -1)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }
    if (list->insertion == 0)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }
    if (del_ptr == 0)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }

    list->data[del_ptr]             = 0;
    list->next[list->prev[del_ptr]] = list->next[del_ptr];
    list->prev[list->next[del_ptr]] = list->prev[del_ptr];

    list->next[del_ptr] = list->free;
    list->prev[del_ptr] = -1;
    list->free          = del_ptr;
    list->insertion    -= 1;
    return NO_ERROR;
}

void ListPrint (List_t list)
{
    printf("\t\tNAME: %s\n", list.name);

    for (unsigned i = 0; i < list.capacity; i++)
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

//  very slowly and hungry for memory
int ListLinearisation (List_t *list)
{
    assert (list);
    int first = 0;
    int second = 0;
    int insert = list->insertion;
    data_t * new_mass = (data_t *) calloc (list->capacity, sizeof (data_t));

    if (list->insertion == 0)
    {
    //  ADD errors checking
    //  soft allertion about this error with message in terminal to checkout the logfile
        return ERROR;
    }

    first = list->next[first];
    for (int i = 0; i < insert; i++)
    {
        second = first;
        first = list->next[second];
        new_mass[i] = list->data[second];
        ListDelete (list, second);
        if (first == 0)
            break;
    }

//  updating data of the list
    list->free = 1;
    for (unsigned i = 1; i < list->capacity - 1; i++)
    {
        list->next[i] = i + 1;
        list->prev[i] = -1;
    }
    list->next[list->capacity - 1] = 0;
    list->prev[list->capacity - 1] = -1;


    for (int i = 0; i < insert; i++)
    {
        ListInsrt (list, NEXT, i, new_mass[i]);
    }

    free (new_mass);
    return NO_ERROR;
}
