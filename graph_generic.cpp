#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template< typename T>
class Graph{

    map<T,list<T>> AdjList;
public:

    Graph(){

    }
    void addEdge(T u, T v,bool bidir=true){
        AdjList[u].push_back(v);
        if(bidir)
            AdjList[v].push_back(u);
    }
    void Print(){
        //Iterate over map
        //it.first is the key
        for(auto it:AdjList){
            cout<<it.first<<"-> ";

        //it.second is the LL
        //auto automatically determines the data type
        for(auto adjNode:it.second){
            cout<<adjNode;
        }
        cout<<endl;
        }
    }
    void DFSHelper(T node,map<T,bool> &visited){
        //whenever you come to a node mark it visited
        visited[node]=true;
        cout<<node<<" , ";

        ///find neighbour not visited
        for (T neighbour: AdjList[node]){
            if(!visited[neighbour]){
                DFSHelper(neighbour,visited);
            }
        }

    }
    void DFS(T Src){
        map<T,bool> visited;

        ///components is the number of unconnected graph in the given forest
        int component=1;

        DFSHelper(Src,visited);
        cout<<endl;

        for(auto i:AdjList){
            T city=i.first;
            ///we iterate over all the cities after we have completed a DFS for a particular components
            ///and we again procede with the DFS of the city which is unvisited and increase the cnt of component
            if(!visited[city]){
                DFSHelper(city,visited);
                component++;
            }
        }

    cout<<"The current graph had "<<component<<" components";
    }
    void Topological(T node, map <T,bool> &visited, list<T> &ordering){
        visited[node]=true;
        for(T neighbour:AdjList[node]){
            if(!visited[neighbour])
                Topological(neighbour,visited,ordering);
        }
        //at this point every neighbour of the node is visited hence we enter this node into the list
        ordering.push_front(node);

    }
    void dfsTopologicalSort(){
        map<T,bool> visited;
        list <T> Ordering;

        for(auto it:AdjList){
            T node= it.first;
            if(!visited[node])
                  Topological(node,visited,Ordering);
        }
        for( T ele: Ordering){
            cout<<ele<<" -> ";
        }

    }

    void BFsTopologicalSort(){
        //create and find in degree of all the elements
        map<T, int> Indeg;
        map<T, bool> visited;
        queue<T> q;
        //initialise
        for(auto it:AdjList){
            T node=it.first;
            visited[node]=false;
            Indeg[node]=0;
        }
        for(auto it:AdjList){
            T node=it.first;
            for(T neighbour :AdjList[node]){
                Indeg[neighbour]++;
            }
        }
        for(auto it:AdjList){
            T node=it.first;
            if(Indeg[node]==0)
                q.push(node);
        }
        //start of algo
        while(!q.empty()){
            T curNode=q.front();
            q.pop();
            cout<<curNode<<" ";
            for(T v:AdjList[curNode]){
                Indeg[v]--;

                if(Indeg[v]==0){
                    q.push(v);
                }
            }
        }
    }
    bool IsCyclicBFS(T src){
        map<T, bool> visited;
        map<T, T> Parent;
        queue <T> q;

        visited[src]=true;
        Parent[src]=src;
        q.push(src);

        while(!q.empty()){
            T Curr=q.front();
            q.pop();

            for(T neighbour:AdjList[Curr]){
                if(visited[neighbour]&& Parent[neighbour]!=Curr){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    Parent[neighbour]=Curr;
                    q.push(neighbour);
                }
            }
        }
        return false;


    }

    bool IsCyclicDFSHelper(T src, T Parent, map<T,bool> &visited){
        visited[src]=true;
        for(T neighbour:AdjList[src]){
            if(!visited[neighbour]){
                bool ans=IsCyclicDFSHelper(neighbour,src,visited);
                if(ans)
                    return true;
            }
            else if(neighbour!=Parent){
                return true;
            }
        }
        return false;
    }

    bool IsCyclicDFS(T src){
        map<T,bool> visited;
        //map<T, int> Parent;
        for(auto it: AdjList){
            T node= it.first;
            if(!visited[node]){
                bool ans=IsCyclicDFSHelper(node,visited,node);
                if(ans)
                    return true;
            }
        }
        return false;
    }
};

int main(){

    Graph <string>g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope  ",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",false);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);

    g.Print();
    //g.dfsTopologicalSort();
    g.BFsTopologicalSort();


}
