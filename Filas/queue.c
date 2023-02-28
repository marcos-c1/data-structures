#include "queue.h"

void createQueue(Queue **q, queue_fn_constructor constructor, queue_fn_destructor destructor, queue_fn_comparator comparator){
    (*q) = malloc(sizeof(Queue)); 
    (*q)->head = NULL;
    (*q)->tail = NULL;
    (*q)->constructor = constructor;
    (*q)->destructor = destructor;
    (*q)->comparator = comparator;
    (*q)->size = 0;
}

Node *createNode(void *data, queue_fn_constructor constructor)
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

void enqueue(Queue *q, void *data)
{
    assert(q);
    if(q->head == NULL){
        q->head = createNode(data, q->constructor);
        q->tail = q->head;
    } else {
        Node *aux = q->head;
        while(aux->next){
            aux = aux->next;
        }
        aux->next = createNode(data, q->constructor);
        q->tail = aux->next;
    }
    q->size++;
}

void dequeue(Queue *q)
{
    assert(q && (q->head || q->tail));
    Node *aux = q->head;
    q->head = q->head->next;
    q->destructor(aux);
    q->size--;
}

Node* peek(Queue *q){
    assert(q);
    if(q->head == NULL) return NULL;
    return q->head;
}

void print(Queue *q)
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