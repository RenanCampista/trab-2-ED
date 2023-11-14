#if !defined(_CONNECTION_H_)
#define _CONNECTION_H_

typedef struct {
    int neighbor; //vertice
    float distance;
} Connection;

Connection *connection_create(int neighbor, float distance);
void connection_destroy(Connection *connection);
float connection_get_distance(Connection *connection);
int connection_get_neighbor(Connection *connection);
#endif // _CONNECTION_H_
