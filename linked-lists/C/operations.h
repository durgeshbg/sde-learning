typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void create(Node *, Node *);
void push_front(Node *, Node *, int);
void push_back(Node *, Node *, int);
int pop_front(Node *, Node *);
int pop_back(Node *, Node *);
int size(Node *);
int empty(Node *);
int value_at(Node *, int);
int front(Node *);
int back(Node *, Node *);
int insert(Node *, int, int);
int erase(Node *, int);
int value_n_from_end(Node *, int);
int reverse(Node *, Node *);
int remove_value(Node *, int);