/*	
    Implementing wilson's identity with the help of Segmented Sieve method	
    	
    WILSON'S IDENTITY: https://en.wikipedia.org/wiki/Wilson%27s_theorem	
    Question: https://www.hackerearth.com/problem/algorithm/fact-count-a6300182/	
   */	


#include <bits/stdc++.h>	
using namespace std;	
typedef long long int ll;	
vector<ll> vect;	
void simpleSieve(ll limit, vector<ll> &prime)        //implementation of simple sieve	
{ 	
	bool mark[limit+1]; 	
	memset(mark, true, sizeof(mark)); 	
	for (ll p=2; p*p<limit; p++) 	
	{ 	
		if (mark[p] == true) 	
		{ 	
			for (ll i=p*2; i<limit; i+=p) 	
		        mark[i] = false; 	
		} 	
	} 	
	for (ll p=2; p<limit; p++) 	
	{ 	
		if (mark[p] == true) 	
		{ 	
			prime.push_back(p);                          //prime is a vector which stores prime numbers	
			vect.push_back(p);                           	
		} 	
	} 	
} 	
void segmentedSieve(ll n)                 //Function to implement Segmented Sieve	
{ 	
	ll limit = floor(sqrt(n))+1; 	
	vector<ll> prime; 	
	simpleSieve(limit, prime); 	

        // Divide the range [0..n-1] in different segments 	
        // We have chosen segment size as sqrt(n).	
	ll low = limit; 	
	ll high = 2*limit; 	
	while (low < n) 	
	{ 	
		if (high >= n) 	
		high = n; 	
		bool mark[limit+1]; 	
		memset(mark, true, sizeof(mark)); 	
		for (ll i = 0; i < prime.size(); i++) 	
		{ 	
			ll loLim = floor(low/prime[i]) * prime[i]; 	
			if (loLim < low) 	
				loLim += prime[i]; 	
			for (ll j=loLim; j<high; j+=prime[i]) 	
				mark[j-low] = false; 	
		} 	
		for (ll i = low; i<high; i++) 	
			if (mark[i - low] == true) 	
				vect.push_back(i);	
		low = low + limit; 	
		high = high + limit; 	
	} 	
} 	
int main()	
{	
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);	
    cout.tie(NULL);	
    segmentedSieve(100000001); 	
    ll t,n,c,i,b;	
    cin>>t;                              // t= number of test cases	
    while(t--)	
    {	
        cin>>n;                        // n=number of integers you want to enter	
        c=0;	
        for(i=0;i<n;i++)	
        {	
            cin>>b;                   	
            if(binary_search(vect.begin(),vect.end(),b))    //check whether b follows Wilson's identity	
            c++;	
        }	
        cout<<c<<endl;                // number of intergers from the entered number which follow Wilson's Identity	
    }	
    return 0;	
}	

/*	
  INPUT:	
  1	
  5	
  3 4 6 7 8	
  	
  OUTPUT:	
  2	
  */
