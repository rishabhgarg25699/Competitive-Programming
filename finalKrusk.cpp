#include<fstream>
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
class ConecEdge{
  public:
  int start;
  int end;
  int cost;
};
bool compare(ConecEdge e1,ConecEdge e2){
  return e1.cost<e2.cost;
}
int findbefore(int vert,int *before){
  if(before[vert]==vert)
    return vert;
  return findbefore(before[vert],before);

}
void kruskals(ConecEdge*edge,int E,int V,ofstream &f2){
  sort(edge,edge+E,compare);
  ConecEdge*res=new ConecEdge[V-1];
   int *before=new int[V];
    for(int i=0;i<V;i++){
      before[i]=i;
    }
  int c=0;
  int i=0;
  while(c!=V-1){
  ConecEdge curr=edge[i];
    int startbefore=findbefore(edge[i].start,before);
    int  destbefore=findbefore(edge[i].end,before);
    if(startbefore!=destbefore){
      res[c]=curr;
      c++;
      before[startbefore]=destbefore;
    }
  i++;
  }
  for(int i=0;i<V-1;i++){
 f2<<char(res[i].start+97)<<","<<char(res[i].end+97)<<endl;
 }
}




int main(int argc,char *argv[]){
ConecEdge edge[50];
int i=0;
ifstream f1;
f1.open(argv[1]);
ofstream f2;
f2.open(argv[2]);
string str1="";
string str2="";
f1>>str2;
int vert=str2[0]-48;
f1>>str2;
while(!f1.eof()){
    string str;
    f1>>str;
    edge[i].start=str[0]-97;
    edge[i].end=str[2]-97;
     int i=4;
    int x=str[i]-48;
   i++;
    while(str[i]!='\0'){
        x=x*10+(str[i]-48);
        i++;
    }
    edge[i].cost=x;
    i++;
}
 kruskals(edge,i-1,vert,f2);
}
