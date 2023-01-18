#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void create(Node *, Node *);
void push_front(Node *, Node *, int);
void push_back(Node *, Node *, int);
int pop_front(Node *, Node *);
int pop_back(Node *, Node *);
int size(Node *);
int empty(Node *);
int value_at(Node *, int);
int front(Node *);
int back(Node *, Node *);
int insert(Node *, int, int);
int erase(Node *, int);
int value_n_from_end(Node *, int);
int reverse(Node *, Node *);
int remove_value(Node *, int);

int main(void)
{
    Node *head, *tail, *node;
    create(head, tail);
    node = head;
    while (head != tail)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    return 0;
}

void create(Node *head, Node *tail)
{
    int n;
    Node *node = (Node *)malloc(sizeof(Node));
    printf("Enter -999 to end the list.\n");
    printf("Enter data: ");
    scanf("%d", &n);

    head = node;
    while (n != -999)
    {
        node->data = n;
        node->next = (Node*) malloc(sizeof(Node));
        node = node->next;
        printf("Enter data: ");
        scanf("%d", &n);
        node->next = NULL;
    }
    tail = node;
}

void push_front(Node *head, Node *tail, int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = key;
    node->next = head;
    head = node;
    if (tail == NULL)
        tail = head;
}

void push_back(Node *head, Node *tail, int key)
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

int pop_front(Node *head, Node *tail)
{
    int key;
    if (head == NULL)
        return -1;
    key = head->data;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    return key;
}

int pop_back(Node *head, Node *tail)
{
    int key;
    Node *node = head;
    if (head == NULL)
        return -1;
    key = tail->data;
    if (head == tail)
        head = NULL;
    else
    {
        while (node->next->next != NULL)
            node = node->next;
        node->next = NULL;
        tail = node;
    }
    return key;
}

int size(Node *head)
{
    int s = 0;
    Node *node = head;
    while (node->next != NULL)
    {
        s++;
        node = node->next;
    }
    return s;
}

int empty(Node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

int value_at(Node *head, int n)
{
    Node *node = head;
    if (n > size(head) || n < 0)
        return -1;
    for (int i = 0; i < n; i++)
        node = node->next;
    return node->data;
}

int front(Node *head)
{
    if (head == NULL)
        return -1;
    return head->data;
}

int back(Node *head, Node *tail)
{
    if (head == NULL)
        return -1;
    return tail->data;
}

int insert(Node *head, int index, int value)
{
    Node *node, *p;
    if (index > size(head) || index < 0)
        return -1;
    node->data = value;
    p = head;
    for (int i = 0; i < index - 1; i++)
        p = p->next;
    node->next = p->next;
    p->next = node;
    return 0;
}

int erase(Node *head, int index)
{
    Node *node;
    if (index < 0 || index > size(head))
        return -1;
    node = head;
    for (int i = 0; i < index - 1; i++)
        node = node->next;
    node->next = node->next->next;
    return 0;
}

int value_n_from_end(Node *head, int n)
{
    Node *node = head;
    int index = size(head) - n + 1;
    if (index < 0 || index > size(head))
        return -1;
    for (int i = 0; i < index; i++)
        node = node->next;
    return node->data;
}

int reverse(Node *head, Node *tail)
{
    Node *curr, *prev, *temp;
    if (head == NULL)
        return -1;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    tail = head;
    head = curr;
    return 0;
}

int remove_value(Node *head, int value)
{
    Node *node;
    if (head == NULL)
        return -1;
    node = head;
    while (node->next->data != value || node->next != NULL)
        node = node->next;
    if (node->data == value)
        node->next = node->next->next;
    else
        return -1;
    return 0;
}
