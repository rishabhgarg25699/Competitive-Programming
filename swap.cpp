#include<iostream>

void swap(int *a, int *b)
{

	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
