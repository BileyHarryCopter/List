#include "list.h"

int main (void)
{
    List_t list_1;
    List_Ctor(&list_1, "list_1");

    List_Insrt(&list_1, NEXT, 0, 20);
    List_Insrt(&list_1, NEXT, 1, 30);
    List_Insrt(&list_1, NEXT, 2, 40);
    List_Insrt(&list_1, NEXT, 3, 50);
    List_Insrt(&list_1, NEXT, 4, 60);
    List_Insrt(&list_1, NEXT, 5, 70);
    List_Insrt(&list_1, NEXT, 6, 80);
    List_Insrt(&list_1, NEXT, 7, 90);
    List_Insrt(&list_1, NEXT, 8, 1000);
    List_Insrt(&list_1, NEXT, 9, 13120);
    List_Insrt(&list_1, NEXT, 10, 920);

    List_Delete (&list_1, 2);
    List_Insrt(&list_1, NEXT, 2, 30);

    List_Print(list_1);

    Graph_Damp (list_1);

    List_Dtor(&list_1);
    return 0;
}
