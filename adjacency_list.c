#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "adjacency_list.h"

// Cria um novo nó da lista de adjacência
Node* node_construct(int dest, float weight) {
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
void adjacency_list_add_node(AdjacencyList* list, int dest, float weight) {
    //pushBack(list->nodes, node);
    Node *new_node = node_construct(dest, weight);
    vector_push_back(list->nodes, new_node);
}