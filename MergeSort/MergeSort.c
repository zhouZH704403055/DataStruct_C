#include"MergeSort.h"


void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void Merge(int arr[], int begin, int mid, int end, int* tmp)
{
	int i = begin;
	int j = mid + 1;
	int n = begin;
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			tmp[n] = arr[i];
			i++;
		}
		else
		{
			tmp[n] = arr[j];
			j++;
		}
		n++;
	}
	while (i <= mid)
	{
		tmp[n++] = arr[i++];
	}
	while (j <= end)
	{
		tmp[n++] = arr[j++];
	}
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void _MergeSort(int arr[], int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid + 1, end, tmp);
	Merge(arr, begin, mid, end, tmp);
}

void MergeSort(int arr[], int size)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*size);
	_MergeSort(arr, 0, size - 1, tmp);
	free(tmp);
}