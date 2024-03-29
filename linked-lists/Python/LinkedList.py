class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, data):
        self._data = data


class LinkedList:
    def __init__(self, head=None, tail=None):
        self.head = head
        self.tail = tail

    def traverse(self):
        node = self.head
        print("Elements: ", end=" ")
        while node.next:
            print(f"{node.data}", end=" -> ")
            node = node.next
        print(node.data)

    def push_front(self, data):
        print(f"Pushing {data} front...")
        node = Node(data)
        node.next = self.head
        self.head = node
        if self.tail == None:
            self.tail = self.head

    def push_back(self, data):
        print(f"Pushing {data} back...")
        node = Node(data)
        p = self.head
        if self.head == None:
            self.head = self.tail = node
        while p.next:
            p = p.next
        p.next = node
        self.tail = node

    def pop_front(self):
        if self.head == None:
            raise IndexError("Empty List")
        value = self.head.data
        self.head = self.head.next
        if self.head == None:
            self.tail = None
        return value

    def pop_back(self):
        if self.head == None:
            raise IndexError("Empty List")
        p = self.head
        while p.next.next:
            p = p.next
        value = p.next.data
        p.next = None
        self.tail = p
        return value

    def size(self):
        p = self.head
        s = 0
        while p:
            s = s + 1
            p = p.next
        return s

    def empty(self):
        if self.head == None:
            return True
        return False

    def value_at(self, index):
        p = self.head
        if index > self.size() or index < 0:
            raise IndexError("Invalid index")
        for i in range(index - 1):
            p = p.next
        return p.data

    def front(self):
        if self.head == None:
            raise IndexError("Empty list")
        return self.head.data

    def back(self):
        if self.head == None:
            raise IndexError("Empty list")
        return self.tail.data

    def insert(self, index, data):
        if index > self.size() or index < 0:
            raise IndexError("Invalid index")
        print(f"Inserting {data} at {index}...")
        node = Node(data)
        p = self.head
        for i in range(index - 1):
            p = p.next
        node.next = p.next
        p.next = node

    def erase(self, index):
        if index > self.size() or index < 0:
            raise IndexError("Invalid index")
        p = self.head
        for i in range(index - 1):
            p = p.next
        print(f"Erasing {p.next.data} at {index}...")
        p.next = p.next.next

    def value_n_from_end(self, index):
        index = self.size() - index
        if index > self.size() or index < 0:
            raise IndexError("Invalid index")
        p = self.head
        for i in range(index):
            p = p.next
        return p.data

    def reverse(self):
        print("Reversing...")
        prev = None
        curr = self.head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        self.head, self.tail = self.tail, self.head

    def remove_value(self, data):
        p = self.head
        if p.data == data:
            p = p.next
            head = p
            return 0
        while p.next.data != data and p.next.next != None:
            p = p.next
        if p.next.data == data or p.next.next != None:
            print(f"Removing {data}...")
            p.next = p.next.next
            if p.next == None:
                tail = p
        else:
            print("Value not found")
        return 0
