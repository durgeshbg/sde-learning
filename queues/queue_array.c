#include <stdio.h>
#define MAX 5

int enqueue(int);
int dequeue();
int empty();
int full();
void display();

int QUEUE[MAX];
int READ, WRITE;

int main(void)
{
    int x;
    for (int i = 1; i <= MAX; i++)
    {
        enqueue(i);
    }
    display();

    x = dequeue();
    printf("Element removed: %d\n", x);
    display();
    x = empty();
    printf("Empty: %d\n", x);
    x = full();
    printf("Full: %d\n", x);
    return 0;
}

int enqueue(int data)
{
    if (WRITE > MAX)
        return -1;
    QUEUE[WRITE++] = data;
    return 0;
}

int dequeue()
{
    if (READ == WRITE)
        return -1;
    int data = QUEUE[READ];
    QUEUE[READ] = 0;
    READ++;
    return data;
}

void display()
{
    printf("Elements in Queue: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int empty()
{
    if (READ == WRITE)
        return 1;
    else
        return 0;
}

int full()
{
    if (WRITE == MAX)
        return 1;
    else
        return 0;
}