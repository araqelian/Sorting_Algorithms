#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubbleSort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			swap(&arr[i], &arr[i - 1]);
			i = 0;
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

int main()
{
	int	arr[] = {7, 10, -1, 50, 78, 65};
	int	size = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, size);

	printArr(arr, size);

	return 0;
}