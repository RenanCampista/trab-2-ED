#if !defined(_GRAPH_H_)
#define _GRAPH_H_
#include "node.h"
#include "vector.h"

typedef struct Graph Graph;

struct Graph {
    int num_nodes;
    Vector *nodes;
};

Graph *graph_construct(int num_nodes);
void graph_destruct(Graph *g);
void graph_add_node(Graph *graph, int src, int neighbor, float weight);
void graph_read(Graph* graph, FILE *file);
Connection *graph_get_connection(Graph *graph, int idx_neighbor, int idx_connection);
int graph_get_num_connections_from_node(Graph *graph, int idx_neighbor);

#endif // _GRAPH_H_
