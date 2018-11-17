#include"list.h"

//��ʼ������
void InitList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}

//��������
void DestroyList(pList* pplist)
{
	assert(pplist);	
	pNode cur = *pplist;
	pNode del = *pplist;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

//����һ���½��
pNode BuyNode(DataType data)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//β��
void PushBack(pList* pplist, DataType data)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = BuyNode(data);
	}
	else
	{
		pNode cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = BuyNode(data);
	}
}

//βɾ
void PopBack(pList* pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pNode cur = *pplist;
		pNode del = cur->next;
		while (del->next)
		{
			cur = cur->next;
			del = cur->next;
		}
		free(del);
		cur->next = NULL;
	}
}

//ͷ��
void PushFront(pList* pplist, DataType data)
{
	assert(pplist);
	pNode cur = *pplist;
	*pplist = BuyNode(data);
	(*pplist)->next = cur;
}

//ͷɾ
void PopFront(pList* pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		pNode cur = (*pplist)->next;
		free(*pplist);
		*pplist = cur;
	}
}

//����Ԫ��Ϊdata�Ľ��
pNode Find(pList plist, DataType data)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//��posλ�ò�����
void Insert(pList* pplist, pNode pos, DataType data)
{
	assert(pplist);
	assert(pos);
	pNode cur = *pplist;
	if (pos == cur)
	{
		*pplist = BuyNode(data);
		(*pplist)->next = cur;
	}
	else
	{
		while (cur->next != NULL && cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur->next == NULL)
		{
			return;
		}
		else
		{
			cur->next = BuyNode(data);
			cur->next->next = pos;
		}
	}
}

//ɾ��posλ�õĽ��
void Erase(pList* pplist, pNode pos)
{
	assert(pplist);
	assert(pos);
	if (*pplist == NULL)
	{
		return;
	}
	pNode cur = *pplist;
	if (pos == *pplist)
	{
		cur = cur->next;
		free(pos);
		*pplist = cur;
	}
	else
	{
		while (cur->next != NULL && cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur->next != NULL)
		{
			cur->next = pos->next;
			free(pos);
		}
	}
}

//ɾ�������е�һ��Ԫ��Ϊdata�Ľ��
void Remove(pList* pplist, DataType data)
{
	assert(pplist);
	pNode cur = *pplist;
	pNode del = cur;
	while (del != NULL && del->data != data)
	{
		cur = del;
		del = del->next;
	}
	if (del != NULL)
	{
		if (*pplist == del)
		{
			*pplist = (*pplist)->next;
		}
		else
		{
			cur->next = del->next;
		}
		free(del);
	}
}

//ɾ������������Ԫ��Ϊdata�Ľ��
void RemoveAll(pList* pplist, DataType data)
{
	assert(pplist);
	pNode cur = *pplist;
	pNode del = cur;
	while (del)
	{
		if (del->data == data)
		{
			if (del == *pplist)
			{
				*pplist = (*pplist)->next;
			}
			else
			{
				cur->next = del->next;
			}
			free(del);
			del = *pplist;
			cur = del;
		}
		else
		{
			cur = del;
			del = cur->next;
		}
	}
}

//��ͷ��β��ӡ����
void PrintList(pList plist)
{
	pNode cur = plist;
	while (cur)
	{
		printf("%d����>", cur->data);
		cur = cur->next;
	}
	printf("NULL!\n");
}

//�ݹ飺�����ӡ����
//void PrintTailToHead(pList plist)
//{
//	if (plist == NULL)
//	{
//		printf("NULL");
//		return;
//	}
//	PrintTailToHead(plist->next);
//	printf("<����%d", plist->data);
//}

//�ǵݹ飺�����ӡ����
void PrintTailToHead(pList plist)
{
	pNode cur = plist;
	pNode tail = plist;
	while (tail)
	{
		tail = tail->next;
	}
	while (tail != plist)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		if (tail == NULL)
		{
			printf("NULL");
		}
		printf("<����%d", cur->data);
		tail = cur;
	}
}

//��ȡ����ĳ���
unsigned int GetListLength(pList plist)
{
	pNode cur = plist;
	unsigned int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//ɾ����ͷ������ķ�β���
void DelNodeNotTail(pNode pos)
{
	assert(pos);
	assert(pos->next);
	pNode cur = pos->next;
	pos->data = cur->data;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}

//����ͷ�������һ�����ǰ����һ�����
void InsertNode(pNode pos, DataType data)
{
	assert(pos);
	pNode cur = pos->next;
	DataType tmp = pos->data;
	pos->next = BuyNode(data);
	pos->data = data;
	pos->next->data = tmp;
	pos->next->next = cur;
}

//Լɪ��
void JosephusCycle(pList* pplist, int k)
{
	pNode cur = *pplist;
	pNode del = NULL;
	while (cur != cur->next)
	{
		for (int i = 1; i < k; i++)
		{
			cur = cur->next;
		}
		printf("The %d is die!\n", cur->data);
		del = cur->next->next;
		cur->data = cur->next->data;
		free(cur->next);
		cur->next = del;
		del = NULL;
	}
	*pplist = cur;
	printf("The %d is live!\n", cur->data);
}

//��������:��ָ�뷨
//void ReverseList(pList* pplist)
//{
//	assert(pplist);
//	if ((*pplist) == NULL || (*pplist)->next == NULL)
//	{
//		return;
//	}
//	pNode frist = *pplist;
//	pNode second = frist->next;
//	pNode third = second->next;
//	while (second != NULL)
//	{
//		second->next = frist;
//		frist = second;
//		second = third;
//		if (third != NULL)
//		{
//			third = third->next;
//		}
//	}
//	(*pplist)->next = NULL;
//	*pplist = frist;
//}

//��������ͷ�巨
void ReverseList(pList* pplist)
{
	assert(pplist);
	if ((*pplist) == NULL || ((*pplist)->next == NULL))
	{
		return;
	}
	pList pHead = NULL;
	pNode cur = *pplist;
	pNode tmp = cur->next;
	while (cur)
	{
		if (pHead == NULL)
		{
			pHead = cur;
		}
		else
		{
			cur->next = pHead;
			pHead = cur;
			cur = tmp;
			if (tmp)
			{
				tmp = tmp->next;
			}
		}
	}
	(*pplist)->next = NULL;
	*pplist = pHead;
}

//ð������
void BubbleSort(pList plist)
{
	if (NULL == plist)
	{
		return;
	}
	int flag = 0;;
	pNode tail = NULL;
	while (tail != plist)
	{
		pNode cur = plist;
		pNode next = cur->next;
		while (next != tail)
		{
			if (next->data < cur->data)
			{
				DataType tmp = next->data;
				next->data = cur->data;
				cur->data = tmp;
				flag = 1;
			}
			else
			{
				cur = next;
				next = next->next;
			}
		}
		if (flag == 0)
		{
			return;
		}
		tail = cur;
	}
}

//�ϲ�������������ϲ�����Ȼ����
pList Merge(pList plist1, pList plist2)
{
	if (plist1 == plist2)
	{
		return plist1;
	}
	if (plist1 == NULL)
	{
		return plist2;
	}
	if (plist2 == NULL)
	{
		return plist1;
	}
	pList newlist = NULL;
	pList cur = NULL;
	while (plist1 != NULL && plist2 != NULL)
	{
		if (plist1->data < plist2->data)
		{
			if (newlist == NULL)
			{
				newlist = plist1;
				cur = newlist;
			}
			else
			{
				cur->next = plist1;
				cur = cur->next;
			}
			plist1 = plist1->next;
		}
		else
		{
			if (newlist == NULL)
			{
				newlist = plist2;
				cur = newlist;
			}
			else
			{
				cur->next = plist2;
				cur = cur->next;
			}
			plist2 = plist2->next;
		}
	}
	if (plist1 == NULL && plist2 != NULL)
	{
		cur->next = plist2;
	}
	else if (plist1 != NULL && plist2 == NULL)
	{
		cur->next = plist1;
	}
	return newlist;
}

//ֻ��������һ�飬�ҵ��м���
pNode FindMidNode(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//ֻ����һ���ҵ�����ĵ�����K�����
pNode FindLastKNode(pList plist, int k)
{
	if (plist == NULL)
	{
		return NULL;
	}
	int count = k;
	pNode fast = plist;
	pNode slow = plist;
	while (count--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//�ж������Ƿ����
pNode IsCircle(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		return plist;
	}
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}

//��������󻷵ĳ���
unsigned int GetCircleLength(pNode meet)
{
	assert(meet);
	pNode cur = meet->next;
	unsigned int len = 1;
	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

//��ȡ�������
pNode GetCicleEnterNode(pList plist, pNode meet)
{
	assert(meet);
	if (NULL == plist)
	{
		return NULL;
	}
	while (plist != meet)
	{
		plist = plist->next;
		meet = meet->next;
	}
	return plist;
}

//�ж����������Ƿ��ཻ��������������
bool CheckCrossWithioutCircle(pList plist1, pList plist2)
{
	pNode tail1 = plist1;
	pNode tail2 = plist2;
	while (tail1->next != NULL)
	{
		tail1 = tail1->next;
	}
	while (tail2->next != NULL)
	{
		tail2 = tail2->next;
	}
	if (tail1 == tail2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ȡ�����ཻ����Ľ��㣬������������
pNode GetCrossNodeWithoutCircle(pList plist1, pList plist2)
{
	if (plist1 == NULL || plist2 == NULL)
	{
		return NULL;
	}
	int len1 = 1;
	int len2 = 1;
	int ret = 0;
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	while (cur1->next)
	{
		cur1 = cur1->next;
		len1++;
	}
	while (cur2->next)
	{
		cur2 = cur2->next;
		len2++;
	}
	cur1 = plist1;
	cur2 = plist2;
	ret = len1 - len2;
	if (len1 < len2)
	{
		pNode tmp = cur1;
		cur1 = cur2;
		cur2 = tmp;
		ret = len2 - len1;
	}
	for (int i = 0; i < ret; i++)
	{
		cur1 = cur1->next;
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

//��������������Ľ���
void UnionSet(pList plist1, pList plist2)
{
	if (plist1 == NULL || plist2 == NULL)
	{
		return;
	}
	while (plist1 != NULL && plist2 != NULL)
	{
		if (plist1->data == plist2->data)
		{
			printf("%d ", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
		}
		else if (plist1->data < plist2->data)
		{
			plist1 = plist1->next;
		}
		else
		{
			plist2 = plist2->next;
		}
	}
	printf("\n");
}