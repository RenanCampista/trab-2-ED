#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph_node.h"

GraphNode *graph_node_construct(int node_number) {
    GraphNode *graph_node = malloc(sizeof(GraphNode));
    graph_node->node_number = node_number;
    graph_node->connections = vector_construct();
    graph_node->dist_origin = FLT_MAX;
    return graph_node;
}

void graph_node_destruct(GraphNode *graph_node) {
    vector_destroy(graph_node->connections);
    free(graph_node);
}

int graph_node_get_node_number(GraphNode *graph_node) {
    return graph_node->node_number;
}

float graph_node_get_dist_origin(GraphNode *graph_node) {
    return graph_node->dist_origin;
}

void graph_node_set_dist_origin(GraphNode *graph_node, float dist_origin) {
    graph_node->dist_origin = dist_origin;
}

void graph_node_add_connection(GraphNode *graph_node, Connection *connection) {
    vector_push_back(graph_node->connections, connection);
}

int graph_node_dist_origin_is_defined(GraphNode *graph_node) {
    return graph_node->dist_origin != FLT_MAX;
}

void graph_node_print(GraphNode *graph_node) {
    printf("Node %d\n", graph_node->node_number);
    printf("Distance from origin: %f\n\n", graph_node->dist_origin);
    // printf("Connections:\n");
    // for (int i = 0; i < vector_size(graph_node->connections); i++) {
    //     Connection *connection = (Connection *) vector_get(graph_node->connections, i);
    //     printf("  Node %d, distance %f\n", connection_get_neighbor(connection), connection_get_distance(connection));
    // }
}