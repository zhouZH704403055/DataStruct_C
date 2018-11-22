#include"Maze.h"

int CheckAccess(Pos next)
{
	if (next._row >= 0 && next._row < N && next._col >= 0 && next._col < N && maze[next._row][next._col]==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	while (!StackEMpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
		maze[cur._row][cur._col] = 2;

		//判断是否找到出口
		if (cur._row == exit._row&&cur._col == exit._col)
		{
			print(maze);
			StackDestory(&path);
			return 1;
		}
		//探测下一次走的位置
		
		next = cur;
		next._col += 1;//向右走
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		next = cur;
		next._row -= 1;//向上走
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		next = cur;
		next._row += 1;//向下走
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		next = cur;
		next._col -= 1;//向左走
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		StackPop(&path);
	}
	StackDestory(&path);
	return 0;
}

void print(int arr[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}