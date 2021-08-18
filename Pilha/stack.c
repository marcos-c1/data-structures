#include "stack.h"
#include <string.h>

Stack *createStack()
{
    Stack *st = malloc(sizeof(Stack));
    st->top = NULL;
    st->size = 0;

    return st;
}

Node *createNode()
{
    Node *nd = malloc(sizeof(Node));
    nd->next = NULL;
    return nd;
}

void removeNode(Node *node)
{
    free(node);
    node = NULL;
}

size_t stack_size(Stack *st)
{
    return st->size;
}

size_t stack_empty(Stack *st)
{
    return stack_size(st) == 0 ? 1 : 0;
}

void push(Stack *st, void* data)
{
    Node *newEl = createNode();
    newEl->data = data;

    if (stack_empty(st))
    {
        st->top = newEl;
    }

    else
    {
        Stack_it *it = st->top;

        st->top = newEl;
        st->top->next = it;
    }

    st->size++;
}

void pop(Stack *st)
{
    assert(!stack_empty(st));

    if (stack_size(st) == 1)
        removeNode(st->top);

    else
    {
        Stack_it *it = st->top;
        st->top = st->top->next;
        removeNode(it);
    }
    st->size--;
}

void printStack(Stack *st)
{
    assert(!stack_empty(st));

    Stack_it *it = st->top;
    for (short int i = 0; i < stack_size(st); ++i)
    {
        printf("|%s|\n---\n", it->data);
        it = it->next;
    }
}

Stack* reverse(Stack *st)
{
    assert(!stack_empty(st));

    Stack *new_st = createStack();
    char dest[29];

    strcpy(dest, st->top->data);

    char *delm = dest;
    char *final;

    while ((delm = strtok(delm, " ")))
    {
        final = malloc(sizeof(delm));
        for(int i = strlen(delm)-1, j = 0; i > -1; --i, ++j){
            final[j] = delm[i];
        }
        delm = NULL;
        push(new_st, final);
        final = NULL;
    }

    return new_st;
}