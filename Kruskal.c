#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int v1,v2,weight,id;
}node;//to form a graph with these nodes as elements of array

typedef struct Graph{
    int vertices,edgeCount;
    node *edges;
}graph;

typedef struct SetNode{
    int size,vertex;//to implement disjoint sets 
    struct SetNode * parent; 
}setNode;

void merge(node *arr,int low,int mid,int high){
	int i,j,k;
    node *arr1,*arr2;//to sort edges of a graph
	i = j = k = 0;
	arr1 = (node *)malloc(sizeof(node)*(mid-low+1));
	arr2 = (node *)malloc(sizeof(node)*(high-mid));
	while(i++ < mid-low+1) arr1[i-1] = arr[low+i-1]; 
	while(j++ < high - mid) arr2[j-1] = arr[mid+j]; 
	i = j = 0;
	while(i < mid-low+1 && j < high - mid)
		if(arr1[i].weight < arr2[j].weight) arr[low + k] = arr1[i],i++,k++;
		else arr[low + k] = arr2[j],j++,k++;
	if(i == mid-low+1) 
		while(j != high - mid) arr[low + k] = arr2[j] ,j++ ,k++;
	else 
		while(i != mid-low+1) arr[low + k] = arr1[i] ,i++ ,k++;
	free(arr1);
	free(arr2);
}

void mergeSort(node *arr,int low,int high){
	if(low == high) return;
	int mid = (low + high )/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

graph * createGraph(int n,int e){
    graph * temp = (graph *)malloc(sizeof(graph));
    temp -> vertices = n; 
    temp -> edgeCount = e; //vertices start from 0 to n-1
    temp -> edges = (node *)malloc(sizeof(node )*e);
    return temp;
}

void insertEdge(graph * G,int v1,int v2,int weight,int i){
    G -> edges[i].v1 = v1;
    G -> edges[i].v2 = v2;
    G -> edges[i].weight = weight;
    G -> edges[i].id = i;
}

setNode * rootNode(setNode * set){
    setNode * temp2,* temp = set->parent;
    temp2 = set;//to find parent(root) of a disjoint set
    while(temp != set){
        set = temp;
        temp = set->parent;
    }
    while(temp2 != temp){
        set = temp2 -> parent;
        temp2 -> parent = temp;
        temp2 -> size = 1;
        temp2 = set;

    }
    return temp;
}

void mergeSet(setNode * set,int v1,int v2){
    setNode * temp1,* temp2;
    temp1 = rootNode(set + v1);
    temp2 = rootNode(set + v2); //to merge two disjoint sets to form one 
    if(temp1 -> size < temp2 -> size){
        temp1 -> parent = temp2 -> parent;
        temp2 -> size = temp1-> size + temp2 -> size;
    }
    else{
        temp2 -> parent = temp1 -> parent;
        temp1 -> size = temp1-> size + temp2 -> size;
    }
}

void createSet(setNode * set,int i){
    set[i].parent = set+i;
    set[i].size = 1;
}

void printTree(graph * G){
    int i;
    for(i = 0;i < G->edgeCount;i++){
        printf("%d %d %d\n",G -> edges[i].v1,G -> edges[i].v2,G -> edges[i].weight);
    }   
}

int main(){
    int i,j,vertices,edges,temp,v1,v2;
    scanf("%d %d",&vertices,&edges);
    graph * G = createGraph(vertices,edges);
    for(v1 = 0; v1 < edges; v1++){
        scanf("%d %d %d",&i,&j,&temp);
        insertEdge(G,i,j,temp,i);
    } 
    mergeSort(G -> edges,0,edges-1);
    setNode * set = (setNode *)malloc(sizeof(setNode)*vertices);
    for(i = 0; i < vertices;i++){
        createSet(set,i);
    }
    graph * MST = createGraph(vertices,vertices-1);
    j = 0;
    for(i = 0; i < edges && j < vertices-1; i++){
        v1 = (rootNode(set+G->edges[i].v1))->vertex;
        v2 = (rootNode(set +G->edges[i].v2))->vertex;
        if(v1 == v2) continue;
        mergeSet(set,v1,v2);
        MST -> edges[j] = G->edges[i];
        j++;
    }
    printTree(MST);
    return 0;
}