import java.util.*;
class Zeck
{
    public static int fib(int n)
    {
        if (n == 0 || n == 1)
        return n;
        int a = 0, b = 1, c = 1;
        while (c <= n)
        {
            a = b;
            b = c; 
            c = a + b;
        }
        return b;
    }
    public static void disp(int n)
    {
        while (n > 0)
        {
            int f = fib(n);
            System.out.print(f + " ");
            n = n - f;
        }
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("The representation for " + n + " is");
        disp(n);
    }
}