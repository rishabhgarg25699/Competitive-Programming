#include<iostream>

using namespace std;
void dfs(int** graph,int n,int* visited,int i){

    if(visited[i]==1)
        return ;
    cout<<i<<" ";
    visited[i]=1;
    for(int j=1;j<=n;j++)
        if(graph[i][j]==1)
            if(visited[j]!=1)
                dfs(graph,n,visited,j);

    return ;
}
int main(){


    int n,E;
    cin>>n>>E;
    int** grph = new int*[n];
    for(int i= 1;i<=n;i++)
        grph[i]=new int[n];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grph[i][j]=0;     
        }
    }
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        grph[u][v]=1;
       // grph[v][u]=1;
    }    
    int* visited= new int[n+1];

    dfs(grph,n,visited,1);

    return 0;
}