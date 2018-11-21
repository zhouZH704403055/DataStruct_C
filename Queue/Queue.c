#include"Queue.h"

//��ʼ������
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->_front = NULL;
	pQueue->_back = NULL;
}

//���ٶ���
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

//����һ���½��
QueueNode* BuyQueueNode(DataType data)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(NewNode);
	NewNode->_data = data;
	NewNode->_next = NULL;
	return NewNode;
}

//������
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

//������
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

//��ȡ��ͷԪ��
DataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	assert(pQueue->_front);
	return pQueue->_front->_data;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return (pQueue->_front == NULL) ? true : false;
}

//��ȡ������Ԫ�ظ���
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