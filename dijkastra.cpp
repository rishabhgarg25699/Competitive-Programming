#include<bits/stdc++.h>
using namespace std;
int getmin(bool* visited , int* dis , int n){
    int min =-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (min==-1 || dis[min] > dis[i])){
            min = i;
        }
    }
    return min;
}
void dijkastra(int** edge , int n){
    bool* visited = new bool[n];
    int* dis = new int[n];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        dis[i] = INT_MAX-100;
    }
    parent[0] =-1;
    dis[0] = 0;
    for(int i=0;i<n-1;i++){
        int minnode = getmin(visited,dis,n);
        visited[minnode] = true;
        for(int j=0;j<n;j++){
            if(edge[minnode][j]!=0 && !visited[j]){
                if(dis[j]  > (dis[minnode]+edge[minnode][j])){
                    parent[j] = minnode;
                    dis[j] = dis[minnode]+edge[minnode][j];
                }
            }
        }
    }
    //cout<< "now for the output"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<< " "<<dis[i]<<endl;
    }
}
int main(void){
    int n,e;
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] =0 ;
        }
    }
    for(int i=0;i<e;i++){
        int s,f,wt;
        cin>>s>>f>>wt;
        edge[s][f] = wt;
        edge[f][s] = wt;
    }
    dijkastra(edge,n);
}