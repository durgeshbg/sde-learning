#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CAPACITY;
void display(int *);
int size(int *);
bool is_empty(int *);
void at(int *, int);
int *push(int *, int);
int *insert(int *, int, int);

int main(void)
{
    int *a;
    printf("Enter no. of elements to store: ");
    scanf("%d", &CAPACITY);
    a = malloc((CAPACITY + 1) * sizeof(int));
    printf("Storing %d integers...\n", CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
        *(a + i) = i;
    *(a + CAPACITY) = -999;

    printf("Size: %d | Capacity: %d\n", size(a), CAPACITY);
    if (is_empty(a))
        printf("\nEmpty\n");
    display(a);

    at(a, 1);
    a = push(a, 5);
    display(a);

    a = insert(a, 2, 99);
    display(a);
    return 0;
}

void display(int *a)
{
    int i = 0;
    printf("----Integers:----\n");
    while (*(a + i) != -999)
    {
        printf("%d: %d\n", i , *(a + i));
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
    if (i >= CAPACITY)
        printf("\nIndex out of bound\n");
    else
        printf("\nReturning element at %d: %d\n", i, *(a + i));
}
int *push(int *a, int x)
{
    int *t, s, i = 0;
    s = size(a);
    t = malloc((s + 2) * sizeof(int));
    printf("\n+ + + + Pushing %d + + + +\n", x);
    while (*(a + i) != -999)
    {
        *(t + i) = *(a + i);
        i++;
    }
    *(t + s) = x;
    *(t + s + 1) = -999;
    return t;
}
int *insert(int *a, int i, int x)
{
    int *t, s, j = 0;
    s = size(a);
    printf("\n* * * Inserting %d at %d * * *\n", x, i);
    t = malloc((s + 2) * sizeof(int));
    while (*a != -999)
    {
        *(t + j) = i == j ? x : *(a++);
        j++;
    }
    printf("%d\n",j);
    *(t + s + 1) = -999;
    return t;
}