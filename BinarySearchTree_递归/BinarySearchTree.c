#include"BinarySearchTree.h"

BinarySearchTreeNode* BuyBinarySearchTreeNode(BSTDataType data)
{
	BinarySearchTreeNode* NewNode = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
	NewNode->_data = data;
	NewNode->_left = NULL;
	NewNode->_right = NULL;
	return NewNode;
}

void BinarySearchTreeInsertR(BinarySearchTreeNode** tree, BSTDataType data)
{
	assert(tree);
	if (*tree == NULL)
	{
		*tree = BuyBinarySearchTreeNode(data);
		return;
	}
	else if (data > (*tree)->_data)
	{
		BinarySearchTreeInsertR(&(*tree)->_right, data);
	}
	else if (data < (*tree)->_data)
	{
		BinarySearchTreeInsertR(&(*tree)->_left, data);
	}
}


void BinarySearchTreeRemoveR(BinarySearchTreeNode** tree, BSTDataType data)
{
	assert(tree);
	if (*tree == NULL)
	{
		return;
	}
	else if (data > (*tree)->_data)
	{
		BinarySearchTreeRemoveR(&(*tree)->_right, data);
	}
	else if (data < (*tree)->_data)
	{
		BinarySearchTreeRemoveR(&(*tree)->_left, data);
	}
	else
	{
		if ((*tree)->_left == NULL)
		{
			BinarySearchTreeNode* del = *tree;
			*tree = (*tree)->_right;
			free(del);
		}
		else if ((*tree)->_right == NULL)
		{
			BinarySearchTreeNode* del = *tree;
			*tree = (*tree)->_left;
			free(del);
		}
		else
		{
			BinarySearchTreeNode* replace = (*tree)->_right;
			//BinarySearchTreeNode* parent = *tree;
			while (replace->_left)
			{
				//parent = replace;
				replace = replace->_left;
			}
			(*tree)->_data = replace->_data;
			BinarySearchTreeRemoveR(&(*tree)->_right, replace->_data);
			//if (replace == parent->_right)
			//{
			//	parent->_right = replace->_right;
			//}
			//else if (replace == parent->_left)
			//{
			//	parent->_left = replace->_right;
			//}
			//free(replace);
		}
	}
}


BinarySearchTreeNode* BinarySearchTreeFindR(BinarySearchTreeNode* tree, BSTDataType data)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else if (tree->_data == data)
	{
		return tree;
	}
	else if (data > tree->_data)
	{
		return BinarySearchTreeFindR(tree->_right, data);
	}
	else if (data < tree->_data)
	{
		return BinarySearchTreeFindR(tree->_left, data);
	}
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