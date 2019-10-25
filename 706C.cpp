#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mx 1000005
#define mod 1000000007
// #define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define mxi 1005
 
int main()
{
    fast_as_levi;
    ll i,j,k,n;
    cin>>n;
    ll ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    string str[n][2];
    for(i=0;i<n;i++)
    {
        cin>>str[i][0];
        str[i][1] = str[i][0];
        reverse(str[i][1].begin(),str[i][1].end());
    }
    ll dp[mx][2];
    // dp[0][0] = 0;
    dp[0][1] = ar[0];
    for(i=1;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            dp[i][j] = 1e18;
            for(k=0;k<2;k++)
            {
                if(str[i][j]>=str[i-1][k])
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][k] + ar[i]*j);
                }
            }
        }
    }
    // for(i=0;i<n;i++)
    // {
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<"\n";
    // for(i=0;i<n;i++)
    // {
    //     cout<<dp[i][1]<<" ";
    // }
    // cout<<"\n";
    ll ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans == 1e18)
    return cout<<-1 , 0;
    cout<<ans;
}
