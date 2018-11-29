#include"SelectSort.h"

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

void SelectSort(int *arr, int size)
{
	assert(arr);
	int begin = 0;
	int end = size - 1;

	while (begin <= end)
	{	
		int maxindex = begin;
		int minindex = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxindex])
			{
				maxindex = i;
			}
			if (arr[i] < arr[minindex])
			{
				minindex = i;
			}
		}
		Swap(&arr[begin], &arr[minindex]);
		if (begin == maxindex)
		{
			maxindex = minindex;
		}
		Swap(&arr[end], &arr[maxindex]);
		begin++;
		end--;
	}
}