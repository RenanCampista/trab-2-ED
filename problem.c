// problem.c
#include <stdio.h>
#include <stdlib.h>
#include "problem.h"
#include "connection.h"
#include "graph_node.h"

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
    vector_destruct(problem->graph_nodes);
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
            if (c == '\n') {
                break;
            }
            Connection *connection = connection_create(neighbor, distance);
            graph_node_add_connection(graph_node, connection);
        }
        vector_push_back(problem->graph_nodes, graph_node);
    }
    fclose(file);

    return problem;
}

// int problem_get_min_neighbor(Problem *problem, int idx) {
//     if (idx < 0 || idx >= problem->num_nodes) {
//         exit(printf("Error: problem_get_min_neighbor index out of bounds.\n"));
//     }
    
//     Vector *connections = vector_get(problem->node_connections, idx);
//     int min_neighbor = -1;
//     //Pegar o vizinho com menor indice
//     for (int i = 0; i < vector_size(connections); i++) {
//         Connection *connection = vector_get(connections, i);
//         if (min_neighbor == -1 || connection->neighbor < min_neighbor) {
//             min_neighbor = connection->neighbor;
//         }
//     }
//     return min_neighbor;
// }