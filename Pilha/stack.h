#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node{
    struct Node *next;
    void* data;
}Node;

typedef struct Stack{
    Node *top;
    size_t size;
}Stack;

typedef Node Stack_it;

/*
 * @brief Creates a new Stack
 * @return The pointer to the stack
 */
Stack *createStack();

/* @brief Creates a new Node */
Node *createNode();

/* @brief Remove the node in memory */
void removeNode(Node *node);

/* @brief Gets the stack size */
size_t stack_size(Stack *st);

/* @brief Checks if the stack is empty */
size_t stack_empty(Stack *st);

/* @brief Stack up the data on top 
*  @param stack The stack itself
*  @param data The data it will belongs to the node
*/
void push(Stack *st, void* data);

/* @brief Unstacks the data on top 
*/
void pop(Stack *st);

/* @brief Print out the stack */
void printStack(Stack *st);

/* @brief Reverses the entire stack 
*  @param The stack which will be reversed
*  @return The new stack 
*/
Stack* reverse(Stack *st)

#endif