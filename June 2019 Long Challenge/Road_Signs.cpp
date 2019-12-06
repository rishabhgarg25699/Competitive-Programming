#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;     
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main() 
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout<<(power(2,n-1,MOD)%MOD * 10%MOD)%MOD<<endl;
    }
    return 0;
}