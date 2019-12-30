//MAXIMUM SUM OF SUBARRAY(CONTIGUOUS SUBSEQUENCE) KADANE'S ALGO

#include <stdio.h>
#include <limits.h> //CONTAINS INT_MIN

int kadmax(int arr[], int size)
{    
    int finalMax = INT_MIN , currentMax = 0; //INT_MIN = MOST NEGATIVE INTEGER
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
    printf("Enter length of Array : ");
    scanf("%d", &len);
    int ar[len];
    printf("Enter elements of Array\n");
    for(int i = 0; i < len; i++)
        scanf("%d", &ar[i]);
    ans = kadmax(ar, len);
    printf("%d\n", ans);
}
