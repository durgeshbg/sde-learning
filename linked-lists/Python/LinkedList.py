class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = None
    
    @property
    def data(self):
        return self._data
    @data.setter
    def data(self, data):
        self._data = data
    

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def create():
        ...
    
    def traverse(head):
        node = head
        while node:
            print(f"{node.data} ->",end=' ')
            node = node.next

    def push_front(data):
        ...

    def push_front(data):
        ...

    def push_back(data):
        ...

    def pop_front():
        ...

    def pop_back():
        ...

    def size():
        ...

    def empty():
        ...

    def value_at(data):
        ...

    def front():
        ...

    def back():
        ...

    def insert(data, index):
        ...

    def erase(data):
        ...

    def value_n_from_end(data):
        ...

    def reverse():
        ...

    def remove_value(data):
        ...
