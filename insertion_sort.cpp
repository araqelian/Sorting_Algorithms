#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int	j = i;
		while (arr[j] < arr[j - 1] && j > 0)
		{
			swap(&arr[j], &arr[j - 1]);
			--j;
		}
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
	int	arr[] = {12, -5, 789, 0, -12, 63, 50, 100, 51, 60, 71};
	int	size = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, size);

	printArr(arr, size);

	return 0;
}