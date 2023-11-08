#ifndef HEAP_H
#define HEAP_H

typedef struct HeapNode {
    int node;    // Índice do nó no grafo
    float dist;  // Distância da origem até este nó
} HeapNode;

typedef struct Heap {
    HeapNode *nodes;
    int size;
    int capacity;
} Heap;

Heap *heap_create(int capacity);
void heap_push(Heap *heap, int node, float dist);
void heap_pop(Heap *heap);
HeapNode heap_top(Heap *heap);
int heap_empty(Heap *heap);
void heap_destroy(Heap *heap);

#endif