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
		printf("�ҵ����ڣ�\n");
	}
	else
	{
		printf("û�г��ڣ�\n");
	}
}

int main()
{
	test();
	return 0;
}
