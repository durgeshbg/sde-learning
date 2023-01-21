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
LinkedList.traverse(head)

head, tail = LinkedList.push_front(head, tail, 0)
LinkedList.traverse(head)

head, tail = LinkedList.push_back(head, tail, 6)
LinkedList.traverse(head)

value, head, tail = LinkedList.pop_front(head, tail)
print(f"Poped {value}")
LinkedList.traverse(head)

value, head, tail = LinkedList.pop_back(head, tail)
print(f"Poped {value}")
LinkedList.traverse(head)

s = LinkedList.size(head)
print(f"Size: {s}")