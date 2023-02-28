#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef void*(*avl_fn_constructor)(void*);
typedef void (*avl_fn_destructor)(void*);
typedef int (*avl_fn_comparator)(const void*, const void*);

typedef struct Node {
  void *data;
  struct Node *left;
  struct Node *right;
  size_t height;
}Node;

typedef struct AVL {
  Node *root;
  avl_fn_constructor constructor;
  avl_fn_destructor destructor;
  avl_fn_comparator comparator;
  size_t size;
}AVL;

void createAVL(AVL **avl, avl_fn_constructor constructor, avl_fn_destructor destructor, avl_fn_comparator comparator);
Node* createNode(void *data, avl_fn_constructor constructor);
int height(Node *node);
void* int_constructor(void* data);
void int_destructor(void* data);
int int_comparator(const void* a, const void* b);
int max(int a, int b);
int BF(Node *node);
Node *rightRotate(Node *node);
Node *leftRotate(Node *node);
Node* insert_helper(AVL *avl, Node *node, void *data);
void insert(AVL *avl, void *data);
int find_helper(AVL *avl, Node *node, void *data);
int find(AVL *avl, void *data);
void inOrder(Node *node);

#endif