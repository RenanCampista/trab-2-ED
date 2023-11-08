#ifndef PATH_H
#define PATH_H

typedef struct Path {
    int *nodes;    // Sequência de nós no caminho
    int length;    // Número de nós no caminho
    float cost;    // Custo total do caminho
} Path;

Path *path_create(int length);
void path_destroy(Path *path);
void path_print(Path *path);

#endif
