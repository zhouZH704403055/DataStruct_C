#include"Topic.h"

void test()
{
	QueueByTwoStack qts;
	QueueByTwoStackInit(&qts);
	QueueByTwoStackPush(&qts, 1);
	QueueByTwoStackPush(&qts, 2);
	if (QueueByTwoStackEmpty(&qts))
	{
		printf("�ն��У�\n");
	}
	else
	{
		printf("�ǿն��У�\n");
	}
	//printf("%d\n", QueueByTwoStackFront(&qts));
	QueueByTwoStackPush(&qts, 3);
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPush(&qts, 4);
	QueueByTwoStackPush(&qts, 5);
	//printf("%d\n", QueueByTwoStackFront(&qts));
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPop(&qts);
	if (QueueByTwoStackEmpty(&qts))
	{
		printf("�ն��У�\n");
	}
	else
	{
		printf("�ǿն��У�\n");
	}
	//printf("%d\n", QueueByTwoStackFront(&qts));
	QueueByTwoStackDestory(&qts);
}

int main()
{
	test();
	return 0;
}