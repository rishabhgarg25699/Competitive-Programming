#include<iostream>

using namespace std;

void updateTree(int* bit, int val ,int idx,int size){
    for(;idx<=size;idx  = idx + (idx&(-idx)))
        bit[idx]= bit[idx]+val;
}
int queryTree(int* bit,int i){
    int sum=0;
    for(;i>0;i-=i&(-i)){
        sum+=bit[i];
        cout<<"Sum is "<<sum<<endl;
    }

return sum;
}

int main()
{

    int n;
    cin>>n;
    int* arr = new int[n+1];
    int* bit = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        updateTree(bit,arr[i],i,n);
        cout<<bit[i]<<endl;
    }
    cout<<queryTree(bit,6)<<endl;
    return 0;
}