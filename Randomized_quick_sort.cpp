#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct pivot
{
	ll m1;
	ll m2;
};
void swap(ll arr[],ll i,ll j)
{
	ll temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void part_r(ll arr[],ll l,ll r)
{
	ll x=l+rand()%(r-l);
	swap(arr,l,x);
}
pivot partition(ll arr[],ll l,ll r)
{
	part_r(arr,l,r);
	ll i,j=l,k=l,c=0;
	pivot p;
	for(i=l+1;i<=r;i++)
	{
		if(arr[i]==arr[l])
		{
			k++;
			j++;
			swap(arr,j,i);
			swap(arr,k,j);
		}
		else if(arr[i]<arr[l])
		{
			j++;
			swap(arr,i,j);
		}
	}
	for(i=l;i<=k;i++)
	{
		swap(arr,i,j-c);
		c++;
	}
	k=j-c+1;
	p.m1=k;
	p.m2=j;
	return p;
	
}
void qsort(ll arr[],ll l,ll r)
{
	if(l<r)
	{
		pivot m=partition(arr,l,r);
		qsort(arr,l,m.m1-1);
		qsort(arr,m.m2+1,r);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cut.tie(NULL);
	ll n,i;
	cin>>n;
	ll arr[n+100];
	for(i=0;i<n;i++) 
	   cin>>arr[i];
	qsort(arr,0,n-1);
	for(i=0;i<n;i++)
	   cout<<arr[i]<<" ";
	return 0;
}
