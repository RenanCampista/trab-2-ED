#include <stdio.h>
#include <stdlib.h>
#include "connection.h"

Connection *connection_create(int neighbor, float distance) {
    Connection *connection = (Connection *)calloc(1, sizeof(Connection));
    if (connection == NULL)
        exit(printf("Error: connection_create failed to allocate memory.\n"));
   
    connection->neighbor = neighbor;
    connection->distance = distance;
    return connection;
}

void connection_destroy(Connection *connection) {
    free(connection);
}

float connection_get_distance(Connection *connection) {
    return connection->distance;
}

int connection_get_neighbor(Connection *connection) {
    return connection->neighbor;
}