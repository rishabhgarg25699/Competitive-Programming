/**
 * Java program to find the nth Fibonacci number in O(log n) time
 * complexity.
 * 
 * Algorithm:
 *  Consider a matrix:
 *   | 1  1 | | 1  1 |
 *   | 1  0 | | 1  0 |
 *  The nth power of the matrix is:
 *   | F(n + 1) F(n)     |
 *   | F(n)     F(n - 1) |
 *   where F(n) is the nth Fibonacci number
 * 
 * Time Complexity: O(log n)
 * Extra Space Complexity: O(log n) for recursive stack calls
 */


class FibonacciMatrixMethod {
    public static void main(String args[]) {
        int n = 8;

        System.out.print(n + "th Fibonacci number is ");
        System.out.println(getFibonacci(n));
    }

    // method to get the nth Fibonacci number
    static int getFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int f[][] = { {1, 1}, {1, 0} };
        // get f^(n - 1) whose 1st element is F(n)
        getMatrixPower(f, n - 1);

        return f[0][0];
    }

    // returns f in nth power
    static void getMatrixPower(int f[][], int n) {
        if (n == 0 || n == 1)   return;

        // gets f^(n / 2)
        getMatrixPower(f, n / 2);
        multiplyMatrix(f, f);   // squaring the matrix

        int m[][] = { {1, 1}, {1, 0} };
        // if n was odd multiply once with initial matrix
        if (n % 2 != 0)
            multiplyMatrix(f, m);
    }

    // multiplies matrices f and m, result stored in f
    static void multiplyMatrix(int f[][], int m[][]) {
        int a = f[0][0] * m[0][0] + f[0][1] * m[1][0];
        int b = f[0][0] * m[0][1] + f[0][1] * m[1][1];
        int c = f[1][0] * m[0][0] + f[1][1] * m[1][0];
        int d = f[1][0] * m[0][1] + f[1][1] * m[1][1];

        f[0][0] = a; f[0][1] = b;
        f[1][0] = c; f[1][1] = d;
    }
}
