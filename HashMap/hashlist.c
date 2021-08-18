#include "hashlist.h"

HashList *createList()
{
    HashList *list = malloc(sizeof(HashList));
    list->head = list->tail = NULL;
    list->size = 0;

    return list;
}

HashList_Node *createNode(unsigned int key, void* data, char *hash)
{
    HashList_Node *el = malloc(sizeof(HashList_Node));
    el->next = NULL;
    el->data = data;
    el->hash = hash;
    el->key = key;

    return el;
}

void removeNode(HashList_Node *node)
{
    free(node);
    node = NULL;
}

size_t list_size(HashList *list)
{
    return list->size;
}

size_t list_empty(HashList *list)
{
    return list_size(list) > 0 ? 0 : 1;
}

void deleteHead(HashList *list)
{
    assert(!list_empty(list));

    HashList_Node *newEl = malloc(sizeof(HashList_Node));
    newEl = list->head;
    list->head = list->head->next;

    removeNode(newEl);

    list->size--;
}

void deleteTail(HashList *list)
{
    assert(!list_empty(list));

    HashList_it *it = list->head;

    for (int i = 0; i < list_size(list) - 2; ++i)
    {
        it = it->next;
    }

    removeNode(it->next);
    list->size--;
    it->next = NULL;
}

HashList_Node* accessHead(HashList *list)
{
    assert(!list_empty(list));
    return list->head;
}

HashList_Node* accessTail(HashList *list)
{
    assert(!list_empty(list));
    return list->tail;
}

void removeList(HashList *list)
{
    assert(!list_empty(list));

    while (!list_empty(list))
    {
        deleteHead(list);
    }
    free(list);
    list = NULL;
}

void deleteNode_At_Position(HashList *list, size_t position, void* data, unsigned int key, char *hash)
{
    assert(!list_empty(list) && position < list_size(list));

    if (position == 0){
        deleteHead(list);
    }

    else if (position == list_size(list)){
        deleteTail(list);
    }

    else
    {
        HashList_it *it = list->head;
        HashList_Node *node = createNode(key, data, hash);

        for (int i = 0; i < position - 1; ++i)
        {
            it = it->next;
        }

        node = it->next;
        it->next = node->next;

        free(node);
        list->size--;
    }
}

void insertNode(HashList *list, size_t position, void* data, unsigned int key, char *hash)
{
    assert(position <= list_size(list));
    if (position == 0){
        preppendNode(list, data, key, hash);
    } 
    
    else if (position == list_size(list)){
        appendNode(list, data, key, hash);
    }
    
    else {
        HashList_Node *newEl = createNode(key, data, hash);
        HashList_Node *node = createNode(key, data, hash);

        HashList_it *it = list->head;
        for (int i = 0; i < position - 1; ++i){
            it = it->next;
        }
        node = it->next;
        it->next = newEl;
        newEl->next = node;
        
        list->size++;
    }
}

void appendNode(HashList *list, void *data, unsigned int key, char *hash)
{

    HashList_Node *newEl = createNode(key, data, hash);

    if (list->size == 0)
    {
        list->head = newEl;
    }

    else
    {
        list->tail->next = newEl;
    }
    list->tail = newEl;
    list->size++;
}

void preppendNode(HashList *list, void *data, unsigned int key, char *hash)
{
    HashList_Node *newEl = createNode(key, data, hash);

    newEl->next = list->head;
    list->head = newEl;

    if (list_empty(list))
    {
        list->tail = newEl;
    }
    list->size++;
}

void printList(HashList *list)
{
    assert(!list_empty(list));

    HashList_Node *next = list->head;
    for (int i = 0; i < list_size(list); ++i)
    {
        if (i == list->size - 1)
            printf("%d\n", *(int *)next->data);
        else
            printf("%d -> ", *(int *)next->data);
        next = next->next;
    }
}
