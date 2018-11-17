#pragma once

#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node,*pNode,*pList;


pNode BuyNode(DataType data);

void InitList(pList* pplist);
void DestroyList(pList* pplist);
unsigned int GetListLength(pList plist);

void PushBack(pList* pplist, DataType data);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType data);
void PopFront(pList* pplist);

pNode Find(pList plist, DataType data);
void Insert(pList* pplist, pNode pos, DataType data);
void Erase(pList* pplist, pNode pos);
void Remove(pList* pplist, DataType data);
void RemoveAll(pList* pplist, DataType data);

void PrintList(pList plist);
void PrintTailToHead(pList plist);

//面试题
void DelNodeNotTail(pNode pos);//删除无头单链表的非尾结点
void InsertNode(pNode pos, DataType data);//在无头单链表的一个节点前插入一个节点
void JosephusCycle(pList* pplist,int k);//约瑟夫环
void ReverseList(pList* pplist);//逆序链表
void BubbleSort(pList plist);//冒泡排序
pList Merge(pList plist1, pList plist2);//合并两个有序链表，合并后仍然有序
pNode FindMidNode(pList plist);//只遍历链表一遍找到中间结点
pNode FindLastKNode(pList plist, int k);//只遍历一遍找到链表的倒数第K个结点
pNode IsCircle(pList plist);//判断链表是否带环
unsigned int GetCircleLength(pNode meet);//获取环的长度
pNode GetCicleEnterNode(pList plist, pNode meet);//获取环的入口
bool CheckCrossWithioutCircle(pList plist1, pList plist2);//判断两个链表是否相交，假设链表不带环
pNode GetCrossNodeWithoutCircle(pList p1, pList p2);//求两个相交链表的交点，假设链表不带环
void UnionSet(pList plist1, pList plist2);//求两个有序链表的交集