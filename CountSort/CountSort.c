#include"CountSort.h"

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}


void CountSort(int arr[], int size)
{
	assert(arr);
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int range = max - min + 1;
	int* counts = (int*)malloc(sizeof(int) * range);
	memset(counts, 0, sizeof(int) * range);
	for (int i = 0; i < size; i++)
	{
		counts[arr[i] - min]++;
	}
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (counts[i]--)
		{
			arr[index++] = i + min;
		}
	}
}