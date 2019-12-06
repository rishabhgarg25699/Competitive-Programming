#include<iostream>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll x,sum=0;
        cin >> x;
        ll temp = x;
        while(x > 0)
        {
            sum += x%10;
            x = x/10;
        }
        ll a = sum % 10;
        a = 10 - a;
        if(a == 10)
            a = 0;
        cout << temp << a <<endl;; 
    }
}