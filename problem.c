#include <stdio.h>
#include <stdlib.h>
#include "problem.h"

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
    fclose(file);
    return problem;
}
