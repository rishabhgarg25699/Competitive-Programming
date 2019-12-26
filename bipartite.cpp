/************ Assuming the graph is connected graph ************************/ 
#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
bool bipartite(vector<int>* edge ,int n){
  if(n==0){
    return true;
  }
  unordered_set<int> set[2];
  vector<int> pending_queue;
  set[0].insert(0);
  pending_queue.push_back(0);
  while(pending_queue.size()>0){
    int current = pending_queue.back();
    pending_queue.pop_back(); /// using vector as a stack
    int current_set = set[0].count(current)>0?0:1; // returns in which set is the current element ?
    for(int i=0;i<edge[current].size();i++){
      int adj = edge[current][i];
      if(set[0].count(adj)==0 && set[1].count(adj)==0){  // element is not present at both the sets
        set[1-current_set].insert(adj);
        pending_queue.push_back(adj);
      }
      else if(set[current_set].count(adj)>0){
        return false;
      }
    }

  }
  return true;

}
int main(void){
  while(true){
    int n;
    cin>>n;
    if(n==0){
      break;
    }
    vector<int>* edge = new vector<int>[n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
      int s,f;
      cin>>s>>f;
      edge[s].push_back(f);
      edge[f].push_back(s);
    }
    bool ans = bipartite(edge , n);
    delete [] edge;
    if(ans){
      cout<<"BICOLORABLE "<<endl;
    }else{
      cout<<"NOT BICOLORABLE"<<endl;
    }
  }
}
