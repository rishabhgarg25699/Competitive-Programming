//dfs implementation in graphs
#include<iostream>
using namespace std;
void dfs(int v);
int adj[100][100],visited[100],present_stack[100],stk[100],n,m,top=0;
int main()
{
	int i,l,j;
	for(i=0;i<100;i++)//initializing all elements to 0
	{
		visited[i]=0;
		present_stack[i]=0;
		stk[i]=0;
	}
	cout<<"ENTER THE NUMBER OF VERTICES"<<endl;
	cin>>n;
	cout<<"ENTER THE NUMBER OF EDGES"<<endl;
	cin>>m;
	for(l=1;l<=m;l++)
	{
		cout<<"enter the edges"<<endl;
		cin>>i>>j;
		adj[i][j]=1;//storing the values in adjacency matrix
	}
	int v;
	cout<<"ENTER THE INITIAL VERTEX TO START FROM"<<endl;
	cin>>v;
	cout<<"DFS TRAVERSAL OF GRAPHS"<<endl;
	dfs(v);
}
void dfs(int v)
{
	int k,j;

	cout<<v<<" ";//printing the node from where we need to start traversing
	visited[v]=1;//marking this node as visited
	for(k=1;k<n;k++)//running loop from 1 to nnumber of vertices
	{
		for(j=n-1;j>=0;j--)
		{
			if(adj[v][j]!=0 && visited[j]!=1 && present_stack[j]!=1)//checking if the element is present in adjacency matrix ,not visited and should not be present in stack
			{
				present_stack[j]=1;//marking that the element is present in stack
				stk[top++]=j;//storing the element in stack
			}
		}
		v=stk[--top];//poping the element
		cout<<v<<" ";
		present_stack[v]=0;//marking that the element is no longer present in stack
		visited[v]=1;//marking that node as visited
	}
}

