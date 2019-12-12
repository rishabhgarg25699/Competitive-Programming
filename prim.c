
/*
    Greedy algorithm to fist Minimum Spanning Tree for weighted undirected graphs
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{ 
    int key,weight;
    struct Node *next;
}node;

typedef struct Graph{
    int vertices;
    node **edges;
}graph;

node * createNode(int key){
    node * temp = (node *)malloc(sizeof(node));
    temp -> key = key;
    temp -> next = NULL;
    return temp;
}

graph * createGraph(int n){
    graph * temp = (graph *)malloc(sizeof(graph));
    temp -> vertices = n;  //vertices start from 0 to n-1
    temp -> edges = (node **)malloc(sizeof(node *)*n);
    for(int i = 0; i < n; i++) temp -> edges[i] = NULL;
    return temp;
}

void insertEdge(graph * G,int v1,int v2,int weight){
    node * temp1,* temp2;
    temp1 = createNode(v1);
    temp2 = createNode(v2);
    temp1 -> weight = weight,temp2 -> weight = weight;
    temp2 -> next = G -> edges[v1];
    G-> edges[v1] = temp2;
    temp1 -> next = G -> edges[v2];
    G-> edges[v2] = temp1;
}

void printTree(graph * G){
    node *temp;
    int i,n = G->vertices;
    for(i = 0; i < n; i++){
        temp = G->edges[i];
        while(temp != NULL){
            printf("%d %d %d\t",i,temp -> key,temp -> weight);
            temp = temp -> next;
        }
        printf("\n");
    } 
}

int main(){
    int n,e,i,j,v1,v2,min,k,z;
    node * temp;
    graph * G = createGraph(n);
    scanf("%d %d",&n,&e);
    
    for(i = 0;i < e; i++){
        scanf("%d %d %d",&v1,&v2,&j);
        insertEdge(G,v1,v2,j);
    }
    
    int *arr = (int *)malloc(sizeof(int)*n);  //stores minium edge weights between two sets of vertices -present in mst,yet to be sent to mst
    int *mstnodes = (int *)malloc(sizeof(int)*n);   //stores nodes present in mst as 1 ,absent as 0
    int *minedge = (int *)malloc(sizeof(int)*n);  //stores corresponding other vertex for its index and minimum weight edge

    for(i = 0; i < n; i++) arr[i] = INT_MAX,mstnodes[i] = 0;
    temp = G->edges[0],mstnodes[0] = 1,j = 0;
    graph * MSTtree = createGraph(n);
    while(temp != NULL){ //inserted node 0,updating minimum edge weights
        if(arr[temp -> key] > temp -> weight) arr[temp -> key] = temp -> weight,minedge[temp -> key] = j;
        temp = temp -> next;
    }

    for(z = 1; z < n; z++){
        for(i = 0,min = INT_MAX; i < n; i++){
           if(!mstnodes[i] && arr[i] < min) min = arr[i],k = i;//find minimum of minimum edge
        }
        insertEdge(MSTtree,minedge[k],k,min);
        mstnodes[k] = 1,temp = G->edges[k],j = k;
        while(temp != NULL){
            if(arr[temp -> key] > temp -> weight) arr[temp -> key] = temp -> weight,minedge[temp -> key] = j;
            temp = temp -> next;
        }
    }
    printTree(MSTtree);
    return 0;
}