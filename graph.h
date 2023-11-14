#if !defined(_GRAPH_H_)
#define _GRAPH_H_
#include "adjacency_list.h"

typedef struct Graph Graph;

struct Graph {
    int num_nodes;
    AdjacencyList* array;
};

Graph *graph_construct(int num_nodes);

void graph_destruct(Graph *g);

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight);

//void graph_read(const char* filename, Graph* graph);

void graph_read(Graph* graph, FILE *file);

#endif // _GRAPH_H_
