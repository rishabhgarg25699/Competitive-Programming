/**
 * Java program to find the palindromic substrings in a
 * string that are of maximum length (among palindromic
 * substrings in the string), using bottom-up Dynamic
 * Programming approach
 * 
 * Algorithm:
 *  Let n denote the length of the string s; create a
 *    boolean 2D n x n array; initialize all to false
 *  (Any entry a[i][j] be true means the substring
 *    between indices i and j, both inclusive, is a
 *    palindromic substring)
 *  Initialize all a[i][i] to be true (all single
 *    character substrings are palindromic)
 *  If an entry a[i + 1][j - 1] is true and s(i) ==
 *    s(j), it means that substring between i and j
 *    is palindromic, as substring between i + 1 and
 *    j - 1 is already found to be a substring
 *  Keep count of maximum length while verifying
 *  To find the list of longest palindromic substrings
 *    after completion of the array filling, check for
 *    all a[i][i], if a[i][i + maxLength - 1] is true
 *    the substring between i and i + maxLength - 1 is
 *    a longest palindromic substring
 * 
 * Example array after filling:
 *     b a n a n a
 *     -----------
 * b | 1 0 0 0 0 0
 * a | 0 1 0 0 0 0 
 * n | 0 0 1 0 0 0
 * a | 0 0 0 1 0 0
 * n | 0 0 0 0 1 0
 * a | 0 0 0 0 0 1
 * 
 * Longest Palindromic Substring/s: anana
 */


import java.util.ArrayList;

class LongestPalindromicSubstringDP {
    public static void main(String args[]) {
        // query string
        String s = "kookaburrua";

        // getting the list of Longest Palindromic Substrings
        // and finding the length
        ArrayList<String> strings = getLongPalinSubstr(s);
        int lenMax = strings.size() == 0 ? 0 : strings.get(0).length();

        System.out.println("Query String: " + s);
        System.out.println("\nLength of Longest Palindromic Substrings: " + lenMax);

        System.out.println("\nLongest Palindromic Substrings: ");
        for (String i : strings)
            System.out.println("  - " + i);
    }


    // method to find the list of the Longest Palindromic
    // Substrings of a given string
    static ArrayList<String> getLongPalinSubstr(String s) {
        int len = s.length();

        boolean arr[][] = new boolean[len][len];

        // filling true for substrings of length 1
        for (int i = 0; i < len; i++)
            arr[i][i] = true;
        
        // initializing maximum length of longest palindromic
        // substring to 1, as it is the minimum
        int lenMax = 1;


        // filling true for length 2
        for (int i = 0; i < len - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                arr[i][i + 1] = true;
                lenMax = 2;
            }
        }

        
        // filling true for length 3 and up
        for (int k = 3; k <= len; k++) {
            for (int i = 0; i < len - k + 1; i++) {
                int j = i + k - 1;

                if (arr[i + 1][j - 1] &&
                    s.charAt(i) == s.charAt(j)) {
                    
                    arr[i][j] = true;
                    lenMax = k;
                }
            }
        }


        // creating the list of longest palindromic substrings
        ArrayList<String> strings = new ArrayList<>();
        
        for (int i = 0; i < len; i++) {
            if ((i + lenMax - 1) >= len)
                break;
            
            if (arr[i][i + lenMax - 1])
                strings.add(s.substring(i, i + lenMax));
        }

        return strings;
    }
}
