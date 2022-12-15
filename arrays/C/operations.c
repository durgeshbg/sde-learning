#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int CAPACITY = 16;

void display(int *a)
{
    int i = 0;
    printf("Size: %d | Capacity: %d\n", size(a), CAPACITY);
    printf("----Integers:----\n");
    while (*(a + i) != -999)
    {
        printf("%d: %d\n", i, *(a + i));
        i++;
    }
}

int size(int *a)
{
    int i = 0;
    while (*(a + i) != -999)
        i++;
    return i;
}

int is_empty(int *a)
{
    if (size(a) == 0)
        return 1;
    return 0;
}

void at(int *a, int i)
{
    if (i >= size(a))
        printf("\nIndex out of bound\n");
    else
        printf("\nReturning element at %d: %d\n", i, *(a + i));
}

int *push(int *a, int x)
{
    int s = size(a);
    printf("\n+ + + + Pushing %d + + + +\n", x);
    if (s >= CAPACITY)
        resize(a);
    *(a + s) = x;
    *(a + s + 1) = -999;
    return a;
}

int *insert(int *a, int index, int x)
{
    int s = size(a);
    if (s >= CAPACITY)
        resize(a);
    printf("\n* * * Inserting %d at %d * * *\n", x, index);
    while (s >= index)
    {
        *(a + s + 1) = *(a + s);
        s--;
    }
    *(a + index) = x;
    return a;
}

int *prepend(int *a, int x)
{
    int s = size(a);
    if (s >= CAPACITY)
        resize(a);
    printf("\n- - - - Prepending %d - - - -\n", x);
    while (s >= 0)
    {
        *(a + s + 1) = *(a + s);
        s--;
    }
    *a = x;
    return a;
}

int pop(int *a)
{
    int p = *(a + size(a) - 1), s = size(a);
    *(a + s - 1) = -999;
    if (s <= CAPACITY / 4)
        resize(a);
    return p;
}

int *del(int *a, int i)
{
    int s = size(a);
    printf("\n- - - Deleting item at %d - - -\n", i);
    while (i < s)
    {
        *(a + i) = *(a + i + 1);
        i++;
    }
    *(a + CAPACITY) = -999;
    if (s <= CAPACITY / 4)
        resize(a);
    return a;
}

int *rem(int *a, int x)
{
    for (int i = 0; i < size(a); i++)
    {
        if (*(a + i) == x)
            a = del(a, i);
    }
    return a;
}

int find(int *a, int x)
{
    for (int i = 0; i < size(a); i++)
    {
        if (*(a + i) == x)
            return i;
    }
    return -1;
}

int *resize(int *a)
{
    int new_size;
    if (size(a) <= CAPACITY / 4)
        new_size = CAPACITY / 2;
    else if (size(a) >= CAPACITY)
        new_size = CAPACITY * 2;
    CAPACITY = new_size;
    return realloc(a, sizeof(int) * CAPACITY);
}