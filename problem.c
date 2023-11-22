#include <stdio.h>
#include <stdlib.h>
#include "problem.h"

struct Problem {
    Graph *graph;
};

Problem *problem_construct(int num_nodes) {
    Problem *problem = (Problem *)calloc(1, sizeof(Problem));
    if (problem == NULL)
        exit(printf("Error: problem_construct failed to allocate memory.\n"));

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
    Problem *problem = problem_construct(num_nodes);
    graph_read(problem->graph, file);
    fclose(file);
    return problem;
}


int problem_get_num_nodes(Problem *problem) {
    return graph_get_num_nodes(problem->graph);
}

Graph *problem_get_graph(Problem *problem) {
    return problem->graph;
}
