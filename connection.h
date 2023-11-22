#if !defined(_CONNECTION_H_)
#define _CONNECTION_H_

typedef struct Connection Connection;

/**
 * @brief Cria uma nova conexão com o vizinho e peso especificados.
 * @param neighbor O número do vizinho.
 * @param weight O peso da conexão.
 * @return Ponteiro para a nova conexão.
*/
Connection* connection_construct(int neighbor, float weight);

/**
 * @brief Destrói uma conexão, liberando a memória alocada.
 * @param connection Ponteiro para a conexão a ser destruída.
*/
void connection_destruct(Connection *connection);

/**
 * @brief Retorna o número do vizinho de uma conexão.
 * @param connection Ponteiro para a conexão.
 * @return O número do vizinho.
*/
int connection_get_neighbor(Connection *connection);

/**
 * @brief Retorna o peso de uma conexão.
 * @param connection Ponteiro para a conexão.
 * @return O peso da conexão.
*/
float connection_get_weight(Connection *connection);


#endif // _CONNECTION_H_
