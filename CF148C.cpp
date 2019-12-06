#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


ll modo=1e9+7;
const ll inf=1e15;
const ll ms=(1e5*2) +5;

int ar[200];

int main()
{
    idfc;


    int n;
    int a;
    int b;
    cin>>n>>a>>b;
    int p=1;
    ar[1]=1;

    int s=1;
    int rem=n-a-b-1;
    int i;
    int mx=1;
    while(b--)
    {
        p++;
        ar[p]=s+1;
        s+=ar[p];
        mx=ar[p];
    }
    while(rem--)
    {
        p++;
        ar[p]=1;
        s+=ar[p];
    }
    while (a--)
    {
        p++;
        ar[p]=mx+1;
        if(ar[p]>s)
        {
            cout<<"-1";
            return 0;
        }
        s+=ar[p];
        mx=ar[p];
    }
    for(i=1;i<=n;i++)cout<<ar[i]<<" ";



    return 0;
}
