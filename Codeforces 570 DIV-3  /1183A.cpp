#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
ll sum(ll n)
{
    ll k =0;
    // cout << n << endl;
    while(n > 0)
    {
        k += n%10;
        n = n/10;
    }
    return k;
}
int main()
{
    ll n;
    cin >> n;
    ll a = sum(n);
    // cout << a << endl;
    while(a%4 != 0)
    {
        n++;
        a = sum(n);
    }
    cout << n << endl;
    return 0;
}