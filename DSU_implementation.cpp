#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nn,m,parent[100001],ranki[100001];
void makeset()         // to initialize parent of the node to node itself and rank to 0
{
    for(ll i=0;i<=nn;i++)
    {
        parent[i]=i;
        ranki[i]=0;
    }
}
ll find(ll i)        //function to find the key
{
    while(i!=parent[i])
    i=parent[i];
    return i;
}
void unioni(ll x,ll y)           // function to do union after finding the key of both x and y
{
    ll first=find(x);
    ll second=find(y);
    if(first!=second)         
    {
        if(ranki[first]<ranki[second])
        {
            parent[first]=second;
        }
        else
        {
            parent[second]=first;
            if(ranki[first]==ranki[second])
            ranki[first]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,i,t;
    cin>>nn>>m;         //nn= number of nodes, m = number of connected edges
    makeset();
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        --a;
        --b;
        unioni(a,b);
    }
    for(i=0;i<nn;i++)
    {
        cout<<"Node-->"<<i+1<<" "<<"Parent-->"<<parent[i]+1<<" "<<"Rank-->"<<ranki[i]<<endl;           // to print node ,it's parent and it's rank
    }
} 

/* INPUT:
   5 4
   1 3
   2 4
   1 2
   1 4 
   
   OUTPUT:
   Node-->1 Parent-->1 Rank-->2
   Node-->2 Parent-->1 Rank-->1
   Node-->3 Parent-->1 Rank-->0
   Node-->4 Parent-->2 Rank-->0
   Node-->5 Parent-->5 Rank-->0
   
   */
