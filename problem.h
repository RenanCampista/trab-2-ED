#if !defined(_PROBLEM_H_)
#define _PROBLEM_H_

#include "vector.h"
#include "graph.h"


typedef struct {
    int num_nodes;
    Graph *graph;
} Problem;

/**
 * @brief Cria um novo problema com o número de nós especificado e grafo vazio.
 * @param num_nodes Número de nós do problema.
 * @return Ponteiro para o novo problema.
 */
Problem *problem_create(int num_nodes);

/**
 * @brief Destrói um problema, liberando a memória alocada.
 * @param problem Ponteiro para o problema a ser destruído.
*/
void problem_destroy(Problem *problem);

/**
 * @brief Lê um problema de um arquivo, contendo um grafo no formato de lista de adjacências.
 * @param filename Nome do arquivo a ser lido.
 * @return Ponteiro para o problema lido.
*/
Problem *problem_data_read(const char *filename);

#endif // _PROBLEM_H_
