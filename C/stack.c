#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Node *new_node(int v);
Stack *new_stack();
void stack_push(Stack *stack, int val);
Node *stack_pop(Stack *stack);
void free_stack(Stack *stack);

Node *new_node(int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->val = v;
    newNode->next = NULL;

    return newNode;
}

Stack *new_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;

    return stack;
}

void stack_push(Stack *stack, int v) {
    Node *newNode = new_node(v);
    newNode->next = stack->top;
    stack->top = newNode;
}

Node *stack_pop(Stack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    Node *removedNode = stack->top;
    stack->top = removedNode->next;

    return removedNode;
}

void free_stack(Stack *stack) {
    Node *cur = stack->top;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(stack);
}

int main() {
    Stack *stack = new_stack();
    
    
    free_stack(stack);
    
    return 0;
}
