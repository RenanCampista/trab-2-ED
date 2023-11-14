#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "graph.h"
#include "path.h"


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

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void return_numbers(int parent[], int *j, Path *p) {
    if(parent[*j] == -1) {
        path_add_node(p, j);
        return;
    }

    return_numbers(parent, &parent[*j], p);
    path_add_node(p, j);
}

void printSolution(float dist[], int parent[], int src, int num_nodes) {
   // printf("Caminhos mais curtos a partir da origem %d:\n", src);
    for (int i = 0; i < num_nodes; i++) {
        if (i != src) {

            printPath(parent, i);
            printf(": %.2f\n", dist[i]);

        }
    }
}

// Função que implementa o algoritmo de Dijkstra
Vector* djikstra_solve(Problem *problem) {
    int V = problem->num_nodes;
    float dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = FLT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        for (int i = 0; i < graph_get_num_connections_from_node(problem->graph, u); i++) {
            Connection *current_connection = graph_get_connection(problem->graph, u, i);
            int v = connection_get_neighbor(current_connection);
            int weight = connection_get_weight(current_connection);
            if (!sptSet[v] && dist[u] != FLT_MAX && (dist[u] + weight < dist[v])) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    //printSolution(dist, parent, 0, V);

    // Vector *paths = vector_construct();
    // for (int i = 0; i < V; i++) {
    //     Path *p = path_create();
    //     int *k = malloc(sizeof(int));
    //     *k = i;
    //     return_numbers(parent, k, p);
    //     p->cost = dist[i];
    //     vector_push_back(paths, p);
    // }

    Vector *paths = vector_construct();
    for (int i = 1; i < V; i++) {
        Path *p = path_create(dist, parent, i);
        vector_push_back(paths, p);
    }

    return paths;
    
}


// void dijkstra(Graph* graph, int src) {
//     int V = graph->V;
//     float dist[V];
//     int sptSet[V];
//     int parent[V];

//     for (int i = 0; i < V; i++) {
//         dist[i] = FLT_MAX;
//         sptSet[i] = 0;
//         parent[i] = -1;
//     }

//     dist[src] = 0;

//     for (int count = 0; count < V - 1; count++) {
//         int u = minDistance(dist, sptSet, V);
//         sptSet[u] = 1;

//         Vector* nodes = graph->array[u].nodes;
//         for (int i = 0; i < vector_size(nodes); i++) {
//             //AdjListNode* currentNode = (AdjListNode*)nodes->data[i];
//             AdjListNode *currentNode = (AdjListNode*)vector_get(nodes, i);
//             int v = currentNode->dest;
//             if (!sptSet[v] && dist[u] != FLT_MAX && (dist[u] + currentNode->weight < dist[v])) {
//                 dist[v] = dist[u] + currentNode->weight;
//                 parent[v] = u;
//             }
//         }
//     }

//     printSolution(dist, parent, src, V);
// }