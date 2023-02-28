#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef void *(*deque_fn_constructor)(void *);
typedef void (*deque_fn_destructor)(void *);
typedef int (*deque_fn_comparator)(const void *, const void *);

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Deque
{
    Node *head;
    Node *tail;
    deque_fn_constructor constructor;
    deque_fn_destructor destructor;
    deque_fn_comparator comparator;
    size_t size;
} Deque;

void createQueue(Deque **q, deque_fn_constructor constructor, deque_fn_destructor destructor, deque_fn_comparator comparator);
Node *createNode(void *data, deque_fn_constructor constructor);
void *int_constructor(void *data);
void int_destructor(void *data);
int int_comparator(const void *a, const void *b);
void enqueue(Deque *q, void *data);
void dequeue(Deque *q, void *data);
Node *peek(Deque *q);
Node *removeTail(Deque *q);
Node *removeHead(Deque *q);
void print(Deque *q);

#endif