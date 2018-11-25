#include"Stack.h"

//初始化栈
void StackInit(Stack* pStack)
{
	assert(pStack);
	pStack->_capacity = 4;
	pStack->_top = 0;
	pStack->_arr = malloc(sizeof(DataType)*(pStack->_capacity));
	assert(pStack->_arr);
}

//销毁栈
void StackDestory(Stack* pStack)
{
	assert(pStack);
	if (pStack->_arr)
	{	
		pStack->_capacity = 0;
		pStack->_top = 0;
		free(pStack->_arr);
		pStack->_arr = NULL;
	}
}

//压栈
void StackPush(Stack* pStack, DataType data)
{
	assert(pStack);
	assert(pStack->_arr);
	if (pStack->_top == pStack->_capacity)
	{
		DataType* pnew = (DataType*)realloc(pStack->_arr, sizeof(DataType)*(pStack->_capacity * 2 + 1));
		if (pnew != NULL)
		{
			pStack->_arr = pnew;
		}
		//pStack->_arr = (DataType*)realloc(pStack->_arr, (sizeof(DataType)*(pStack->_capacity * 2 + 1)));
		//DataType* newarr = (DataType*)malloc(sizeof(DataType)*(pStack->_capacity * 2 + 1));
		//for (int i = 0; i < pStack->_top; i++)
		//{
		//	newarr[i] = pStack->_arr[i];
		//}
		//free(pStack->_arr);
		//pStack->_arr = newarr;
		//newarr = NULL;
		assert(pStack);
		pStack->_capacity = pStack->_capacity * 2 + 1;
	}
	pStack->_arr[pStack->_top] = data;
	pStack->_top++;
}

//出栈
void StackPop(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top > 0)
	{
		pStack->_top--;
	}
}

//获取栈顶元素
DataType StackTop(Stack* pStack)
{
	assert(pStack);
	assert(pStack->_arr);
	assert(pStack->_top > 0);
	return pStack->_arr[pStack->_top - 1];
}

//判断栈是否为空
bool StackEMpty(Stack* pStack)
{
	assert(pStack);
	if (pStack->_top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//获取栈中有多少个元素
int StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->_top;
}