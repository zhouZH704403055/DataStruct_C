#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef DataType;

typedef struct DoubleNode
{
	DataType data;
	struct DoubleNode* next;
	struct DoubleNode* prev;
}DoubleNode;

DoubleNode* BuyNode(DataType data);//����һ���½��
DoubleNode* InitList();//��ʼ����ͷ����˫������
void PushBack(DoubleNode* plist, DataType data);
void PrintList(DoubleNode* plist);