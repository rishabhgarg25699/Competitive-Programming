#include <bits/stdc++.h>
using namespace std;
#define faf ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld  double
long double PI =3.14159265358979323846;
 
 
const  ll modo=1e9+7;
const ll inf=1e13;
const ll ms=(1e5*5) +5;
 
int ar[15];
ll dp[15][110][3];
ll callme() {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int i;
    int j;
    int k;
    int tt;
    for (i = 1; i <= 10; i++) {
        for (j = 0; j <= 99; j++) {
            for (k = 0; k <= 9; k++) {
                tt = j + k;
                dp[i][tt][1] += dp[i - 1][j][1];
                if (k < ar[i]) {
                    dp[i][tt][1] += dp[i - 1][j][0];
                } else if (k == ar[i]) {
                    dp[i][tt][0] += dp[i - 1][j][0];
                }
            }
        }
    }
    ll aa=0;
    ll pp;
    for (i = 0; i <= 99; i++)
    {
        pp=dp[10][i][0]+dp[10][i][1];
        aa+=(pp*i);
    }
    return aa;
}
 
 
void solve(int n)
{
    memset(ar,0, sizeof(ar));
    int i=10;
    while(n)
    {
        ar[i]=n%10;
        i--;
        n/=10;
    }
}
 
int main()
{
    faf;
    int n;
    int m;
    cin>>n>>m;
    while(n>=0&&m>=0)
    {
        n--;
        ll a=0;
        ll b=0;
        if(n>0)
        {
            solve(n);
            a=callme();
        }
        if(m>0)
        {
            solve(m);
            b=callme();
        }
        ll aa=b-a;
        cout<<aa<<"\n";
        cin>>n>>m;
    }
} 
