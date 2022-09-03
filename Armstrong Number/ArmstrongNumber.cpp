/*A positive integer of n digits is called an Armstrong number of order n  if
abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... */

#include <iostream>
#include <math.h>
using namespace std;

//To calculate number of digits(order)
int order(int n)
{
    int c=0;
    while (n > 0)
    {
        c++;
        n=n/ 10;
    }
    return c;
}

//Function to check if the number is armstrong or not
int armstrong(int n, int p)
{
    int sum = 0,d;
    while (n > 0)
    { 
        d = n % 10;
        sum =sum+pow(d,p);
        n =n/ 10;
    }
    return sum;
}

int main()
{
    int n, d;
    cout<<"Enter the number:";
    cin>>n;
    
    int pow = order(n);

    int sum = armstrong(n, pow);

    if (sum == n)
        cout<<n<< "is an Armstrong number";
    else
        cout<<n<< "is not an Armstrong number";

    return 0; 
}


