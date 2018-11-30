#include<stdio.h>
#include<assert.h>
void AdjustDown(int* arr, int size, int root)
{
	assert(arr);
	int parent = root;
	int child = 2 * parent + 1;
	
	while (child < size)
	{
		if ((child + 1) < size && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[parent] < arr[child])
		{
			int tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int* arr, int size)
{
	int count = size;
	//´ó¶Ñ£¬ÅÅÉýÐò
	for(int i=(size-2)/2;i>=0;i--)
	{
		AdjustDown(arr, size, i);
	}
	while (--count)
	{
		int tmp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = tmp;
		size--;
		AdjustDown(arr, size, 0);
	}
}

int main()
{
	int arr[] = { 53,17,78,9,45,65,87,23,31 };
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}