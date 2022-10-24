class Dynamic_Array:
    def __init__(self):
        self._size = 0
        self._capacity = 1
        self._Array = self._create(self._capacity)


    def _create(self,capacity):
        return [None] * capacity

    def _resize(self, capacity):
        NewArray = [None] * capacity
        for i in range(self._size):
            NewArray[i] = self._Array[i]
        self._Array = NewArray
        self._capacity = capacity
