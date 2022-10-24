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
            NewArray = [None] * (2 * self._capacity)
            for i in range(self._size):
                NewArray[i] = self._Array[i]
            self._Array = NewArray
            self._capacity = 2 * self._capacity

        self._Array[self._size] = item
        self._size += 1

    def insert(self, index, item):
        if self._capacity == self._size:
            NewArray = [None] * (2 * self._capacity)
            for i in range(self._size):
                NewArray[i] = self._Array[i]
            self._Array = NewArray
            self._capacity = 2 * self._capacity
            
        for i in range(self._size, index, -1):
            self._Array[i] = self._Array[i - 1]
        self._Array[index] = item
        self._size += 1

    def remove(self, i):
        if i < 0 or i > self._size:
            raise IndexError("Out of range.")
        for j in range(i, self._size - 1):
            self._Array[j] = self._Array[j + 1]
        self._size -= 1

    def __str__(self):
        message = ""
        for i in range(self._size):
            message += str(self._Array[i])
            message += " "
        return message
