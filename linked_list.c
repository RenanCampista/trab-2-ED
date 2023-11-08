#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct LinkedList {
    Node *head;
    Node *last;
    int size;
};

LinkedList *linked_list_construct() {
    LinkedList *l = (LinkedList *)calloc(1, sizeof(LinkedList));
    if (l == NULL)
        exit(printf("Error: linked_list_construct: could not allocate memory.\n"));

    l->head = NULL;
    l->last = NULL;
    l->size = 0;

    return l;

}

void linked_list_destroy(LinkedList *l, void (*destroy_fn)(data_type)) {
    Node *n = l->head;
    while (n != NULL) {
        Node *next = n->next;
        node_destroy(n, destroy_fn);
        n = next;
    }
    free(l);
}

int linked_list_size(LinkedList *l) {
    return l->size;

}

void linked_list_push_front(LinkedList *l, data_type data) {
    Node *n = node_construct(data, l->head);
    l->head = n;
    if (l->last == NULL)
        l->last = n;
    l->size++;

}

void linked_list_push_back(LinkedList *l, data_type data) {
    Node *n = node_construct(data, NULL);
    if (l->last != NULL)
        l->last->next = n;
    l->last = n;
    if (l->head == NULL)
        l->head = n;
    l->size++;
}

void linked_list_remove(LinkedList *l, data_type value, void (*destroy_fn)(data_type)) {
    Node *n = l->head;
    Node *prev = NULL;
    while (n != NULL) {
        if (n->data == value) {
            if (prev == NULL)
                l->head = n->next;
            else
                prev->next = n->next;
            if (n == l->last)
                l->last = prev;
            node_destroy(n, destroy_fn);
            l->size--;
            return;
        }
        prev = n;
        n = n->next;
    }
}

void linked_list_print(LinkedList *l, void (*print_fn)(data_type)) {
    Node *n = l->head;
    while (n != NULL) {
        print_fn(n->data);
        n = n->next;
    }
}

data_type linked_list_get(LinkedList *l, int i) {
    if (i >= linked_list_size(l))
        exit(printf("Error: linked_list_get: invalid index %d for linked_list with size %d.\n", i, linked_list_size(l)));
    Node *n = l->head;
    while (i > 0) {
        n = n->next;
        i--;
    }
    return n->data;
}

data_type linked_list_pop_front(LinkedList *l, void (*destroy_fn)(data_type)) {
    if (l->head == NULL)
        exit(printf("Error: linked_list_pop_front: linked_list is empty.\n"));
    Node *n = l->head;
    l->head = n->next;
    if (l->last == n)
        l->last = NULL;
    data_type val = n->data;
    node_destroy(n, destroy_fn);
    l->size--;
    return val;
}

LinkedList *linked_list_reverse(LinkedList *l) {
    LinkedList *r = linked_list_construct();
    Node *n = l->head;
    while (n != NULL) {
        linked_list_push_front(r, n->data);
        n = n->next;
    }
    return r;
}

void linked_list_unique(LinkedList *l, int (*cmp_fn)(data_type, data_type), void (*destroy_fn)(data_type)) {
    Node *n = l->head;
    while (n != NULL) {
        Node *next = n->next;
        Node *prev = n;
        while (next != NULL) {
            if (cmp_fn(n->data, next->data) == 0) {
                prev->next = next->next;
                node_destroy(next, destroy_fn);
                l->size--;
            } else {
                prev = next;
            }
            next = prev->next;
        }
        n = n->next;
    }
}

int linked_list_search(LinkedList *l, data_type data, int (*cmp_fn)(data_type, data_type)) {
    Node *n = l->head;
    int i = 0;
    while (n != NULL) {
        if (cmp_fn(n->data, data) == 0)
            return i;
        n = n->next;
        i++;
    }
    return -1;
}

void linked_list_sort(LinkedList *l, int (*cmp_fn)(data_type, data_type)) {
    for (Node *i = l->head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (cmp_fn(i->data, j->data) > 0) {
                data_type temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void linked_list_destroy_node(LinkedList *l) {
    Node *n = l->head;
    while (n != NULL) {
        Node *next = n->next;
        free(n);
        n = next;
    }
    free(l);
}