#include<bits/stdc++.h>
using namespace std;
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int calc(int n, int r, int p)
{
    int c[r+1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = min(i, r); j > 0; j--)
        c[j] = (c[j] + c[j-1]) % p;
    }
    return c[r];
}
int Luc(int n, int r, int p)
{
    if(r == 0)
    return 1;
    return((Luc(n / p, r / p, p) * calc(n % p, r % p, p)) % p);
}
int main()
{
    int n, r, p;
    cin>>n;
    cin>>r;
    cin>>p;
    printf("%d", Luc(n, r, p));
    return 0;
}