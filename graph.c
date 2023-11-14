#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph.h"

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: graph_construct failed to allocate memory.\n"));
    g->V = num_nodes;
    g->array = (AdjacencyList*)malloc(num_nodes * sizeof(AdjacencyList));

    for (int i = 0; i < num_nodes; ++i) {
        g->array[i] = *initAdjacencyList();
    }

    return g;
}

void graph_destruct(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        vector_destroy(g->array[i].nodes);
    }
    free(g->array);
    free(g);
}


// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight){
    Node* new_Node = newNode(dest, weight);
    addNode(&graph->array[src], new_Node);
}

void graph_read(const char* filename, Graph* graph) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int V;
    fscanf(file, "%d", &V);

    // Atualiza o número de vértices no grafo
    graph->V = V;

    for (int i = 0; i < V; ++i) {
        int dest;
        float weight;
        char c;
        //fscanf(file, "%d", &src);

        while (1) {
            fscanf(file, "%d %f%c", &dest, &weight, &c);
            graph_add_edge(graph, i, dest, weight);
            if (c != ' ') {
                break;
            }
        }
    }

    fclose(file);
}