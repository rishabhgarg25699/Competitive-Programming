#include<bits/stdc++.h>
using namespace std;

bool canPlace(int a[][20],int n,int x,int y,int num)
{   
    for(int i=0;i<n;i++)
    {
        if(a[i][y]==num)				//Checking if any row or column 
            return false;				//already has the number num
        if(a[x][i]==num)
            return false;
    }

    int block=sqrt(n);
    int rowBeg=(x/block)*block;
    int colBeg=(y/block)*block;
    for(int i=rowBeg;i<rowBeg+block;i++)		//Checking if smaller grids
        for(int j=colBeg;j<colBeg+block;j++)       	//already contains a number 
            if(a[i][j]==num)
                return false;

    return true;
}
bool sudoku(int a[][20],int n,int x,int y)
{
    if(x==n)
    {
	cout<<endl;
        for(int i=0;i<n;i++)
        {						//Printing The final answer
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;

        return false;					//Base case 
    }

    if(y==n)
        return sudoku(a,n,x+1,0);
        
    if(a[x][y]!=0)					//Checking for availability of a cell
        return sudoku(a,n,x,y+1);

    for(int i=1;i<=n;i++)				//Checking for all possibilities
    {
        if(canPlace(a,n,x,y,i))			
        {
            a[x][y]=i;
            bool canSolve = sudoku(a,n,x,y+1);		//Recursively solving the Sudoku
            if(canSolve)
                return true;
            a[x][y]=0;					//Backtracking
        }
    }
    return false;				
}

int main()
{
    int n;
    cin>>n;
    int a[20][20],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    bool res=sudoku(a,n,0,0);				//No output implies Sudoku cannot be solved

}

/*

Sample Input:

9 
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Sample Output:

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 

*/

