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

//������
void DelNodeNotTail(pNode pos);//ɾ����ͷ������ķ�β���
void InsertNode(pNode pos, DataType data);//����ͷ�������һ���ڵ�ǰ����һ���ڵ�
void JosephusCycle(pList* pplist,int k);//Լɪ��
void ReverseList(pList* pplist);//��������
void BubbleSort(pList plist);//ð������
pList Merge(pList plist1, pList plist2);//�ϲ��������������ϲ�����Ȼ����
pNode FindMidNode(pList plist);//ֻ��������һ���ҵ��м���
pNode FindLastKNode(pList plist, int k);//ֻ����һ���ҵ�����ĵ�����K�����
pNode IsCircle(pList plist);//�ж������Ƿ����
unsigned int GetCircleLength(pNode meet);//��ȡ���ĳ���
pNode GetCicleEnterNode(pList plist, pNode meet);//��ȡ�������
bool CheckCrossWithioutCircle(pList plist1, pList plist2);//�ж����������Ƿ��ཻ��������������
pNode GetCrossNodeWithoutCircle(pList p1, pList p2);//�������ཻ����Ľ��㣬������������
void UnionSet(pList plist1, pList plist2);//��������������Ľ���