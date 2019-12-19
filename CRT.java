import java.util.*;
import java.lang.*;
class CRT
{
    public static int invMod(int a, int b)
    {
        int q , r = 1, t1 = 0, t2 = 1, t = 0, a0 = a;
        while(r > 0)
        {
            q = a / b;
            r = a % b;
            t = t1 - t2 * q;
            a = b;
            b = r;
            t1 = t2;
            t2 = t;
        }
        if(t1 < 0)
        t1 += a0;
        return t1;
    }
    public static int calc(int n[], int r[], int k)
    {
        int product = 1, p = 1, num = 0;
        for(int i = 0; i < k; i++)
        product *= n[i];
        for (int i = 0; i < k; i++)
        {
            p = product / n[i];
            num += r[i] * invMod(n[i], p) * p;
        }
        return num % product;
    }
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Number of values to be entered:");
        int k = sc.nextInt();
        System.out.println("Enter numbers with remainder:");
        int n[] = new int[k];
        int r[] = new int[k];
        for(int i = 0; i < k; i++)
        {
            n[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        System.out.println("The smallest number is " + calc(n, r, k));
    }
}