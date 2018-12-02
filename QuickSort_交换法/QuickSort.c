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
	int keyindex = end;
	while (begin < end)
	{	
		while (begin < end && arr[begin] <= arr[keyindex])
		{
			begin++;
		}
		while (end > begin && arr[end] >= arr[keyindex])
		{
			end--;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[keyindex]);
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