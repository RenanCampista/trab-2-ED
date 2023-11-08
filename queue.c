#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue {
    LinkedList *list;
};

Queue *queue_construct() {
    Queue *queue = (Queue *) calloc(1, sizeof(Queue));
    if (queue == NULL)
        exit(printf("Error: queue_construct: could not allocate memory.\n"));

    queue->list = linked_list_construct();
    return queue;

}

void queue_enqueue(Queue *queue, data_type value) {
    linked_list_push_back(queue->list, value);
}

data_type queue_dequeue(Queue *queue, void (*destroy_fn)(data_type)) {
    return linked_list_pop_front(queue->list, destroy_fn);
}

int queue_is_empty(Queue *queue) {
    return linked_list_size(queue->list) == 0;
}

void queue_destroy(Queue *queue) {
    linked_list_destroy(queue->list, NULL);
    free(queue);
}