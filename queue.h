#if !defined(_QUEUE_H_)
#define _QUEUE_H_
#include "linked_list.h" // data_type

typedef struct Queue Queue;

Queue *queue_construct();
void queue_enqueue(Queue *queue, data_type value);
data_type queue_dequeue(Queue *queue, void (*destroy_fn)(data_type));
int queue_is_empty(Queue *queue);
void queue_destroy(Queue *queue);

#endif // _QUEUE_H_
