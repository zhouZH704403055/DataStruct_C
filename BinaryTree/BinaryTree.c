#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"


//创建二叉树，arr是一个层序遍历结果的数组，包含空
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


//arr是一个前序遍历结果的数组，包含空
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

//销毁二叉树
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

//二叉树中结点的个数
size_t BinaryTreeSize(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

//二叉树的高度
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

//二叉树中叶子结点的个数
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

//第K层的结点个数
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

//在二叉树中查找值为data的元素
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

//前序遍历  根  左  右
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

//中序遍历  左  根  右
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

//后序遍历  左  右  根
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

//层序遍历
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


//非递归前序遍历
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

//非递归前序遍历
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

//非递归中序遍历
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

//非递归后序遍历
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

//判断二叉树是不是完全二叉树
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