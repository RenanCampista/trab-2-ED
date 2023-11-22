#if !defined(_NODE_H_)
#define _NODE_H_
#include "vector.h"
#include "connection.h"

typedef struct Node Node;

/**
 * @brief Cria um novo nó.
 * @return Ponteiro para o novo nó.
*/
Node *node_construct();

/**
 * @brief Destrói um nó, liberando a memória alocada.
 * @param node Ponteiro para o nó a ser destruído.
*/
void node_destruct(Node *node);

/**
 * @brief Adiciona uma conexão ao nó.
 * @param node Ponteiro para o nó.
 * @param neighbor O nó vizinho.
 * @param weight O peso da conexão.
*/
void node_add_connection(Node* node, int neighbor, float weight);

/**
 * @brief Retorna uma conexão do nó.
 * @param node Ponteiro para o nó.
 * @param idx O índice da conexão.
 * @return Ponteiro para a conexão.
*/
Connection *node_get_connection(Node *node, int idx);

/**
 * @brief Retorna o número de conexões de um nó.
 * @param node Ponteiro para o nó.
 * @return O número de conexões.
*/
int node_get_num_connections(Node *node);

#endif // _NODE_H_
