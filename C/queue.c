#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *tail;
} Queue;

Node *new_node(int v);
Queue *new_queue();
void enqueue(Queue *queue, int val);
Node *dequeue(Queue *queue);
void free_queue(Queue *queue);

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

Queue *new_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    Node *sentinela = new_node(0); // Nó sentinela
    queue->head = sentinela;
    queue->tail = sentinela;

    return queue;
}

void enqueue(Queue *queue, int val) {
    Node *newNode = new_node(val);
    queue->tail->next = newNode;
    queue->tail = newNode;
}

Node *dequeue(Queue *queue) {
    if (queue->head == queue->tail) {
        return NULL;
    }
    Node *removedNode = queue->head->next;
    queue->head->next = removedNode->next;
    if (queue->head->next == NULL) {
        queue->tail = queue->head;
    }
    return removedNode;
}

void free_queue(Queue *queue) {
    Node *cur = queue->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(queue);
}

int main() {
    Queue *queue = new_queue();
    
    
    free_queue(queue);
    
    return 0;
}
