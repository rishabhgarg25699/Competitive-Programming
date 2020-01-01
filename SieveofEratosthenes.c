//SIEVE OF ERATOSTHENES (FIND ALL PRIME NUMBERS LESS THAN A GIVEN NUMBER)

#include <stdio.h>
#include <math.h> //Contains sqrt() function

void sieve(int n, int primes[])
{
    for (int i = 0; i < n; i++)
        primes[i] = 1; //Initialize the Array 1 (True)
    
    //INITIALSE FIRST AND SECOND ELEMENT REPRESENTING 0 AND 1 AS 0(BOTH ARE NOT PRIME)
    primes[0] = 0;
    primes[1] = 0;
    
    for (int i = 2; i*i < n; i++) 
        for (int j = i*i; j < n ;j += i)
            primes[j] = 0; //FALSE (IF NOT PRIME)
}


void main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int arr[num];
    
    sieve(num, arr);
    
    for (int i = 0; i < num; i++)
        if (arr[i] == 1)
            printf("%d is prime\n", i);
}

