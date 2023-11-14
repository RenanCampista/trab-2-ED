#include "path.h"
#include <stdio.h>
#include <stdlib.h>

Path *path_create() {
    Path *path = (Path *)calloc(1, sizeof(Path));
    if (path == NULL)
        exit(printf("Error: bla bla bla\n"));
    path->nodes = vector_construct();
    path->cost = 0;
    return path;
}

void path_destroy(Path *path) {
    free(path->nodes);
    free(path);
}

void path_add_node (Path *path, int *parent) {
    vector_push_back(path->nodes, parent);
}

void path_print(Path *path) {
    for (int i = 0; i < vector_size(path->nodes); i++) {
        int *num = (int *) vector_get(path->nodes, i);
        printf("%d", *num);
        if (i < vector_size(path->nodes) - 1)
            printf(" -> ");
    }
    printf(": %.2f\n", path->cost);
}