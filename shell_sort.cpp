#include <iostream>
using namespace std;

void	swap(int* a, int* b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	shellSort(int arr[], int size)
{
	for	(int i = size / 2; i > 0; i /= 2)
	{
		for(int j = i; j < size; ++j)
		{
			int	tmp = arr[j];
			int k;
			for (k = j; k >= i && arr[k - i] > tmp; k -= i)
			{
				arr[k] = arr[k - i];
			}
			arr[k] = tmp;
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
	int	arr[] = {34, 98, -10, 632, 76, 42};
	int	size = sizeof(arr) / sizeof(arr[0]);

	shellSort(arr, size);

	printArr(arr, size);

	return 0;
}