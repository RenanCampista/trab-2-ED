#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "problem.h"
#include "path.h"

void print_and_destroy_paths(Vector *paths)  { 
    for (int i = 0; i < vector_size(paths); i++) { 
        Path *path = vector_get(paths, i); 
        path_print(path); 
        path_destroy(path); 
    } 
    vector_destroy(paths); 
} 

int main() {
    Problem *problem_data;
   // Vector *paths;

    problem_data = problem_data_read("in.txt");

     djikstra_solve(problem_data);
    //print_and_destroy_paths(paths);
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

// void print_and_destroy_paths(Vector *paths)  { 
//     for (int i = 0; i < vector_size(paths); i++) { 
//         Path *path = vector_get(paths, i); 
//         path_print(path); 
//         path_destroy(path); 
//     } 
//     vector_destroy(paths); 
// } 
 
// int main() { 
//     Problem *problem_data; 
//     Vector *paths; 

//     problem_data = problem_data_read("in.txt"); 
//     paths = djikstra_solve(problem_data); 
//     print_and_destroy_paths(paths); 
//     problem_data_destroy(problem_data); 
    
//     return 0; 
// } 