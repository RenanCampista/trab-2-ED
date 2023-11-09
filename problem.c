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
            if (c != ' ') {
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

void problem_set_smallest_origin_distance_from_nodes(Problem *problem) {
    //Definir distancia da origem sendo 0
    GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, 0);
    graph_node_set_dist_origin(node, 0.0);
    //Definir as distancias 
    for (int i = 0; i < vector_size(node->connections); i++) {
        Connection *c = (Connection *) vector_get(node->connections, i);
        GraphNode *n = (GraphNode *) vector_get(problem->graph_nodes, connection_get_neighbor(c));
        graph_node_set_dist_origin(n, connection_get_distance(c));
    }

    for (int i = 1; i < problem->num_nodes; i++) {
        GraphNode *node = (GraphNode *) vector_get(problem->graph_nodes, i);
        //Lembrar que sempre o no 1 ira se conectar com a origem
        //verificar as conexoes
        if (!graph_node_dist_origin_is_defined(node)) {
            for (int j = 0; j < vector_size(node->connections); j++) {
                Connection *c = (Connection *) vector_get(node->connections, j);
                if (connection_get_neighbor(c) == 0) {
                    //Define a distancia 
                // graph_node_set_dist_origin(node, connection_get_distance(c));
                //Ja foi definido então pode parar e ir para o proximo
                    break;
                } else {
                    //Olhar o no
                    GraphNode *n = (GraphNode *) vector_get(problem->graph_nodes, connection_get_neighbor(c));
                    if(graph_node_dist_origin_is_defined(n)) {
                        float distance = connection_get_distance(c) + graph_node_get_dist_origin(n);
                        graph_node_set_dist_origin(node, distance);
                        break;
                    }
                    
                }
            }
        }
    }
}