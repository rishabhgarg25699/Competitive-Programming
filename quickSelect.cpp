//Kth smallest element
//Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli partition(lli arr[],lli l.lli r){
	lli temp = arr[r],i=l;
	for(int j=l;j<r;j++){
		if(arr[j]<=temp){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[i],arr[r]);
	return i;	
}

lli randomPartition(lli arr[],lli l,lli r){
	lli n = r-l+1;
	lli pivot = rand()%n;
	swap(arr[l+pivot],arr[r]);
	return partition(arr,l,r);
}

lli ksmallest(lli arr[],lli l,lli r,lli k){
	lli index = randomPartition(arr,l,r);
	
	if(index-l == k-1)
		return arr[index];
	else if(index-l > k-1)
		return ksmallest(arr,l,index-1,k);
	else
		return ksmallest(arr,index+1,r,k-index-1+l);	
}

int main(){
	int t;
	cin >> t;
	while(t--){
	    lli n,k;
        cin >> n;
        lli arr[n];
        for(lli i=0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        lli ans = ksmallest(arr,0,n-1,k);
        cout << ans << endl;	
	return 0;
}
