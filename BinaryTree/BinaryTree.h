#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BinaryTreeNode;

BinaryTreeNode* BuyNode(BTDataType data);
BinaryTreeNode* BinaryTreeCreate(BTDataType* arr,size_t* n);//arr是一个前序遍历结果的数组，包含空
void BinaryTreeDestory(BinaryTreeNode** root);

size_t BinaryTreeSize(BinaryTreeNode* root);
size_t BinaryTreeHeight(BinaryTreeNode* root);
size_t BinaryTreeLeafSize(BinaryTreeNode* root);
size_t BinaryTreeLevelKSize(BinaryTreeNode* root, int k);
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType data);

//递归遍历
void BinaryTreePrevOrder(BinaryTreeNode* root);//前序遍历  根  左  右
void BinaryTreeInOrder(BinaryTreeNode* root);//中序遍历  左  根  右
void BinaryTreePostOrder(BinaryTreeNode* root);//后序遍历  左  右  根


//非递归遍历
void BinaryTreeLevelOrder(BinaryTreeNode* root);//层序遍历
void BinaryTreePrevOrderNonR(BinaryTreeNode* root);//前序遍历
void BinaryTreeInOrderNonR(BinaryTreeNode* root);//中序遍历
void BinaryTreePostOrderNonR(BinaryTreeNode* root);//后序遍历

bool BinaryTreeComplete(BinaryTreeNode* root);//判断二叉树是不是完全二叉树