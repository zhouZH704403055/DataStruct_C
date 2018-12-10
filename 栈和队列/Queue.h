#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* pQueue);//��ʼ������
void QueueDestory(Queue* pQueue);//���ٶ���
QueueNode* BuyQueueNode(DataType data);//����һ���½��
void QueuePush(Queue* pQueue, DataType data);//������
void QueuePop(Queue* pQueue);//������
DataType QueueFront(Queue* pQueue);//��ȡ��ͷԪ��
bool QueueEmpty(Queue* pQueue);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pQueue);//��ȡ������Ԫ�ظ���