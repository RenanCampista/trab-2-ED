#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void graph_printI(Graph *g) {
    printf("Number of nodes: %d\n", vector_size(g->adj));
    for (int i = 0; i < vector_size(g->adj); i++) {
        Vector *v = (Vector *)vector_get(g->adj, i);
        for (int j = 0; j < vector_size(v); j++) {
            float *distance = (float *)vector_get(v, j);
            printf("%d ", (int)*distance);
        }
        printf("\n");
    }
}

Graph *graph_construct(int num_nodes) {
    Graph *g = calloc(1, sizeof(Graph));
    if (g == NULL)
        exit(printf("Error: calloc failed\n"));
    g->adj = vector_construct();
    for (int i = 0; i < num_nodes; i++) {
        Vector *v = vector_construct();
        for (int j = 0; j < num_nodes; j++) {
            float *distance = malloc(sizeof(float));
            *distance = 0;
            vector_push_back(v, distance);
        }
        vector_push_back(g->adj, v);
    }
    return g;
}

void graph_destruct(Graph *g) {
    vector_destroy(g->adj);
    free(g);
}



void graph_read(Graph *g, FILE *file) {
    char c;
    for (int i = 0; i < vector_size(g->adj); i++) {
        while(1) {
            int neighbor;
            float *distance = malloc(sizeof(float));
            // fscanf(file, "%d %f%c", &neighbor, &distance, &c);
            fscanf(file, "%d %f%c", &neighbor, distance, &c);
            if(c != ' ' || c == '\n') {
                break;
            }
            Vector *v = (Vector *)vector_get(g->adj, i);
            vector_set(v, neighbor, distance);
        }
    }
    graph_printI(g);
    exit(1);
}

float graph_get(Graph *g, int i, int j) {
    Vector *v = (Vector *)vector_get(g->adj, i);
    float *distance = (float *)vector_get(v, j);
    return *distance;
}

