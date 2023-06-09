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
	return max;
}

void	countingSort(int arr[], int size, int place)
{
	const int max = 10;
	int	count[max];
	int	output[size];

	for (int i = 0; i < max; ++i)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; ++i)
	{
		count[(arr[i] / place) % 10]++;
	}

	for (int i = 1; i < max; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; --i)
	{
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		--count[(arr[i] / place) % 10];
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] = output[i];
	}
}

void	radixSort(int arr[], int size)
{
	const int max = getMax(arr, size);
	
	for (int i = 1; max / i > 0; i *= 10)
	{
		countingSort(arr, size, i);
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
	int	arr[] = {745, 12, 634, 14, 69, 4521, 762};
	int	size = sizeof(arr) / sizeof(arr[0]);

	radixSort(arr, size);

	printArr(arr, size);

	return 0;
}