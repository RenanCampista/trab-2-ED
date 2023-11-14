#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "problem.h"

int main() {
    Problem *problem_data;

    problem_data = problem_data_read("in.txt");

    djikstra_solve(problem_data);
    problem_destroy(problem_data);


    return 0;
}


// int main() {
//     int V = 9;
//     Graph* graph = createGraph(V);

//     graph_read("in.txt", graph);

//     dijkstra(graph, 0);

//     return 0;
// }
