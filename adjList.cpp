#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> > adjList;
public:
	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void printAdjList(){
		for(auto node:adjList){
			cout<<node.first<<"-->";
			for(auto children:node.second){
				cout<<children<<",";
			}
			cout<<endl;
		}
	}

	void BFS(T src){
		queue<T> q;
		q.push(src);
		map<T,bool> visited;
        for(auto node:adjList)
        {
			visited[node.first]=false;
		}
		visited[src]=true;

		while(!q.empty()){
			T node=q.front();
			q.pop();
			cout<<node<<",";
			for(auto children:adjList[node]){
				if(!visited[children]){
					q.push(children);
					visited[children]=true;
				}
			}
		}
	cout<<endl;

	}

	int SSSP(T src,T des){
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent;

		for(auto node:adjList){
			dist[node.first]=INT_MAX;
		}
		q.push(src);
		dist[src]=0;
		parent[src]=src;

		while(!q.empty()){
			T node=q.front();
			cout<<endl<<node;
			q.pop();

			for(auto children:adjList[node]){
				if(dist[children]==INT_MAX){
					dist[children]=dist[node]+1;
					q.push(children);
					parent[children]=node;
				}
			}
		}

		for(auto children:dist){
			cout<<"Distance of "<<children.first<<" from "<<src<<" : "<<children.second<<endl;
		}

		return dist[des];
	}

};


int main(){

	Graph<int> g;
	// g.addEdge("Modi","Trump");
	// g.addEdge("Modi","Yogi");
	// g.addEdge("Yogi","Prabhu",false);
	// g.addEdge("Prabhu","Modi",false);
	// g.addEdge("Putin","Trump",false);
	// g.addEdge("Putin","Modi",false);
	// g.addEdge("Putin","Pope",false);
	g.addEdge(0,1);
	g.addEdge(2,1);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(4,3);
	g.addEdge(5,3);
	g.addEdge(0,4);

	g.BFS(0);


	return 0;
}
