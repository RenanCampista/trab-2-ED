#include "path.h"
#include <stdio.h>
#include <stdlib.h>

Path *path_create(int length) {
    Path *path = (Path *)malloc(sizeof(Path));
    path->nodes = (int *)malloc(length * sizeof(int));
    path->length = length;
    path->cost = 0;
    return path;
}

void path_destroy(Path *path) {
    free(path->nodes);
    free(path);
}

void path_print(Path *path) {
    printf("0 -> %d: %.2f\n", path->nodes[0], path->cost);
    for (int i = 1; i < path->length; i++) {
        printf("0 -> %d", path->nodes[0]);
        for (int j = 1; j <= i; j++) {
            printf(" -> %d", path->nodes[j]);
        }
        printf(": %.2f\n", path->cost);
    }
}
