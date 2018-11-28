#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _arr;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* arr, size_t n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType data);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
size_t HeapSize(Heap* hp);
size_t HeapCapacity(Heap* hp);
bool HeapEmpty(Heap* hp);