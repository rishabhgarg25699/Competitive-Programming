#include<bits/stdc++.h>
using namespace std;
// C++ code to implement DFS in graph
// Use global variables to prevent overflow

int nodes,edges;
#define MAXN 200000
// Here nodes and edges denotes the number of nodes and number of edges in the graph 
vector<int> graph[MAXN+1];
// A memory efficient way to store the graph in form of adjacency list
bool vis[MAXN+1];
void DFS(int vertex)
{
    vis[vertex]=true;
    //printing the dfs order of the graph
    cout<<vertex<<'\n';
    //traversing in the adjacency list of the graph
    for(int i=0;i<graph[vertex].size();++i)
    {
        int nex=graph[vertex][i];
        // if the vertex is not visited then we go to next unvisited vertex
        if(!vis[nex])
            {
                DFS(nex);
            }
    }
}
int main()
{
    cin>>nodes>>edges;
    for(int i=0;i<edges;++i)
    {
        int vertex1,vertex2;
        cin>>vertex1>>vertex2;
        //denote the edge in the graph
        graph[vertex1].push_back(vertex2);
        //comment out the next line in case of directed graphs
        graph[vertex2].push_back(vertex1);
    }
    int source;
    cin>>source;
    //source vertex to run dfs from the source vertex
    //initializing all the nodes to non-visited
    memset(vis,false,sizeof(vis));
    DFS(source);
}