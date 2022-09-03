#include <iostream>
#include<algorithm>
#include<cstring>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define inf (int)1e9
int dp[101][50001];  // dp[n][sum]
bool istrue(ll arr[], int n, int sum)
{
    if ((sum == 0) || (n == 0 && sum == 0))
        return true;
    if (n == 0)
        return false;
    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];
    bool p = false, q = false;
    if (sum >= arr[n - 1])
        p = istrue(arr, n - 1, sum - arr[n - 1]);
    q = istrue(arr, n - 1, sum);
    dp[n - 1][sum] = p || q;
    return dp[n - 1][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    // t  = 1;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        ll sum = 0;
        memset(dp, -1, sizeof(dp));
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            sum = sum / 2;
            // cout << sum << endl;
            if (istrue(arr, n, sum) == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}

