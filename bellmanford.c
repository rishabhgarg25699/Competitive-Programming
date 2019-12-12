#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge{
	int src,dst,weight;
};

struct Graph{
	int v,e;
	struct Edge *edge;
};

struct Graph *creategraph(int v1,int e1){
	struct Graph *graph;
	graph=(struct Graph *)malloc(v1*sizeof(struct Graph));
	graph->v=v1;
	graph->e=e1;
	graph->edge=(struct Edge *)malloc(e1*sizeof(struct Edge));
	return graph;
}

void addedge(struct Graph *graph,int i,int src,int dst,int weight){
	graph->edge[i].src=src;
	graph->edge[i].dst=dst;
	graph->edge[i].weight=weight;
}

void print(struct Graph *graph){
	printf("Vertices:%d\n",graph->v);
	printf("Edges:%d\n",graph->e);
	for(int i=0;i<graph->e;i++){
		printf("%d %d %2d\n",graph->edge[i].src,graph->edge[i].dst,graph->edge[i].weight);
	}
}

void pathprinting(int parent[],int a){
	if(a<0) return;
	pathprinting(parent,parent[a]);
	printf(" %d ",a);
}

void bellman(struct Graph *graph,int src){
	int v=graph->v;
	int i,j,dist[v],a,b,weight;
	int parent[v];
	for(i=0;i<v;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	dist[src]=0;
	for(i=1;i<=v-1;i++){
		for(j=0;j<graph->e;j++){
			a=graph->edge[j].src;
			b=graph->edge[j].dst;
			weight=graph->edge[j].weight;
			if(dist[a]!=INT_MAX && dist[a]+weight<dist[b]){
				dist[b]=dist[a]+weight;
				parent[b]=a;
			}
		}
	}
	for(j=0;j<graph->e;j++){
		a=graph->edge[j].src;
		b=graph->edge[j].dst;
		weight=graph->edge[j].weight;
		if(dist[a]!=INT_MAX && dist[a]+weight<dist[b]){
			printf("Graph has negative weight cycle\n");
			return;
		}
	}
	for(i=0;i<v;i++){
		printf("Distance of vertex %d from %d is %d. Its path is [",i,src,dist[i]);
		pathprinting(parent,i);
		printf("]");
		printf("\n");
	}
}

int main()
{
	int v,e;
	printf("Enter v: ");
	scanf(" %d",&v);
	printf("Enter e: ");
	scanf(" %d",&e);
	struct Graph *graph=creategraph(v,e);
	int i,src,dst,weight,source;
	for(i=0;i<e;i++){
		printf("Enter source,dest,weight: ");
		scanf("%d %d %d",&src,&dst,&weight);
		addedge(graph,i,src,dst,weight);
	}
	printf("Enter source vertex: ");
	scanf(" %d",&source);
	bellman(graph,source);
	return 0;
}