#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        double d;
        string s;
        cin >> d >> s;
        double a = ceil(0.75*d);
        // cout << a << endl;
        ll count = 0;
        for(ll i=0;i<d;i++)
        {
            if(s[i] == 'P')
                count++;
        }
        if(count >= a)
            cout<<"0"<<endl;
        else
        {
            ll temp = 0,ans;
            count = a - count ;
            ans = count;
            for(ll i=2;i<d-2;i++)
            {
                if(count <= 0)
                {
                    temp = 1;
                    break;
                }
                if(s[i] == 'A')
                {
                    if((s[i-2] == 'P' || s[i-1] == 'P') && (s[i+2] == 'P' ||  s[i+1] == 'P'))
                        count--;
                }
            }
            if(temp == 0 && count != 0)
                cout<<"-1"<<endl;
            else
                cout<<ans<<endl;
        }
    }    
    return 0;
}