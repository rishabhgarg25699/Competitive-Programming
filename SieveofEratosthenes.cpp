#include<iostream>
#include<vector>
using namespace std;
int main()
{

        int i,j,n,count=0;
        vector<bool> prime;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            prime.push_back(true);
        }
        
        if(n<=2)
        {
            return 0;
        }
        
        for(i=2;i<sqrt(n);i++)
        {
            for(j=2;i*j<n;j++)
            {
                prime[i*j]=false;
            }
        }
        
        for(i=2;i<n;i++)
        {
           if(prime[i]==true)
           {
               count++;
               cout<<i<<" "<<"is prime"<<endl;
           }
        }
        
    return 0;
}
