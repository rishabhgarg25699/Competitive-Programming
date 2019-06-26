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
        ll n,sum = 0,sum2 = 0;  cin >> n;
        ll arr[n],test[n];
        for(ll i=0;i<n;i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        ll k,x,count = 0;  cin >> k >> x;
        for(ll i=0;i<n;i++)
        {
            test[i] = (arr[i]^x)-arr[i];
            if((arr[i]^x)-arr[i] > 0)
                count++;
            sum2 += arr[i]^x;
        }
        sort(test,test+n,greater<ll>());
        // for(ll i=0;i<n;i++) cout << test[i] <<" ";
        // cout<<endl; 
        ll p = sum ;
        if(n == k)
            cout << max(sum,sum2) << endl;
        else if(k%2 == 0)
        {
            if(count % 2 != 0)
            {
                if((count == n) || ((test[count-1]+test[count]) < 0))
                    count--;
                else
                    count++;
            }
            for(ll i=0;i<count;i++)
                sum += test[i];
            cout << sum <<endl;
        }
        else
        {
            for(ll i=0;i<count;i++)
                sum += test[i];
            cout << sum << endl;
        }
    }
}