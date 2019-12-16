//finding the count inverstion of an array using merge sort
#include <iostream>
using namespace std;
int n,temp[100];
int  merge_sort(int arr[],int left ,int right);
int merge(int arr[],int left,int mid,int right);
int main()
{
	int  *arr,n,i;
        cout<<"enter the number of elements in the array"<<endl;
	cin>>n;
	arr=new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter the element"<<endl;
		cin>>arr[i];
	}

	 int ic=merge_sort(arr,0,n-1);
	cout<<ic;
}
//this function keeps partitioning the array and sorts them as well 
int  merge_sort(int arr[],int left ,int right)
{
	int c=0;
	if(right>left)//we continue dividing till right is more than the left index
	{
		 int mid=(right+left)/2;
		c+=merge_sort(arr,left,mid);//the inversion count is the sum of inversions in left 
		c+=merge_sort(arr,mid+1,right);//half,right half and merged array
		c+=merge(arr,left,mid,right);
	}
	return c;
}
//this function merges the two parts and returns the inversion count
int merge(int arr[],int left,int mid,int right)
{
	int c=0;
	int i=left,j=mid+1,k=left;
	while(i<=mid && j<=right)
	{
		if(arr[i]<=arr[j])
		        temp[k++]=arr[i++];
		else
		{
			temp[k++]=arr[j++];
			c+=mid-i+1;
		}
	}
	while(i<=mid)
	temp[k++]=arr[i++];
	while(j<=right)
	temp[k++]=arr[j++];
	return c;
}


