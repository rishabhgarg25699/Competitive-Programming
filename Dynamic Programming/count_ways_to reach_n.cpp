#include <iostream>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll arr[100000];
    arr[0] = 1;
    arr[1] = 2;
    for(ll i=2;i<100000;i++)
        arr[i] = (arr[i-1]%mod + arr[i-2]%mod)%mod;
    // for(ll i=0;i<102;i++)
    //     cout << i << " -> " << arr[i] << endl;
    while(t--)
    {
        ll n;
        cin >> n; 
        cout << arr[n-1] << endl;
    }
    return 0;
}