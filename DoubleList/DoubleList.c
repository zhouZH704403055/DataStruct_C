#include"DoubleList.h"

DoubleNode* BuyNode(DataType data)
{
	DoubleNode* pNewNode = (DoubleNode*)malloc(sizeof(DoubleNode));
	if (pNewNode == NULL)
	{
		perror("BuyNode::malloc error!\n");
		return 0;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	pNewNode->prev = NULL;
	return pNewNode;
}

DoubleNode* InitList()
{
	DoubleNode* pHead = BuyNode(0);
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

void PushBack(DoubleNode* plist,DataType data)
{
	assert(plist);
	DoubleNode* ptail = plist->prev;
	DoubleNode* newnode = BuyNode(data);
	ptail->next = newnode;
	newnode->prev = ptail;
	newnode->next = plist;
	plist->prev = newnode;
}

void PrintList(DoubleNode* plist)
{
	DoubleNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d¡ª¡ª>", cur->data);
		cur = cur->next;
	}
	printf("Head!\n");
}
