#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"


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
void djikstra_solve(Problem *problem) {
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

        Vector* nodes = problem->graph->array[u].nodes;
        for (int i = 0; i < vector_size(nodes); i++) {
            //AdjListNode* currentNode = (AdjListNode*)nodes->data[i];
            Node *currentNode = (Node*)vector_get(nodes, i);
            int v = currentNode->dest;
            if (!sptSet[v] && dist[u] != FLT_MAX && (dist[u] + currentNode->weight < dist[v])) {
                dist[v] = dist[u] + currentNode->weight;
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, 0, V);
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