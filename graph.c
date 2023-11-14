#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "graph.h"

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: graph_construct failed to allocate memory.\n"));
    g->V = num_nodes;
    g->array = (AdjList*)malloc(num_nodes * sizeof(AdjList));

    for (int i = 0; i < num_nodes; ++i) {
        g->array[i] = *initAdjList();
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

// Graph* createGraph(int V) {
//     Graph* graph = (Graph*)malloc(sizeof(Graph));
//     graph->V = V;
//     graph->array = (AdjList*)malloc(V * sizeof(AdjList));

//     for (int i = 0; i < V; ++i) {
//         graph->array[i] = *initAdjList();
//     }

//     return graph;
// }

// Adiciona uma aresta ao grafo
void graph_add_edge(Graph *graph, int src, int dest, float weight){
    AdjListNode* newNode = newAdjListNode(dest, weight);
    addNode(&graph->array[src], newNode);
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