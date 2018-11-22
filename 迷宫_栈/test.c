#include"Maze.h"
#include"Stack.h"

//void print(int arr[][N])
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//}

void test()
{
	Pos entry;
	Pos exit;
	entry._row = 5;
	entry._col = 2;
	exit._row = 4;
	exit._col = 5;	
	int ret = GetMazePath(entry, exit);
	if (ret)
	{
		printf("找到出口！\n");
	}
	else
	{
		printf("没有出口！\n");
	}
}

int main()
{
	test();
	return 0;
}
