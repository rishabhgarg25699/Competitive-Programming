#include <stdio.h>
 
int main()
{
    int n, s = 0, i; 
    printf("Enter a Number: ");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            s = s + i;
        }
    }
    if (s == n)
        printf("%d is a perfect number",n);
    else
        printf("%d is not a perfect number",n);
    return 0;
}