#include"Topic.h"

void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);
	StackInit(&(qts->s1));
	StackInit(&(qts->s2));
}

void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	assert(qts);
	StackDestory(&(qts->s1));
	StackDestory(&(qts->s2));
}

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType data)
{
	assert(qts);
	StackPush(&(qts->s1), data);
}

void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEMpty(&(qts->s2)) == true)
	{
		while (StackEMpty(&(qts->s1)) == false)
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	StackPop(&(qts->s2));
}

DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEMpty(&(qts->s2)) == true)
	{
		while (StackEMpty(&(qts->s1)) == false)
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	return StackTop(&(qts->s2));
}

bool QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEMpty(&(qts->s2)) == true)
	{
		if (StackEMpty(&(qts->s1)) == true)
		{
			return true;
		}
	}
	return false;
}

int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&(qts->s1)) + StackSize(&(qts->s2));
}



//////////////////////////////////////////////////////////////////////////////////////////////


void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&(stq->q1));
	QueueInit(&(stq->q2));
}


void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&(stq->q1));
	QueueDestory(&(stq->q2));
}


void StackByTwoQueuePush(StackByTwoQueue* stq, DataType data)
{
	assert(stq);
	if (QueueEmpty(&(stq->q1)) == true)
	{
		QueuePush(&(stq->q1), data);
	}
	else
	{
		QueuePush(&(stq->q2), data);
	}
}


void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue* empty = &stq->q1;
	Queue* nonempty = &stq->q2;
	if (QueueEmpty(&(stq->q1)) == false)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}

	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueuePop(nonempty);
}


DataType StackByTwoQueueFront(StackByTwoQueue* stq)
{
	assert(stq);
	Queue* empty = &stq->q1;
	Queue* nonempty = &stq->q2;
	if (QueueEmpty(&(stq->q1)) == false)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}

	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	return QueueFront(nonempty);
}


bool StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	if (QueueEmpty(&(stq->q1)) == true)
	{
		if (QueueEmpty(&(stq->q2)) == true)
		{
			return true;
		}
	}
	return false;
}


int StackByTwoQueueSize(StackByTwoQueue* stq)
{

	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));
}