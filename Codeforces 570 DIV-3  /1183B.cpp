#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll arr[n];
        
        for(ll i=0;i<n;i++) cin >> arr[i];

        ll *max = max_element(arr,arr+n);
        ll *min = min_element(arr,arr+n);

        ll a = *max - k;
        ll b = *max + k;
        ll c = *min - k;
        ll d = *min + k;

        if(a > d)   
            cout << "-1" << endl;
        else
        {
            cout << d << endl;
        }
    }
    return 0;
}