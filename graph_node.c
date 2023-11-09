#include <stdio.h>
#include <stdlib.h>
#include "graph_node.h"
#include "connection.h"

GraphNode *graph_node_construct(int node_number) {
    GraphNode *graph_node = malloc(sizeof(GraphNode));
    graph_node->node_number = node_number;
    graph_node->connections = vector_construct();
    graph_node->dist_origin = DISTANCE_NOT_DEFINED;
    return graph_node;
}

void graph_node_destruct(GraphNode *graph_node) {
    vector_destruct(graph_node->connections);
    free(graph_node);
}

int graph_node_get_node_number(GraphNode *graph_node) {
    return graph_node->node_number;
}

void graph_node_set_dist_origin(GraphNode *graph_node, float dist_origin) {
    graph_node->dist_origin = dist_origin;
}

void graph_node_add_connection(GraphNode *graph_node, Connection *connection) {
    vector_push_back(graph_node->connections, connection);
}