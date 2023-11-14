#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph.h"

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: graph_construct failed to allocate memory.\n"));
    g->num_nodes = num_nodes;
    g->nodes = vector_construct();
    for (int i = 0; i < num_nodes; i++) {
        Node *n = node_construct();
        vector_push_back(g->nodes, n);
    }
    return g;
}

void graph_destruct(Graph *graph) {
    vector_destroy(graph->nodes, node_destruct);
    free(graph);
}

void graph_add_node(Graph *graph, int src, int neighbor, float weight){
    Node *n = (Node *) vector_get(graph->nodes, src);
    node_add_connection(n, neighbor, weight);
}

void graph_read(Graph* graph, FILE *file) {
    int neighbor;
    float weight;
    char c;
    for (int i = 0; i < graph->num_nodes; ++i) {
        while (1) {
            fscanf(file, "%d %f%c", &neighbor, &weight, &c);
            graph_add_node(graph, i, neighbor, weight);
            if (c != ' ') {
                break;
            }
        }
    }
}

Connection *graph_get_connection(Graph *graph, int idx_neighbor, int idx_connection) {
    Node *n = (Node *) vector_get(graph->nodes, idx_neighbor);
    return node_get_connection(n, idx_connection);
}

int graph_get_num_connections_from_node(Graph *graph, int idx_neighbor) {
    Node *n = (Node *) vector_get(graph->nodes, idx_neighbor);
    return node_get_num_connections(n);
}
