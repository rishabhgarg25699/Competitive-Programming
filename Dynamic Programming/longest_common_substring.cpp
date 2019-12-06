#include <iostream>
using namespace std;
#define ll unsigned long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; 
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1 >> s2;
        ll arr[n+1][m+1] ;
        for(ll i=0;i<n+1;i++)
            arr[i][0] = 0;
        for(ll i=0;i<m+1;i++)
            arr[0][i] = 0;
        ll max = 0;
        for(ll i=1;i<n+1;i++)
        {
            for(ll j=1;j<m+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                    arr[i][j] = arr[i-1][j-1] + 1;
                else
                    arr[i][j] = 0;
                if(arr[i][j] > max)
                    max = arr[i][j];
            }
        }
        // for(ll i=0;i<n+1;i++)
        // {
        //     for(ll j=0;j<m+1;j++)
        //     {
        //         cout << arr[i][j] <<" ";
        //     }
        //     cout << endl;
        // }
        cout << max << endl;
    }
    return 0;
}