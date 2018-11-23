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

DoubleNode* BuyNode(DataType data);//创建一个新结点
DoubleNode* InitList();//初始化带头结点的双向链表
void PushBack(DoubleNode* plist, DataType data);
void PrintList(DoubleNode* plist);