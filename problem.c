// problem.c
#include <stdio.h>
#include <stdlib.h>
#include "problem.h"
#include "connection.h"
#include "graph_node.h"
#include <float.h>

Problem *problem_create(int num_nodes) {
    Problem *problem = (Problem *)calloc(1, sizeof(Problem));
    if (problem == NULL)
        exit(printf("Error: problem_create failed to allocate memory.\n"));

    problem->num_nodes = num_nodes;
    problem->graph_nodes = vector_construct();
    return problem;
}

void problem_destroy(Problem *problem) {
    for (int i = 0; i < vector_size(problem->graph_nodes); i++) {
        GraphNode *graph_node = vector_get(problem->graph_nodes, i);
        graph_node_destruct(graph_node);
    }
    vector_destroy(problem->graph_nodes);
    free(problem);
}

Problem *problem_data_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        exit(printf("Error: problem_data_read failed to open file.\n"));
    }

    int num_nodes;
    fscanf(file, "%d", &num_nodes);

    Problem *problem = problem_create(num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        char c;
        int neighbor;
        float distance;
     
        GraphNode *graph_node = graph_node_construct(i);
        while(1) {
            fscanf(file, "%d %f%c", &neighbor, &distance, &c);
            // printf("%d %d ", neighbor, (int)distance);
            if (c != ' '|| c == '\n') {
                // printf("\n");
                break;
            }
            
            Connection *connection = connection_create(neighbor, distance);
            graph_node_add_connection(graph_node, connection);
        }
        vector_push_back(problem->graph_nodes, graph_node);
    }
    fclose(file);
    // exit(1);
    return problem;
}

// void problem_set_smallest_origin_distance_from_nodes(Problem *problem) {
//     //Definir distancia da origem sendo 0
//     GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, 0);
//     graph_node_set_dist_origin(node, 0.0);
//     //Definir as distancias 
//     for (int i = 0; i < vector_size(node->connections); i++) {
//         Connection *c = (Connection *) vector_get(node->connections, i);
//         GraphNode *n = (GraphNode *) vector_get(problem->graph_nodes, connection_get_neighbor(c));
//         graph_node_set_dist_origin(n, connection_get_distance(c));
//     }

// for (int k = 0; k < 2; k++) {
//     for (int i = 1; i < problem->num_nodes; i++) {
//         GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, i);
//         float min_distance = FLT_MAX; // Inicialize a distância mínima como infinito

//         for (int j = 0; j < vector_size(node->connections); j++) {
//             Connection *c = (Connection *) vector_get(node->connections, j);
//             float distance;

//             if (connection_get_neighbor(c) == 0) {
//                 distance = connection_get_distance(c);
//             } else {
//                 GraphNode *n = (GraphNode *) vector_get(problem->graph_nodes, connection_get_neighbor(c));
//                 if(graph_node_dist_origin_is_defined(n)) {
//                     distance = connection_get_distance(c) + graph_node_get_dist_origin(n);
//                 } else {
//                     continue; // Se a distância do vizinho à origem ainda não foi definida, ignore esta conexão
//                 }
//             }

//             if (distance < min_distance) {
//                 min_distance = distance; // Se a distância calculada for menor que a distância mínima atual, atualize a distância mínima
//             }
//         }

//         // Depois de verificar todas as conexões, defina a distância do nó para a origem como a distância mínima encontrada
//         graph_node_set_dist_origin(node, min_distance);
//     }
// }
    // for (int i = 1; i < problem->num_nodes; i++) {
    //     GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, i);
    //     //Lembrar que sempre o no 1 ira se conectar com a origem
    //     //verificar as conexoes
    //     if (!graph_node_dist_origin_is_defined(node)) {
    //         for (int j = 0; j < vector_size(node->connections); j++) {
    //             Connection *c = (Connection *) vector_get(node->connections, j);
    //             if (connection_get_neighbor(c) == 0) {
    //                 //Define a distancia 
    //             graph_node_set_dist_origin(node, connection_get_distance(c));
    //             //Ja foi definido então pode parar e ir para o proximo
    //                 break;
    //             } else {
    //                 //Olhar o no
    //                 GraphNode *n = (GraphNode *) vector_get(problem->graph_nodes, connection_get_neighbor(c));
    //                 if(graph_node_dist_origin_is_defined(n)) {
    //                     float distance = connection_get_distance(c) + graph_node_get_dist_origin(n);
    //                     graph_node_set_dist_origin(node, distance);
    //                     break;
    //                 }
                    
    //             }
    //         }
    //     }
    // }
// }

void problem_print(Problem *problem) {
    problem_set_smallest_origin_distance_from_nodes(problem);
    printf("Number of nodes: %d\n", problem->num_nodes);
    for (int i = 0; i < vector_size(problem->graph_nodes); i++) {
        GraphNode *graph_node = (GraphNode *) vector_get(problem->graph_nodes, i);
        graph_node_print(graph_node);
    }
}

int minDistance(float dist[], int visited[], int num_nodes) {
    float min = FLT_MAX;
    int min_index;

    for (int v = 0; v < num_nodes; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void problem_set_smallest_origin_distance_from_nodes(Problem *problem) {
    int num_nodes = problem->num_nodes;
    float dist[num_nodes]; 
    int visited[num_nodes];

    for (int i = 0; i < num_nodes; i++) {
        dist[i] = FLT_MAX;
        visited[i] = 0;
    }

    dist[0] = 0; 

    for (int i = 0; i < num_nodes - 1; i++) {
        int u = minDistance(dist, visited, num_nodes);
        visited[u] = 1;

        for (int v = 0; v < num_nodes; v++) {
            Connection *connection = (Connection *)vector_get(((GraphNode *)vector_get(problem->graph_nodes, u))->connections, v);
            if (!visited[v] && connection && dist[u] != FLT_MAX
                && dist[u] + connection_get_distance(connection) < dist[v]) {
                dist[v] = dist[u] + connection_get_distance(connection);
            } 
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, i);
        graph_node_set_dist_origin(node, dist[i]);
    }
}



// void dijkstra(Problem *problem, int origin) {
//     float dist[problem->num_nodes];
//     int visited[problem->num_nodes];

//     for (int i = 0; i < problem->num_nodes; i++) {
//         dist[i] = FLT_MAX;
//         visited[i] = 0;
//     }

//     dist[origin] = 0;

//     for (int i = 0; i < problem->num_nodes - 1; i++) {
//         int u = minDistance(dist, visited, problem->num_nodes);
//         visited[u] = 1;

//         for (int v = 0; v < problem->num_nodes; v++) {
//         Connection *connection = (Connection *)vector_get(((GraphNode *)vector_get(problem->graph_nodes, u))->connections, v);
//         if (!visited[v] && connection && dist[u] != FLT_MAX
//             && dist[u] + connection_get_distance(connection) < dist[v]) {
//             dist[v] = dist[u] + connection_get_distance(connection);
//         }
//         }
//     }
// }

// int minDistance(float dist[], int visited[], int num_nodes) {
//     float min = FLT_MAX;
//     int min_index;

//     for (int v = 0; v < num_nodes; v++) {
//         if (visited[v] == 0 && dist[v] <= min) {
//             min = dist[v];
//             min_index = v;
//         }
//     }

//     return min_index;
// }