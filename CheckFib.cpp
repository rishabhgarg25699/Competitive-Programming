//To check if a number is a Fibonacci Number

#include <iostream>
#include <math.h>

using namespace std;

int checksq ( int n )          //checks if a number is a perfect square
{
	int k = sqrt(n);

	if ( n == k*k )
		return 1;
	else
		return 0;
}

int checkFib ( int n )
{
	if ( checksq ( 5*n*n + 4 ) || checksq ( 5*n*n - 4 ) )     //a number n is a Fibonacci number if
		return 1;                                             //5n^2 + 4 or 5n^2 - 4 is a perfect square
	else
		return  0;
}

int main()
{
	int x;
	cin>>x;

	if ( checkFib(x) )
		cout<<"True";
	else
		cout<<"False";

	return 0;
}
	

