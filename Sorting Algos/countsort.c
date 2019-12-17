#include<stdio.h>
#include<string.h>
#define n 200

void count_sort(int ch[],int num){
	int arr[n];
	int temp,i=0;
	for(i=0;i<n;i++){
		arr[i]=0;
	}	
	
	for(i=0;i<num;i++){
		temp=ch[i];
		arr[temp]++;
	}	
	
	for(i=1;i<n;i++){
		arr[i]+=arr[i-1];
	}	
	for(i=n-1;i>=0;i--){
		arr[i]=arr[i-1];
	}
	
	int outputarr[num];
	for(i=0;i<num;i++ ){
		temp=ch[i];
		outputarr[arr[temp]]=temp;
		arr[temp]++;
	}
	for(i=0;i<num;i++){
		ch[i]=outputarr[i];	
	}
	
}

int main(){
	int k,i=0;
	scanf("%d",&k);
	int *a=(int *) malloc(k*sizeof(int));
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	count_sort(a,k);
	for(i=0;i<k;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
