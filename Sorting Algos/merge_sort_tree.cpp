//Codeforces Enemy is Weak- https://codeforces.com/contest/61/problem/E


#include <bits/stdc++.h>
using namespace std;
#define faf ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


ll modo=1e9+7;
const ll inf=1e13;
const ll ms=(1e6) +5;
int ar[ms];
vector<int> tree[ms*4];



void buildtree(int s,int e ,int index)
{
    if(s==e)
    {
        tree[index].pb(ar[s]);
        return;
    }
    int mid=(s+e)/2;
    buildtree(s,mid,2*index);
    buildtree(mid+1,e,2*index+1);
    merge(tree[2*index].begin(),tree[2*index].end(),tree[2*index+1].begin(),tree[2*index+1].end(),back_inserter(tree[index]));
    return;
}


ll  binone(vector<int> vv,int p)
{
    int siz=vv.size();
    int l=0;
    int r=siz-1;
    int mid;
    int ans=siz;
    while (l<=r)
    {
        mid=(l+r)/2;
        if(vv[mid]>p){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    return siz-ans;
}

ll bintwo(vector<int> vv,int p)
{
    int r=vv.size()-1;
    int l=0;
    int ans=-1;
    int mid;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(vv[mid]>=p){
            r=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans+1;
}

ll query1(int s,int e,int l,int r ,int index,int v,int ty)
{
    if(s>r||l>e)return 0;
    if(s>=l&&r>=e)
    {
        if(ty)
        {
            int pp=tree[index].end()-upper_bound(tree[index].begin(),tree[index].end(),v);
            return pp;
        }
        else
        {
            int pp=upper_bound(tree[index].begin(),tree[index].end(),v)-tree[index].begin();
            return pp;
        }
    }
    int mid=(s+e)/2;
    ll lef=query1(s,mid,l,r,2*index,v,ty);
    ll rig=query1(mid+1,e,l,r,2*index+1,v,ty);
    return lef+rig;
}



int main()
{
    faf;
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)cin>>ar[i];
    buildtree(0,n-1,1);
    ll ans=0;
    ll lef=0;
    ll rig=0;
    for(i=1;i<n-1;i++)
    {
        lef=query1(0,n-1,0,i-1,1,ar[i],1);
        rig=query1(0,n-1,i+1,n-1,1,ar[i],0);
        ans+=(lef*rig);
    }
    cout<<ans;

    return 0;
}
