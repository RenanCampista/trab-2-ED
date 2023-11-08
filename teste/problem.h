#ifndef PROBLEM_H
#define PROBLEM_H

typedef struct Problem {
    int num_nodes;
    float **graph; // Matriz de adjacência representando o grafo
} Problem;

Problem *problem_data_read(const char *filename);
void problem_data_destroy(Problem *problem);

#endif