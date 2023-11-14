#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "graph.h"
#include "path.h"
#include "heap.h"

int minDistance(float dist[], int sptSet[], int V) {
    float min = FLT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Função que implementa o algoritmo de Dijkstra
Vector* djikstra_solve(Problem *problem) {
    int V = problem->num_nodes;
    float dist[V];
    int parent[V];

    Vector *visited = vector_construct();

    for (int i = 0; i < V; i++) {
        dist[i] = FLT_MAX;
        parent[i] = -1;

        int *visited_value = (int*)malloc(sizeof(int));
        *visited_value = 0;
        vector_push_back(visited, visited_value);
    }

    dist[0] = 0;
    Heap *not_visited = heap_construct();
    int *origin = (int*)malloc(sizeof(int));
    *origin = 0;
    heap_push(not_visited, origin, 0);

    while(!heap_is_empty(not_visited)) {
        int *u = (int*)heap_pop(not_visited);

        int *visited_value = vector_get(visited, *u);
        if(visited_value == NULL || *visited_value == 1) {
            free(u);
            continue;
        }
        *visited_value = 1;

        for (int i = 0; i < graph_get_num_connections_from_node(problem->graph, *u); i++) {
            Connection *current_connection = graph_get_connection(problem->graph, *u, i);
            int v = connection_get_neighbor(current_connection);
            int weight = connection_get_weight(current_connection);
            int *visited_status = vector_get(visited, v);
            if (!(*visited_status) && dist[*u] != FLT_MAX && (dist[*u] + weight < dist[v])) {
                dist[v] = dist[*u] + weight;
                parent[v] = *u;
                int *value = (int*)malloc(sizeof(int));
                *value = v;
                heap_push(not_visited, value, dist[v]);
            } 
        }
        free(u);
    }

    Vector *paths = vector_construct();
    for (int i = 1; i < V; i++) {
        Path *p = path_create(dist, parent, i);
        vector_push_back(paths, p);
    }
    
    heap_destroy(not_visited, free);
    vector_destroy(visited, free);
    return paths;
}
