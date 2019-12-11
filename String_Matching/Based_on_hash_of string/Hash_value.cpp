//including libraries..
#include<bits/stdc++.h>
using namespace std;
/*
h_val function take string as input and 
return integer value(hash value) as output.
.Here we are considering lowercase only.
*/
long long h_val(string const& str){
	const int prime=31;   //choosing prime closest to no. of alphabets.(use 53 for both upper and lower case.)
	const int mod=1e9 +9; //can also chooose 2**64 but there has been found some collision independent of prime value.
	long long hash_value=0;
	long long p=1;
	//calculating hash value by initialsing a=>1,b=>2...andd so on..
	// "a" is not initialise to 0 as it will n=make a,aa,aaa same ..
	for(char c: str){
		hash_value=(hash_value+(c-'a'+1)*p)%mod;
		p=(p*prime)%mod;
	}
	return hash_value; // return hash value..
}
int main(){
	//taking string as input..
	string s;
	cout<<"Enter the string :";
	cin>>s;
	//getting hash value as output..
	cout<<"\n Hash value is "<<h_val(s);
	return 0;
}