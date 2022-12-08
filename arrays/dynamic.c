#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display(int *);
int size(int *);
bool is_empty(int *);
void at(int *, int, int);

int main(void)
{
    int *a, s;
    printf("Enter no. of elements to store: ");
    scanf("%d", &s);
    a = malloc((s + 1) * sizeof(int));
    printf("Storing %d integers...\n", s);
    for (int i = 0; i < s; i++)
        *(a + i) = i;
    *(a + s) = -999;

    printf("Size: %d | Capacity: %d\n", size(a), s);
    if (is_empty(a))
        printf("Empty\n");
    display(a);

    at(a, 7, s);

    return 0;
}

void display(int *a)
{
    int i = 0;
    printf("Integers:\n");
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
void at(int *a, int i, int s)
{
    if (i >= s)
        printf("Index out of bound\n");
    else
        printf("Returning element at %d: %d\n", i, *(a + i));
}