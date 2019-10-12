#include<iostream>
#include<conio.h>
using namespace std;
int binarysearch(int *a,int l,int r,int x)
{
    int mid=(l+r)/2;
    if(x<a[mid])
        return binarysearch(a,l,mid-1,x);
    if(x>a[mid])
        return binarysearch(a,mid+1,r,x);
    if(x==a[mid])
        return mid;
    return -1;
}
int main()
{
    int ans,n,x;
    cout<<"Enter the size of the array";
    cin>>n;
    cout<<"Enter the values in the array";
    int t,a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element you want to find"<<endl;
    cin>>x;
    ans=binarysearch(a,0,n-1,x);
    if(ans==-1)
        cout<<"Element not found"<<endl;
    else
        cout<<"Element found at "<<ans<<"position;
    return 0;
}
