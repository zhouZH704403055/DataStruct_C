#include"QuickSort.h"
#include"Stack.h"

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

int GetMidIndex(int arr[], int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (arr[begin] < arr[mid])
	{
		if (arr[mid] < arr[end])
		{
			return mid;
		}
		else if (arr[begin] < arr[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else if(arr[mid]>arr[end])
	{
		return mid;
	}
	else if (arr[begin] < arr[end])
	{
		return begin;
	}
	else
	{
		return end;
	}
}

//非递归
void QuickSort(int arr[], int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (StackEMpty(&s) == false)
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int div = PartSort(arr, begin, end);
		if (begin < div - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&s, div + 1);
			StackPush(&s, end);
		}
	}
	StackDestory(&s);
}