#ifndef ERR
#define ERR

//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
            //  initialization of whole errors-constant //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
enum numberrors
{
    NO_ERROR = 0,
    ERROR,
    NULL_PTR_ERROR,
    INSERT_ERROR,
    DELETE_UNEXISTED,
    DELETE_EMPTY,
    DELETE_FICT,
    LINEAR_ERROR,
    FIND_UNEXISTED,
    DOT_ERROR,
    NUMBER_OF_ERROR
};

typedef struct namerrors
{
    char * names [NUMBER_OF_ERROR];
} namerrors;

namerrors ERROR_NAMES =
{
    "NO_ERROR",
    "ERROR",
    "structer of list_type with null ptr_adress was sended to the function",
    "trying to insert around unexisted element",
    "trying to delete an unexisted element",
    "trying to delete an element from empty list",
    "trying to delete a fictive element from the list",
    "truing to linearizate an empty list",
    "trying to find a number of unexisted element",
    "problem with openning a dot file"
};
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

#endif
