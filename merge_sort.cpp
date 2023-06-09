#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

int*		my_merge(int arr[], int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			swap(&arr[i], &arr[i - 1]);
			i = left;
		}
	}
	return arr;
}

void	mergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int	mid = (left + right) / 2;
		mergeSort(arr, left, mid - 1);
		mergeSort(arr, mid + 1, right);
		arr = my_merge(arr, left, right);
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

int main()
{
	int	arr[] = {5, 4, 3, 2, 1, 0};
	int	size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, size);

	printArr(arr, size);

	return 0;
}