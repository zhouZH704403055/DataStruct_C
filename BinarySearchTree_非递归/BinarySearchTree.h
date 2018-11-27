#pragma once


#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int BSTDataType;

typedef struct BinarySearchTreeNode
{
	struct BinarySearchTreeNode* _left;
	struct BinarySearchTreeNode* _right;
	BSTDataType _data;
}BinarySearchTreeNode;

//非递归
void BinarySearchTreeInsert(BinarySearchTreeNode** tree, BSTDataType data);
void BinarySearchTreeRemove(BinarySearchTreeNode** tree, BSTDataType data);
BinarySearchTreeNode* BinarySearchTreeFind(BinarySearchTreeNode* tree, BSTDataType data);

void BinarySearchTreeInOrder(BinarySearchTreeNode* tree);
void BinarySearchTreeDestroy(BinarySearchTreeNode** tree);