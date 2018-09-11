#include "Topic.h"

void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);
	StackInit(&(qts->s1));
	StackInit(&(qts->s2));
}

void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	assert(qts);
	StackDestory(&(qts->s1));
	StackDestory(&(qts->s2));
}

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x)
{
	assert(qts);
	StackPush(&(qts->s1), x);//Ĭ�ϴ�ջһ��
}

void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&(qts->s2)) == 0)
	{
		while (StackEmpty(&(qts->s1)))
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	StackPop(&(qts->s2));
}

DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&(qts->s2)) == 0)
	{
		while (StackEmpty(&(qts->s1)))
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	return StackTop(&(qts->s2));
}

int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&(qts->s1)) + StackSize(&(qts->s2));
}

int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);
	return StackEmpty(&(qts->s1)) | StackEmpty(&(qts->s2));
}

void TestQueueByTwoStack()
{
	DataType tmp = 0;
	QueueByTwoStack qs;
	QueueByTwoStackInit(&qs);
	QueueByTwoStackPush(&qs, 11);
	QueueByTwoStackPush(&qs, 22);
	QueueByTwoStackPush(&qs, 33);
	QueueByTwoStackPush(&qs, 44);
	tmp = QueueByTwoStackFront(&qs);
	printf("ջ����Ԫ���ǣ�%d\n", tmp);
	QueueByTwoStackPop(&qs);
	tmp = QueueByTwoStackFront(&qs);
	printf("ջ����Ԫ���ǣ�%d\n", tmp);
	if (!QueueByTwoStackEmpty(&qs))
	{
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ�ǿ�\n");
	}
	tmp = QueueByTwoStackSize(&qs);
	printf("ջ��Ԫ�ظ�����%d\n", tmp);
	QueueByTwoStackDestory(&qs);
}

