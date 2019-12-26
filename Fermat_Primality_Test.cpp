#include <bits/stdc++.h> 
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std; 
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
cpp_int calculate(cpp_int a, cpp_int n, cpp_int p) 
{ 
	cpp_int ans=1; 
	a=a%p; 
	while (n>0) 
	{ 
		if (n&1) 
			ans=(ans*a)%p;
		n=n>>1;
		a=(a*a)%p; 
	} 
	return ans; 
} 
bool isPrime(cpp_int n, int k) 
{ 
    if(n<=1 || n==4) 
    return false; 
    if(n<=3) 
    return true;
    while (k>0) 
    {  
    	cpp_int a =2+rand()%(n-4); 
	    if (__gcd(n,a)!=1) 
		    return false; 
	    if (calculate(a,n-1,n)!= 1) 
		    return false; 
	    k--; 
	} 
	return true; 
} 
int main() 
{ 
    fio;
	int t;
	cpp_int n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int k=3;
	    if(isPrime(n,k))
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	return 0; 
} 
