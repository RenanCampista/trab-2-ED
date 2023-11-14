#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


struct Heap {
    Vector *nodes;
};

Heap *heap_construct() {
    Heap *heap = (Heap *)calloc(1, sizeof(Heap));
    if (heap == NULL)
        exit(printf("Error: heap_construct: could not allocate memory.\n"));
    heap->nodes = vector_construct();
    return heap;
}

void heap_destroy(Heap *heap, void (*destroy_fn)(data_type)) {
    if (destroy_fn != NULL) {
        for (int i = 0; i < vector_size(heap->nodes); i++)
            destroy_fn(vector_get(heap->nodes, i));
    }
    vector_destroy(heap->nodes, free);
    free(heap);
}

void  swap_nodes(Heap *heap, int i, int j) {
    vector_swap(heap->nodes, i, j);
}

//Heap for min priority
void heapify_down(Heap *heap, int idx) {
    int min = idx;
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;

    if (left_child < vector_size(heap->nodes) && ((HeapNode*)vector_get(heap->nodes, left_child))->priority < ((HeapNode*)vector_get(heap->nodes, min))->priority)
        min = left_child;

    if (right_child < vector_size(heap->nodes) && ((HeapNode*)vector_get(heap->nodes, right_child))->priority < ((HeapNode*)vector_get(heap->nodes, min))->priority)
        min = right_child;

    if (min != idx) {
        swap_nodes(heap, idx, min);
        heapify_down(heap, min);
    }
}

void heapify_up(Heap *heap, int idx) {
    int parent = (idx - 1) / 2;
    if ((parent >=0) && (((HeapNode*)vector_get(heap->nodes, idx))->priority < ((HeapNode*)vector_get(heap->nodes, parent))->priority)) {
        swap_nodes(heap, idx, parent);
        heapify_up(heap, parent);
    }
}

//Heap for max priority
// void heapify_down(Heap *heap, int idx) {
//     int max = idx;
//     int left_child = 2 * idx + 1;
//     int right_child = 2 * idx + 2;

//     if (left_child < vector_size(heap->nodes) && ((HeapNode*)vector_get(heap->nodes, left_child))->priority > ((HeapNode*)vector_get(heap->nodes, max))->priority)
//         max = left_child;

//     if (right_child < vector_size(heap->nodes) && ((HeapNode*)vector_get(heap->nodes, right_child))->priority > ((HeapNode*)vector_get(heap->nodes, max))->priority)
//         max = right_child;

//     if (max != idx) {
//         swap_nodes(heap, idx, max);
//         heapify_down(heap, max);
//     }
// }

// void heapify_up(Heap *heap, int idx) {
//     int parent = (idx - 1) / 2;
//     if ((parent >=0) && (((HeapNode*)vector_get(heap->nodes, idx))->priority > ((HeapNode*)vector_get(heap->nodes, parent))->priority)) {
//         swap_nodes(heap, idx, parent);
//         heapify_up(heap, parent);
//     }
// }

void heap_push(Heap *heap, data_type data, double priority) {
    HeapNode *node = (HeapNode *)calloc(1, sizeof(HeapNode));
    if (node == NULL)
        exit(printf("Error: heap_push: could not allocate memory.\n"));
    node->data = data;
    node->priority = priority;
    vector_push_back(heap->nodes, node);
    heapify_up(heap, vector_size(heap->nodes) - 1);
}

data_type heap_pop(Heap *heap) {
    if (vector_size(heap->nodes) == 0)
        exit(printf("Error: heap_pop: heap is empty.\n"));

    data_type data = ((HeapNode*)vector_get(heap->nodes, 0))->data;
    vector_set(heap->nodes, 0, vector_get(heap->nodes, vector_size(heap->nodes) - 1));
    vector_pop_back(heap->nodes);
    heapify_down(heap, 0);

    return data;
}

int heap_is_empty(Heap *heap) {
    return vector_size(heap->nodes) == 0;
}

HeapNode heap_top(Heap *heap) {
    if (vector_size(heap->nodes) == 0)
        exit(printf("Error: heap_top: heap is empty.\n"));
    return *((HeapNode*)vector_get(heap->nodes, 0));
}