#if !defined(_GRAPH_H_)
#define _GRAPH_H_

#include "vector.h"

typedef struct Graph Graph;
struct Graph {
    Vector *adj;
};

Graph *graph_construct(int num_nodes);

void graph_destruct(Graph *g);

void graph_read(Graph *g, FILE *file);

float graph_get(Graph *g, int i, int j);
 void graph_printI(Graph *g);

#endif // _GRAPH_H_
