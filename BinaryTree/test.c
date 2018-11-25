#include"BinaryTree.h"

void test()
{
	size_t n = 0;
	char array[] = { 'A','B','D','#','#','#','C','E','#','#','F','#','#' };
	BinaryTreeNode* BinTree = BinaryTreeCreate(array, &n);
	//BinaryTreePrevOrder(BinTree);
	//putchar('\n');
	//BinaryTreeInOrder(BinTree);
	//putchar('\n');
	//BinaryTreePostOrder(BinTree);
	//putchar('\n');
	//BinaryTreeLevelOrder(BinTree);
	//BinaryTreeNode* ret = BinaryTreeFind(BinTree, 'D');
	//if(ret!=NULL)
	//	printf("%c\n", ret->_data);
	//printf("Height:%d\n", BinaryTreeHeight(BinTree));	
	//if (BinaryTreeComplete(BinTree))
	//{
	//	printf("����ȫ��������");
	//}
	//else
	//{
	//	printf("������ȫ��������");
	//}

	BinaryTreePrevOrderNonR(BinTree);
	BinaryTreeInOrderNonR(BinTree);
	BinaryTreePostOrderNonR(BinTree);
	BinaryTreeDestory(&BinTree);

}

int main()
{
	test();
	return 0;
}