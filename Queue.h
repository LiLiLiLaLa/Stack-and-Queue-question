#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _back;  // ��β
}Queue;

void QueueInit(Queue* pq);//��ʼ������
void QueueDestory(Queue* pq);//���ٶ���
QueueNode* BuyQueueNode(DataType x);//�����½��
void QueuePush(Queue* pq, DataType x);//��β�����½��
void QueuePop(Queue* pq);//��ͷ����Ԫ��
DataType QueueFront(const Queue* pq);//���ض�ͷԪ��
int QueueEmpty(const Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(const Queue* pq);//���ض��еĴ�С
void TestQueue();//���Ժ���