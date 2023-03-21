#include <stdio.h>
#include <stdlib.h>

int dequeue();
int enqueue(int data);
int empty();
void display();

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head, *tail;

int main(void)
{
    int d;
    for (int i = 0; i < 5; i++)
    {
        enqueue(i);
    }
    display();
    d = dequeue();
    printf("Element removed: %d\n", d);
    display();
    return 0;
}

int dequeue()
{
    int data;
    if (head == NULL)
        return -1;
    data = head->data;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
        head = head->next;
    return data;
}

int enqueue(int data)
{
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (head == NULL) {
        head = node;
        tail = node;
    }
    tail->next = node;
    tail = node;
    return 0;
}

int empty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void display() {
    printf("Queue items: ");
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        printf("%d ",temp->data);
    }
    printf("\n");
}