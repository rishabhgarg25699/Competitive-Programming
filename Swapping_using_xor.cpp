//Swapping using bitwise XOR
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int num1,num2;
    //Taking input
    cout<<"Enter two numbers: ";
     cin>>num1>>num2;
                       //  num1            num2
    num1=num1^num2;    //  num1 xor num2   num2
    num2=num1^num2;    //  num1 xor num2   num1
    num1=num1^num2;    //  num2            num1
    cout<<"The swapped numbers are: "<<num1<<" "<<num2;
}
