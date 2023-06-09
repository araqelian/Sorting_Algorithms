#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heapify(int arr[], int i, int size)
{
	int	left = 2 * i + 1;
	int	right = 2 * i + 2;
	int	largest = i;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, largest, size);
	}
}

void	heapSort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		heapify(arr, i, size);
	}

	for (int i = size - 1; i > 0; --i)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, 0, i);
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
	int	arr[] = {7, -987, 324, 96, 3, 14, 54};
	int	size = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, size);

	printArr(arr, size);

	return 0;
}