#include<iostream>

using namespace std;

int main(){
	int n,r;
	string a,b;
	cout<<"Input main string\n";
	cin>>a;
	cout<<"Input string to find...\n";
	cin>>b;
	r=b.length();         //for further use in checking z
	b=b +"$"+a;		//adding special character and main string
	n=b.length();
	int z[n];
	int i=0,count,k,j;
	z[0]=0;
	for(i=1;i<n;i++){		//making z array
		count=0;
		k=i;
		for(j=0;j<n-1;j++,k++){
			if(b[k]==b[j]){
				count++;
				continue;
			}
			else break;
		}
		z[i]=count;
	}
	cout<<"The string is at index : ";
	count=0;
	for(i=0;i<n;i++){		//checking for index it occurs
		
		if(z[i]==r){
		cout<<i-r-1<<" ";
		count++;
		}
	}
	if(count==0) cout<<"No index found";
	return 0;
}
