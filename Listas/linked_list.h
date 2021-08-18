#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../Listas/linked_list.h"
typedef struct List
{
    struct Node *head;
    struct Node *tail;
    size_t size;
} List;

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef Node List_it;

/* @brief Creates the linked list 
   @return The pointer to the linked list
*/
List *createList();

/* @brief Creates the element node for the linked list 
*  @return The pointer to the node
*/
Node *createNode();

/* @brief Remove a node in the memory
*/
void removeNode(Node *node);

/* @brief Gets the size of the linked list 
* @return size_t
*/
size_t list_size(List *list);

/* @brief Check if the linked list is empty 
* @return boolean 
*/
size_t list_empty(List *list);

/* @brief Delete the head element 
*/
void deleteHead(List *list);

/* @brief Delete the tail element 
*/
void deleteTail(List *list);

/* @brief Access head element
*  @return The pointer to the head
*/
Node* accessHead(List *list);

/* @brief Access tail element
*  @return The pointer to the tail
*/
Node* accessTail(List *list);

/* @brief Delete the entire linked list 
*/
void removeList(List *list);

/* @brief Delete a specific node at that position
* @param list The linked list itself
* @param position The position of the element to be delete 
*/
void deleteNode_At_Position(List *list, size_t position);

/* @brief Append a node to the list
* @param list The linked list itself
* @param data The data it will belong to the nod 
*/
void appendNode(List *list, void *data);

/* @brief Preppend a node to the list 
* @param list The linked list itself
* @param data The data it will belong to the nod
*/
void preppendNode(List *list, void *data);

/* @brief Prints the entire list 
*/
void printList(List *list);

#endif