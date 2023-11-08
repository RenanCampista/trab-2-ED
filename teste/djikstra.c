#include "djikstra.h"
#include "heap.h"
#include "vector.h"
#include "problem.h"
#include "path.h"
#include <float.h>
#include <stdlib.h>

Vector *djikstra_solve(Problem *problem) {
    int num_nodes = problem->num_nodes;
    float *distances = (float *)malloc(num_nodes * sizeof(float));
    int *predecessors = (int *)malloc(num_nodes * sizeof(int));
    int *visited = (int *)malloc(num_nodes * sizeof(int));

    for (int i = 0; i < num_nodes; i++) {
        distances[i] = FLT_MAX;
        predecessors[i] = -1;
        visited[i] = 0;
    }

    distances[0] = 0; // Distância da fábrica para si mesma é zero
    Heap *heap = heap_create(num_nodes);
    heap_push(heap, 0, 0);

    while (!heap_empty(heap)) {
        HeapNode current = heap_top(heap);
        heap_pop(heap);
        if (visited[current.node]) {
            continue;
        }
        visited[current.node] = 1;

        for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
            if (!visited[neighbor] && problem->graph[current.node][neighbor] > 0) {
                float new_distance = distances[current.node] + problem->graph[current.node][neighbor];
                if (new_distance < distances[neighbor]) {
                    distances[neighbor] = new_distance;
                    predecessors[neighbor] = current.node;
                    heap_push(heap, neighbor, new_distance);
                }
            }
        }
    }

    Vector *paths = vector_create(num_nodes - 1);
    for (int dest = 1; dest < num_nodes; dest++) {
        if (distances[dest] == FLT_MAX) {
            continue; // Não é possível alcançar o destino
        }
        int current = dest;
        int path_length = 0;
        while (current != 0) {
            path_length++;
            current = predecessors[current];
        }
        Path *path = path_create(path_length);
        current = dest;
        for (int i = path_length - 1; i >= 0; i--) {
            path->nodes[i] = current;
            current = predecessors[current];
        }
        path->cost = distances[dest];
        vector_push(paths, path);
    }

    free(distances);
    free(predecessors);
    free(visited);
    heap_destroy(heap);

    return paths;
}
