/**
 * Java program to find out the intersecting node of two linked
 * lists: all nodes following, and including that node, are
 * common to both of the two linked lists
 * 
 * Algorithm:
 *  Traverse both the lists till the end calculating the
 *    lengths of each
 *  On the longer list, traverse as many nodes from start
 *    as the difference in length of the lists
 *  Continue traversing on both lists from that point
 *  The first node which is same in both the lists is the
 *    intersecting node
 * 
 *  Time Complexity: O(n)
 *  Extra Space Complexity: O(1)
 */


import java.util.*;

class Intersection {
    public static void main(String args[]) {
        Intersection ob = new Intersection();

        // creating and printing the intersecting linked lists
        LinkedList<Integer> list1 = new LinkedList<>();
        LinkedList<Integer> list2 = new LinkedList<>();
        ob.makeIntersectingLists(list1, list2);

        System.out.print("List 1: "); printList(list1);
        System.out.print("List 2: "); printList(list2);

        // get the intersecting node
        Integer e = getIntersection(list1, list2);
        if (e == null)
            System.out.println("\nLists do not intersect");
        else
            System.out.println("\nLists intersect at node " + e.intValue());
    }


    // function to find intersecting node of two linked lists
    static Integer getIntersection(LinkedList<Integer> list1, LinkedList<Integer> list2) {
        Integer e = null;

        // finding the lengths of both linked lists
        int len1 = 0, len2 = 0;
        Iterator<Integer> it;

        it = list1.iterator();
        while (it.hasNext()) {
            it.next();
            len1++;
        }

        it = list2.iterator();
        while (it.hasNext()) {
            it.next();
            len2++;
        }

        // finding the longer and shorter list
        LinkedList<Integer> longList, shrtList;
        if (len1 >= len2) {
            longList = list1;
            shrtList = list2;
        }
        else {
            longList = list2;
            shrtList = list1;
        }


        Iterator<Integer> it1, it2;
        it1 = longList.iterator();
        it2 = shrtList.iterator();
        
        // iterating the longer list as much nodes ahead as the
        // difference between the lengths of the two, such that
        // same number of further nodes remain on both lists
        for (int i = 0; i < Math.max(len1, len2) - Math.min(len1, len2); i++)
            it1.next();
        
        // traversing both lists together and comparing nodes
        while (it1.hasNext()) {
            Integer e1 = it1.next();
            Integer e2 = it2.next();
            
            if (e1 == e2) {
                e = e1;
                break;
            }
        }

        return e;
    }


    // prints the linked list nodes horizontally
    static void printList(LinkedList<Integer> list) {
        Iterator<Integer> i = list.iterator();
        while (i.hasNext())
            System.out.print(i.next().intValue() + " ");
        System.out.println();
    }


    // makes an example intersecting list of two lists
    void makeIntersectingLists(LinkedList<Integer> list1, LinkedList<Integer> list2) {
        list1.add(Integer.valueOf(2));
        list1.add(Integer.valueOf(3));
        list1.add(Integer.valueOf(4));
        list1.add(Integer.valueOf(5));
        list1.add(Integer.valueOf(6));
        list1.add(Integer.valueOf(7));
        list1.add(Integer.valueOf(8));
        list1.add(Integer.valueOf(9));

        list2.add(Integer.valueOf(0));
        list2.add(Integer.valueOf(1));
        list2.add(list1.get(4));
        list2.add(list1.get(5));
        list2.add(list1.get(6));
        list2.add(list1.get(7));

        // (LL1)  2 - 3 - 4 - 5
        //                      > 6 - 7 - 8 - 9
        // (LL2)          0 - 1
        
        // intersection at 6
    }
}