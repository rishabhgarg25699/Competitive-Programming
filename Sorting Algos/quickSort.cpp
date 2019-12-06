#include <iostream>
using namespace std;
int partitionIndex(int *a,int low,int high)
{
    int pivot=a[high]/*element jisse humko correct position par le jana hai*/;
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int *a,int low,int high)
{
    if(low<high)
    {
        ///let pivot = last element of array
        int pi=partitionIndex(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main()
{
    int n;
    cout<<"Enter no of elements you want to sort\n";
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nBefore Sorting :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    quickSort(a,0,n-1);
    cout<<"\nAfter Sorting :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
