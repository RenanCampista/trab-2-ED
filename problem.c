// problem.c
#include <stdio.h>
#include <stdlib.h>
#include "problem.h"
#include <float.h>

Problem *problem_create(int num_nodes) {
    Problem *problem = (Problem *)calloc(1, sizeof(Problem));
    if (problem == NULL)
        exit(printf("Error: problem_create failed to allocate memory.\n"));

    problem->num_nodes = num_nodes;
    problem->graph = graph_construct(num_nodes);
    return problem;
}

void problem_destroy(Problem *problem) {
    graph_destruct(problem->graph);
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
    graph_read(problem->graph, file);
    // for (int i = 0; i < num_nodes; i++) {
    //     char c;
    //     int neighbor;
    //     float distance;
     
    //     GraphNode *graph_node = graph_node_construct(i);
    //     while(1) {
    //         fscanf(file, "%d %f%c", &neighbor, &distance, &c);
    //         // printf("%d %d ", neighbor, (int)distance);
    //         if (c != ' '|| c == '\n') {
    //             // printf("\n");
    //             break;
    //         }
            
    //         Connection *connection = connection_create(neighbor, distance);
    //         graph_node_add_connection(graph_node, connection);
    //     }
    //     vector_push_back(problem->graph_nodes, graph_node);
    // }
    fclose(file);
    // exit(1);
    return problem;
}

// void problem_print(Problem *problem) {
//     problem_set_smallest_origin_distance_from_nodes(problem);
//     printf("Number of nodes: %d\n", problem->num_nodes);
//     for (int i = 0; i < vector_size(problem->graph_nodes); i++) {
//         GraphNode *graph_node = (GraphNode *) vector_get(problem->graph_nodes, i);
//         graph_node_print(graph_node);
//     }
// }

