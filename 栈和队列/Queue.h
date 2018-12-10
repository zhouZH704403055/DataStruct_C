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

void QueueInit(Queue* pQueue);//初始化队列
void QueueDestory(Queue* pQueue);//销毁队列
QueueNode* BuyQueueNode(DataType data);//创建一个新结点
void QueuePush(Queue* pQueue, DataType data);//进队列
void QueuePop(Queue* pQueue);//出队列
DataType QueueFront(Queue* pQueue);//获取队头元素
bool QueueEmpty(Queue* pQueue);//判断队列是否为空
int QueueSize(Queue* pQueue);//获取队列中元素个数