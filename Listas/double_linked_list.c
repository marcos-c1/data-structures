#include "double_linked_list.h"

DLL *createDLL()
{
    DLL *list = malloc(sizeof(DLL));
    list->head = list->tail = NULL;
    list->size = 0;

    return list;
}


Node *createNode()
{
    Node *node = malloc(sizeof(Node));
    node->prev = node->next = NULL;

    return node;
}



size_t DLL_empty(DLL *list)
{
    return list->size == 0 ? 1 : 0;
}

size_t DLL_size(DLL *list)
{
    return list->size;
}


Node* DLL_access_head(DLL *list)
{
    return list->head;
}

Node* DLL_access_tail(DLL *list)
{
    return list->tail;
}

void deleteHead(DLL *list)
{
    Node *newEl = createNode();
    newEl = list->head;
    list->head = list->head->next;
    
    list->size--;
    
    free(newEl);
    newEl = NULL;
}

void deleteTail(DLL *list)
{
    Node *newEl = createNode();
    newEl = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;

    list->size--;

    free(newEl);
    newEl = NULL;
}

void appendDLL(DLL *list, void *data)
{
    Node *newEl = createNode();
    newEl->data = data;

    if (DLL_empty(list))
    {
        list->head = newEl;
    }

    else
    {
        list->tail->next = newEl;
    }
    newEl->prev = list->tail;
    list->tail = newEl;
    list->size++;
}

void preppendDLL(DLL *list, void *data)
{
    Node *newEl = createNode();
    newEl->data = data;

    if (DLL_empty(list))
        list->tail = newEl;

    else
    {
        newEl->next = list->head;
        list->head = newEl;
    }
    list->size++;
}

void DLL_insert(DLL *list, size_t position, void *data)
{
    assert(!DLL_empty(list) || (position > -1 && position < DLL_size(list)));
    

    if (position == 0){
        preppendDLL(list, data);
    }
    else if (position == DLL_size(list)){
        appendDLL(list, data);
    }
    else
    {
        DLL_it *it = list->head;
        Node *newEl = createNode();
        newEl->data = data;

        Node *aux = createNode();
        for (int i = 0; i < position - 1; ++i)
        {
            it = it->next;
        }
        aux = it->next;
        it->next = newEl;
        it->next->next = aux;
        it->next->prev = aux->prev;
        list->size++;
    }
}

void DLL_remove(DLL *list, size_t position)
{
    assert((!DLL_empty(list)) && (position < DLL_size(list)));

    if (position == 0){
        deleteHead(list);
    } else if (position == DLL_size(list)){
        deleteTail(list);
    } else {
        DLL_it *it = list->head;

        Node *newEl = createNode();

        for (int i = 0; i < position-1; ++i){
            it = it->next;
        }
        newEl = it->next;
        it->next = it->next->next;
        it->next->prev = it->prev;

        free(newEl);
        newEl = NULL;

        list->size--;
    }
}

void DLL_delete(DLL *list)
{
    assert(!DLL_empty(list));

    while (!DLL_empty(list))
        deleteHead(list);
    
    free(list);
    list = NULL;
}

void printDLL(DLL *list)
{
    assert(!DLL_empty(list));

    DLL_it *it = list->head;
    for (int i = 0; i < DLL_size(list); ++i)
    {
        if (i == DLL_size(list) - 1){
            printf("%d\n", *(int*)it->data);
        }
        else{
            printf("%d -> ", *(int *)it->data);
        }
        it = it->next;
    }
}