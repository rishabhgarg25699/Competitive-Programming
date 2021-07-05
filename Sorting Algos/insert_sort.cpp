void insert_sort(int a[], int size)
{
	int i, j, item;

	for(i = 1; i < size; i++)
	{
		item = a[i];

		j = i-1;

		while((item < a[j]) && (j >= 0))
		{
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = item;
	}
}
