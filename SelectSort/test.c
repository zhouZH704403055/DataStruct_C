#include"SelectSort.h"

void test()
{
	int arr[] = { 21,25,49,25,16,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	Print(arr, size);
}

int main()
{
	test();
	return 0;
}