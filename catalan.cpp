#include<bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

//Program to find the nth catalan number

ull catalan(ull n) {
	ull c = 1;
	for (int i = 0; i < n; ++i) {
		c *= (2*n-i);
		c /= (i+1);
	}
	c /= (n+1);
	return c;
}

int main() {
	ull n;
	cin>>n;
	cout<<catalan(n)<<endl;

	return 0;
}