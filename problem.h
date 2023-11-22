#if !defined(_PROBLEM_H_)
#define _PROBLEM_H_
#include "graph.h"

typedef struct Problem Problem;


/**
 * @brief Cria um novo problema com o número de nós especificado e grafo vazio.
 * @param num_nodes Número de nós do problema.
 * @return Ponteiro para o novo problema.
 */
Problem *problem_construct(int num_nodes);

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

/**
 * @brief Retorna o número de nós do problema.
 * @param problem Ponteiro para o problema.
 * @return O número de nós.
*/
int problem_get_num_nodes(Problem *problem);

/**
 * @brief Retorna o grafo do problema.
 * @param problem Ponteiro para o problema.
 * @return Ponteiro para o grafo.
*/
Graph *problem_get_graph(Problem *problem);

#endif // _PROBLEM_H_
