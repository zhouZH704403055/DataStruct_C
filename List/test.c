#include"list.h"

//void test()
//{
//	Node* plist = NULL;
//	PushBack(&plist, 1);
//	PushBack(&plist, 2);
//	PushBack(&plist, 4);
//	PushBack(&plist, 5);
//	PrintList(plist);
//	pNode pos = Find(plist, 4);
//	InsertNode(pos, 3);
	//DelNodeNotTail(pos);
	//PrintList(plist);
	//PrintTailToHead(plist);
	//PushBack(&plist, 1);
	//PushBack(&plist, 2);
	//PushBack(&plist, 1);
	//PushBack(&plist, 2);
	//RemoveAll(&plist, 1);
	//pNode pos = Find(plist, 2);
	//Erase(&plist, pos);
	//PrintList(plist);
	//RemoveAll(&plist, 2);
	//PrintList(plist);
	//pNode pos = Find(plist, 2);
	//if (pos)
	//{
	//	printf("%d\n", pos->data);
	//}
	//else
	//{
	//	printf("NO FIND!\n");
	//}
	//pos = Find(plist, 5);
	//if (pos)
	//{
	//	printf("%d\n", pos->data);
	//}
	//else
	//{
	//	printf("NO FIND!\n");
	//}
	//PushFront(&plist, 4);
	//PrintList(plist);
	//PushFront(&plist, 3);
	//PrintList(plist);
	//PushFront(&plist, 2);
	//PrintList(plist);
	//PushFront(&plist, 1);
	//PrintList(plist);
	//PopFront(&plist);
	//PrintList(plist);
	//PopFront(&plist);
	//PrintList(plist);
	//PopFront(&plist);
	//PrintList(plist);
	//PopFront(&plist);
	//PrintList(plist);
	//PopBack(&plist);
	//PrintList(plist);
	//PopBack(&plist);
	//PrintList(plist);
	//PopBack(&plist);
	//PrintList(plist);
	//PopBack(&plist);
	//PrintList(plist);
	//DestroyList(&plist);
	//PrintList(plist);
//}

//void TestJosephusCycle()
//{
//	pNode plist = NULL;
//	for (int i = 1; i <= 10; i++)
//	{
//		PushBack(&plist, i);
//	}
//	PrintList(plist);
//	pNode pos = Find(plist, 10);
//	pos->next = plist;
//	JosephusCycle(&plist, 3);
//}

//void test()
//{
//	pList plist = NULL;
//	pList plist1 = NULL;
//	pList plist2 = NULL;
//	for (int i = 1; i < 10; i+=2)
//	{
//		PushBack(&plist1, i);
//	}
//	PrintList(plist1);
//	for (int i = 2; i <= 10; i += 2)
//	{
//		PushBack(&plist2, i);
//	}
//	PrintList(plist2);
//	plist = Merge(plist1, plist2);
//	//BubbleSort(plist);
//	//ReverseList(&plist);
//	PrintList(plist);
//}

void test()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	for (int i = 1; i < 10; i+=2)
	{
		PushBack(&plist1, i);
	}
	for (int i = 2; i <= 8; i++)
	{
		PushBack(&plist2, i);
	}
	PrintList(plist1);
	PrintList(plist2);
	UnionSet(plist1, plist2);
	//pNode pos = Find(plist1, 5);
	//pNode tail = plist2;
	//while (tail->next)
	//{
	//	tail = tail->next;
	//}
	//tail->next = pos;
	//PrintList(plist1);
	//PrintList(plist2);
	//bool ret = CheckCrossWithioutCircle(plist1, plist2);
	//if (ret)
	//{
	//	printf("�ཻ��\n");
	//	pNode ret = GetCrossNodeWithoutCircle(plist1, plist2);
	//	printf("����Ϊ��%d\n", ret->data);
	//}
	//else
	//{
	//	printf("���ཻ��\n");
	//}
	//pNode ret = IsCircle(plist);
	//if (ret)
	//{
	//	printf("������Ϊ��%d\n", ret->data);
	//	unsigned int len = GetCircleLength(ret);
	//	printf("���ĳ���Ϊ��%d\n", len);
	//	pNode enter = GetCicleEnterNode(plist, ret);
	//	printf("�������Ϊ��%d\n", enter->data);
	//}
	//else
	//{
	//	printf("����������\n");
	//}
	//DestroyList(&plist);
}

int main()
{
	test();
	//TestJosephusCycle();
	return 0;
}