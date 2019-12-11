void swap(int *a , int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bub_sort(int a[], int size)
{

	for(int i =size-1; i > 0; i--)
	{
		int flag = 0;

		for(int j = 0; j < i; j++)
		{
			if(a[j] > a[j+1]) 
			{
				swap(a+j, a+j+1);

				flag = 1;
			}

		}
		if(flag == 0) break;
	}
}
