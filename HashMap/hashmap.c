#include "hashmap.h"
#include "../Listas/linked_list.h"

void randKey(char *str)
{
#ifndef CHAR_LIMIT
#define MIN_CHAR_ASCII 97
#define MAX_CHAR_ASCII 122
#endif
    int i = 0;
    srand(time(0));
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
    hs->current = NULL;
    hs->size = 0;

    return hs;
}

Node *createNode()
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->hash = malloc(sizeof(MAX_WORD_LENGTH));
    return node;
}


size_t HashMap_size(HashMap *hs)
{
    return hs->size;
}


void connectNode(HashMap *hs, void* data)
{
    Node *newEl = createNode();
    randKey(newEl->hash);

    if (hs->size == 0){
        hs->current = newEl;
    }
    else {
        HashMap_it it = hs->current;
        for (int i = 0; i < hs->size; ++i){
            it = it->next;
        }
    }
    hs->size++;
}


int main()
{

    HashMap *hs = createHashMap();
   
    

        test->key = hash(hs->size, test->hash);

    printf("[%d] -> %s\n", test->key, test->hash);
    return 0;
}