#pragma once

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _arr;
	int _top;//ջ�� ��Ԫ�ظ�����
	int _capacity;//����
}Stack;

void StackInit(Stack* pStack);//��ʼ��ջ
void StackDestory(Stack* pStack);//����ջ
void StackPush(Stack* pStack,DataType data);//ѹջ
void StackPop(Stack* pStack);//��ջ
DataType StackTop(Stack* pStack);//��ȡջ��Ԫ��
bool StackEMpty(Stack* pStack);//�ж�ջ�Ƿ�Ϊ��
int StackSize(Stack* pStack);//��ȡջ���ж��ٸ�Ԫ��