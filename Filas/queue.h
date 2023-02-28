#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef void* (*queue_fn_constructor)(void *);
typedef void (*queue_fn_destructor)(void *);
typedef int (*queue_fn_comparator)(const void *, const void *);

typedef struct Node {
    void *data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    queue_fn_constructor constructor;
    queue_fn_destructor destructor;
    queue_fn_comparator comparator;
    size_t size;
}Queue;

void createQueue(Queue **q, queue_fn_constructor constructor, queue_fn_destructor destructor, queue_fn_comparator comparator);
Node *createNode(void *data, queue_fn_constructor constructor);
void *int_constructor(void *data);
void int_destructor(void *data);
int int_comparator(const void *a, const void *b);
void enqueue(Queue *q, void *data);
void dequeue(Queue *q);
Node* peek(Queue *q);
void print(Queue *q);
#endif