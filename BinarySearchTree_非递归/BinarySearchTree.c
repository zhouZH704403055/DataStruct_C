#include"BinarySearchTree.h"

BinarySearchTreeNode* BuyBinarySearchTreeNode(BSTDataType data)
{
	BinarySearchTreeNode* NewNode = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
	NewNode->_data = data;
	NewNode->_left = NULL;
	NewNode->_right = NULL;
	return NewNode;
}

void BinarySearchTreeInsert(BinarySearchTreeNode** tree, BSTDataType data)
{
	assert(tree);
	BinarySearchTreeNode* cur = NULL;
	BinarySearchTreeNode* parent = NULL;
	if (*tree == NULL)
	{
		*tree = BuyBinarySearchTreeNode(data);
	}
	cur = *tree;
	while (cur)
	{
		if (cur->_data > data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return;
		}
	}
	if (parent->_data < data)
	{
		parent->_right = BuyBinarySearchTreeNode(data);
	}
	else
	{
		parent->_left = BuyBinarySearchTreeNode(data);
	}
}


void BinarySearchTreeRemove(BinarySearchTreeNode** tree, BSTDataType data)
{
	assert(tree);
	BinarySearchTreeNode* cur = NULL;
	BinarySearchTreeNode* parent = NULL;
	cur = *tree;
	while (cur)
	{
		if (cur->_data > data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			if (cur->_left == NULL)
			{
				if (cur == (*tree))
				{
					*tree = cur->_right;
				}
				else if (cur == parent->_left)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
				free(cur);
				cur = NULL;
			}
			else if (cur->_right == NULL)
			{
				if (cur == (*tree))
				{
					*tree = cur->_left;
				}
				else if (cur == parent->_left)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
				free(cur);
				cur = NULL;
			}
			else
			{
				BinarySearchTreeNode* replace = cur->_right;
				parent = cur;
				while (replace->_left)
				{
					parent = replace;
					replace = replace->_left;
				}
				cur->_data = replace->_data;
				if (replace == parent->_right)
				{
					parent->_right = replace->_right;
				}
				else if (replace == parent->_left)
				{
					parent->_left = replace->_right;
				}
				free(replace);
				replace = NULL;
				return;
			}
		}
	}
}


BinarySearchTreeNode* BinarySearchTreeFind(BinarySearchTreeNode* tree, BSTDataType data)
{
	assert(tree);
	BinarySearchTreeNode* cur = tree;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		else if (cur->_data < data)
		{
			cur = cur->_right;
		}
		else
		{
			cur = cur->_left;
		}
	}
	return NULL;
}


void BinarySearchTreeInOrder(BinarySearchTreeNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	BinarySearchTreeInOrder(tree->_left);
	printf("%d ", tree->_data);
	BinarySearchTreeInOrder(tree->_right);
}

void BinarySearchTreeDestroy(BinarySearchTreeNode** tree)
{
	assert(tree);
	if (*tree == NULL)
	{
		return;
	}
	BinarySearchTreeDestroy(&(*tree)->_left);
	BinarySearchTreeDestroy(&(*tree)->_right);
	free(*tree);
	*tree = NULL;
}