#include "heap.h"
#include <stdlib.h>

Heap *heap_create(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->nodes = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_push(Heap *heap, int node, float dist) {
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size].node = node;
        heap->nodes[heap->size].dist = dist;
        heap->size++;
        int i = heap->size - 1;
        while (i > 0 && heap->nodes[i].dist < heap->nodes[(i - 1) / 2].dist) {
            // Swap with parent if smaller
            HeapNode temp = heap->nodes[i];
            heap->nodes[i] = heap->nodes[(i - 1) / 2];
            heap->nodes[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
}

void heap_pop(Heap *heap) {
    if (heap->size > 1) {
        heap->nodes[0] = heap->nodes[heap->size - 1];
        heap->size--;
        int i = 0;
        while (1) {
            int left_child = 2 * i + 1;
            int right_child = 2 * i + 2;
            int smallest = i;
            if (left_child < heap->size && heap->nodes[left_child].dist < heap->nodes[smallest].dist) {
                smallest = left_child;
            }
            if (right_child < heap->size && heap->nodes[right_child].dist < heap->nodes[smallest].dist) {
                smallest = right_child;
            }
            if (smallest != i) {
                // Swap with the smallest child
                HeapNode temp = heap->nodes[i];
                heap->nodes[i] = heap->nodes[smallest];
                heap->nodes[smallest] = temp;
                i = smallest;
            } else {
                break;
            }
        }
    } else if (heap->size == 1) {
        heap->size--;
    }
}

HeapNode heap_top(Heap *heap) {
    return heap->nodes[0];
}

int heap_empty(Heap *heap) {
    return heap->size == 0;
}

void heap_destroy(Heap *heap) {
    free(heap->nodes);
    free(heap);
}
