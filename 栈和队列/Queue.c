#include"Queue.h"

//初始化队列
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->_front = NULL;
	pQueue->_back = NULL;
}

//销毁队列
void QueueDestory(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* cur = pQueue->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pQueue->_front = NULL;
	pQueue->_back = NULL;
}

//创建一个新结点
QueueNode* BuyQueueNode(DataType data)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(NewNode);
	NewNode->_data = data;
	NewNode->_next = NULL;
	return NewNode;
}

//进队列
void QueuePush(Queue* pQueue, DataType data)
{
	assert(pQueue);
	QueueNode* NewNode = BuyQueueNode(data);
	if (pQueue->_back == NULL)
	{
		pQueue->_front = NewNode;
		pQueue->_back = NewNode;
	}
	else
	{
		pQueue->_back->_next = NewNode;
		pQueue->_back = NewNode;
	}
}

//出队列
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	if (pQueue->_front == NULL)
	{
		return;
	}
	else
	{
		QueueNode* cur = pQueue->_front;
		pQueue->_front = cur->_next;
		free(cur);
		cur = NULL;
	}
	if (pQueue->_front == NULL)
	{
		pQueue->_back = NULL;
	}
}

//获取队头元素
DataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->_front);
	return pQueue->_front->_data;
}

//判断队列是否为空
bool QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return (pQueue->_front == NULL) ? true : false;
}

//获取队列中元素个数
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	int size = 0;
	QueueNode* cur = pQueue->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}