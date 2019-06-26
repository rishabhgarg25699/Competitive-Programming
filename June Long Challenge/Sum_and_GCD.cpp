#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll findGCD(ll arr[], ll n) 
{ 
    ll result = arr[0]; 
    for (ll i = 1; i < n; i++) 
        result = __gcd(arr[i], result); 
  
    return result; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n;
        if(n == 2)
        {
            ll r,t;
            cin >> r >> t;
            cout << r + t <<endl;
        }
        else
        {
            set<ll> myset;
            for(ll i=0;i<n;i++)
            {
                cin >> k;
                myset.insert(k);
            }
            ll a = myset.size();
            if(a == 1)
                cout << k <<endl;
            else
            {
                ll arr[a],j=0;
                for(auto i:myset)
                {
                    arr[j] = i;
                    j++;
                }
                // for(ll i=0;i<a;i++) cout<<arr[i]<<" ";
                // cout<<endl;
                // CASE 1
                ll p = arr[a-1];
                ll q = findGCD(arr,a-1);
                // cout << p << a <<endl;
                ll gcd1 = p + q;
                //CASE 2
                ll x = arr[a-2];
                arr[a-2] = 0;
                ll y = findGCD(arr,a);
                ll gcd2 = x + y;
                // cout << gcd1 << " " << gcd2 <<endl;
                cout << max(gcd1,gcd2) << endl;
            }
        }
    }    
    return 0;
}