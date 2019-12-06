#include <bits/stdc++.h>
using namespace std;
#define faf ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld  double
long double PI =3.14159265358979323846;


const  ll modo=1e9+7;
const ll inf=1e13;
const ll ms=(1e6) +5;

int nn=0;
vector<int> vv[ms];
int euler[2*ms];
bool vis[ms]={false};
int first[ms];
int tree[8*ms];
int heh[ms];

void dfs(int node,int h)
{
    //cout<<node<<endl;
    vis[node]= true;
    heh[node]=h+1;
    first[node]=nn;
    euler[nn]=node;
    ++nn;
    for(int i:vv[node])
    {
        if(!vis[i])
        {
            dfs(i,heh[node]);
            euler[nn]=node;
            ++nn;
        }
    }
}


void buildtree(int s,int e ,int index)
{
    if(s==e)
    {
        tree[index]=euler[s];
        return ;
    }
    int mid=(s+e)/2;
    buildtree(s,mid,2*index);
    buildtree(mid+1,e,2*index+1);

    tree[index]=heh[tree[2*index]]<=heh[tree[2*index+1]]?tree[2*index]:tree[2*index+1];
}


int query(int s,int e,int l,int r,int index)
{
    if(s>r||l>e)return -1;
    if(s>=l&&r>=e)return tree[index];

    int mid=(s+e)/2;
    int ln=query(s,mid,l,r,2*index);
    int rn=query(mid+1,e,l,r,2*index+1);

    int lh=ln!=-1?heh[ln]:INT_MAX;
    int rh=rn!=-1?heh[rn]:INT_MAX;
    if(lh<=rh)return ln;
    return rn;
}

int lca(int u,int v)
{
    int l=first[u];
    int r=first[v];
    if(l>r)swap(l,r);
    return query(0,nn,l,r,1);
}

int main()
{
    faf;

    int t;
    cin>>t;
    int cc=1;
    while(t--)
    {
        int n;
        cin>>n; int m;
        int i; int j; int e;
        for(i=1;i<=n;i++) {
            cin >> m;
            for (j = 1; j <= m; j++)
            {
                cin>>e;
                vv[i].pb(e);
                vv[e].pb(i);
            }
        }

        dfs(1,0);
        buildtree(0,nn,1);
        int q;
        cin>>q;
        cout<<"Case "<<cc<<": \n";
        while (q--)
        {
            int u;int v;
            cin>>u>>v;
            e=lca(u,v);
            cout<<e<<"\n";
        }
        for(i=0;i<=n;i++)
        {
            vv[i].clear();
            vis[i]=0;
        }
        n=0;
        ++cc;
    }



    return 0;
} 
