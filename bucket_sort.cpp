#include <iostream>
using namespace std;

void	swap(float* a, float* b)
{
	float	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	insertionSort(float arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int 	j = i;
		float	tmp = arr[i];
		while (i > 0 && arr[i] != 0 && arr[i] < arr[i - 1])
		{
			swap(&arr[i], &arr[i - 1]);
			--i;
		}
		i = j;
	}
}

void	bucketSort(float arr[], int size)
{
	float bucket[10][size];

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			bucket[i][j] = 0;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		int	tmp = arr[i] * 10;

		if (tmp < 0)
			tmp = 0;
		
		int	j = 0;
		for (; j < size && bucket[tmp][j] != 0; ++j);
		bucket[tmp][j] = arr[i];
	}

	for (int i = 0; i < size; ++i)
	{
		insertionSort(bucket[i], sizeof(bucket[i]) / sizeof(bucket[i][0]));
	}

	int	index = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < size && bucket[i][j] != 0; ++j)
		{
			arr[index++] = bucket[i][j];
		}
	}
}

void	printArr(float arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int	main()
{
	float	arr[] = {0.54, 0.51, -0.314, 0.68, 0.0001, 0.4786, 0.12, 0.25, 0.9};
	int		size = sizeof(arr) / sizeof(arr[0]);

	bucketSort(arr, size);

	printArr(arr, size);

	return 0;
}