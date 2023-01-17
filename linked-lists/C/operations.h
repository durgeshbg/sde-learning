typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void PushFront(int);
void PushBack(int);
int PopFront();
int PopBack();
int size();
int empty();
int value_at(int);