#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head, *tail;

void PushFront(int);
void PushBack(int);

int main(void)
{
    return 0;
}

void PushFront(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = key;
    node->next = head;
    head = node;
    if (tail == NULL)
        tail = head;
}
void PushBack(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = key;
    node->next = NULL;
    if (tail == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}