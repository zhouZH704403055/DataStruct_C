#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;

//创建一个复杂链表的结点
ComplexNode* BuyComplexNode(DataType data);
//复制一个复杂链表
ComplexNode* CopyComplexList(ComplexNode* plist);