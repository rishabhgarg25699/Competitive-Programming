#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void update_add(ll *tree,ll *lazy,int start,int end , int index,int left,int right,int val){
    if(start > end){
        return;
    }
   
    if(lazy[index]!=0){ // for old updation
       tree[index] += lazy[index]*((ll)end-start+1);
       if(start!=end){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
       }
       lazy[index]=0;
       
   }
    if(start > right || end<left){
        return;
    }
    if(start >= left && end<=right){ // for new update
        tree[index] += val*((ll)end-start+1);
        if(start!=end){
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
        }
        return;
    }
    int mid = (start+end)/2;
    update_add(tree,lazy,start,mid,2*index,left,right,val);
    update_add(tree,lazy,mid+1,end,2*index+1,left,right,val);
    tree[index] = tree[2*index]+tree[2*index+1];
    
}
ll query(ll *tree,ll *lazy,int start,int end,int index,int left,int right ){
     
    
    if(lazy[index] != 0 ){ // for old updation
        ll val = lazy[index];
       tree[index]+=val*(end-start+1);
       if(start!=end){
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
       }
       lazy[index]=0;
   }
    if(start > right || end<left){
        return 0;
    }
    
    if(start >= left && end<=right){ // for new update
        return tree[index];
    }
    int mid = (start+end)/2;
   ll ans1 = query(tree,lazy,start,mid,2*index,left,right);
   ll ans2 =  query(tree,lazy,mid+1,end,2*index+1,left,right);
   // tree[index] = tree[2*index]+tree[2*index+1];
    return ans1+ans2;
}
int main(void){
    
        int n,c;
        cin>>n>>c;
        ll *tree = new ll[4*n];
        ll *lazy = new ll[4*n];
        for(int i=0;i<4*n;i++){
            lazy[i] = 0;
            tree[i]  =0;
        }
        while(c--){
            int type;
            cin>>type;
            if(type == 0){ // type 0 for updation
                int p,q,v;
                cin>>p>>q>>v;
                update_add(tree,lazy,0,n-1,1,p-1,q-1,v);
            }
            else{ // type 1 for query
                int p,q;
                cin>>p>>q;
                ll sol = query(tree,lazy,0,n-1,1,p-1,q-1);
                cout<<sol<<endl;
            }
        }
    
}