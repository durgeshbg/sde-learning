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
    return head,tail

head,tail = create(5)

LinkedList.traverse(head)