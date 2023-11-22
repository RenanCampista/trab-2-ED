#include <stdio.h>
#include <stdlib.h>
#include "connection.h"

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

void connection_destruct(Connection *connection) {
    free(connection);
}

int connection_get_neighbor(Connection *connection) {
    return connection->neighbor;
}

float connection_get_weight(Connection *connection) {
    return connection->weight;
}