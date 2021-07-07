# include <iostream>

using namespace std;

int findMajorityElement(int Arr[], int Size)
{
    int Count = 0, majorityElement;
    for(int i = 0 ; i < Size ; i++)
    {
        if(Count == 0)
          majorityElement = Arr[i];
        if(Arr[i] == majorityElement)
          Count++;
        else
          Count--;
    }

    Count = 0;
    for(int i = 0 ; i < Size ; i++)
    {
        if(Arr[i] == majorityElement)
        {
            Count++;
        }
    }

    if(Count > Size / 2)
    {
        return majorityElement;
    }
    return -1;
}

//Driver function
int main(void)
{
    int Arr[] = {1, 1, 3, 3, 3, 1, 1, 1};
    //int Arr[] = {1, 2, 3, 3, 3, 4, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int majorityElement = findMajorityElement(Arr, n);
    if(majorityElement == -1)
      cout << "\nThere is no majority element.";
    else
      cout << "The majority element is : " << majorityElement;
    return 0;
}
//End of program
