class Dynamic_Array:
    def __init__(self):
        self._size = 0
        self._capacity = 1
        self._Array = self._create(self._capacity)

    def get(self, i):
        if i < 0 or i >= self._capacity:
            raise IndexError("Out of range.")
        return self._Array[i]

    def pushback(self, item):
        if self._capacity == self._size:
            self._resize(2*self._capacity)
        self._Array[self._size] = item
        self._size += 1

    def _create(self,capacity):
        return [None] * capacity

    def _resize(self, capacity):
        NewArray = [None] * capacity
        for i in range(self._size):
            NewArray[i] = self._Array[i]
        self._Array = NewArray
        self._capacity = capacity
