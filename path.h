#if !defined(_PATH_H_)
#define _PATH_H_
#include "vector.h"

typedef struct Path Path;


/**
 * @brief Cria um caminho com base no vetor de distâncias e no vetor de pais.
 * @param dist Vetor de distâncias.
 * @param parent Vetor de pais.
 * @param dest Nó de destino.
 * @return Ponteiro para o caminho criado.
*/
Path *path_create(Vector *dist, Vector *parent, int dest);

/**
 * @brief Libera a memória alocada para o caminho.
 * @param path Ponteiro para o caminho.
*/
void path_destroy(Path *path);

/**
 * @brief Imprime o caminho desde a origem até o destino e o custo total.
 * @param path Ponteiro para o caminho.
*/
void path_print(Path *path);

#endif // _PATH_H_
