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
            print(f"{node.data} ->", end=" ")
            node = node.next

    def push_front(head, tail, data):
        node = Node(data, next)
        node.next = head
        head = node
        if tail == None:
            tail = head

    def push_back(head, data):
        node = Node(data, next)
        p = head
        if head == NULL:
            head = tail = node
        while p.next:
            p = p.next
        p.next = node
        tail = node

    def pop_front(head):
        if head == None:
            raise IndexError("Empty List")
        head = head.next

    def pop_back():
        ...

    def size(head):
        p = head
        s = 0
        while p:
            s=s+1
            p = p.next
        return s

    def empty():
        if head == None:
            return True
        return False

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
