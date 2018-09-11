#pragma once

#include "Queue.h"

//��������ʵ��һ��ջ
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);//��ʼ��
void StackByTwoQueueDestory(StackByTwoQueue* stq);//����
DataType StackByTwoQueueTop(StackByTwoQueue* stq);//��ͷ
int StackByTwoQueueEmpty(const StackByTwoQueue* stq);//�п�
int StackByTwoQueueSize(const StackByTwoQueue* stq);//Ԫ�ظ���
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);//��
void StackByTwoQueuePop(StackByTwoQueue* stq);//��
void TestStackByTwoQueue();
