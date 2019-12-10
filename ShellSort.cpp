/*Shell Sort*/

#include <iostream>

using namespace std;

//Uses insertion sort not for consecutive elements
//but for far off elements are separated by 'gaps'
//gaps taken here are n/2,n/4,...1

void ShellSort( int *a , int n )
{
	int gap = n/2;                                         // creating gaps: n/2,n/4,n/8,....1

	while ( gap > 0 )
	{
		for ( int i = gap ; i < n ; i++ )              
		{
			int key = a[i];
			int j = i;
		
			while ( j > 0 && a[j-gap]>key )       //finding elements before a[i] at invertal gap
			{
				a[j] = a[j-gap];              //which are greater than key and using insertion sort,
				j = j - gap;                  //the gap-spaced elements are sorted
			}                                      
			a[j] = key;
		}
		gap = gap/2;                                  //decrementing gap
	}
}

int main()                                                    //program to test above function
{
	int a[] = {20,-1,78,3,5,9,6};
	
	int n = sizeof(a)/sizeof(int);

	ShellSort(a,n);

	for ( int i = 0 ; i < n ; i++ )
		cout<<a[i]<<"\t";

	return 0;
}
