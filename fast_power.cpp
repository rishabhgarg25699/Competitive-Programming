#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD9 1000000009
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define endl "\n"
typedef long long ll;
using namespace std;

ll fast_power(ll n, ll k, ll p = MOD) {
ll r = 1; 
for (; k; k >>= 1)
 {
 if (k & 1) r = r * n%p; 
 n = n * n%p;
 } 
 return r;
 }
 




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 ll a,b,c;
 cin>>a>>b>>c;
 ll ans=fast_power(a,b,c);
 cout<<ans<<endl;
 



    
    
    
  return 0;
    
}
