#include"ComplexList.h"

//创建一个复杂链表的结点
ComplexNode* BuyComplexNode(DataType data)
{
	ComplexNode* NewNode = (ComplexNode*)malloc(sizeof(ComplexNode));
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->random = NULL;
	return NewNode;
}

ComplexNode* CopyComplexList(ComplexNode* plist)
{
	if (NULL == plist)
	{
		return NULL;
	}
	ComplexNode* NewList = NULL;
	ComplexNode* cur = plist;
	ComplexNode* pnext = cur->next;
	while (cur)
	{
		ComplexNode* NewNode = BuyComplexNode(cur->data);
		cur->next = NewNode;
		NewNode->next = pnext;
		cur = NewNode->next;
		if (pnext != NULL)
		{
			pnext = pnext->next;
		}
	}
	cur = plist;
	ComplexNode* copy = cur->next;
	NewList = copy;
	while (cur)
	{
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		cur = copy->next;
		if (cur)
		{
			copy = cur->next;
		}
	}
	cur = plist;
	copy = NewList;
	while (cur)
	{
		cur->next = copy->next;
		cur = cur->next;
		if (cur)
		{
			copy->next = cur->next;
			copy = cur->next;
		}
	}
	return NewList;
}