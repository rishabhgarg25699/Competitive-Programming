/**
 * Java program to find out if there is a loop occuring in
 * a linked list, i.e. the linked list is corrupt, and fix
 * the corruption by removing the link where loop forms
 * 
 * Algorithm:
 *  Traverse the list while storing its nodes in a hash set
 *  If a node is encountered which belongs to the hash set,
 *    i.e. the node was previously encountered, it is the
 *    node where the loop starts forming; remove the link
 *    to that node from the end of the linked list
 * 
 *  Time Complexity: O(n)
 *  Extra Space Complexity: O(n)
 */


import java.util.*;

class LoopDetectionHashing {
    public static void main(String args[]) {
        // creating and printing the intersecting linked list
        // ** this is not the java.util.Collections linked list
        LinkedListCustom list = new LinkedListCustom();
        list.makeCorruptList();

        System.out.print("Corrupt List: "); list.semiPrintList();

        // removing and printing the straightened list
        list.removeListLoop();
        System.out.print("Fixed List:   "); list.printList();
    }
}


// implementing a custom linked list
class LinkedListCustom {
    // defining a linked list node
    class Node {
        int value;
        Node next;
    
        // constructor
        Node(int value) {
            this.value = value;
            this.next  = null;
        }
    }

    // points to the head of the linked list
    Node head = null;

    // points to the last node in the linked list
    Node last = null;

    // stores the length of the linked list
    int length = 0;

    // adds an element to the end of the linked list
    void push(Node e) {
        if (head == null)
            head = e;
        
        else
            last.next = e;

        last = e;
        length++;
    }

    // fetches Node at position i
    Node get(int i) {
        if (i >= length || i < 0)
            return null;

        // interates to ith Node
        Node e = head;
        for (int k = 1; k <= i; k++)
            e = e.next;

        return e;
    }

    // prints a non-corrupt linked list nodes
    void printList() {
        Node curr = head;

        while (curr != null) {
            System.out.print(curr.value + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    // function to straighten a corrupt linked list
    void removeListLoop() {
        // if head is the only node and its next points to itself
        if (head == last && last.next == head) {
            last.next = null;
            return;
        }


        // if there are two or more nodes make a hash set of nodes
        HashSet<Node> nodes = new HashSet<>();

        Node curr = head;
        // iterate linked list
        while (curr.next != null) {
            Node temp = curr.next;
            
            // if a node is encountered that was traversed previously
            // that node is where the list starts looping; break the
            // connection there
            if (nodes.contains(temp)) {
                curr.next = null;
                break;
            }
            // if node has not been encountered before, add it to set
            else {
                nodes.add(curr);
                curr = temp;
            }
        }
    }

    // prints a corrupt linked list nodes to some extent
    void semiPrintList() {
        Node curr = head;
        int counter = 30;

        while (curr != null && (counter--) > 0) {
            System.out.print(curr.value + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    // makes an example corrupt linked list
    void makeCorruptList() {
        this.push(new Node(1));
        this.push(new Node(2));
        this.push(new Node(3));
        this.push(new Node(4));
        this.push(new Node(5));
        this.push(new Node(6));
        this.push(new Node(7));
        this.push(new Node(8));
        this.push(new Node(9));

        this.get(8).next = this.get(3);

        // (List)  1 - 2 - 3 - 4 - 5
        //                   /       \
        //                  9         6
        //                   \       /
        //                     8 - 7
    }
}