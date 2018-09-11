#pragma once

#include "Queue.h"

//两个队列实现一个栈
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);//初始化
void StackByTwoQueueDestory(StackByTwoQueue* stq);//销毁
DataType StackByTwoQueueTop(StackByTwoQueue* stq);//队头
int StackByTwoQueueEmpty(const StackByTwoQueue* stq);//判空
int StackByTwoQueueSize(const StackByTwoQueue* stq);//元素个数
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);//入
void StackByTwoQueuePop(StackByTwoQueue* stq);//出
void TestStackByTwoQueue();
