#include "avl.h"

void createAVL(AVL **avl, avl_fn_constructor constructor, avl_fn_destructor destructor, avl_fn_comparator comparator){
  (*avl) = malloc(sizeof(AVL));
  (*avl)->root = NULL;
  (*avl)->constructor = constructor;
  (*avl)->destructor = destructor;
  (*avl)->comparator = comparator;
  (*avl)->size = 0;
}

Node* createNode(void *data, avl_fn_constructor constructor){
  Node *node = (Node*) malloc(sizeof(Node));
  node->data = constructor(data);
  node->left = NULL;
  node->right = NULL;
  node->height = 0;

  return node;
}

int height(Node *node){
  if(node == NULL) return 0;
  return node->height;
}

void* int_constructor(void* data)
{   
    void* ptr = malloc(sizeof(int));
    memcpy(ptr, data, sizeof(int));
    return ptr;
} 

void int_destructor(void* data)
{
    free(data);
}

int int_comparator(const void* a, const void* b)
{
    if(*(int*)a < *(int*)b){
        return -1;
    } else if (*(int*) a == *(int*)b){
        return 0;
    }
    return 1;
}

int max(int a, int b){
  return a > b ? a : b;
}

int BF(Node *node){
  if(node == NULL) return 0;
  return height(node->left) - height(node->right);
}

Node *rightRotate(Node *node){
  Node *x = node->left; 
  Node *y = node;

  x->right = y;
  node->left = x->right;

  y->height = max(height(node->left), height(node->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node *leftRotate(Node *node){
  Node *x = node;
  Node *y = x->right;

  x->right = y->left;
  y->left = x;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

Node* insert_helper(AVL *avl, Node *node, void *data){
  if(node == NULL){
    node = createNode(data, avl->constructor);
    avl->size++;
  }
  
  if(avl->comparator(data, node->data) < 0){
    node->left = insert_helper(avl, node->left, data);
  }
  else if(avl->comparator(data, node->data) > 0){
    node->right = insert_helper(avl, node->right, data);
  } else {
    return node;
  }

  node->height = 1 + max(height(node->left), height(node->right));
  int bf = BF(node);

  // RR
  if(bf > 1 && (avl->comparator(data, node->left->data) < 0))
    return rightRotate(node);
  
  // LL
  if(bf < -1 && (avl->comparator(data, node->right->data) > 0))
    return leftRotate(node);

  // LR
  if(bf > 1 && (avl->comparator(data, node->left->data) > 0)){
    node->left = leftRotate(node);
    rightRotate(node);
  }
  // RL
  if(bf < -1 && (avl->comparator(data, node->right->data) < 0)){
    node->right = rightRotate(node);
    leftRotate(node);
  }
  return node;
}

void insert(AVL *avl, void *data){
  avl->root = insert_helper(avl, avl->root, data);
}

int find_helper(AVL *avl, Node *node, void *data){
  if(node == NULL)
    return 0;

  if(avl->comparator(node->left->data, data) < 0){
    return find_helper(avl, node->left, data);
  }
  else if(avl->comparator(data, node->data) > 0){
    return find_helper(avl, node->right, data); 
  }

  return 1;
}

int find(AVL *avl, void *data){
  return find_helper(avl, avl->root, data);
}

void inOrder(Node *node)
{
    if (node != NULL){
        inOrder(node->left);
        printf("%d -> ", *(int*) node->data);
        inOrder(node->right);
    }
}