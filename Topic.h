#pragma once

#include "Stack.h"

//两个栈实现一个队列
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);//初始化
void QueueByTwoStackDestory(QueueByTwoStack* qts);//销毁
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);//入
void QueueByTwoStackPop(QueueByTwoStack* qts);//出
DataType QueueByTwoStackFront(QueueByTwoStack* qts);//队头
int QueueByTwoStackSize(QueueByTwoStack* qts);//元素个数
int QueueByTwoStackEmpty(QueueByTwoStack* qts);//判空
void TestQueueByTwoStack();