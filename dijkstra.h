#if !defined(_DIJKSTRA_H_)
#define _DIJKSTRA_H_
#include "graph.h"
#include "problem.h"

int minDistance(float dist[], int sptSet[], int V);

void printPath(int parent[], int j);

// Função que implementa o algoritmo de Dijkstra
void dijkstra(Graph* graph, int src);
void djikstra_solve(Problem *problem);
#endif // _DIJKSTRA_H_
