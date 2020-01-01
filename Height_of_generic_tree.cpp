//Height of a generic(N-ary) tree from parent array

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)

ll findHeight(ll p[], ll node, ll height[], ll visited[]){
    if(p[node]==-1)
    return 1;
    if(visited[node])
    return height[node];
    visited[node]=1;
    height[node]=1+findHeight(p,p[node],height,visited);
    return height[node];
}

ll maxHeight(ll p[], ll n){
    ll height[n]={0};
    ll visited[n]={0};
    ll H=0;
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            height[i]=findHeight(p,i,height,visited);
            H=max(H,height[i]);
        }
        //cout<<height[i]<<" ";
    }
    //cout<<endl;
    return H;
}

int main(){
    fio;
    ll n;
    cin>>n;
    ll parent[n];
    for(ll i=0;i<n;i++)
    cin>>parent[i];
    cout<<maxHeight(parent,n)<<endl;
}
