#include"Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	printf("%d ", QueueSize(&q));
	QueuePush(&q, 2);
	printf("%d ", QueueSize(&q));
	QueuePush(&q, 3);
	printf("%d ", QueueSize(&q));
	QueuePush(&q, 4);
	printf("%d ", QueueSize(&q));
	//printf("%d ", QueueFront(&q));
	QueuePush(&q, 5);
	printf("%d ", QueueSize(&q));
	QueuePop(&q);
	QueuePop(&q);
	//printf("%d ", QueueFront(&q));
	//if (QueueEmpty(&q))
	//{
	//	printf("空队列！\n");
	//}
	//else
	//{
	//	printf("非空！\n");
	//}
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d ", QueueSize(&q));
	//if (QueueEmpty(&q))
	//{
	//	printf("空队列！\n");
	//}
	//else
	//{
	//	printf("非空！\n");
	//}
	QueueDestory(&q);
}

int main()
{
	test();
	return 0;
}