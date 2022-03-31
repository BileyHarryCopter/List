#include "sources/list/list.h"

int main (void)
{
    List_t list_1;
    List_Ctor(&list_1, "list_1");


    List_Insrt(&list_1, NEXT, 0, 20);
    List_Insrt(&list_1, NEXT, 1, 30);
    List_Insrt(&list_1, NEXT, 2, 40);
    List_Insrt(&list_1, NEXT, 3, 60);
    List_Insrt(&list_1, NEXT, 4, 860);
    List_Insrt(&list_1, NEXT, 7, 13260);

    //List_Linearisation (&list_1);

    Graph_Dump (list_1);

    List_Dtor(&list_1);
    return 0;
}
