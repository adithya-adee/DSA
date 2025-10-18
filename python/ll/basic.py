class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        node = Node(data, self.head)
        self.head = node

    def insert_at_end(self, data):
        if self.head is None:
            print("Linked List is empty")
            return

        itr = self.head

        while itr.next:
            itr = itr.next

        itr.next = Node(data, None)

    def insert(self, idx, data):
        if self.head is None:
            print("Linked List is empty")
            return

        itr = self.head

        for _ in range(idx - 1):
            if itr.next is None:
                print("Out of bound")
                return
            else:
                itr = itr.next

        next_node = itr.next
        new_node = Node(data, None)
        itr.next = new_node
        new_node.next = next_node

    def remove(self, idx):
        if self.head is None:
            print("Linked List is empty")
            return

        if idx == 0:
            itr = self.head
            self.head = itr.next
            return

        itr = self.head

        for _ in range(idx - 1):
            if itr.next is None:
                print("Out of bound")
                return
            else:
                itr = itr.next

        delete_node = itr.next

        if delete_node is None:
            print("Out of bound")
            return
        else:
            itr.next = delete_node.next

    def print(self):
        if self.head is None:
            print("Linked List is empty")
            return

        itr = self.head
        ll = ""

        while itr:
            ll += str(itr.data) + "->"
            itr = itr.next

        ll += "NULL"
        print(ll)

    def get_length(self):
        if self.head is None:
            print("Linked List is empty")
            return

        cnt = 0
        itr = self.head

        while itr:
            cnt += 1
            itr = itr.next

        return cnt


if __name__ == "__main__":
    ll = LinkedList()
    ll.insert_at_beginning(1)
    ll.insert_at_beginning(2)
    ll.insert_at_beginning(3)
    ll.insert_at_beginning(4)

    ll.insert_at_end(4)
    ll.insert_at_end(3)
    ll.insert_at_end(2)
    ll.insert_at_end(1)

    ll.insert(3, 10)
    ll.insert(6, 111)
    ll.insert(1000, 111)

    ll.remove(3)
    ll.remove(6)

    ll.print()

    print(ll.get_length())
