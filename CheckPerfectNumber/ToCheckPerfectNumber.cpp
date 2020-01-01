//Issue #215

#include<iostream>
#include<cmath>

using namespace std ;

bool checkPerfectNumber(int N)
{   
    int sum = 0 ; //sum of divisor
    if(N <= 0)
    {
        return 0 ;
    }

    for(int i=1; i<sqrt(N); i++)
    {
        if(N%i==0)
        {
            sum += i+(N/i) ;
        }
    }
    return sum/2==N ; //if N is perfect Number, this Fanction return 1 .
}

//test main

int main(void){
    int N=0;
    cin >> N ;
    if(checkPerfectNumber(N)){
        cout << N << " is Perfect Number" << endl ;
    }
    else
    {
        cout << N << " is NOT Perfect Number" << endl ; 
    }
    return 0 ;
}