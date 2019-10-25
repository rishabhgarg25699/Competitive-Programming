#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, k;
    long long int N = 1000000007;
    cin>>n>>k;
    
    map <long long int,long long int> m;
    while(n--)
    {
        //cout<<n;
        long long int temp;
        cin>>temp;
        m[temp]++;
    } 
    if(k>m.size()) k = m.size(); 
    long long int arr[k][m.size()];
    auto it = m.begin();
    long long int sum = 0;
    for(long long int num = 0; num < m.size() && it != m.end(); num++)
    {
        arr[0][num] = it->second;
        sum = (sum % N+ arr[0][num] % N) % N;
        it++;
    }
    //cout<<sum<<endl;
    long long int sumlen = sum;
    long long int tsum = 0;
    for(long long int len = 1; len < k; len++)
    {
        if(len != 1) {sumlen = tsum; tsum = 0;}
        for(long long int num = 0; num < m.size(); num++ )
        {
            
            sumlen = (sumlen - arr[len-1][num]);
            while(sumlen < 0) sumlen += N;
            arr[len][num] = sumlen*arr[0][num] % N;
            //if(arr[len][num] < 0) break;
            tsum = (tsum% N + arr[len][num]% N) % N;
            sum = (sum% N + arr[len][num]% N) % N;
            //cout<<sumlen<<" "<<len<<endl;

        }
        //cout<<"t"<<tsum<<endl;
        
    }
    cout<<(sum+1) % N;
    return 0;
}
