#include "dump.h"
#include "err_ass.h"
#include "init.h"
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//
//  REALISATION OF DUMPING  //
//===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*===*//

char *SystemDot(List_t *list, char *name_file) {
  char *Fname = (char *)calloc(FLEXSIZE, sizeof(char));
  strcat(Fname, "dot ");
  strcat(Fname, name_file);
  strcat(Fname, " -T png -o logs/");
  strcat(Fname, list->name);
  strcat(Fname, "_dump.png");

  return Fname;
}

char *SystemOpen(List_t *list) {
  char *Oname = (char *)calloc(FLEXSIZE, sizeof(char));
  strcat(Oname, "open logs/");
  strcat(Oname, list->name);
  strcat(Oname, "_dump.png");
  return Oname;
}

int GraphDump(List_t *list) {
  assert(list->name);
  char *name_file = (char *)calloc(2 * NAMESIZE, sizeof(char));
  strcpy(name_file, "logs/");
  strcat(name_file, list->name);
  strcat(name_file, "_dump.dot");
  assert(name_file);

  FILE *file = fopen(name_file, "w");
  assert(file);
  if (file == NULL)
    return DOT_ERROR;

  //  hard damping
  fseek(file, 0L, SEEK_SET);
  fprintf(file,
          "digraph LIST\n"
          "{\n"
          "\tgraph [dpi = 200, nodesep = 1];\n"
          "\trankdir = LR;\n\n"
          "\tsubgraph LISTS\n"
          "\t{\n"
          "\t\tnode [shape = record, style = \"filled\", fillcolor = \"teal\", "
          "fontcolor = \"white\"];\n"
          "\t\tedge [maxlen = 2, penwidth = 1, arrowhead = \"empty\", weight = "
          "0, dir = \"both\"];\n"
          "\t\t\tl_elem_%d [label = \"<name> FICT | <next> NEXT: %d | <prev> "
          "PREV: %d | <data> DATA: null\", fillcolor = \"darkslategray\"];\n",
          0, list->next[0], list->prev[0]);
  for (int i = 1; i < list->capacity; i++) {
    fprintf(file,
            "\t\t\tl_elem_%d [label = \"<name> NODE: %d | <next> NEXT: %d | "
            "<prev> PREV: %d | <data> DATA: %.2lf\"];\n",
            i, i, list->next[i], list->prev[i], list->data[i]);
  }

  fprintf(file, "\t\tl_elem_0");
  for (int i = 1; i < list->capacity; i++) {
    fprintf(file, "->l_elem_%d", i);
  }
  fprintf(file, " [weight = 5, style = \"invisible\", arrowhead = \"none\", "
                "dir = \"forward\"];\n\n");

  if (list->insertion != 0) {
    for (int i = 0; i < list->capacity; i++) {
      if (i == 0) {
        fprintf(file, "\t\tl_elem_%d:se -> l_elem_%d:sw;\n", i, list->next[i]);
        fprintf(file, "\t\tl_elem_%d:ne -> l_elem_%d:nw;\n", i, list->prev[i]);
        continue;
      } else if (list->prev[i] == -1 || list->next[i] == 0)
        continue;
      if (list->next[i] < i) {
        fprintf(file, "\t\tl_elem_%d:nw -> l_elem_%d:ne;\n", i, list->next[i]);
        continue;
      }
      fprintf(file, "\t\tl_elem_%d:se -> l_elem_%d:sw;\n", i, list->next[i]);
    }
  }

  fprintf(file, "\t}\n\n");

  fprintf(file,
          "\tsubgraph MAIN\n"
          "\t{\n"
          "\t\tnode\t[shape = record, width = 2, height = 2, style = "
          "\"filled\", fillcolor = \"olive\", fontcolor = \"white\"];\n"
          "\t\tedge\t[maxlen = 1 , penwidth = 1, arrowhead = \"empty\"];\n"
          "\t\tmain\t[label = \"{NAME:  %s} | {CAPACITY:  %u} | {INSERT:  %d} "
          "| {FREE:  %d} | {FICT:  %d}\"];\n"
          "\t}\n\n",
          list->name, list->capacity, list->insertion, list->free, list->fict);

  fprintf(file,
          "\tsubgraph TITLE\n"
          "\t{\n"
          "\t\tnode 	[shape = ellipse, height = 1, style = \"filled\", "
          "fillcolor = \"greenyellow\", fontcolor = \"black\"];\n"
          "\t\ttitle 	[label = \"Graphic Dump\"];\n"
          "\t}\n\n");

  fprintf(file, "}\n");

  // TODO: nothing works
  // why???
  fclose(file);

  //  invocation a dump.png with function "system (const char *)"
  char *commdump = SystemDot(list, name_file);
  char *opendump = SystemOpen(list);
  system(commdump);
  system(opendump);
  free(commdump);
  free(opendump);

  return NO_ERROR;
}
