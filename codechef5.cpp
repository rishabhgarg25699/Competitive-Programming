#include<bits/stdc++.h>
using namespace std;
void dfs(int** edges,int n,int sv,bool* visit)
{
	visit[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		 continue;
		if(edges[sv][i]==1)
			{
			if(visit[i])
			 continue;
		dfs(edges,n,i,visit);
	}
	}
}
int primes[]={29,31,37,41,43,47};
int main()
{
	int test;
	int in;
	cin>>test;
	while(test--)
	{
		cin>>in;
		int* arr=new int[in];
		int** edges=new int*[in];
		for(int i=0;i<in;i++)
		{

		 edges[i]=new int[in];
		 for(int j=0;j<in;j++)
		 	edges[i][j]=0;
		}
		for(int i=0;i<in;i++)
		 {
		 	cin>>arr[i];

		 }
		 for(int i=0;i<in-1;i++)
		 {
		 	int j=i+1;
		 	while(j<in)
		 	{
		 		if(__gcd(arr[i],arr[j])==1)
		 		{
		 			edges[i][j]=1;
		 			edges[j][i]=1;
				}
				j++;
			}
		 }
		 bool* visited=new bool[in];
		 for(int i=0;i<in;i++)
		 	visited[i]=false;
		dfs(edges,in,0,visited);
		bool res=false;
		 for(int i=0;i<in;i++)
		 {
		 	if(!visited[i])
		 	{
		 		bool check=false;
		 		res=true;
		 		for(int r=0;r<in;r++)
		 		{
		 			if(arr[r]!=47)
		 			{

		 			arr[i]=47;
		 			check=true;
		 			}
				 }
				 if(!check)
				 	arr[i]=29;
				 break;
			 }

		 }
		 if(res)
		 {
		 	cout<<1<<endl;
		 }
		 else
		 {
		 	cout<<0<<endl;
		 }
		 for(int i=0;i<in;i++)
		 {
		 	cout<<arr[i]<<" ";
			 }
			 cout<<endl;
	}
}
