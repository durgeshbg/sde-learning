class Dynamic_Array:
    def __init__(self):
        self._size = 0
        self._capacity = 1
        self._Array = [None] * self._capacity

    def size(self):
        return self._size

    def capacity(self):
        return self._capacity

    def is_empty(self):
        if self._size == 0:
            return True
        return False

    def at(self, i):
        if i < 0 or i >= self._capacity:
            raise IndexError("Out of range.")
        return self._Array[i]

    def push(self, item):
        if self._capacity == self._size:
            self._resize(2 * self._capacity)
        self._Array[self._size] = item
        self._size += 1

    def insert(self, index, item):
        if self._capacity == self._size:
            self._resize(2 * self._capacity)
        for i in range(self._size, index, -1):
            self._Array[i] = self._Array[i - 1]
        self._Array[index] = item
        self._size += 1

    def prepend(self, item):
        self.insert(0, item)

    def pop(self):
        if self._size == (self._capacity // 4):
            self._resize(capacity / 2)
        item = self._Array[self._size]
        self._size -= 1
        return item

    def delete(self, index):
        if index < 0 or index > self._size:
            raise IndexError("Out of range.")
        for i in range(index, self._size - 1):
            self._Array[i] = self._Array[i + 1]
        self._size -= 1

    def remove(self, item):
        for i in range(self._size):
            if item == self._Array[i]:
                self.delete(i)

    def find(self, item):
        try:
            return self._Array.index(item)
        except ValueError:
            return -1

    def _resize(self, capacity):
        NewArray = [None] * (capacity)
        for i in range(self._size):
            NewArray[i] = self._Array[i]
        self._Array = NewArray
        self._capacity = capacity

    def __str__(self):
        message = ""
        for i in range(self._size):
            message += str(self._Array[i])
            message += " "
        return message
