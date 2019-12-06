#include<iostream>
#include<conio.h>
using namespace std;
int linearsearch(int *a,int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            return i;
    }
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
    ans=linearsearch(a,n,x);
    if(ans==-1)
        cout<<"Element not found"<<endl;
    else
        cout<<"Element found at "<<ans<<"position;
    return 0;
}
