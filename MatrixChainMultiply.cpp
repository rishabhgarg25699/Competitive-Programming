//Dynamic Programming
//Matrix chain multiply problem
#include<bits/stdc++.h>
using namespace std;

//For printing the Sequence with parenthesis
void prt(int *arr,int i,int j,int n)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else if(j==i+1)
    {
        cout<<"A"<<i<<".A"<<j;
    }
    else
    {
        int k=arr[i*n+j];
        cout<<"(";
        prt(arr,i,k-1,n);
        cout<<")(";
        prt(arr,k,j,n);
        cout<<")";
    }
}

//Function to find the positions of the brackets
void matrix_chain_multiply(int n,int p[])
{
    int arr1[n][n],arr2[n][n];
    int q;
    for(int i=0;i<n;++i)
    {
        arr1[i][i]=0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;++i)
        {
            int j=i+l-1;
            for(int k=i+1;k<=j;++k)//k is the break point where parenthesis will be positioned
            {
                q=arr1[i][k-1]+arr1[k][j]+p[i]*p[k]*p[j+1];
                if(k==i+1)
                {
                    arr1[i][j]=q;
                    arr2[i][j]=k;
                }
                else if(arr1[i][j]>q)
                {
                    arr1[i][j]=q;
                    arr2[i][j]=k;
                }
            }
        }
    }
    //Outputting the results
    cout<<"Minimum number of scalar multiplications: "<<arr1[0][n-1]<<endl;
    prt((int *)arr2,0,n-1,n);
}

//Driver code
int main()
{
    int n;
    cout<<"Enter number of matrices: ";
    cin>>n;
    cout<<"Enter the number of rows of the matrices followed by the number of columns of the last matrix:";
    int arr1[n][n];
    int arr2[n][n];
    int p[n+1];
    for(int i=0;i<=n;++i)//Taking input the orders of the matrices
    {
        cin>>p[i];
    }
    matrix_chain_multiply(n,p);
    return 0;
}

