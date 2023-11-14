#if !defined(_GRAPH_H_)
#define _GRAPH_H_
#include <stdio.h>
#include "node.h"
#include "vector.h"

typedef struct Graph Graph;

struct Graph {
    int num_nodes;
    Vector *nodes;
};

/**
 * @brief Cria um novo grafo com o número de nós especificado e sem conexões.
 * @param num_nodes Número de nós do grafo.
 * @return Ponteiro para o novo grafo.
 */
Graph *graph_construct(int num_nodes);

/**
 * @brief Destrói um grafo, liberando a memória alocada.
 * @param g Ponteiro para o grafo a ser destruído.
*/
void graph_destruct(Graph *g);

/**
 * @brief Adiciona uma conexão ao grafo.
 * @param graph Ponteiro para o grafo.
 * @param src O nó de origem.
 * @param neighbor O nó vizinho.
 * @param weight O peso da conexão.
*/
void graph_add_node(Graph *graph, int src, int neighbor, float weight);

/**
 * @brief Lê um grafo de um arquivo, contendo um grafo no formato de lista de adjacências.
 * @param graph Ponteiro para o grafo.
 * @param file Ponteiro para o arquivo a ser lido.
*/
void graph_read(Graph* graph, FILE *file);

/**
 * @brief Retorna uma conexão entre dois nós do grafo.
 * @param graph Ponteiro para o grafo.
 * @param idx_neighbor O índice do vizinho.
 * @param idx_connection O índice da conexão.
 * @return Ponteiro para a conexão.
*/
Connection *graph_get_connection(Graph *graph, int idx_neighbor, int idx_connection);

/**
 * @brief Retorna o número de conexões de um nó do grafo.
 * @param graph Ponteiro para o grafo.
 * @param idx O índice do nó.
 * @return O número de conexões.
*/
int graph_get_num_connections_from_node(Graph *graph, int idx);

#endif // _GRAPH_H_
