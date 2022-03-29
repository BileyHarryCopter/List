#include "list.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
                    //    functions for dumping of List   //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
int Graf_Dump (List_t list)
{
    assert (list.name);
    char * name_file = strcat (list.name, "_damp.dot");
    printf ("NAME OF THE FILE: %s\n", name_file);
    assert (name_file);
    FILE * file = fopen (name_file, "w");
    if (file == NULL)
        return DAMP_ERROR;
//  hard damping
    fseek (file, 0L, SEEK_SET);
    fprintf (file,
            "digraph LIST\n"
            "{"
            "\tdpi = 200;\n"
            "\trankdir = LR;\n\n"
            "\tsubgraph LISTS\n"
            "\t{\n"
            "\t\tnode [shape = record, style = \"filled\", fillcolor = \"teal\", fontcolor = \"white\"];\n"
            "\t\tedge [maxlen = 2, penwidth = 1, arrowhead = \"empty\", weight = 1];\n"
            "\t\t\tl_elem_fict [label = \"<name> FICT | <next> NEXT: %d | <prev> PREV: %d | <data> DATA: null\", fillcolor = \"darkslategray\"];\n",
            list.next[0], list.prev[0]);
    for (int i = 1; i < list.capacity; i++)
    {
        fprintf (file, "\t\t\tl_elem_%d [label = \"<name> NODE: %d | <next> NEXT: %d | <prev> PREV: %d | <data> DATA: %lf\"];)\n",
                        i, i, list.next[i], list.prev[i], list.data[i]);
    }

    fprintf (file, "\t\tl_elem_fict->");
    for (int i = 1; i < list.capacity; i++)
    {
        fprintf (file, "l_elem_%d->", i);
    }
    fprintf (file, " [weight = 5, style = \"invisible\", arrowhead = \"none\"];\n\n");
    fprintf (file, "\t\tl_elem_fict:next -> l_elem_%d:name\n", list.next[0]);

    for (int i = 0; i < list.capacity; i++)
    {
        if (list.prev[i] == -1)
            continue;
        fprintf (file, "\t\tl_elem_%d:next -> l_elem_%d:name\n", i, list.next[0]);
    }
    fprintf (file, "\t\t}\n\n");

    fprintf (file,
            "\tsubgraph MAIN\n"
            "\t{\n"
            "\t\tnode\t[shape = record, width = 2, height = 2, style = \"filled\", fillcolor = \"olive\", fontcolor = \"white\"];\n"
            "\t\tedge\t[maxlen = 1 , penwidth = 1, arrowhead = \"empty\"];\n"
            "\t\tmain\t[label = \"{NAME:  %s} | {CAPACITY:  %u} | {INSERT:  %d} | {FREE:  %d} | {FICT:  %d}\"];\n"
            "\t}\n\n",
            name_file, list.capacity, list.insertion, list.free, list.fict);

    fprintf (file, "}\n");

    fclose (file);
    return NO_ERROR;
}
