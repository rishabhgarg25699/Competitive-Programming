#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;
void dfs(bool* visited,int start,vector<int>* edge ,stack<int>& st){
    visited[start] = true;
    for(int i=0;i<edge[start].size();i++){
        int adj = edge[start][i];
        if(!visited[adj]){
            dfs(visited,adj,edge,st);

        }
    }
    st.push(start);
}
void dfs2(bool* visited,vector<int>* edgeT,int start,unordered_set<int>* com){
     visited[start] = true;
     com->insert(start);
    for(int i=0;i<edgeT[start].size();i++){
        int adj = edgeT[start][i];
        if(!visited[adj]){
            dfs2(visited,edgeT,adj,com);

        }
    }
}
void scc(vector<int>* edge,vector<int>* edgeT,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(visited,i,edge,st);

        }
    }
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    unordered_set<unordered_set<int> *>* collection = new unordered_set<unordered_set<int> *>();
    while(!st.empty()){
       int top = st.top();
        st.pop();

                unordered_set<int>* component = new unordered_set<int>();
                if(!visited[top]){
                    dfs2(visited , edgeT,top,component);

                }
               (collection)->insert(component);


     }
    unordered_set< unordered_set<int>* >::iterator itr = collection->begin();
    for(;itr!=collection->end();itr++){
        unordered_set<int>* temp = *itr;
        unordered_set<int>::iterator it = temp->begin();
        for(;it!=temp->end();it++){
            cout<<*it+1<<" ";
        }
        cout<<endl;
    }
}
int main(){
    // making of adjacency list
    int n;
    cin>>n;
     vector<int>* edgeT = new vector<int> [n];
    vector<int>* edge = new vector<int>[n];
   int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int s,f;
        cin>>s>>f;
        edge[s-1].push_back(f-1);
        edgeT[f-1].push_back(s-1);
    }
    scc(edge,edgeT,n);
    return 0;
}
