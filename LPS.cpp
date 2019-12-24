//To find the longest palindromic substring in linear time

#include <iostream>
#include <string.h>

using namespace std;

void newString ( char s[] , char a[] , int n )       //inserts special characters inbetween the characters of the string
{
	a[0] = '@';                                //special character at the starting
	
	for ( int i = 1 ; i < n-1 ; i++ )
	{
		a[i] = '*';
		i++;
		a[i] = s[(i-1)/2];
	}

	a[n-1] = '#';                            //as well as at the end
	a[n] = '\0';
}

void LPS ( char s[] )
{
	int n = 2*strlen(s) + 3;
	char *newS = (char*) malloc ( (n+1)*sizeof(char) );                        
	int *x = ( int* ) calloc ( n, sizeof(int) );                      //keeps the value of LPS at each element

	newString ( s , newS , n );

	int center = 0, right = 0, max = 0 , pos = 0;

	for ( int i = 1 ; i < n-1 ; i++ )
	{
		int mirror = 2*center - i;

		if ( i < right )                                                       //if the current element lies in the palindromic substring in consideration
			x[i] = ( x[mirror] > (right - i) ) ? (right-i) : x[mirror];        //assigning it LPS based on boundary condition or mirroring property

		while ( newS[ i - 1 - x[i] ] == newS[ i + 1 + x[i] ]    )              //expanding about a palindromic center
			x[i]++;															   //incrementing the value of LPS at the center

		if (  i + x[i] > right )                                               //checking if current substring in consideration lies
		{																	   //in the ealier considered palindromic substring
			center = i;														   //if not, the center is changed along with the boundary
			right = i + x[i];
		}

		if ( x[center] > max )                                                //storing the value of max LPS and position of its center
		{
			max = x[center];
			pos = center;
		}
	}

	for ( int j = (pos-max)/2 ; j < (pos+max)/2 ; j++ )
	{
		cout<<s[j];
	}
}


int main()
{
	char a[20];
	cin>>a;
	LPS(a);
	return 0;

}