import java.util.*;
import java.lang.*;
class Shoelace
{
    static double area(double x[], double y[], int n)
    {
        double ar = 0.0;
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            ar += (x[j] + x[i]) * (y[j] - y[i]);
            j = i;
        }
        ar = Math.abs(ar / 2.0);
        return ar;
    }
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int len;
        System.out.println("Enter the sides in polygon: "); 
        len = sc.nextInt();
        double x[] = new double[len];
        double y[] = new double[len];
        System.out.println("Enter the coordinates in order: ");
        for(int i = 0; i < len; i++)
        {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        double a = area(x, y, len);
        System.out.println("Area is "+a);
    }
}