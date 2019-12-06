#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll t ;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll arr[n];
		for(ll i=0;i<n;i++) cin >> arr[i];
		ll m;
		cin >> m;
		ll dp[n+1][m+1];
		for(ll i=0;i<n+1;i++)
			dp[i][0] = 1;
		for(ll i=0;i<m+1;i++)
			dp[0][i] = 0;
		for(ll i=1;i<n+1;i++)
		{
			for(ll j=1;j<m+1;j++)
			{
				if(arr[i-1] > j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
			}
		}
		// for(ll i=0;i<n+1;i++)
		// {
		// 	for(ll j=0;j<m+1;j++)
		// 	{
		// 		cout << dp[i][j] <<" ";
		// 	}
		// 	cout << endl;
		// }
		cout << dp[n][m] << endl;
	}
}