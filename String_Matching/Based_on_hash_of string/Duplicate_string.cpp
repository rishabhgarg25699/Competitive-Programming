//Given a list of n strings si, each no longer than m characters..
//Finding no. of unique elements..
//Printing all the unique string and their occurences..
//here we are using polynomial rolling hash function..

#include<bits/stdc++.h>
using namespace std;
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
//function for finding unique strings..

//TIME COMPLEXITY O(nm+nlogn)   INSTEAD OF O(nmlogn).
vector<vector<int> >group_identical(vector<string> const& s){
int N=s.size();
vector<pair<long long,int> >hashes(N);
for (int i=0;i<N;i++){
	hashes[i]={h_val(s[i]),i};
}
//after getting hash value of each string, we sort and get required ..
//changing string in integers changes the comparision time to O(1)..
sort(hashes.begin(),hashes.end());
vector<vector<int>> ret;
for (int i=0;i<N;i++){
	if(i==0|| hashes[i].first!=hashes[i-1].first){
		ret.emplace_back();
	}
	ret.back().push_back(hashes[i].second);
}
return ret;
}

int main(){
	//taking string as input..
	vector<string> s;
	string tmp;
	int no;
	cout<<"Enter no. of strings:";
	cin>>no;
	for(int i=0;i<no;i++){
	cout<<"Enter the string :";cin>>tmp;
	s.push_back(tmp);
	}
	//getting hash value as output..
	vector<vector<int> >v;
	v=group_identical(s);
	cout<<"Unique elements :"<<v.size()<<"\n";
	//here we have occurence of each element then we can according to the  requirement.
	for (int i=0;i<v.size();i++){
		cout<<"\nString :"<<s[v[i][0]]<<"     Size :"<<v[i].size();
	}
	return 0;
}