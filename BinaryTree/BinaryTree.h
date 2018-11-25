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
BinaryTreeNode* BinaryTreeCreate(BTDataType* arr,size_t* n);//arr��һ��ǰ�������������飬������
void BinaryTreeDestory(BinaryTreeNode** root);

size_t BinaryTreeSize(BinaryTreeNode* root);
size_t BinaryTreeHeight(BinaryTreeNode* root);
size_t BinaryTreeLeafSize(BinaryTreeNode* root);
size_t BinaryTreeLevelKSize(BinaryTreeNode* root, int k);
BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType data);

//�ݹ����
void BinaryTreePrevOrder(BinaryTreeNode* root);//ǰ�����  ��  ��  ��
void BinaryTreeInOrder(BinaryTreeNode* root);//�������  ��  ��  ��
void BinaryTreePostOrder(BinaryTreeNode* root);//�������  ��  ��  ��


//�ǵݹ����
void BinaryTreeLevelOrder(BinaryTreeNode* root);//�������
void BinaryTreePrevOrderNonR(BinaryTreeNode* root);//ǰ�����
void BinaryTreeInOrderNonR(BinaryTreeNode* root);//�������
void BinaryTreePostOrderNonR(BinaryTreeNode* root);//�������

bool BinaryTreeComplete(BinaryTreeNode* root);//�ж϶������ǲ�����ȫ������