#include<stdio.h>
#include<string.h>

int main(){
	int n,r;
	char a[40],b[20];
	printf("Input main string\n");
	scanf("%s",a);
	printf("Input string to find...\n");
	scanf("%s",b);
	r=strlen(b);           //for further use in checking z
	strcat(b,"$");			//adding special character and main string
	strcat(b,a);
	n=strlen(b);
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
	printf("The string is at index : ");
	count=0;
	for(i=0;i<n;i++){		//checking for index it occurs
		
		if(z[i]==r){
		printf("%d ",i-r-1);
		count++;
		}
	}
	if(count==0) printf("No index found");
	return 0;
}
