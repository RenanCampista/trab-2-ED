#if !defined(_HEAP_H_)
#define _HEAP_H_
#include "vector.h"

typedef struct HeapNode{
    void *data;
    float priority;
} HeapNode;

typedef struct Heap Heap;

Heap *heap_construct();
void heap_destroy(Heap *heap, void (*destroy_fn)(data_type));
void heap_push(Heap *heap, data_type data, float priority);
data_type heap_pop(Heap *heap);
int heap_is_empty(Heap *heap);
HeapNode heap_top(Heap *heap);
data_type heap_node_get_data(HeapNode *node);

#endif // _HEAP_H_
