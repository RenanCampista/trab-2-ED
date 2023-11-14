#if !defined(_GRAPH_H_)
#define _GRAPH_H_
#include "adj_list.h"

typedef struct Graph Graph;

struct Graph {
    int V;
    AdjList* array;
};

Graph *graph_construct(int num_nodes);
//Graph* createGraph(int V);
void graph_destruct(Graph *g);

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight);

void graph_read(const char* filename, Graph* graph);

#endif // _GRAPH_H_
