#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll arr[n+1] = {0};
        ll p;
        for(ll i=0;i<n;i++)
        {
            cin >> p;
            arr[p]++;
        }
        vector<ll> myvec;
        for(ll i=0;i<n+1;i++)
        {
            if(arr[i] > 0)
                myvec.push_back(arr[i]);
        }
        sort(myvec.begin(),myvec.end(),greater<ll>());
        // for(auto i : myvec)
        //     cout << i <<" ";
        // cout << endl;
        ll ma = myvec[0];
        ll total = ma-1;
        for(ll i=1;i<myvec.size();i++)
        {
            if(total > 0)
            {
                ma += min(total,myvec[i]);
                total = min(total,myvec[i])-1;
            }
            else
                break;
        }
        cout << ma  << endl;
    }
    return 0;
}