#include<algorithm>
using namespace std;
# define ll long long int
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,p;
		cin >> n;
		ll arr[n], dp[n];
		for(ll i=0;i<n;i++) cin >> arr[i];
		for(ll i=0;i<n;i++) dp[i] = 1;
		for(ll i=1;i<n;i++)
		{
			for(ll j=0;j<i;j++)
			{	
				if(arr[j] < arr[i])
				{
				    p = 1 + dp[j];
					if(dp[i] < p)
						dp[i] = p;
				}
			}	
		}
		 // for(ll i=0;i<n;i++) cout << dp[i] << " ";
		//cout<<dp[n-1]<<endl;
		 ll *l = max_element(dp,dp+n);
		cout << *l <<endl;
	}
}