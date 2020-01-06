#include<bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

//Program to find the nth fibonnaci number

int main() {
	ull n;
	cin>>n;
	ull t1,t2;
	t1 = 1;
	t2 = 1;
	if(n==1 || n==2) {
		cout<<1<<endl; 
		return 0;
	}
	n -= 2;
	while(n != 0) {
		t2 += t1;
		t1 = t2 - t1;
		n--;
	}
	cout<<t2<<endl;
	return 0;
}