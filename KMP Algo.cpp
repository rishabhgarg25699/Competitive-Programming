#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void LPS(char pat[], int lps[], int b)
{
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < b;)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if(j!=0)
            j = lps[j-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP(char pat[], char txt[], int a, int b)
{
    int lps[b];
    LPS(pat, lps, b);
    int status = 0;
    int tP = 0;
    int pP = 0;
    while(tP < a)
    {
        if(pat[pP]==txt[tP])
        {
            pP++;
            tP++;
        }
        if(pP==b)
        {
            status++;
            printf("Pattern is found at index %d\n", (tP - pP));
            tP++;
            pP = 0;
        }
        else if(pat[pP] != txt[tP])
        {
            status = 0;
            if(pP != 0)
            pP = lps[pP-1];
            else
            tP++;
        }
    }
}

int main() 
{ 
    char txt[100];
    char pat[100];
    cout << "Enter the text: ";
    cin >> txt;
    cout << "Enter the pattern: ";
    cin >> pat;
    int a = strlen(txt);
    int b = strlen(pat);
    KMP(pat, txt, a, b);
    return 0;
}