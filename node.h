#if !defined(_NODE_H_)
#define _NODE_H_
#include "vector.h"

/*
Em teoria dos grafos, uma lista de adjacência, estrutura de adjacência ou dicionário é a representação de todas arestas ou arcos de um grafo em uma lista.

*/

typedef struct Connection Connection;
typedef struct Node Node;
struct Node {
    Vector* connections;
};

Node *node_construct();
void node_destruct(data_type node);
void node_add_connection(Node* node, int neighbor, float weight);
Connection *node_get_connection(Node *node, int idx);
int connection_get_neighbor(Connection *connection);
float connection_get_weight(Connection *connection);
int node_get_num_connections(Node *node);


#endif // _NODE_H_
