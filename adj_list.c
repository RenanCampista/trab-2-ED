#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "adj_list.h"

// Cria um novo nó da lista de adjacência
AdjListNode* newAdjListNode(int dest, float weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    return newNode;
}

// Inicializa uma lista de adjacência
AdjList* initAdjList() {
    AdjList* list = (AdjList*)malloc(sizeof(AdjList));
    list->nodes = vector_construct();
    return list;
}

// Adiciona um nó à lista de adjacência
void addNode(AdjList* list, AdjListNode* node) {
    //pushBack(list->nodes, node);
    vector_push_back(list->nodes, node);
}