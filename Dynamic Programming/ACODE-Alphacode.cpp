#include<bits/stdc++.h>
using namespace std;
int main()
{
    string d;
    long long dp[5001];   
    while(true)
    {
        cin >> d;
        if(d[0]=='0') 
            break;
        long long L = d.length();    
        dp[0] = dp[1] = 1;
        for(int i = 2;i<=L;++i)
        {
            dp[i] = 0;    
            char c1 = d[i-2]-'0', c2 = d[i-1]-'0';
            if(c1==1 || (c1==2 && c2<=6))  // for two digit number 
                dp[i] += dp[i-2];
            if(c2!=0)                      // for single digit number
                dp[i] += dp[i-1];
        }
        cout << dp[L] << endl;
    }
    return 0;
}