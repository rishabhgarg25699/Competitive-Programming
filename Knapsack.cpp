#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll knapSack(ll M,ll w[],ll v[],ll n){ 
    vector<vector<ll>>K(n+1,vector<ll>(M+1));
    for (ll i=0;i<=n;i++){ 
	    for(ll j=0;j<=M;j++){ 
		    if(i==0 || j==0) 
			    K[i][j] = 0; 
		    else if(w[i-1]<=j) 
			    K[i][j]=max((v[i-1]+K[i-1][j-w[i-1]]),K[i-1][j]); 
		    else
			    K[i][j]=K[i-1][j]; 
	    } 
    } 
    return K[n][M]; 
} 
int main(){ 
    fio;
	ll v[]={20,15,30,40}; 
	ll w[]={1,2,3,5}; 
	ll M;       // Capacity of knapsack
	cin>>M;    
	ll n =sizeof(v)/sizeof(v[0]); 
	cout<<knapSack(M,w,v,n); 
	return 0; 
} 
