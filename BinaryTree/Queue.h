#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BinaryTreeNode* QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* pQueue);//��ʼ������
void QueueDestory(Queue* pQueue);//���ٶ���
QueueNode* BuyQueueNode(QUDataType data);//����һ���½��
void QueuePush(Queue* pQueue, QUDataType data);//������
void QueuePop(Queue* pQueue);//������
QUDataType QueueFront(Queue* pQueue);//��ȡ��ͷԪ��
bool QueueEmpty(Queue* pQueue);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pQueue);//��ȡ������Ԫ�ظ���