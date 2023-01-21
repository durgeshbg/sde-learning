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
    ...