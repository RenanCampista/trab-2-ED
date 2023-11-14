#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "adjacency_list.h"

struct Node {
    int dest;
    float weight;
};

// Cria um novo nó da lista de adjacência
Node* node_construct(int dest, float weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    return newNode;
}

// Inicializa uma lista de adjacência
AdjacencyList* initAdjacencyList() {
    AdjacencyList *list = (AdjacencyList *) calloc(1, sizeof(AdjacencyList));
    if (list == NULL)
        exit(printf("Error: adjacency_list_construct failed to allocate memory.\n"));
    list->nodes = vector_construct();
    return list;
}

AdjacencyList *adjacency_list_construct() {
    AdjacencyList *list = (AdjacencyList *) calloc(1, sizeof(AdjacencyList));
    if (list == NULL)
        exit(printf("Error: adjacency_list_construct failed to allocate memory.\n"));
    list->nodes = vector_construct();
    return list;
}

// Adiciona um nó à lista de adjacência
void adjacency_list_add_node(AdjacencyList* list, int dest, float weight) {
    //pushBack(list->nodes, node);
    Node *new_node = node_construct(dest, weight);
    vector_push_back(list->nodes, new_node);
}

Node *adjacency_list_get_node(AdjacencyList *edge, int idx) {
    return (Node *)vector_get(edge->nodes, idx);
}

int adjacency_list_get_num_nodes(AdjacencyList *edge) {
    return vector_size(edge->nodes);
}

int node_get_dist(Node *node) {
    return node->dest;
}

float node_get_weight(Node *node) {
    return node->weight;
}