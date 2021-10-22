# Bug - Queue is not Implemented, use a linkedlist to implement the queue. 
# Solution - : A simple Python program to Implement a queue using a linked list.
# Author - Abhinav Arora.
#Email -: abhinavaroraa14799@gmail.com.

#No Random Search as only sequential search is carried out within each element.

# Node Class Defined.
class Node(object):
    def __init__(self, data, Next = None):
        self.data = data
        self.next = Next
# It initialized the element data and the next pointer reference. 
    def getData(self):
        return self.data

    def setData(self, data):
        self.data = data

    def getNext(self):
        return self.next

    def setNext(self, newNext):
        self.next = newNext
# Defined the LinkedList Class.
class LinkedList(object):
    def __init__(self):
        self.head = None
# Empty list check Defined.
    def isEmpty(self):
        return self.head == None
# Defined Adding New Node
    def add(self, element):
        temp = Node(element)
        temp.setNext(self.head)
        self.head = temp
# Defined size of the node
    def size(self):
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.getNext()
        return count
# Defined search for node
    def search(self,item):
        current = self.head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()

        return found
# Defined Removal of the Node
    def remove(self,item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()

        if previous == None:
            self.head = current.getNext()
        else:
            previous.setNext(current.getNext())

    def fetchData(self):
        current = self.head
        ex = []
        while current:
            ex.append(current.getData())
            current = current.getNext()

        return ex
#Defining The Main Condition
if __name__ == '__main__':
    myList = LinkedList()

    print(myList.head)

    myList.add(7)
    myList.add(14)
    myList.add(21)
    myList.add(28)
    myList.add(35)

    print(myList.size())

    print(myList.search(93))
    print(myList.search(14))
    print(myList.fetchData())
    myList.remove(14)
    print(myList.fetchData())