#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "adjacency_list.h"

// Cria um novo nó da lista de adjacência
Node* newNode(int dest, float weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    return newNode;
}

// Inicializa uma lista de adjacência
AdjacencyList* initAdjacencyList() {
    AdjacencyList* list = (AdjacencyList*)malloc(sizeof(AdjacencyList));
    list->nodes = vector_construct();
    return list;
}

// Adiciona um nó à lista de adjacência
void addNode(AdjacencyList* list, Node* node) {
    //pushBack(list->nodes, node);
    vector_push_back(list->nodes, node);
}