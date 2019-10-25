/*
Can't look back
they will not come back
Can't be afraid
It's time after time
So once again
I'm hiding in my room
the peaceful times have made us blind
 
So you can't fly if never try
You told me... Oh, Long ago
But you left the wall
Outside the gate
So more than ever, It's real
 
It was like a nightmare...
It's painful for me..
Cause' nobody wants to die too fast...
Remember the day of grief
now it's strange for me..
I could see your face
I could hear your voice....
Remember the day we met
And it's painful for me..
Cause' nobody wants to die too fast...
Remember a day we dreamt
Oh, it's painful for me....
I could see your face..
I could hear your voice.....!!!
*/
 
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
#define mxi 32000

int main()
{
    fast_as_levi;
    ll n,t;
    cin>>n>>t;
    ll ar[mx],br[mx],dp[2][mx];
	dp[1][0]=t;
	for(ll i=0;i<n-1;i++)
	{
		cin>>ar[i];
	}
	for(ll i=0;i<n-1;i++)
	{
		cin>>br[i];
	}
	for(ll i=1;i<n;i++)
	{
		dp[0][i]=min(ar[i-1],br[i-1]+t)+min(dp[0][i-1],dp[1][i-1]);
		dp[1][i]=min(dp[0][i-1]+br[i-1]+t,dp[1][i-1]+br[i-1]);
	}
	for(ll i=0;i<n;i++) 
	{
	    cout<<min(dp[0][i],dp[1][i])<<" ";
	}
}
