//contiguous subarray with sum equal to S

#include<bits/stdc++.h>
using namespace std;
int  main()
{
	int n,sum;
	cin>>n;
	int *arr;
	arr=new int [n];
	int i;
	for(i=0;i<n;i++)//inputting the array elements
	cin>>arr[i];
	cin>>sum;//inputting the sum
	int s=0,start=0;
	for(i=0;i<n;i++)
	{
		s+=arr[i];//keep summing until it is more than sum
		for(;s>sum && start<i;)
			s-=arr[start++];//subtracting the elements from the starting until it exceed sum
		if(s==sum)
		{
			cout<<start<<" TO "<<i;//printing the starting and the end index
			break;
		}
	}

}
/*in the worst case the same element can either be removed or added from sum ,so maximum operations is 2*n so O(n) complexity*/ 

