#include<stdio.h>

int factorial(int n)
{
    if(n>=1)  return n*factorial(n-1);
	else return 1;
}

int main()
{
    int n;int ar[100];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&ar[i-1]);
	    
	}
	for(int i=1;i<=n;i++)
	 {
	 	 printf("%d \n",factorial(ar[i-1]));
	 }		
		return 0;
}

