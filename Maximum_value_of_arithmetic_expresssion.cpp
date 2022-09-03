/* --> Calculating the maximum value of the given expression by placing parentheses .	
   --> Expression can contain +,- or * operators.	
  */	

#include<bits/stdc++.h>	
using namespace std;	
long long calculate(long long sha, long long roop, char xyz) 	
{	
    if (xyz == '*')	
        return sha * roop;   //return after multiplying	
    else if (xyz == '+')	
        return sha + roop;   //return after adding	
    else if (xyz == '-')	
        return sha - roop;   //return after subtracting	
    else	
        assert(0);	
}	
int main()	
{	
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);	
    cout.tie(NULL);	
    char a[50];	
    cin>>a;	
    long long l,n,i,s,j,k,minvalue,maxvalue,p,b,c,d;	
    l=strlen(a);	
    n=(l+1)/2;	
    //cout<<n<<endl;	
    for(i=l;i>=1;i--)	
    {	
        a[i]=a[i-1];	
    }	
    a[0]='0';	
    long long mina[n+1][n+1];    //creating matrix to store minimum value	
    long long maxa[n+1][n+1];    //creating matrix to store maximum value	
    memset(mina,0,sizeof(mina));	
    memset(maxa,0,sizeof(maxa));	
    for(i=1;i<=n;i++)	
    {	
        mina[i][i]=a[2*i-1]-'0';	
        maxa[i][i]=a[2*i-1]-'0';	
    }	
    for(s=1;s<=n-1;s++)	
    {	
        for(i=1;i<=n-s;i++)	
        {	
            j=i+s;	
            minvalue=LLONG_MAX;	
            maxvalue=LLONG_MIN;	
            for(k=i;k<=j-1;k++)                	
            {	
                //checking for all the four cases and calculating minimum and maximum value	
                p=calculate(maxa[i][k],maxa[k+1][j],a[2*k]);	
                b=calculate(maxa[i][k],mina[k+1][j],a[2*k]);	
                c=calculate(mina[i][k],maxa[k+1][j],a[2*k]);	
                d=calculate(mina[i][k],mina[k+1][j],a[2*k]);	
                minvalue=min(minvalue,min(p,min(b,min(c,d))));	
                maxvalue=max(maxvalue,max(p,max(b,max(c,d))));	
            }	
            mina[i][j]=minvalue;	
            maxa[i][j]=maxvalue;	
        }	
    }	
    /*for(i=1;i<=n;i++)	
    {	
        for(j=1;j<=n;j++)	
        {	
            cout<<mina[i][j]<<" ";	
        }	
        cout<<endl;	
    }	
    cout<<endl;	
    for(i=1;i<=n;i++)	
    {	
        for(j=1;j<=n;j++)	
        {	
            cout<<maxa[i][j]<<" ";	
        }	
        cout<<endl;	
    }	
    cout<<endl;*/	
    cout<<maxa[1][n]<<endl;	
}	

/* INPUT:	
   5-8+7*4-8+9	
   	
   OUTPUT:	
   200	
   	
   EXPLAINATION:	
   200 = (5 − ((8 + 7) × (4 − (8 + 9))))	
   */
