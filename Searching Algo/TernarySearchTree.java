/** Time Complexity Analysis : The time complexity of the ternary search tree operations is similar to that 
of binary search tree. i.e. the insertion, deletion and search operations take 
time proportional to the height of the ternary search tree.

Space Complexity Analysis : The space is proportional to the length of the string to be stored.

**/

import java.util.ArrayList;
import java.util.List;
public class TernarySearchTree < Value > {
    private int size; // size
    private Node < Value > root; // root of TST

    private static class Node < Value > {
        private char c; // Character
        private Node < Value > left,
        mid,
        right; // Subtries
        private Value val;
    }
    public int size() {
        return size;
    }
    public boolean contains(String key) {
        return get(key) != null;
    }
    public Value get(String key) {
        if (key == null)
            throw new IllegalArgumentException("calls get() with null argument");
        else if (key.length() == 0)
            throw new IllegalArgumentException("key must have length >= 1");

        Node < Value > x = get(root, key, 0);
        return x == null ? null : x.val;
    }
    // Return subtrie corresponding to given key	
    private Node < Value > get(Node < Value > x, String key, int d) {
        if (x == null)
            return null;

        if (key.length() == 0)
            throw new IllegalArgumentException("key must have length >= 1");

        char c = key.charAt(d);
        if (c < x.c) {
            return get(x.left, key, d);
        } else if (c > x.c) {
            return get(x.right, key, d);
        } else if (d < key.length() - 1) {
            return get(x.mid, key, d + 1);
        } else {
            return x;
        }
    }
    public void put(String key, Value val) // Put Method for check null and already contains
    {
        if (key == null) {
            throw new IllegalArgumentException("calls put() with null key");
        }
        if (!contains(key))
            size++;
        root = put(root, key, val, 0);
    }
    private Node < Value > put(Node < Value > x, String key, Value val, int d) {
        char c = key.charAt(d);
        if (x == null) {
            x = new Node < > ();
            x.c = c;
        }
        if (c < x.c) {
            x.left = put(x.left, key, val, d);
        } else if (c > x.c) {
            x.right = put(x.right, key, val, d);
        } else if (d < key.length() - 1) {
            x.mid = put(x.mid, key, val, d + 1);
        } else {
            x.val = val;
        }
        return x;
    }
    public List < Value > valuesWithPrefix(String prefix) {
        if (prefix == null) {
            throw new IllegalArgumentException("calls keysWithPrefix() with null argument");
        }
        List <Value> values = new ArrayList < > ();
        Node <Value> x = get(root, prefix, 0);
        if (x == null)
            return values;
        else if (x.val != null)
            values.add(x.val);
        collect(x.mid, new StringBuilder(prefix), values);
        return values;
    }
    private void collect(Node < Value > x, StringBuilder prefix, List < Value > values) {
        if (x == null) return;
        collect(x.left, prefix, values);
        if (x.val != null) values.add(x.val);
        collect(x.mid, prefix.append(x.c), values);
        prefix.deleteCharAt(prefix.length() - 1);
        collect(x.right, prefix, values);
    }
}