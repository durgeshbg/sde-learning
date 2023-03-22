#include <stdio.h>
#define MAX 5

int enqueue(int);
int dequeue();
void display(void);

int BUFFER[MAX];
int READ, WRITE;

int main(void)
{
    /* Wrote the main function to test the 
        below functions you can modify the 
        main as you want.*/
    for (int i = 1; i <= MAX; i++)
    {
        enqueue(i);
    }
    display();

    enqueue(6);
    enqueue(7);
    display();
    for (int i = 0; i < MAX+1; i++)
    {
        printf("%d\n",dequeue());
    }
    display();

    return 0;
}

int enqueue(int data)
{
    BUFFER[WRITE++] = data;
    WRITE %= MAX;
    return 0;
}

int dequeue()
{
    int data = BUFFER[READ];
    BUFFER[READ++] = 0;
    READ %= MAX;
    return data;
}

void display()
{
    printf("Buffer elements: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", BUFFER[i]);
    }
    printf("\n");
}