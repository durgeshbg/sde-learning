from LinkedList import LinkedList, Node


def create(n):
    i = 1
    node = Node(i)
    head = node
    while i < n:
        i = i + 1
        node.next = Node(i)
        node = node.next
    tail = node
    return head, tail


head, tail = create(5)
ll = LinkedList(head, tail)
ll.traverse()

ll.push_front(0)
ll.traverse()

ll.push_back(6)
ll.traverse()

v = ll.pop_front()
print(f"Poped front: {v}")
ll.traverse()

v = ll.pop_back()
print(f"Poped back: {v}")
ll.traverse()

s = ll.size()
print(f"Size: {s}")

if ll.empty():
    print("List is empty")
else:
    print("List is not empty")

v = ll.value_at(3)
print(f"Value at 2: {v}")

f = ll.front()
print((f"Front value: {f}"))

b = ll.back()
print(f"Back value: {b}")

ll.insert(2, 2.5)
ll.traverse()

ll.erase(2)
ll.traverse()

v = ll.value_n_from_end(2)
print(f"Value at 2 from end: {v}")
