#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selectionSort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int	min_index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
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
	int	arr[] = {10, -500, 0, 78, 98, 80};
	int	size = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, size);

	printArr(arr, size);

	return 0;
}