#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	sortArr(int arr[], int left, int right)
{
	int	pivot = arr[right];

	int	i = left - 1;

	for (int j = left; j < right; ++j)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	
	++i;

	swap(&arr[i], &arr[right]);

	return i;
}

void	quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int	pivot = sortArr(arr, left, right);

		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

void	printArr(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int	main()
{
	int	arr[] = {56, -1, 0, 7854, 124, 91, 98, 66};
	int	size = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, size - 1);

	printArr(arr, size);

	return 0;
}