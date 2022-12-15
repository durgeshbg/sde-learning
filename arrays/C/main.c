#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

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
    {
        printf("Array is Empty\n");
        return -1;
    }
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

    a = del(a, 5);
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
