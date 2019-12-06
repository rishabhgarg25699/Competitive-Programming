//INSERTION SORT
#include <iostream>
using namespace std;
void insert(int a[],int n)
{/*WE insert elemnts in already sorted part of array starting from i=1 */
	        int i,key,j;
                for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>0 && a[j]>key)/*j needs to be greater than zero and if we  are sorting in                                      ascending order than a[j]>key*/
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void print(int a[],int n)/*to print the array*/
{        int i;
        cout<<"the elements in ascending order"<<endl;
	for(i=0;i<n;i++)

	cout<<a[i]<<endl;
}
int  main()
{
	int n,i;
        int a[100];
	cout<<"enter the number of elements"<<endl;
	cin>>n;//accepting n
	for(i=0;i<n;i++)
	{
		cout<<"enter the number"<<endl;//accepting the number
		cin>>a[i];
	}
	insert(a,n);
	print(a,n);
        return 0;
}

