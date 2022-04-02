#include "sources/list/list.h"

int main (void)
{
    List_t *list_1 = ListCtor ("list_1");


    ListInsrt(list_1, NEXT, 0, 20);
    ListInsrt(list_1, NEXT, 1, 30);
    ListInsrt(list_1, NEXT, 2, 40);
    ListInsrt(list_1, NEXT, 3, 60);
    ListInsrt(list_1, NEXT, 4, 86);

    ListDelete(list_1, 0);

    //  ListInsrt(&list_1, NEXT, 7, 13260);

    ListLinearisation (list_1);

    GraphDump (list_1);

    ListDtor(list_1);
    return 0;
}
