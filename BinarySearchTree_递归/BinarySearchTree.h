#pragma once

typedef int BSTDataType;

typedef struct BinarySearchTreeNode
{
	struct BinarySearchTreeNode* _left;
	struct BinarySearchTreeNode* _right;
	BSTDataType _data;
}BinarySearchTreeNode;


//递归
void BinarySearchTreeInsertR(BinarySearchTreeNode** tree, BSTDataType data);
void BinarySearchTreeRemoveR(BinarySearchTreeNode** tree, BSTDataType data);
BinarySearchTreeNode* BinarySearchTreeFindR(BinarySearchTreeNode* tree, BSTDataType data);

void BinarySearchTreeInOrder(BinarySearchTreeNode* tree);
void BinarySearchTreeDestroy(BinarySearchTreeNode** tree);