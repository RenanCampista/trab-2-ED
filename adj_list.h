#if !defined(_ADJ_LIST_H_)
#define _ADJ_LIST_H_
#include "vector.h"

typedef struct AdjListNode AdjListNode;
struct AdjListNode {
    int dest;
    float weight;
};

typedef struct AdjList AdjList;
struct AdjList {
    Vector* nodes;
};

// Cria um novo nó da lista de adjacência
AdjListNode* newAdjListNode(int dest, float weight);

// Inicializa uma lista de adjacência
AdjList* initAdjList();

// Adiciona um nó à lista de adjacência
void addNode(AdjList* list, AdjListNode* node);


#endif // _ADJ_LIST_H_
