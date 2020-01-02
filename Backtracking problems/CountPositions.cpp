//You are given a 10*10 chess board and a current position of knight(i, j).
//You have to find maximum number of blocks where knight can be in exactly N moves.
//1<=i,j<=10.

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false)
#define fast_input cin.tie(NULL)
#define fast_output cout.tie(NULL)
 
int v[10][10] = {0};
 
void solve(int x , int y , int v[10][10] , int curr , int n)
{
    if(x<0 || y<0 || x>=10 || y>=10 || curr > n)
      return ;
    if(curr == n)
      v[x][y] = 1;
    solve(x+2,y+1,v , curr+1 , n);
    solve(x+1,y+2,v , curr+1 , n);
    solve(x-2,y+1,v , curr+1 , n);
    solve(x-1,y+2,v , curr+1 , n);
    solve(x+2,y-1,v , curr+1 , n);
    solve(x+1,y-2,v , curr+1 , n);
    solve(x-2,y-1,v , curr+1 , n);
    solve(x-1,y-2,v , curr+1 , n);
}
int main()
{
  fast;
  fast_input;
  fast_output;
  int i,j,n;
  cin>>i>>j>>n;
  solve(i-1, j-1, v , 0 , n);
  int count = 0;
  for(int i=0; i<10 ; i++){
    for(int j=0; j<10 ; j++){
      if(v[i][j] == 1)
        count++;
    }
  }
  cout<<count<<"\n";
  for(int i =0 ; i<10 ; i++){
    for(int j=0 ; j<10 ; j++){
      v[i][j] = 0;
    }
  }
  return 0;
}