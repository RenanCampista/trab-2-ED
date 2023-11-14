#if !defined(_PROBLEM_H_)
#define _PROBLEM_H_

#include "vector.h"
#include "graph.h"


typedef struct {
    int num_nodes;
    Graph *graph;
} Problem;

Problem *problem_create(int num_nodes);
void problem_destroy(Problem *problem);
Problem *problem_data_read(const char *filename);
//void problem_print(Problem *problem);


#endif // _PROBLEM_H_
