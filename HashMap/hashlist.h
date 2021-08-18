#ifndef HASH_LIST 
#define HASH_LIST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct HashList_Node
{
    unsigned int key;
    void *data;
    char *hash;
    struct HashList_Node *next;
}HashList_Node;


typedef struct HashList
{
    HashList_Node* head;
    HashList_Node* tail;
    size_t size;
}HashList;

typedef HashList_Node HashList_it;

HashList *createList();
HashList_Node *createNode(unsigned int key, void* data, char *hash);
void removeNode(HashList_Node *node);
size_t list_size(HashList *list);
size_t list_empty(HashList *list);
void deleteHead(HashList *list);
void deleteTail(HashList *list);
HashList_Node* accessHead(HashList *list);
HashList_Node* accessTail(HashList *list);
void removeList(HashList *list);
void deleteNode_At_Position(HashList *list, size_t position, void* data, unsigned int key, char *hash);
void insertNode(HashList *list, size_t position, void* data, unsigned int key, char *hash);
void appendNode(HashList *list, void *data, unsigned int key, char *hash);
void preppendNode(HashList *list, void *data, unsigned int key, char *hash);
void printList(HashList *list);

#endif