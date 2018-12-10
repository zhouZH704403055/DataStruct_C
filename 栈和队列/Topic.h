#pragma once

#include"Queue.h"
#include"Stack.h"


//两个栈实现一个队列
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType data);
void QueueByTwoStackPop(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);
bool QueueByTwoStackEmpty(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);


//两个队列实现一个栈
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType data);
void StackByTwoQueuePop(StackByTwoQueue* stq);
DataType StackByTwoQueueFront(StackByTwoQueue* stq);
bool StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);