#include "path.h"
#include <stdio.h>
#include <stdlib.h>

Path *path_create(Vector *dist, Vector *parent, int dest) {
    Path *path = (Path *)calloc(1, sizeof(Path));
    if (path == NULL)
        exit(printf("Error: bla bla bla\n"));
    path->nodes = vector_construct();
    path->cost = vector_get(dist, dest) == NULL ? -1 : *(float *)vector_get(dist, dest);

    int current = dest;
    while (current != -1) {
        int* copy = (int*)malloc(sizeof(int));
        *copy = current;
        vector_push_back(path->nodes, copy);
        current = vector_get(parent, current) == NULL ? -1 : *(int *)vector_get(parent, current);
    }

    return path;
}

void path_destroy(Path *path) {
    for (int i = 0; i < vector_size(path->nodes); i++) {
        int *num = (int *) vector_get(path->nodes, i);
        free(num);
    }
    vector_destroy(path->nodes, NULL);
    free(path);
}

void path_add_node (Path *path, int *parent) {
    vector_push_back(path->nodes, parent);
}

void path_print(Path *path) {
    for (int i = vector_size(path->nodes) - 1; i >= 0; i--) {
        int *num = (int *) vector_get(path->nodes, i);
        printf("%d", *num);
        if (i > 0)
            printf(" -> ");
    }
    printf(": %.2f\n", path->cost);
}
