#include"DoubleList.h"

void test()
{
	DoubleNode* pList = InitList();
	PushBack(pList, 1);
	PushBack(pList, 2);
	PushBack(pList, 3);
	PushBack(pList, 4);
	PrintList(pList);
}

int main()
{
	test();
	return 0;
}