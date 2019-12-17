class FibonacciMatrixMethod {
    public static void main(String args[]) {
        int n = 8;

        System.out.print(n + "th Fibonacci number is ");
        System.out.println(getFibonacci(n));
    }

    static int getFibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int f[][] = { {1, 1}, {1, 0} };
        getMatrixPower(f, n - 1);

        return f[0][0];
    }

    static void getMatrixPower(int f[][], int n) {
        if (n == 0 || n == 1)   return;

        getMatrixPower(f, n / 2);
        multiplyMatrix(f, f);

        int m[][] = { {1, 1}, {1, 0} };
        if (n % 2 != 0)
            multiplyMatrix(f, m);
    }

    static void multiplyMatrix(int f[][], int m[][]) {
        int a = f[0][0] * m[0][0] + f[0][1] * m[1][0];
        int b = f[0][0] * m[0][1] + f[0][1] * m[1][1];
        int c = f[1][0] * m[0][0] + f[1][1] * m[1][0];
        int d = f[1][0] * m[0][1] + f[1][1] * m[1][1];

        f[0][0] = a; f[0][1] = b;
        f[1][0] = c; f[1][1] = d;
    }
}