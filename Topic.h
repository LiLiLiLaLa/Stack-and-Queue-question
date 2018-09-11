#pragma once

#include "Stack.h"

//����ջʵ��һ������
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);//��ʼ��
void QueueByTwoStackDestory(QueueByTwoStack* qts);//����
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);//��
void QueueByTwoStackPop(QueueByTwoStack* qts);//��
DataType QueueByTwoStackFront(QueueByTwoStack* qts);//��ͷ
int QueueByTwoStackSize(QueueByTwoStack* qts);//Ԫ�ظ���
int QueueByTwoStackEmpty(QueueByTwoStack* qts);//�п�
void TestQueueByTwoStack();