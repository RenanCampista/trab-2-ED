#include "vector.h"
#include <stdlib.h>

Vector *vector_create(int initial_capacity) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->data = (void **)malloc(initial_capacity * sizeof(void *));
    vector->size = 0;
    vector->capacity = initial_capacity;
    return vector;
}

void vector_push(Vector *vector, void *value) {
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = (void **)realloc(vector->data, vector->capacity * sizeof(void *));
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void *vector_get(Vector *vector, int index) {
    if (index >= 0 && index < vector->size) {
        return vector->data[index];
    }
    return NULL;
}

int vector_size(Vector *vector) {
    return vector->size;
}

void vector_destroy(Vector *vector) {
    free(vector->data);
    free(vector);
}
