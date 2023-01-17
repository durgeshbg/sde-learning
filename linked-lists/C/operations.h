typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push_front(int);
void push_back(int);
int pop_front();
int pop_back();
int size();
int empty();
int value_at(int);
int front();
int back();
int insert(int, int);
int erase(int);
int value_n_from_end(int);