#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "node.h"

struct Connection {
    int neighbor;
    float weight;
};

Connection* connection_construct(int neighbor, float weight) {
    Connection *c = (Connection *)calloc(1, sizeof(Connection));
    if (c == NULL)
        exit(printf("Error: connection_construct failed to allocate memory.\n"));
    c->neighbor = neighbor;
    c->weight = weight;
    return c;
}

Node *node_construct() {
    Node *node = (Node *) calloc(1, sizeof(Node));
    if (node == NULL)
        exit(printf("Error: node_construct failed to allocate memory.\n"));
    node->connections = vector_construct();
    return node;
}

void node_destruct(Node *node) {
    vector_destroy(node->connections, free);
    free(node);
}

void node_add_connection(Node* node, int neighbor, float weight) {
    Connection *new_connection = connection_construct(neighbor, weight);
    vector_push_back(node->connections, new_connection);
}

Connection *node_get_connection(Node *node, int idx) {
    return (Connection *)vector_get(node->connections, idx);
}

int node_get_num_connections(Node *node) {
    return vector_size(node->connections);
}

int connection_get_neighbor(Connection *connection) {
    return connection->neighbor;
}

float connection_get_weight(Connection *connection) {
    return connection->weight;
}
