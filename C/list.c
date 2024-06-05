#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
} List;

Node *new_node(int value);
List *new_list();
Node *list_pos(Node *head, int pos);
Node *list_find(Node *head, int value);
Node *list_insert(Node *cur, int value);
Node *list_remove(Node *cur);
int list_getPosition(Node *head, Node *searchedNode);
void list_free(List *list);

Node *new_node(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

List *new_list() {
    List *list = (List *)malloc(sizeof(List));
    if (!list) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    list->head = new_node(0);
    return list;
}

Node *list_pos(Node *head, int pos) {
    Node *cur = head;
    for (int i = 0; cur->next != NULL && i < pos; i++) {
        cur = cur->next;
    }
    return cur;
}

Node *list_find(Node *head, int value) {
    Node *cur = head->next;
    while (cur != NULL && cur->value != value) {
        cur = cur->next;
    }
    return cur;
}

Node *list_insert(Node *cur, int value) {
    if (!cur) return NULL;
    
    Node *newNode = new_node(value);
    newNode->next = cur->next;
    cur->next = newNode;

    return newNode;
}

Node *list_remove(Node *cur) {
    if (!cur || !cur->next) return NULL;
    
    Node *p = cur->next;
    cur->next = p->next;
    free(p);

    return cur->next;
}

int list_getPosition(Node *head, Node *searchedNode) {
    int position = 0;
    Node *cur = head->next;
    while (cur != NULL && cur != searchedNode) {
        cur = cur->next;
        position++;
    }
    return cur ? position : -1;
}

void list_free(List *list) {
    Node *cur = list->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(list);
}

int main() {
    List *list = new_list();
    Node *pos = list->head;

    
    return 0;
}
