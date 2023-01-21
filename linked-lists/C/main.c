#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(void)
{
    int s, e, v, f, b, i, er, ve, rev, rv;

    create(5);
    traverse();

    push_front(0);
    traverse();

    push_back(5);
    traverse();

    pop_front();
    traverse();

    pop_back();
    traverse();

    s = size();
    printf("Size of the list: %d\n", s);

    e = empty();
    if (e == 1)
        printf("The list is empty.\n");
    else
        printf("The list is not empty.\n");

    v = value_at(2);
    if (v == -1)
        printf("Invalid index.\n");
    else
        printf("The value at %d is: %d.\n", 2, v);

    f = front();
    b = back();
    if (f == -1 || b == -1)
        printf("List is empty.\n");
    else
        printf("Front value: %d.\nBack value: %d.\n", f, b);

    i = insert(3, 0);
    if (i == -1)
        printf("Invalid index.\n");
    else
        traverse();

    er = erase(3);
    if (er == -1)
        printf("Invalid index.\n");
    else
        traverse();

    ve = value_n_from_end(2);
    if (ve == -1)
        printf("Invalid index.\n");
    else
        printf("Value at %d from end: %d.\n", 2, ve);

    rev = reverse();
    if (rev == -1)
        printf("List is empty.\n");
    else
        traverse();

    rv = remove_value(1);
    if (rv == -1)
        printf("Value not found.\n");
    else
        traverse();

    return 0;
}