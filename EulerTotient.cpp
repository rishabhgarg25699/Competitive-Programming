#include <iostream>
using namespace std; 

// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

//Euler Totient Function
int phi(unsigned int n) 
{ 
	unsigned int result = 1; 
	for (int i = 2; i < n; i++) 
		if (gcd(i, n) == 1) 
			result++; 
	return result; 
} 

int main() 
{ 
	int n; 
    cin >> n;
	cout << "phi("<<n<<") = " << phi(n) << endl; 
	return 0; 
} 

