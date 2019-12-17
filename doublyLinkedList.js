class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
    }

    //Inserting a node at the beginning of the list
    insertAtBeginning(value) {

        var newNode = new Node(value);

        if (this.head == null) {
            this.head = newNode;
        } else {
            newNode.prev = null;
            newNode.next = this.head;
            this.head = newNode;
        }
    }

    //Inserting a node at a given position in the list
    insertAt(value, index) {
        var temp = this.head;
        var previous = null;
        var count = 1;
        var newNode = new Node(value);

        while (count < index) {
            previous = temp;
            temp = temp.next;
            count++;
        }

        newNode.next = temp;
        previous.next = newNode;

    }

    //Deleting a node by value
    deleteByValue(value) {
        var temp = this.head;
        var previous = null;

        while (temp) {

            if (temp.data == value) {

                if (temp == this.head) {
                    this.head = this.head.next;
                    this.head.prev = null;
                } else {
                    previous.next = temp.next;
                    temp.next.prev = previous;
                }
            }

            previous = temp;
            temp = temp.next;
        }
    }

    //Deleting a node by it's index
    deleteByIndex(index) {

        var temp = this.head;
        var previous = temp;
        var count = 1;

        if (index == 1) {
            this.head = temp.next;
        } else {

            while (count < index) {
                previous = temp;
                temp = temp.next;
                count++;
            }

            previous.next = temp.next;
            temp.next.prev = previous;
        }

    }

    //Checking if the list is empty
    isEmpty() {

        if (this.length < 1) {
            return true;
        } else {
            return false;
        }
    }

    //Finding the length of the list
    length() {
        var length = 0;
        var temp = this.head;

        while (temp) {
            temp = temp.next;
            length++;
        }
        return length;
    }

    //Printing the list
    print() {
        var temp = this.head;
        var arr = [];

        while (temp) {
            arr.push(temp.data);
            temp = temp.next;
        }

        for (var i = 0; i < arr.length; i++) {
            console.log(arr[i]);
        }

    }

}

module.exports = { DoublyLinkedList, Node };



