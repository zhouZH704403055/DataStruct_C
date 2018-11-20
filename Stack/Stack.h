#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _arr;
	int _top;//栈顶 （元素个数）
	int _capacity;//容量
}Stack;

void StackInit(Stack* pStack);//初始化栈
void StackDestory(Stack* pStack);//销毁栈
void StackPush(Stack* pStack,DataType data);//压栈
void StackPop(Stack* pStack);//出栈
DataType StackTop(Stack* pStack);//获取栈顶元素
bool StackEMpty(Stack* pStack);//判断栈是否为空
int StackSize(Stack* pStack);//获取栈中有多少个元素