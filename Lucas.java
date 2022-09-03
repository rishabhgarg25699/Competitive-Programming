import java.util.*;
class Lucas
{
    public static int calc(int n, int r, int p)
    {
        int c[] = new int[r+1];
        c[0] = 1;
        int m = 0;
        for(int i = 1; i <= n; i++)
        {
            m = Math.min(i, r);
            for(int j = m; j > 0; j--)
            c[j] = (c[j] + c[j-1]) % p;
        }
        return c[r];
    }
    public static int Luc(int n, int r, int p)
    {
        if(r == 0)
        return 1;
        return((Luc(n / p, r / p, p) * calc(n % p, r % p, p)) % p);
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        int p = sc.nextInt();
        System.out.println(Luc(n, r, p));
    }
}