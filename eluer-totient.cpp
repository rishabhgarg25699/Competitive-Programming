#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD9 1000000009
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define endl "\n"
typedef long long ll;
using namespace std;


ll EulerTotient(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
ll n;
cin>>n;
ll x=EulerTotient(n);
cout<<x<<endl;
 



    
    
    
  return 0;
    
}
