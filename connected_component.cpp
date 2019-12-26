#include <bits/stdc++.h>
#include<queue>
using namespace std;
vector<int> visit(int** edge,int n,int start,bool* visited){
    queue<int> q;
    vector<int> v;
    q.push(start);
    v.push_back(start);
    visited[start]=true;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edge[val][i]==1 && visited[i]==false){
                q.push(i);
                visited[i] = true;
                v.push_back(i);
            }
        }
    }
    return v;
}
int main()
{
  int n,e;
    cin>>n;
    cin>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        edge[sv][ev]=1;
        edge[ev][sv]=1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            vector<int> sol = visit(edge,n,i,visited);
            sort(sol.begin(),sol.end());
            vector<int>::iterator itr = sol.begin();
            for(;itr!=sol.end();itr++){
                cout<<*itr<< " ";
            }            
        }
        cout<<endl;
    }
    return 0;
    
    
    
    
    
    
}