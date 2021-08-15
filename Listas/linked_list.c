#include "linked_list.h"

List *createList()
{
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->size = 0;

    return list;
}

Node *createNode()
{
    Node *el = malloc(sizeof(Node));
    el->next = NULL;

    return el;
}

void removeNode(Node *node)
{
    free(node);
    node = NULL;
}

size_t list_size(List *list)
{
    return list->size;
}

size_t list_empty(List *list)
{
    return list_size(list) > 0 ? 0 : 1;
}

void deleteHead(List *list)
{
    assert(!list_empty(list));

    Node *newEl = createNode();
    newEl = list->head;
    list->head = list->head->next;

    removeNode(newEl);

    list->size--;
}

void deleteTail(List *list)
{
    assert(!list_empty(list));

    List_it *it = list->head;

    for (int i = 0; i < list_size(list) - 2; ++i)
    {
        it = it->next;
    }

    removeNode(it->next);
    list->size--;
    it->next = NULL;
}

Node* accessHead(List *list)
{
    assert(!list_empty(list));
    return list->head;
}

Node* accessTail(List *list)
{
    assert(!list_empty(list));
    return list->tail;
}

void removeList(List *list)
{
    assert(!list_empty(list));

    while (!list_empty(list))
    {
        deleteHead(list);
    }
    free(list);
    list = NULL;
}

void deleteNode_At_Position(List *list, size_t position)
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
        List_it *it = list->head;
        Node *node = createNode();

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

void insertNode(List *list, size_t position, void* data)
{
    assert(position < list_size(list));
    if (position == 0){
        appendNode(list, data);
    } else {
        Node *newEl = createNode();
        List_it *it = list->head;
        for (int i = 0; i < position - 1; ++i){
            it = it->next;
        }
        node = it->next;
    }
}

void appendNode(List *list, void *data)
{

    Node *newEl = createNode();
    newEl->data = data;

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

void preppendNode(List *list, void *data)
{
    Node *newEl = createNode();
    newEl->data = data;

    newEl->next = list->head;
    list->head = newEl;

    if (list_empty(list))
    {
        list->tail = newEl;
    }
    list->size++;
}

void printList(List *list)
{
    assert(!list_empty(list));

    Node *next = list->head;
    for (int i = 0; i < list_size(list); ++i)
    {
        if (i == list->size - 1)
            printf("%d\n", *(int *)next->data);
        else
            printf("%d -> ", *(int *)next->data);
        next = next->next;
    }
}