#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "graph.h"
#include "path.h"
#include "heap.h"

void dijkstra_initialize_vectors (Problem *problem, Vector *dist, Vector *parent, Vector *visited) {
    for (int i = 0; i < problem_get_num_nodes(problem); i++) {
        float *dist_value = (float *)malloc(sizeof(float));
        *dist_value = i == 0 ? 0 : FLT_MAX;
        vector_push_back(dist, dist_value);

        int *parent_value = (int *)malloc(sizeof(int));
        *parent_value = -1;
        vector_push_back(parent, parent_value);

        int *visited_value = (int *)malloc(sizeof(int));
        *visited_value = 0;
        vector_push_back(visited, visited_value);
    }
}

void dijkstra_navegate_connections(Problem *problem, int current_node, Vector *visited, Vector *dist, Vector *parent, Heap *not_visited) {
    /**
     * Para cada vizinho do nó atual, se o vizinho não foi visitado e a distância do vizinho é maior que a distância do nó atual + o peso da conexão entre o nó atual e o vizinho, 
     * então atualiza a distância do vizinho e o pai do vizinho.
     * 
     * O parente mais próximo do vizinho passará a ser o nó atual.
     * 
     * Como o vizinho não foi visitado, ele será adicionado na heap de nós não visitados.
    */
    float *dist_current_node = vector_get(dist, current_node);
    for (int i = 0; i < graph_get_num_connections_from_node(problem_get_graph(problem), current_node); i++) {
        Connection *current_connection = graph_get_connection(problem_get_graph(problem), current_node, i);
        int current_neighbor = connection_get_neighbor(current_connection);
        float connection_weight = connection_get_weight(current_connection);

        int *neighbor_was_visited = vector_get(visited, current_neighbor);
        float *dist_current_neighbor = vector_get(dist, current_neighbor);

        if (!(*neighbor_was_visited) && *dist_current_node != FLT_MAX && (*dist_current_node + connection_weight < *dist_current_neighbor)) {
            *dist_current_neighbor = *dist_current_node + connection_weight;

            int *parent_value = vector_get(parent, current_neighbor);
            *parent_value = current_node;

            int *value = (int *)malloc(sizeof(int));
            *value = current_neighbor;
            heap_push(not_visited, value, *dist_current_neighbor);
        }
    }
}

Vector *djikstra_save_path(Problem *problem, Vector *dist, Vector *parent) {
    Vector *paths = vector_construct();
    for (int i = 1; i < problem_get_num_nodes(problem); i++) {
        Path *p = path_construct(dist, parent, i);
        vector_push_back(paths, p);
    }
    vector_destroy(dist, free);
    vector_destroy(parent, free);
    return paths;
}

Vector* djikstra_solve(Problem *problem) {
    Vector *dist = vector_construct();
    Vector *parent = vector_construct(); // parent[i] = vizinho com o menor caminho até o nó i
    Vector *visited = vector_construct();
    dijkstra_initialize_vectors(problem, dist, parent, visited);

    Heap *not_visited = heap_construct();
    int *origin = (int*)malloc(sizeof(int));
    *origin = 0;
    heap_push(not_visited, origin, 0);

    while(!heap_is_empty(not_visited)) {
        int *current_node = (int*)heap_pop(not_visited);

        int *was_visited = vector_get(visited, *current_node);
        if(was_visited == NULL || *was_visited) {
            free(current_node);
            continue;
        }
        *was_visited = 1;
        
        dijkstra_navegate_connections(problem, *current_node, visited, dist, parent, not_visited);
        free(current_node);
    }

    heap_destroy(not_visited, free);
    vector_destroy(visited, free);

    return djikstra_save_path(problem, dist, parent);
}
