#include"QuickSort.h"

void Swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int PartSort(int arr[], int begin, int end)
{
	int tmp = arr[end];
	while (begin < end)
	{
		while (begin < end&&arr[begin] <= tmp)
		{
			begin++;
		}
		arr[end] = arr[begin];
		while (begin < end&&arr[end] >= tmp)
		{
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = tmp;
	return begin;
}

void QuickSort(int arr[], int left, int right)
{
	assert(arr);
	if (left >= right)
	{
		return;
	}

	int div = PartSort(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div + 1, right);
}