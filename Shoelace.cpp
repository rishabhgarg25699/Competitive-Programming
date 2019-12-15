#include <bits/stdc++.h>
using namespace std;
double area(double x[], double y[], int n)
{
    double ar = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        ar += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }
    ar = abs(ar / 2.0);
    return ar;
}
int main()
{
    int len;
    cout << "Enter the sides in polygon: "; 
    cin >> len;
    double x[len], y[len];
    cout << "Enter the coordinates in order: ";
    for(int i = 0; i < len; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }
    double a = area(x, y, len);
    printf("\nArea is %f", a);
}