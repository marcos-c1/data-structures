#ifndef HASHMAP
#define HASHMAP

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "hashlist.h"

#define MAX_WORD_LENGTH 15

typedef struct HashMap_Node
{
    unsigned int key;
    void *data;
    char *hash;
    /* @brief Only assigns if has hash collisions */
    HashList *list;
} HashMap_Node;

typedef struct HashMap
{
    HashMap_Node *array;
    size_t size;
} HashMap;

/* @brief The iterator of the HashMap */
typedef HashMap_Node *HashMap_it;

/* HashMap functions */
/* @brief Generates a random key using a hash function 
*  @param str A pointer which will contains the key in character type
*/
void randKey(char *str);
/* @brief Hash function which will calculate the index based on the key and size of the Hash 
*  @param length The length of the HashMap 
*  @param str The key value
*  @return The index to the dynamic array
*/
unsigned int hash(size_t length, const char *str);

/* @brief Creates a HashMap 
*  @return The pointer to the structure
*/
HashMap *createHashMap();
/* @brief Creates the HashMap Node 
*  @return The pointer to the structure
*/
HashMap_Node *createHashMap_Node();
/* @brief Gets the size of the HashMap
*  @return The size of the Hash 
*/
size_t getSize(HashMap *hs);
/* @brief Verifies if the HashMap has any node 
*  @return A boolean value
*/
size_t isEmpty(HashMap *hs);
/* @brief Put a node into the HashMap  */
void put(HashMap *hs, void* data);

/* @brief It is used to delete an entry for the specified key
*  @param The HashMap
*  @param The hash key of the object 
*/
void remove(HashMap *hs, char *hash)

#endif