#if !defined(_ADJACENCY_LIST_H_)
#define _ADJACENCY_LIST_H_
#include "vector.h"

/*
Em teoria dos grafos, uma lista de adjacência, estrutura de adjacência ou dicionário é a representação de todas arestas ou arcos de um grafo em uma lista.

*/

typedef struct Node Node;
struct Node {
    int dest;
    float weight;
};

typedef struct AdjacencyList AdjacencyList;
struct AdjacencyList {
    Vector* nodes;
};

// Cria um novo nó da lista de adjacência
Node* newNode(int dest, float weight);

// Inicializa uma lista de adjacência
AdjacencyList* initAdjacencyList();

// Adiciona um nó à lista de adjacência
void adjacency_list_add_node(AdjacencyList* list, int dest, float weight);


#endif // _ADJACENCY_LIST_H_
