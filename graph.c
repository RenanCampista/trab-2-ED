#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph.h"

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: graph_construct failed to allocate memory.\n"));
    g->num_nodes = num_nodes;
    g->edge = vector_construct();
    for (int i = 0; i < num_nodes; i++) {
        AdjacencyList *e = adjacency_list_construct();
        vector_push_back(g->edge, e);
    }
    return g;
}

void graph_destruct(Graph *g) {
    vector_destroy(g->edge);
    free(g);
}

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight){
    AdjacencyList *e = (AdjacencyList *) vector_get(graph->edge, src);
    adjacency_list_add_node(e, dest, weight);
}

void graph_read(Graph* graph, FILE *file) {
    int dest;
    float weight;
    char c;
    for (int i = 0; i < graph->num_nodes; ++i) {
        while (1) {
            fscanf(file, "%d %f%c", &dest, &weight, &c);
            graph_add_edge(graph, i, dest, weight);
            if (c != ' ') {
                break;
            }
        }
    }
}

Node *graph_get_node(Graph *graph, int idx_egde, int idx_node) {
    AdjacencyList *e = (AdjacencyList *) vector_get(graph->edge, idx_egde);
    return adjacency_list_get_node(e, idx_node);
}

int graph_get_num_nodes_from_edge(Graph *graph, int idx_edge) {
    AdjacencyList *e = (AdjacencyList *) vector_get(graph->edge, idx_edge);
    return adjacency_list_get_num_nodes(e);
}