#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll polyhash(string S,ll p,ll x)              //Using Polynomial Hash
{
    ll hash=0;
    for(ll i=S.length()-1;i>=0;i--)
    {
        hash=(((hash*x))+(S[i]))%p;
    }
    return hash;
}
vector <ll> precomputehashes(string T,ll pl,ll p,ll x)              
{
    vector<ll> H;
    for(ll i=0;i<(T.length()-pl+1);i++)
    {
        H.push_back(0);
    }
    string S;
    S=T.substr(T.length()-pl,pl);
    H[T.length()-pl]=polyhash(S,p,x);
    ll y=1;
    for(ll i=1;i<=pl;i++)
    {
        y=((y)*(x))%p;
    }
    for(ll i=T.length()-pl-1;i>=0;i--)
    {
        ll prehash=(((((x)*(H[i+1])))+((T[i])))-(((y)*(T[i+pl]))));
        while(prehash<0)
        {
            prehash+=p;
        }
        H[i]=prehash%p;
    }
    return H;
}
bool areequal(string s1,string s2)               //To check that the two strings entered are equal
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    for(ll i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[i])
        return false;
    }
    return true;
}
vector<ll> RabinKarp(string T,string P)            
{
    ll p=1000000007;
    ll x=rand()%(p-1)+1;
    vector<ll> result;
    ll phash=polyhash(P,p,x);
    vector<ll> H;
    H=precomputehashes(T,P.length(),p,x);
    for(ll i=0;i<=(T.length()-P.length());i++)
    {
        if(phash!=H[i])
        continue;
        if(areequal(T.substr(i,P.length()),P))
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string P,T;                   //Enter Pattern as P and Text as t
    cin>>P>>T;
    vector<ll> result;
    result=RabinKarp(T,P);
    for(ll i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Input: pattern and text
   Output: All occurences of the pattern in the test  
   
   Input: aba 
          abacaba 
          
   Output: 0 4 */
