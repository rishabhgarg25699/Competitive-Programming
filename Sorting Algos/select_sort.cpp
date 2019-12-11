int minloc(int A[], int k, int size)
{
	int min = k;

	for(int i = k; i < size; i++)
	{
		if(A[i] < A[min])
		{
			min = i;
		}
	}
	return min;
}

void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
	
}


void selec_sort(int A[], int size)
{
	for(int i = 0; i < size; i++)
	{
		int temp = minloc(A,i,size);
		swap(&A[temp],A+i);

	}
}
