#include<iostream>

using namespace std; 

void buildTree(int* tree,int*arr,int treeNode,int start,int end){

    if(start==end){
        tree[treeNode]= arr[start];
        return ;    
        }
        int mid = (start+end)/2;
        buildTree(tree,arr,2*treeNode,start,mid);
        buildTree(tree,arr,2*treeNode+1,mid+1,end);

        tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
    return;
}
int queryTree(int* tree, int treeNode,int start,int end,int stq,int endq){

    if(stq>end||endq<start)
        return 0;
    
    if(start>=stq&&end<=endq)
        return tree[treeNode];

    int mid = (start+end)/2;
   // cout<<mid<<endl;

    int sum1 = queryTree(tree,2*treeNode,start,mid,stq,endq);
    int sum2 = queryTree(tree,2*treeNode+1,mid+1,end,stq,endq);
    return sum1+sum2;
}
int updateTree(int* tree,int*arr , int treeNode,int start,int end,int idx,int val){
    if(start==end){
        arr[idx]=val;
        tree[treeNode]= val;
        return 0;
        }
    int mid = (start+end)/2;
    if(idx>mid)
        updateTree(tree,arr,2*treeNode+1,mid+1,end,idx,val);
    else
        updateTree(tree,arr,2*treeNode,start,mid,idx,val);

    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
    return 0;
}
int main(){

    int n;
    cin>>n;
    int* arr = new int[n];
    int* seg = new int[3*n];
    for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    buildTree(seg,arr,1,0, n-1);
    updateTree(seg,arr,1,0,n-1,2,10);
    // for(int i =1;i<=2*n;i++)
    //     //cout<<seg[i]<<endl;

    cout<<queryTree(seg,1,0,n-1,2,4)<<endl;
    return 0;
}