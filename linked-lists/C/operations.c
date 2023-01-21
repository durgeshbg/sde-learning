#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

Node *head, *tail;

void create(int n)
{
    int i = 1;
    Node *node = (Node *)malloc(sizeof(Node));
    head = node;
    while (1)
    {
        node->data = i;
        if (i == n)
            break;
        node->next = (Node *)malloc(sizeof(Node));
        node = node->next;
        node->next = NULL;
        i++;
    }
    tail = node;
}

void traverse()
{
    Node *node = head;
    int i = 0;
    printf("*-*-* Elements *-*-*\n");
    while (node != NULL)
    {
        printf("%d. %d\n", i, node->data);
        node = node->next;
        i++;
    }
}

void push_front(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    printf("....Pushing %d front....\n", key);
    node->data = key;
    node->next = head;
    head = node;
    if (tail == NULL)
        tail = head;
}

void push_back(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    printf("....Pushing %d back....\n", key);
    node->data = key;
    node->next = NULL;
    if (head == NULL)
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

int pop_front()
{
    printf("---- Poping %d ----\n", head->data);
    int key;
    if (head == NULL)
        return -1;
    key = head->data;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    return key;
}

int pop_back()
{
    int key;
    Node *node = head;
    printf("---- Poping %d ----\n", tail->data);
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

int size()
{
    int s = 1;
    Node *node = head;
    if (head == NULL)
        return 0;
    while (node->next != NULL)
    {
        s++;
        node = node->next;
    }
    return s;
}

int empty()
{
    if (head == NULL)
        return 1;
    return 0;
}

int value_at(int n)
{
    Node *node = head;
    if (n > size() || n < 0)
        return -1;
    for (int i = 0; i < n; i++)
        node = node->next;
    return node->data;
}

int front()
{
    if (head == NULL)
        return -1;
    return head->data;
}

int back()
{
    if (head == NULL)
        return -1;
    return tail->data;
}

int insert(int index, int value)
{
    Node *node, *p;
    printf("*-*-* Inserting %d at %d.\n", value, index);
    node = (Node *)malloc(sizeof(Node));
    if (index > size() || index < 0)
        return -1;
    node->data = value;
    p = head;
    for (int i = 0; i < index - 1; i++)
        p = p->next;
    node->next = p->next;
    p->next = node;
    return 0;
}

int erase(int index)
{
    Node *node;
    printf("--- Erasing at %d. ---\n", index);
    if (index < 0 || index > size())
        return -1;
    node = head;
    for (int i = 0; i < index - 1; i++)
        node = node->next;
    node->next = node->next->next;
    return 0;
}

int value_n_from_end(int n)
{
    Node *node = head;
    int index = size() - n;
    if (index < 0 || index > size())
        return -1;
    for (int i = 0; i < index; i++)
        node = node->next;
    return node->data;
}

int reverse()
{
    Node *curr, *prev, *temp;
    printf("-=-=- Reversing list -=-=-\n");
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
    temp = head;
    head = tail;
    tail = temp;
    return 0;
}

int remove_value(int value)
{
    Node *node;
    printf("*-*-* Removing %d *-*-*\n", value);
    if (head == NULL)
        return -1;
    if (head->data == value)
        head = head->next;
    else
    {
        node = head;
        while (node->next->data != value && node->next->next != NULL)
            node = node->next;

        if (node->next->data == value)
            node->next = node->next->next;
        else
            return -1;
    }

    return 0;
}