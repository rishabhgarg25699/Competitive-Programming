#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
  int vertex;
  int weight;
  struct node *next;
};

struct Graph{
	int numVertices;
	struct node **adjlist;
};

struct Graph *creategraph(int v){
  struct Graph *graph;
  graph=(struct Graph *)malloc(v*sizeof(struct Graph)); 
  graph->numVertices=v;
  graph->adjlist=(struct node **)malloc(v*sizeof(struct node *));
  int i;
  for(i=0;i<v;i++){
   graph->adjlist[i]=NULL;
  }
 return graph;
}

struct node *createnode(int dest,int weight){
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->vertex=dest;
  newnode->weight=weight;
  newnode->next=NULL;
 return newnode;
}

void addedge(struct Graph *graph,int src,int dst,int weight){
  struct node *new=createnode(dst,weight);
  new->next = graph->adjlist[src];
  graph->adjlist[src] = new;
}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjlist[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf(" -> %d(%d)", temp->vertex,temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printmatrix(int **a,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%5d%c",(a[i][j]==INT_MAX)?-1111:a[i][j],(j==n-1)?'\n':' ');
    }
  }
}

void printpath(int **p,int u,int v){
  printf("->%d",p[u][v]);
  if(p[u][v]==v) return;
  printpath(p,p[u][v],v);
}

void pathprinting(int **p,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i!=j && p[i][j]!=-1){
        printf("Shortest path from %d to %d:  ",i,j);
        printf("%d",i);
        printpath(p,i,j);
        printf("\n");
      }
    }
  }
}

void shortestpath(int **a,int **p,int n){
  int i,j,k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX && a[i][k]+a[k][j]<a[i][j]){
          a[i][j]=a[i][k]+a[k][j];
          p[i][j]=p[i][k];
        }
      }
    }
  }
  printf("\nThe distance matrix is:\n");
  printmatrix(a,n);
}

int main(){
  int v,e,i,j,src,dst,weight;
  printf("Enter no.of vertices: ");
  scanf(" %d",&v);
  struct Graph *graph=creategraph(v);
  printf("Enter no.of edges: ");
  scanf(" %d",&e);
  for(i=0;i<e;i++){
    printf("Enter source,dest,weight: ");
    scanf(" %d%d%d",&src,&dst,&weight);
    addedge(graph,src,dst,weight);
  }
  int **a,**n;
  a=(int **)malloc(v*sizeof(int *));
  for(i=0;i<v;i++){
    a[i]=(int *)malloc(v*sizeof(int));
  }
  n=(int **)malloc(v*sizeof(int *));
  for(i=0;i<v;i++){
    n[i]=(int *)malloc(v*sizeof(int));
  }
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      if(i==j){
        a[i][j]=0;
      }
      else a[i][j]=INT_MAX;
    }
  }
  for(i=0;i<graph->numVertices;i++){
    struct node *temp=graph->adjlist[i];
    while(temp){
      a[i][temp->vertex]=temp->weight;
      temp=temp->next;
    }
  }
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      if(a[i][j]==INT_MAX || a[i][j]==0){
        n[i][j]=-1;
      }
      else{
        n[i][j]=j;
      }
    }
  }
  shortestpath(a,n,v); 
  printf("\n");
  pathprinting(n,v);
}
