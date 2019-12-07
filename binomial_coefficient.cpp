#include<bits/stdc++.h>
using namespace std;

const long long int N=1000001;
const long long int mod=1000000007;

long long int factinverse[N+1];
long long int numinverse[N+1];
long long int fact[N+1];

void invert()
{
  numinverse[0]=1;
  numinverse[1]=1;

  long long int i;
  for(i=2;i<=N;i++)
    numinverse[i]=numinverse[mod%i]*(mod-mod/i)%mod;
}

void invertit()
{
  factinverse[0]=1;
  factinverse[1]=1;

  long long int i;
  for(i=2;i<=N;i++)
    factinverse[i]=(numinverse[i]*factinverse[i-1])%mod;
}

void factorial()
{
  fact[0]=1;
  long long int i;

  for(i=1;i<=N;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

long long int cal(long long int n,long long int r)
{
  long long int ans;
  ans=( (fact[n]*factinverse[r])%mod * factinverse[n-r])%mod;
  return ans;
}

int main()
{
  invert();
  invertit();
  factorial();

  long long int n,r;
  cin>>n>>r;

  cout<<cal(n,r)<<endl;

return 0;
}
