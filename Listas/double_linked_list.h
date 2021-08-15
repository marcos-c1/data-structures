#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    void *data;
} Node;

typedef struct Double_LinkedList
{
    Node *head;
    Node *tail;
    size_t size;
} DLL;

/* @brief Iterator over the double linked list */
typedef Node DLL_it;

/* @brief Create the DLL
*  @return The pointer to the DLL
*/
DLL *createDLL();

/* @brief Creates the node 
*  @return The pointer to the Node
*/
Node *createNode();

/* @brief Checks if the DLL is empty
*  @return boolean
* */
size_t DLL_empty(DLL *list);

/* @brief Gets the size of the DLL 
*  @return size_t
*/
size_t DLL_size(DLL *list);

/* @brief Access the head element 
*  @return The pointer to the head
*/
Node* DLL_access_head(DLL *list);

/* @brief Access the tail element
*  @return The pointer to the tail
*/
Node* DLL_access_tail(DLL *list);

/* @brief Delete the head of the DLL 
*/
void deleteHead(DLL *list);

/* @brief Delete the tail of the DLL 
*/
void deleteTail(DLL *list);

/* @brief Append an element to the DLL 
*  @param list The DLL itself
*  @param data The data of the node to be append
*/
void appendDLL(DLL *list, void *data);

/* 
* @brief Preppend an element to the list
* @param list The list itself
* @param  data The data of the object
*/
void preppendDLL(DLL *list, void *data);

/* 
* @brief Insert a element at specific position
* @param list The list itself
* @param position Position which the element will be inserted
* @param  data The data of the object
*/
void DLL_insert(DLL *list, size_t position, void *data);

/* 
* @brief Delete a element at specific position
* @param list The list itself
* @param position Position which the element will be removed
*/
void DLL_remove(DLL *list, size_t position);

/* @brief Delete the entire list 
*/
void DLL_delete(DLL *list);

/* @brief Literally print out the list 
*/
void printDLL(DLL *list);
#endif