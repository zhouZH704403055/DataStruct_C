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

//前后指针法
int PartSort(int arr[], int begin, int end)
{
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[mid], &arr[end]);
	int prev = begin - 1;
	int cur = begin;
	int key = arr[end];
	while (cur < end)
	{
		if (arr[cur] < key&&++prev!=cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[++prev], &arr[end]);
	return prev;
}

//递归
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