#include<bits/stdc++.h>
using namespace std;
void countingSort(int *a,int n,int range)
{
    int *freq=new int[range];
    int *output=new int[n];
    memset(freq,0,sizeof(freq[0])*range);
    /*cout<<"Range of elements entered "<<range<<endl;
    cout<<"\nFrequency Array Initially:\n";
    for(int i=0;i<range;i++){
        cout<<freq[i]<<" ";
    }
    cout<<"\n";*/
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    /*cout<<"\nFrequency Array :\n";
    for(int i=0;i<range;i++){
        cout<<freq[i]<<" ";
    }
    cout<<"\n";*/

    for(int i=1;i<range;i++){
        freq[i]+=freq[i-1];
    }
    /*cout<<"\nUPDATED Frequency Array :\n";
    for(int i=0;i<range;i++){
        cout<<freq[i]<<" ";
    }
    cout<<"\n";*/
    for(int i=n-1;i>=0;i--){
        freq[a[i]]--;
        output[freq[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=output[i];
    }
}
int main()
{
    int n,s,e;
    cout<<"Enter Range you want to Sort StartElement,EndElement\n";
    cin>>s>>e;
    n=abs(e-s+1);
    int *a=new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //cout<<"No of elements entered "<<n<<endl;
    //cout<<"Range of elements entered "<<e<<endl;
    cout<<"\nBefore Sorting :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    countingSort(a,n,e+1);
    cout<<"\nAfter Sorting :\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
