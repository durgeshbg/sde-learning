class Dynamic_Array:
    def __init__(self):
        self.size = 0
        self.capacity = 10

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        self._size = size

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        self._capacity = capacity

arr = Dynamic_Array()
print(arr.size, arr.capacity)
