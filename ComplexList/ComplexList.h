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

//����һ����������Ľ��
ComplexNode* BuyComplexNode(DataType data);
//����һ����������
ComplexNode* CopyComplexList(ComplexNode* plist);