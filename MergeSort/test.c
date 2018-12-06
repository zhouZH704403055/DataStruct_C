#include"MergeSort.h"

void test()
{
	int arr[] = { 21,25,49,25,16,8,31,41 };
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	test();
	return 0;
}