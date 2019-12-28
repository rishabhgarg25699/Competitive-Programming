//MAXIMUM SUM OF SUBARRAY(CONTIGUOUS SUBSEQUENCE) KADANE'S ALGO

#include <bits/stdc++.h>

using namespace std;

int kadmax(int arr[], int size)
{    
    int finalMax = INT_MIN, currentMax = 0; //INT_MIN = MOST NEGATIVE INTEGER
    for(int i = 0; i < size; i++)
    {
        currentMax = currentMax + arr[i];
        if(finalMax < currentMax)
            finalMax = currentMax;
        if(currentMax < 0)
            currentMax = 0;
    }
    return finalMax;
}

int main()
{
    int len, ans;
    cout << "Enter length of Array : ";
    cin >> len;
    int ar[len];
    cout<<"Enter elements of Array\n";
    for(int i = 0; i < len; i++)
        cin >> ar[i];
    ans = kadmax(ar, len);
    cout<<ans<<endl;
}