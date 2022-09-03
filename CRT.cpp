#include <bits/stdc++.h>
using namespace std;
int invMod(int a, int b)
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
int calc(int n[], int r[], int k)
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
int main()
{
    cout<<"Number of values to be entered:\n";
    int k;
    cin>>k;
    cout<<"Enter numbers with remainder:\n";
    int n[k];
    int r[k];
    for(int i = 0; i < k; i++)
    {
        cin>>n[i];
        cin>>r[i];
    }
    printf("The smallest number is %d", calc(n, r, k));
    return 0;
}