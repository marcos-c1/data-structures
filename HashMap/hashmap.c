#include "hashmap.h"


void randKey(char *str)
{
#ifndef CHAR_LIMIT
#define MIN_CHAR_ASCII 97
#define MAX_CHAR_ASCII 122
#endif
    int i = 0;
    for (i = 0; i < MAX_WORD_LENGTH; ++i)
    {
        char rnd = (char)(MIN_CHAR_ASCII + (rand() % (MAX_CHAR_ASCII - MIN_CHAR_ASCII)));
        str[i] = rnd;
    }
    str[i + 1] = '\0';
}

unsigned int hash(size_t length, const char *str)
{
    unsigned int i = 0, value, sum = 0;

    while (i < MAX_WORD_LENGTH)
    {
        value = *(str + i);
        sum += value;
        ++i;
    }
    value = sum % length;
    return value;
}

HashMap *createHashMap()
{
    HashMap *hs = malloc(sizeof(HashMap));
    hs->size = 0;
    hs->array = (HashMap_Node *)malloc(sizeof(hs->size));

    return hs;
}

HashMap_Node *createHashMap_Node(HashMap *hs, void *data)
{
    HashMap_Node *node = malloc(sizeof(HashMap_Node));
    node->hash = malloc(sizeof(MAX_WORD_LENGTH));
    randKey(node->hash);
    node->key = hash(hs->size, node->hash);
    node->list = NULL;
    node->data = data;

    return node;
}

size_t getSize(HashMap *hs)
{
    return hs->size;
}

void put(HashMap *hs, void *data)
{

    hs->size++;
    HashMap_Node *newEl = createHashMap_Node(hs, data);

    hs->array = realloc(hs->array, sizeof(HashMap_Node) * hs->size);

    if (hs->array[newEl->key].hash == NULL)
    {
        hs->array[newEl->key] = *newEl;
    }
    else
    {
        HashList *list = createList();
        if (hs->array[newEl->key].list == NULL)
        {
            hs->array[newEl->key].list = list;
        }
        appendNode(hs->array[newEl->key].list, newEl->data, newEl->key, newEl->hash);
        hs->size--;
    }
}

size_t isEmpty(HashMap *hs)
{
    return hs->size == 0 ? 1 : 0;
}

void remove(HashMap *hs, char *hash){
    assert(!isEmpty(hs));

    
}
void printHash(HashMap *hs)
{
    assert(!isEmpty(hs));

    for (int i = 0; i < getSize(hs); ++i)
    {
        if (hs->array[i].list)
        {
            HashList_it *it = hs->array[i].list->head;
            for (int j = 0; j < list_size(hs->array[i].list); ++j)
            {
                printf("List: \n");
                printf("Key: %u\n", it->key);
                printf("Data: %d\n", *(int *)it->data);
                printf("Hash: %s\n\n", it->hash);
                it = it->next;
            }
        }
        printf("Key: %u\n", hs->array[i].key);
        printf("Data: %d\n", *(int *)hs->array[i].data);
        printf("Hash: %s\n\n", hs->array[i].hash);
    }
}
