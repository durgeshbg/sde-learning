#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

Node *head, *tail;

void push_front(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = key;
    node->next = head;
    head = node;
    if (tail == NULL)
        tail = head;
}

void push_back(int key)
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

int pop_front()
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

int pop_back()
{
    int key;
    Node *node = head;
    if (head == NULL)
        return -1;
    key = tail->data;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
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
    int s = 0;
    Node *node = head;
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

int front() {
    if (head == NULL)
        return -1;
    return head->data;
}

int back() {
    if (head == NULL)
        return -1;
    return tail->data;
}
