#include <iostream>
using namespace std;

int	getMax(int arr[], int size)
{
	int	max = arr[0];

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return ++max;
}

void	countingSort(int arr[], int size)
{
	const int max = getMax(arr, size);
	int	count[max];
	int	output[size];

	for (int i = 0; i < max; ++i)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; ++i)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < max; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = 0; i < size; ++i)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] = output[i];
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
	int	arr[] = {1, 9, 8, 1, 5, 4, 7, 6, 2, 3};
	int	size = sizeof(arr)/ sizeof(arr[0]);

	countingSort(arr, size);

	printArr(arr, size);

	return 0;
}