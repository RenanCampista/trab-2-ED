#if !defined(_PATH_H_)
#define _PATH_H_
#include "vector.h"

typedef struct Path {
    Vector *nodes; 
    float cost;    // Custo total do caminho
} Path;

Path *path_create(float dist[], int parent[], int dest);
void path_destroy(Path *path);
void path_print(Path *path);

void path_add_node (Path *path, int *parent);

#endif // _PATH_H_
