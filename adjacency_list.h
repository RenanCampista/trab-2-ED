#if !defined(_ADJACENCY_LIST_H_)
#define _ADJACENCY_LIST_H_
#include "vector.h"

/*
Em teoria dos grafos, uma lista de adjacência, estrutura de adjacência ou dicionário é a representação de todas arestas ou arcos de um grafo em uma lista.

*/

typedef struct Node Node;
typedef struct AdjacencyList AdjacencyList;
struct AdjacencyList {
    Vector* nodes;
};


// Cria um novo nó da lista de adjacência
Node* newNode(int dest, float weight);

// Inicializa uma lista de adjacência
// AdjacencyList* initAdjacencyList();
AdjacencyList *adjacency_list_construct();


// Adiciona um nó à lista de adjacência
void adjacency_list_add_node(AdjacencyList* list, int dest, float weight);

Node *adjacency_list_get_node(AdjacencyList *edge, int idx);

int node_get_dist(Node *node);

float node_get_weight(Node *node);

int adjacency_list_get_num_nodes(AdjacencyList *edge);


#endif // _ADJACENCY_LIST_H_
