#if !defined(_HEAP_H_)
#define _HEAP_H_
#include "vector.h"

typedef struct {
    void *data;
    double priority;
} HeapNode;

typedef struct Heap Heap;

Heap *heap_construct();
void heap_destroy(Heap *heap, void (*destroy_fn)(data_type));
void heap_push(Heap *heap, data_type data, double priority);
data_type heap_pop(Heap *heap);
int heap_is_empty(Heap *heap);
HeapNode heap_top(Heap *heap);

#endif // _HEAP_H_
