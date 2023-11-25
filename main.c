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
    vector_destroy(paths, NULL); 
} 

int main() {
    Problem *problem_data;
    Vector *paths;

    char file_name[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", file_name);

    problem_data = problem_data_read(file_name);
    paths = djikstra_solve(problem_data);
    print_and_destroy_paths(paths);
    problem_destroy(problem_data);

    return 0;
}