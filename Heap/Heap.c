#include"Heap.h"

void AdjustDown(HPDataType* arr, size_t size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1) < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		//´ó¶Ñ
		if (arr[parent] < arr[child])
		{
			HPDataType tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* arr, size_t size)
{
	int child = size - 1;
	int parent = (child - 1) / 2;
	//´ó¶Ñ
	while (child > 0 && arr[parent] < arr[child])
	{
		HPDataType tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
		child = parent;
		parent = (child - 1) / 2;
	}
}

void HeapInit(Heap* hp, HPDataType* arr, size_t n)
{
	assert(hp);
	assert(arr);
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (int i = 0; i < n; i++)
	{
		hp->_arr[i] = arr[i];
	}
	for (int i = (n - 1) / 2;i>=0;i--)
	{
		AdjustDown(hp->_arr, hp->_size, i);
	}
}


void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_arr);
	hp->_arr = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}


void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity *= 2;
		HPDataType* New = realloc(hp->_arr, sizeof(HPDataType)*(hp->_capacity));
		assert(New);
		hp->_arr = New;
	}
	hp->_arr[hp->_size] = data;
	(hp->_size)++;
	AdjustUp(hp->_arr, hp->_size);
}


void HeapPop(Heap* hp)
{
	assert(hp);
	hp->_arr[0] = hp->_arr[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_arr, hp->_size, 0);
}


HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_arr[0];
}


size_t HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


size_t HeapCapacity(Heap* hp)
{
	assert(hp);
	return hp->_capacity;
}

bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? true : false;
}