#include"CountSort.h"

void test()
{
	int arr[] = { 21,25,49,16,8,10,15,20,24,1,3,87,34 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	Print(arr, size);
}

int main()
{
	test();
	return 0;
}