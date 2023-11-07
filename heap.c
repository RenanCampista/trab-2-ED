#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

static const int HEAP_INIT_SIZE = 10;
static const int HEAP_GROWTH_RATE = 2;

typedef struct {
    data_type *data;
    double priority;
} HeapNode;

struct Heap {
    HeapNode *nodes;
    int size;
    int capacity;
};

Heap *heap_construct() {
    Heap *heap = (Heap *)calloc(1, sizeof(Heap));
    if (heap == NULL)
        exit(printf("Error: heap_construct: could not allocate memory.\n"));

    heap->capacity = HEAP_INIT_SIZE;
    heap->size = 0;
    heap->nodes = (HeapNode *)calloc(HEAP_INIT_SIZE, sizeof(HeapNode));

    return heap;

}

void heap_destroy(Heap *heap, void (*destroy_fn)(data_type)) {
    if (destroy_fn != NULL) {
        for (int i = 0; i < heap->size; i++)
            destroy_fn(heap->nodes[i].data);
    }
    free(heap->nodes);
    free(heap);
}

void  swap_nodes(Heap *heap, int i, int j) {
    HeapNode temp = heap->nodes[i];
    heap->nodes[i] = heap->nodes[j];
    heap->nodes[j] = temp;
}


void heapify_down(Heap *heap, int idx) {
    int max = idx;
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;

    if (left_child < heap->size && heap->nodes[left_child].priority > heap->nodes[max].priority)
        max = left_child;

    if (right_child < heap->size && heap->nodes[right_child].priority > heap->nodes[max].priority)
        max = right_child;

    if (max != idx) {
        swap_nodes(heap, idx, max);
        heapify_down(heap, max);
    }
}

void heapify_up(Heap *heap, int idx) {
    int parent = (idx - 1) / 2;
    if ((parent >=0) && (heap->nodes[idx].priority > heap->nodes[parent].priority)) {
        swap_nodes(heap, idx, parent);
        heapify_up(heap, parent);
    }
}

void heap_push(Heap *heap, data_type data, double priority) {
    if (heap->size >= heap->capacity) {
        heap->capacity *= HEAP_GROWTH_RATE;
        heap->nodes = (HeapNode *)realloc(heap->nodes, heap->capacity * sizeof(HeapNode));
    }

    heap->nodes[heap->size].data = data;
    heap->nodes[heap->size].priority = priority;
    heap->size++;
    heapify_up(heap, heap->size - 1);
}

data_type heap_pop(Heap *heap) {
    if (heap->size == 0)
        exit(printf("Error: heap_pop: heap is empty.\n"));

    data_type data = heap->nodes[0].data;
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);

    return data;
}

int heap_is_empty(Heap *heap) {
    return heap->size == 0;
}