#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    void **data;
    int size;
    int capacity;
} Vector;

Vector *vector_create(int initial_capacity);
void vector_push(Vector *vector, void *value);
void *vector_get(Vector *vector, int index);
int vector_size(Vector *vector);
void vector_destroy(Vector *vector);

#endif