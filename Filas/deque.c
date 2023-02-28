#include "deque.h"

void createQueue(Deque **q, deque_fn_constructor constructor, deque_fn_destructor destructor, deque_fn_comparator comparator)
{
    (*q) = malloc(sizeof(Deque));
    (*q)->comparator = comparator;
    (*q)->destructor = destructor;
    (*q)->constructor = constructor;
    (*q)->size = 0;
    (*q)->head = NULL;
    (*q)->tail = NULL;
}

Node *createNode(void *data, deque_fn_constructor constructor)
{
    Node *node = malloc(sizeof(Node));
    node->data = constructor(data);
    node->next = NULL;

    return node;
}

void *int_constructor(void *data)
{
    void *ptr = malloc(sizeof(int));
    memcpy(ptr, data, sizeof(int));
    return ptr;
}

void int_destructor(void *data)
{
    free(data);
}

int int_comparator(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else if (*(int *)a == *(int *)b)
    {
        return 0;
    }
    return 1;
}

void enqueue(Deque *q, void *data)
{
    assert(q);
    if (q->head == NULL)
    {
        q->head = createNode(data, q->constructor);
        q->tail = q->head;
    }
    else
    {
        Node *aux = q->head;
        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = createNode(data, q->constructor);
        q->tail = aux->next;
    }
    q->size++;
}

void dequeue(Deque *q, void *data)
{
    assert(q);
    if (q->head == NULL)
    {
        q->head = createNode(data, q->constructor);
        q->tail = q->head;
    }
    else
    {
        Node *aux = q->head;
        Node *node = createNode(data, q->constructor);
        q->head = node;
        q->head->next = aux;
    }
    q->size++;
}

Node *peek(Deque *q)
{
    assert(q);
    if (q->head == NULL)
        return NULL;
    return q->head;
}

Node *removeHead(Deque *q)
{
    assert(q && q->head);
    Node *aux = q->head;
    q->head = q->head->next;
    q->destructor(aux);
    q->size--;
    return aux;
}

Node *removeTail(Deque *q)
{
    assert(q && (q->head || q->tail));
    Node *aux = q->head;
    while(aux){
        if(aux->next == q->tail){
            printf("to antes da cauda\n");
            Node *aux2 = q->tail;
            aux->next = NULL;
            q->tail = aux;
        }
        aux = aux->next;
    }
    q->destructor(aux);
    q->size--;
}

void print(Deque *q)
{
    Node *aux = q->head;
    while (aux)
    {
        if(!aux->next)
            printf("%d\n", *(int *)aux->data);
        else
            printf("%d -> ", *(int *)aux->data);
        aux = aux->next;
    }
    q->destructor(aux);
}