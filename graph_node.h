#if !defined(_GRAPH_NODE_H_)
#define _GRAPH_NODE_H_
#include "vector.h"
#include "connection.h"

#define DISTANCE_NOT_DEFINED -1.0

typedef struct {
    int node_number;
    Vector *connections;
    float dist_origin;
} GraphNode;

GraphNode *graph_node_construct(int node_number);
void graph_node_destruct(GraphNode *graph_node);
int graph_node_get_node_number(GraphNode *graph_node);
void graph_node_set_dist_origin(GraphNode *graph_node, float dist_origin);
void graph_node_add_connection(GraphNode *graph_node, Connection *connection);
int graph_node_dist_origin_is_defined(GraphNode *graph_node);
float graph_node_get_dist_origin(GraphNode *graph_node);

#endif // _GRAPH_NODE_H_
