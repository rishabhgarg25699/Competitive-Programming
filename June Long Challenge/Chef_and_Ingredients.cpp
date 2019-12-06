#include <iostream>
using namespace std;
#define ll unsigned long long int
#define M 1000000007
using namespace std; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        n--;
        k--;
        // k = first term , n = d ; 
        // nth = number of terms in AP
        ll nth = (k / n) + 1;
        ll last_term = k - (nth - 1)*n;
        // cout << (nth * (k + last))/2 <<endl;
        ll ans =  ((nth%M) * ((k%M) + (last_term%M))%M)%M ;
        // cout << ans / 2 <<endl;
        cout << (ans%M*500000004%M)%M<<endl;
    }                                                             
    return 0;
}