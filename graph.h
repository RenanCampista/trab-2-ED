#if !defined(_GRAPH_H_)
#define _GRAPH_H_
#include "adjacency_list.h"
#include "vector.h"

typedef struct Graph Graph;

struct Graph {
    int num_nodes;
    //AdjacencyList* edges; //arestas
    //Tentar usar um vector para salvar as arestas
    Vector *edge;
};

Graph *graph_construct(int num_nodes);

void graph_destruct(Graph *g);

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight);

void graph_read(Graph* graph, FILE *file);

Node *graph_get_node(Graph *graph, int idx_egde, int idx_node);
int graph_get_num_nodes_from_edge(Graph *graph, int idx_edge);
#endif // _GRAPH_H_
