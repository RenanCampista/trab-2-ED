#include "problem.h"
#include <stdio.h>
#include <stdlib.h>

Problem *problem_data_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    Problem *problem = (Problem *)malloc(sizeof(Problem));
    fscanf(file, "%d", &problem->num_nodes);

    // Aloca memória para a matriz de adjacência (grafo)
    problem->graph = (float **)malloc(problem->num_nodes * sizeof(float *));
    for (int i = 0; i < problem->num_nodes; i++) {
        problem->graph[i] = (float *)malloc(problem->num_nodes * sizeof(float));
        for (int j = 0; j < problem->num_nodes; j++) {
            fscanf(file, "%f", &problem->graph[i][j]);
        }
    }

    fclose(file);
    return problem;
}

void problem_data_destroy(Problem *problem) {
    for (int i = 0; i < problem->num_nodes; i++) {
        free(problem->graph[i]);
    }
    free(problem->graph);
    free(problem);
}
