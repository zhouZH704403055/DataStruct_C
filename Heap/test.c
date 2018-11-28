#include"Heap.h"

void test()
{
	int arr[] = { 53,17,78,9,45,65,87,23,31 };
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", hp._arr[i]);
	}
	putchar('\n');
	HeapPush(&hp, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", hp._arr[i]);
	}
	putchar('\n');
	HeapPop(&hp);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", hp._arr[i]);
	}

	HeapDestory(&hp);
}

int main()
{
	test();
	return 0;
}