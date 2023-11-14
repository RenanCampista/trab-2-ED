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

Vector* djikstra_solve(Problem *problem) {
    int V = problem->num_nodes;
    Vector* dist = vector_construct();
    //int parent[V];
    Vector *parent = vector_construct();
    Vector *visited = vector_construct();

    for (int i = 0; i < V; i++) {
        float *dist_value = (float*)malloc(sizeof(float));
        *dist_value = FLT_MAX;
        vector_push_back(dist, dist_value);

        int *parent_value = (int*)malloc(sizeof(int));
        *parent_value = -1;
        vector_push_back(parent, parent_value);

        int *visited_value = (int*)malloc(sizeof(int));
        *visited_value = 0;
        vector_push_back(visited, visited_value);
    }

    float *dist_value = vector_get(dist, 0);
    *dist_value = 0;

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
            float *dist_u_value = vector_get(dist, *u);
            float *dist_v_value = vector_get(dist, v);
            if (!(*visited_status) && *dist_u_value != FLT_MAX && (*dist_u_value + weight < *dist_v_value)) {
                *dist_v_value = *dist_u_value + weight;
               // parent[v] = *u;
                int *parent_value = vector_get(parent, v);
                *parent_value = *u;
                int *value = (int*)malloc(sizeof(int));
                *value = v;
                heap_push(not_visited, value, *dist_v_value);
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
    vector_destroy(dist, free);
    vector_destroy(parent, free);
    return paths;
}
