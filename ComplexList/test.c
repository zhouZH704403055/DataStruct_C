#include"ComplexList.h"

void test()
{
	ComplexNode* plist = NULL;
	ComplexNode* n1 = BuyComplexNode(5);
	ComplexNode* n2 = BuyComplexNode(4);
	ComplexNode* n3 = BuyComplexNode(3);
	ComplexNode* n4 = BuyComplexNode(2);
	ComplexNode* n5 = BuyComplexNode(1);
	plist = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n1->random = n3;
	n2->random = n1;
	n4->random = n2;
	n5->random = n4;
	ComplexNode* NewList = CopyComplexList(plist);
	return;
}

int main()
{
	test();
	return 0;
}