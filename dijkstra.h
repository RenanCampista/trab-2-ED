#if !defined(_DIJKSTRA_H_)
#define _DIJKSTRA_H_
#include "problem.h"

/**
 * @brief Resolve o problema usando o algoritmo de Dijkstra.
 * @param problem Ponteiro para o problema.
 * @return Vetor com o menor caminho de cada nó até o nó de destino (origem).
*/
Vector* djikstra_solve(Problem *problem);

#endif // _DIJKSTRA_H_
