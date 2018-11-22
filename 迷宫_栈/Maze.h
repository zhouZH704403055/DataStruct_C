#pragma once

#include<stdio.h>
#include"Stack.h"

#define N 6
//static int maze[N][N]={
//	{0,0,0,0,0,0},
//    {0,0,1,0,0,0},
//    {0,0,1,0,0,0},
//    {0,0,1,1,1,0},
//    {0,0,1,0,1,1},
//    {0,0,1,0,0,0}
//};

static int maze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0}
};



int GetMazePath(Pos entry, Pos exit);
int CheckAccess(Pos next);
void print(int arr[][N]);
