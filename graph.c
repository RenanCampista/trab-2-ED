#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph.h"

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: graph_construct failed to allocate memory.\n"));
    g->num_nodes = num_nodes;
    g->edges = (AdjacencyList*)malloc(num_nodes * sizeof(AdjacencyList));

    for (int i = 0; i < num_nodes; ++i) {
        g->edges[i] = *adjacency_list_construct();
    }

    return g;
}

void graph_destruct(Graph *g) {
    // for (int i = 0; i < g->num_nodes; i++) {
    //     vector_destroy(g->edges[i].nodes);
    // }
    free(g->edges);
    free(g);
}

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight){
    //Criar um Adjacenc list e dps push_back
    adjacency_list_add_node(&graph->edges[src], dest, weight);
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
    return adjacency_list_get_node(&graph->edges[idx_egde], idx_node);
}

int graph_get_num_nodes_from_edge(Graph *graph, int idx_edge) {
    return adjacency_list_get_num_nodes(&graph->edges[idx_edge]);
}