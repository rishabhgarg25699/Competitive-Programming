/* To create a binary max heap*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1000000],n;
void swap(ll *x, ll *y) 
{ 
    ll temp = *x; 
    *x = *y; 
    *y = temp; 
}
ll parent(ll i)
{
    return (i-1)/2;
}
ll leftchild(ll i)
{
    return 2*i+1;
}
ll rightchild(ll i)
{
    return 2*i+2;
}
void sift_up(ll i)
{
    while(i!=0 && a[parent(i)]<a[i])
    {
        swap(a[parent(i)],a[i]);
        i=parent(i);
    }
}
void sift_down(ll i)
{
    ll max_index=i;
    ll l =leftchild(i);
    ll r=rightchild(i);
    if(l<n && a[l]>a[i])
        max_index=l;
    if(r<n && a[r]>a[max_index])
        max_index=r;
    if(i!=max_index)
    {
        swap(&a[max_index],&a[i]);
        sift_down(max_index);
    }
}
ll extract_max()
{
    ll x=a[0];
    a[0]=a[n-1];
    n=n-1;
    sift_down(0);
    return x;
}
void insert(ll p)
{
    a[n]=p;
    n=n+1;
    sift_up(n-1);
}
void change_priority(ll i,ll p)
{
    ll oldp=a[i];
    a[i]=p;
    if(oldp<p)
        sift_up(i);
    else
        sift_down(i);
}
void deletekey(ll i)
{
    a[i]=a[n-1];
    n=n-1;
    sift_down(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,x,m;
    n=0;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x;
        insert(x);
    }
    cin>>x;
    insert(x);
    cin>>i>>x;
    change_priority(i,x);
    cin>>i;
    deletekey(i);
    cout<<extract_max()<<endl;
}
