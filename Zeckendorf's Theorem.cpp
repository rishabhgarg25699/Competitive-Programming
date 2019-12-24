#include <stdio.h>
#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
    return n;
    int a = 0, b = 1, c = 1;
    while (c <= n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}
void disp(int n)
{
    while (n > 0)
    {
        int f = fib(n);
        printf("%d ", f);
        n = n - f;
    }
}
int main()
{
    	int n;
	cout<<"Enter a number: ";
	cin>>n;
	printf("The representation for %d is \n", n);
	disp(n);
	return 0;
}
