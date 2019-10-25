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
       string str;
       cin>>str;
       ll i,n = str.length(); 
       queue<ll> q1,q2;
       for(auto i:str)
       {
           if((i-'0')%2==0) 
           {
               q1.push(i-'0');
           }
           else
           {
               q2.push(i-'0');
           }
       }
       while(q1.size()||q2.size())
       {
           ll x = mxi;
           ll y = mxi;
           ll z = mxi;
           if(q1.size())
           {
               y = q1.front();
           }
           if(q2.size())
           {
               x = q2.front();
           }
           if(y < x)
           {
               cout<<y;
               q1.pop();
           }
           else if(x < y) 
           {
               cout<<x;
               q2.pop();
           }
       }
       cout<<"\n";
    }
}
