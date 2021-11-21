#include <iostream>
using namespace std;
int g=21,garr[20];
void subarray(int *arr, int n, int x, int ans[], int m)
{
 if(x==0 && n>=-1)
  {
    if(m<=g)
     {
	  g = m;
      for(int j=0;j<g;j++)
	    garr[j] = ans[j];
     }
    return;
  }
 if(n<0)
  return;   
 subarray(arr,n-1,x,ans,m);
 ans[m] = arr[n];
 subarray(arr,n-1,x-arr[n],ans,m+1);
 return;
}
int main()
{
 int n,x,i,j=0,arr[20],ans[20],m=0,narr[20];
 cin>>n>>x;
 for(i=n-1;i>=0;i--)
  {
   cin>>arr[i];
   narr[n-1-i] = arr[i];
  }
 subarray(arr,n-1,x,ans,m);
 if(g==21)
  cout<<"-1";
 else
  {
   for(i=0;i<n;i++)
     {
	  if(narr[i]==garr[j])
	    {
		 if(j==0)	
	      cout<<i+1<<" ";
	     else
           cout<<i+1<<" ";
	     j++;	
        }
      if(j>=g)
        break;
     }
  }  
 return 0;	
}
