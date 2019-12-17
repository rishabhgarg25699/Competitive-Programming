/**
 * Java program to serialize a binary tree, i.e. convert it
 * into a serial object, e.g. a string, and deserialize to a
 * binary tree, i.e. convert a serial object, e.g. a string
 * to a binary tree
 * 
 * (Assumption: Binary Tree is of unique Character nodes)
 * 
 * (Serialization) Algorithm:
 *  Find the Inorder traversal of the tree
 *  Find the Preorder traversal of the tree
 *  Concatenate the results
 * 
 *  Time Complexity: O(n) {n is number of nodes}
 *  Extra Space Complexity: O(h) {h is height of tree}
 * 
 * (Deserialization) Algorithm:
 *  Separate out the Inorder and Preorder traversals
 *  For each entry, let c, in the Preorder traversal
 *    Create a Node for c
 *    Fetch the left and right substrings of c in the
 *      Inorder traversal
 *    Recur for the left and right substrings subse-
 *      quently passed as Inorder traversal for the
 *      current node's lower subtree
 * 
 *  Time Complexity: O(n^2) {n is number of nodes}
 *  Extra Space Complexity: O(h) {h is height of tree}
 * 
 * Example:
 *  Inorder:  GDHBEACIF
 *  Preorder: ABDGHECFI
 * 
 *         GDHBE[A]CIF
 *         /         \
 *     GDH[B]E      [C]IF
 *     /     \          \
 *   G[D]H  [E]       I[F]
 *   /   \            /
 *  [G] [H]          [I]
 */


class SerializeDeserialize {
    public static void main(String args[]) {
        // creating and printing the Inorder and Preorder traversals of
        // an example Binary Character Tree with unique characters
        CharacterTree tree = new CharacterTree();
        tree.makeExample();
        
        System.out.println("Example Tree\n------------");
        System.out.println("Inorder : " + CharacterTree.inorderTraverse(tree.root));
        System.out.println("Preorder: " + CharacterTree.preorderTraverse(tree.root));

        // creating and printing the serial form of the tree
        String s = serializeTree(tree);
        System.out.println("\n" + "Serialized Tree: " + s + "\n");

        // creating and printing the Inorder and Preorder traversals of
        // the deserialized tree
        CharacterTree dest = deserializeTree(s);
        System.out.println("Deserialized Tree\n-----------------");
        System.out.println("Inorder : " + CharacterTree.inorderTraverse(dest.root));
        System.out.println("Preorder: " + CharacterTree.preorderTraverse(dest.root));

        // (the traversals of the original and deserialized trees match)
    }

    // ------ Serialization ------
    // method to get the Tree in Serial form (here a String)
    static String serializeTree(CharacterTree tree) {
        StringBuilder s = new StringBuilder("");

        s.append(tree.getInorder());
        s.append(tree.getPreorder());

        return new String(s);
    }

    // ------ Deserialization ------
    static int pos;

    // method to get the deserialized tree from Serial form (here a String)
    static CharacterTree deserializeTree(String s) {
        CharacterTree tree = new CharacterTree();

        String inorder  = s.substring(0, s.length() >> 1);  // 1st half of string
        String preorder = s.substring(s.length() >> 1);     // 2nd half of string

        // static variable 'pos' indicates the next element in the
        // preorder string that is to be converted to a node
        pos = 0;    // initializing the static varible
        // calling the overloaded utility recursive function that
        // actually generates the deserialized tree
        tree.root = deserializeTree(inorder, preorder);

        return tree;
    }

    // overloaded utility method to generate the deserialized tree
    static CharacterTree.Node deserializeTree(String inorder, String preorder) {
        // base case
        if (inorder.length() == 0)   return null;

        // identifying the next character in preorder string
        char c = preorder.charAt(pos++);
        // creating the node for the character
        CharacterTree.Node temp = new CharacterTree.Node(c);


        // recurring the subtree generation for the left substring
        // of 'c' in 'inorder' in the current instance of this method
        // in the method call stack
        temp.left = deserializeTree(
            inorder.substring(0, inorder.indexOf(c)), preorder
        );

        // recurring the subtree generation for the right substring
        // of 'c' in 'inorder' in the current instance of this method
        // in the method call stack
        temp.right = deserializeTree(
            inorder.substring(inorder.indexOf(c) + 1), preorder
        );

        // retuning the newly created node as root of subtree generated
        // from this node, in the deserialized tree
        return temp;
    }
}


// defining a custom Character Tree ADT
class CharacterTree {
    // defining a Tree node
    static class Node {
        char value;
        Node left, right;

        // constructor
        Node(char value) {
            this.value = value;
            left = right = null;
        }
    }

    // points to the root node of the tree
    Node root = null;

    // returns Inorder traversal of the current Tree object
    String getInorder() {
        return inorderTraverse(root);
    }

    // returns Preorder traversal of the current Tree object
    String getPreorder() {
        return preorderTraverse(root);
    }


    // generates the Inorder traversal of a Tree considering
    // the passed node as root
    static String inorderTraverse(Node root) {
        StringBuilder s = new StringBuilder("");
        // calls the overloaded utility function
        inorderTraverse(root, s);

        return new String(s);
    }

    // overloaded recurring method to generate the Inorder
    // traversal of the subtree considering 'root' as root
    static void inorderTraverse(Node root, StringBuilder s) {
        if (root == null)   return;

        inorderTraverse(root.left,  s);
        s.append(root.value);
        inorderTraverse(root.right, s);
    }


    // generates the Preorder traversal of a Tree considering
    // the passed node as root
    static String preorderTraverse(Node root) {
        StringBuilder s = new StringBuilder("");
        // calls the overloaded utility function
        preorderTraverse(root, s);

        return new String(s);
    }

    // overloaded recurring method to generate the Preorder
    // traversal of the subtree considering 'root' as root
    static void preorderTraverse(Node root, StringBuilder s) {
        if (root == null)   return;

        s.append(root.value);
        preorderTraverse(root.left,  s);
        preorderTraverse(root.right, s);
    }


    // makes an example Character Tree with unique characters
    void makeExample() {
        root = new Node('A');
            root.left  = new Node('B');
                root.left.left  = new Node('D');
                    root.left.left.left  = new Node('G');
                    root.left.left.right = new Node('H');
                root.left.right = new Node('E');
            root.right = new Node('C');
                root.right.right = new Node('F');
                    root.right.right.left = new Node('I');
        
        // (Tree)            A
        //                 /   \
        //               B      C
        //             /  \      \
        //           D     E      F
        //         /  \          /
        //        G    H       I
    }
}