// problem.h
#ifndef PROBLEM_H
#define PROBLEM_H

#include "vector.h"
#include "graph.h"

typedef struct {
    int num_nodes;
    Graph *graph;
} Problem;

Problem *problem_create(int num_nodes);
void problem_destroy(Problem *problem);
Problem *problem_data_read(const char *filename);
void problem_set_smallest_origin_distance_from_nodes(Problem *problem);
void problem_print(Problem *problem);
#endif
