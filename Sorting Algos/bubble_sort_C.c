//added by Ayush Krishna 



#include <stdio.h>

// Function for bubble sort
void bubble_sort(int array[], int size)
{
    int temp, flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            // swapping
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag++;
            }
        }
        if (!flag)
            break;//used to shorten the number of iterations if already sorted
    }

}

// Function to print elements of array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}
