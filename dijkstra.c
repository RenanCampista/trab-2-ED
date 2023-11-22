#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dijkstra.h"
#include "graph.h"
#include "path.h"
#include "heap.h"

Vector* djikstra_solve(Problem *problem) {
    Vector *dist = vector_construct();
    Vector *parent = vector_construct();
    Vector *visited = vector_construct();

    for (int i = 0; i < problem_get_num_nodes(problem); i++) {
        float *dist_value = (float*)malloc(sizeof(float));
        *dist_value = i == 0 ? 0 : FLT_MAX;
        vector_push_back(dist, dist_value);

        int *parent_value = (int*)malloc(sizeof(int));
        *parent_value = -1;
        vector_push_back(parent, parent_value);

        int *visited_value = (int*)malloc(sizeof(int));
        *visited_value = 0;
        vector_push_back(visited, visited_value);
    }

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


        /*
        Para cada conexão, obter o nó vizinho (v) e o peso da conexão.
        Verificar se o nó vizinho já foi visitado e se a distância atual do nó *u não é infinita (ou seja, o nó *u já foi visitado) e se a distância do nó *u mais o peso da conexão é menor que a distância atual do nó vizinho.
        Se todas essas condições forem verdadeiras, ele atualiza a distância do nó vizinho para a soma da distância do nó *u e o peso da conexão.
        Ele também atualiza o nó pai do nó vizinho para o nó *u.
        Finalmente, adiciona o nó vizinho à lista de nós não visitados, com a nova distância como prioridade.
        */
        for (int i = 0; i < graph_get_num_connections_from_node(problem_get_graph(problem), *u); i++) {
            Connection *current_connection = graph_get_connection(problem_get_graph(problem), *u, i);
            int v = connection_get_neighbor(current_connection);
            float weight = connection_get_weight(current_connection);
            int *visited_status = vector_get(visited, v);
            float *dist_u_value = vector_get(dist, *u);
            float *dist_v_value = vector_get(dist, v);
            if (!(*visited_status) && *dist_u_value != FLT_MAX && (*dist_u_value + weight < *dist_v_value)) {
                *dist_v_value = *dist_u_value + weight;

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
    for (int i = 1; i < problem_get_num_nodes(problem); i++) {
        Path *p = path_create(dist, parent, i);
        vector_push_back(paths, p);
    }
    
    heap_destroy(not_visited, free);
    vector_destroy(visited, free);
    vector_destroy(dist, free);
    vector_destroy(parent, free);
    return paths;
}
