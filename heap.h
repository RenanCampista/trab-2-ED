#if !defined(_HEAP_H_)
#define _HEAP_H_
#include "vector.h"

typedef struct HeapNode HeapNode; // Nó do heap
typedef struct Heap Heap;

/**
 * @brief Cria um novo heap vazio.
 * @return Ponteiro para o novo heap.
 */
Heap *heap_construct();

/**
 * @brief Destrói um heap, liberando a memória alocada.
 * @param heap Ponteiro para o heap a ser destruído.
 * @param destroy_fn Função para destruir os dados armazenados no heap.
 */
void heap_destroy(Heap *heap, void (*destroy_fn)(data_type));

/**
 * @brief Insere um elemento no heap e o organiza de acordo com a prioridade.
 * @param heap Ponteiro para o heap.
 * @param data Dados a serem inseridos.
 * @param priority Prioridade do elemento.
 */
void heap_push(Heap *heap, data_type data, float priority);

/**
 * @brief Remove o elemento de maior prioridade do heap e o organiza novamente.
 * @param heap Ponteiro para o heap.
 * @return Dados do elemento removido.
*/
data_type heap_pop(Heap *heap);

/**
 * @brief Verifica se o heap está vazio.
 * @param heap Ponteiro para o heap.
 * @return 1 se o heap estiver vazio, 0 caso contrário.
*/
int heap_is_empty(Heap *heap);

/**
 * @brief Retorna o elemento de maior prioridade do heap.
 * @param heap Ponteiro para o heap.
 * @return Dados do elemento de maior prioridade.
*/
HeapNode heap_top(Heap *heap);

#endif // _HEAP_H_
