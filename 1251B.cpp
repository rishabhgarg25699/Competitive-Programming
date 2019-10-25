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
#define mxi 1005
int main()
{
    fast_as_levi;
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,n;
        cin>>n;
        ll ans=0,y=0,z=0;
        vector<string> str(n);
        for(i = 0; i < n; i++)
        {
            cin>>str[i];
        }
        for(auto x : str)
        {
               ll c1=0,c2=0,c3=0;
               for(auto y : x)
               {
                     if(y == '1')
                        c2++;
                     else
                        c1++;
               }
            //   cout<<c1<<" "<<c2<<" "<<c3<<"\n";
               if(x.size() % 2 == 1)
                  z++;
               if(!c1 || !c2)
                  ans++;
               else
               {
                  if(x.size()&1)
                  {
                      ans++;
                  }
                  else
                  {
                     if(c1&1)
                        y++;
                     else
                        ans++;
                  }
               }
        }
        if(y&1)
        {
            if(!z)
            y--;
        }
        ans += y;
        cout << ans << "\n";
    }
}
