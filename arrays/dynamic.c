#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CAPACITY = 16;
void display(int *);
int size(int *);
bool is_empty(int *);
void at(int *, int);
int *push(int *, int);
int *insert(int *, int, int);
int *prepend(int *, int);
int pop(int *);
int *delete(int *, int);
int *rem(int *, int);
int find(int *, int);
int *resize(int *);

int main(void)
{
    int *a, s;
    printf("Enter no. of elements to store: ");
    scanf("%d", &s);
    a = malloc((CAPACITY) * sizeof(int));
    printf("Storing %d integers...\n", s);
    for (int i = 0; i < s; i++)
        *(a + i) = i;
    *(a + s) = -999;

    if (is_empty(a))
        printf("\nEmpty\n");
    else
        display(a);

    at(a, 1);
    a = push(a, 99);
    display(a);

    a = insert(a, 2, 99);
    display(a);

    a = prepend(a, 99);
    display(a);

    int p = pop(a);
    printf("\nPoped element: %d\n", p);
    display(a);

    a = delete (a, 5);
    display(a);

    a = rem(a, 99);
    display(a);

    int x = find(a, 7);
    if (x == -1)
        printf("Search unsuccessful.\n");
    else
        printf("Element %d found at %d.\n", 7, x);

    free(a);
    return 0;
}

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
bool is_empty(int *a)
{
    if (size(a) == 0)
        return true;
    return false;
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
int *delete(int *a, int i)
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
            a = delete (a, i);
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