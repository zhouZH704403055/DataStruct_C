#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"


//������������arr��һ�����������������飬������
//BinaryTreeNode* BinaryTreeCreate(DataType* arr, size_t n)
//{
//	BinaryTreeNode* NewNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	if (arr[n] == '#')
//	{
//		return NULL;
//	}
//	else
//	{
//		NewNode->_data = arr[n];
//		NewNode->_left = BinaryTreeCreate(arr, 2 * n + 1);
//		NewNode->_right = BinaryTreeCreate(arr, 2 * (n + 1));
//	}
//	return NewNode;
//}

BinaryTreeNode* BuyNode(BTDataType data)
{
	BinaryTreeNode* NewNode = malloc(sizeof(BinaryTreeNode));
	assert(NewNode);
	NewNode->_data = data;
	NewNode->_left = NULL;
	NewNode->_right = NULL;
	return NewNode;
}


//arr��һ��ǰ�������������飬������
BinaryTreeNode* BinaryTreeCreate(BTDataType* arr, size_t* n)
{
	
	if (arr[*n] == '#')
	{
		return NULL;
	}
	else
	{
		BinaryTreeNode* NewNode = BuyNode(arr[*n]);
		(*n)++;
		NewNode->_left = BinaryTreeCreate(arr, n);
		(*n)++;
		NewNode->_right = BinaryTreeCreate(arr, n);
		return NewNode;
	}
}

//���ٶ�����
void BinaryTreeDestory(BinaryTreeNode** root)
{
	assert(root);
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}

//�������н��ĸ���
size_t BinaryTreeSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

//�������ĸ߶�
size_t BinaryTreeHeight(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size_t LeftHeight = BinaryTreeHeight(root->_left);
	size_t RightHeight = BinaryTreeHeight(root->_right);

	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

//��������Ҷ�ӽ��ĸ���
size_t BinaryTreeLeafSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//��K��Ľ�����
size_t BinaryTreeLevelKSize(BinaryTreeNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//�ڶ������в���ֵΪdata��Ԫ��
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType data)
{
	if (root == NULL || root->_data == data)
	{
		return root;
	}
	BinaryTreeNode* ret = BinaryTreeFind(root->_left, data);
	if (ret != NULL)
	{
		return ret;
	}
	else
	{
		return BinaryTreeFind(root->_right, data);
	}
}

//ǰ�����  ��  ��  ��
void BinaryTreePrevOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//�������  ��  ��  ��
void BinaryTreeInOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

//�������  ��  ��  ��
void BinaryTreePostOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

//�������
void BinaryTreeLevelOrder(BinaryTreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q,root);
	}
	while (QueueEmpty(&q) != true)
	{
		QUDataType front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	QueueDestory(&q);
	printf("\n");
}


//�ǵݹ�ǰ�����
//void BinaryTreePrevOrderNonR(BinaryTreeNode* root)
//{
//	Stack s;
//	StackInit(&s);
//	if (root)
//	{
//		printf("%c ", root->_data);
//		StackPush(&s, root);
//	}
//	BinaryTreeNode* cur = root->_left;
//	while (StackEMpty(&s) == false)
//	{
//		if (cur)
//		{
//			printf("%c ", cur->_data);
//			if (cur != StackTop(&s))
//			{
//				StackPush(&s, cur);
//			}
//			cur = cur->_left;
//		}
//		else
//		{
//			cur = StackTop(&s);
//			StackPop(&s);
//			while (cur->_right == NULL)
//			{
//				if (StackEMpty(&s))
//				{
//					break;
//				}
//				cur = StackTop(&s);
//				StackPop(&s);
//			}
//			if (cur->_right != NULL)
//			{
//				cur = cur->_right;
//				StackPush(&s, cur);
//			}
//		}
//	}
//	printf("\n");
//}

//�ǵݹ�ǰ�����
void BinaryTreePrevOrderNonR(BinaryTreeNode* root)
{
	BinaryTreeNode* cur = root;
	Stack s;
	StackInit(&s);
	while (cur || StackEMpty(&s) == false)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BinaryTreeNode* top = StackTop(&s);
		StackPop(&s);
		cur = top->_right;
	}
	printf("\n");
}

//�ǵݹ��������
void BinaryTreeInOrderNonR(BinaryTreeNode* root)
{
	BinaryTreeNode* cur = root;
	Stack s;
	StackInit(&s);
	while (cur || StackEMpty(&s) == false)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BinaryTreeNode* top = StackTop(&s);
		printf("%c ", top->_data);
		StackPop(&s);
		cur = top->_right;
	}
	putchar('\n');
}

//�ǵݹ�������
void BinaryTreePostOrderNonR(BinaryTreeNode* root)
{
	Stack s;
	StackInit(&s);
	BinaryTreeNode* cur = root;
	BinaryTreeNode* prev = root;
	while (cur || StackEMpty(&s) == false)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BinaryTreeNode* top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
}

//�ж϶������ǲ�����ȫ������
bool BinaryTreeComplete(BinaryTreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) == false)
	{
		QUDataType front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			while (QueueEmpty(&q) != true)
			{
				front = QueueFront(&q);
				if (front != NULL)
				{
					QueueDestory(&q);
					return false;
				}
				QueuePop(&q);
			}
		}
	}
	return true;
}