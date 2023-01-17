#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head, *tail;

Node *PushFront(int);

int main(void)
{
    return 0;
}

Node *PushFront(int key)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = key;
    node->next = head;
    head = node;
    if (tail == NULL)
        tail = head;
}