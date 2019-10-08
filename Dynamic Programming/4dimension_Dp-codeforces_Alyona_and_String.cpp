#include <bits/stdc++.h>
using namespace std;
#define faf ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define inff 100000
 
 
ll modo=1e9+7;
 
int dp[1001][1001][11][2]={0};
 
int main()
{
    faf;
    int n,m,l;
    cin>>n>>m>>l;
 
    string s;
    string t;
    cin>>s>>t;
    int a,b,c,d;
    for(a=0;a<=n;a++)
    {
        for(b=1;b<=m;b++)
        {
            for(c=1;c<=l;c++)for(d=0;d<=1;d++)dp[a][b][c][d]=-1;
        }
    }
 
    for(a=1;a<=n;a++)
    {
        for(b=1;b<=m;b++) {
 
            if (s[a - 1] == t[b - 1]) {
 
 
                dp[a][b][1][1]=1;
                for(c=1;c<l;c++)
                {
                    for(d=0;d<2;d++)
                    {
                        if(dp[a-1][b-1][c][d]>0)
                        {
                            dp[a][b][c+1][1]=max(dp[a][b][c+1][1],dp[a-1][b-1][c][d]+1);
                        }
                    }
                }
                for(c=1;c<=l;c++)
                {
                    if(dp[a-1][b-1][c][1]>0)
                    {
                        dp[a][b][c][1]=max(dp[a][b][c][1],dp[a-1][b-1][c][1]+1);
                    }
                }
            }
 
            for (c = 1; c <= l; c++) {
                for (d = 0; d < 2; d++) {
                    dp[a][b][c][0] = max(dp[a][b][c][0], dp[a - 1][b - 1][c][d]);
                    dp[a][b][c][0] = max(dp[a][b][c][0], dp[a - 1][b][c][d]);
                    dp[a][b][c][0] = max(dp[a][b][c][0], dp[a][b - 1][c][d]);
                }
            }
        }
    }
 
    int mx=0;
    for(a=1;a<=n;a++)
    {
        for(b=1;b<=m;b++)
        {
            mx=max(mx,max(dp[a][b][l][0],dp[a][b][l][1]));
        }
    }
    cout<<mx;
 
}
