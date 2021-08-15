#ifndef HASHMAP
#define HASHMAP
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 15
#endif

typedef struct Node
{
    unsigned int key;
    void *data;
    char *hash;
    struct Node *next;
} Node;

typedef struct HashMap
{
    Node *current;
    size_t size;
} HashMap;

typedef Node *HashMap_it;

void randKey(char *str);
unsigned int hash(size_t length, const char *str);
HashMap *createHashMap();
Node *createNode();
size_t HashMap_size(HashMap *hs);
void connectNode(HashMap *hs, void* data);


#endif