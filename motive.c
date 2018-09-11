#include "motive.h"

void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&(stq->q1));
	QueueInit(&(stq->q2));
}

void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&(stq->q1));
	QueueDestory(&(stq->q2));
}

static  void EmptyCmp(Queue** em, Queue** noem, StackByTwoQueue** pstq)
{
	QueueEmpty(&(*pstq)->q1) == 1 ? ((*noem = &(*pstq)->q1), *em = &((*pstq)->q2)) : ((*noem = &(*pstq)->q2), *em = &((*pstq)->q1));
}

DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue* em;
	Queue* noem;
	DataType tmp = 0;
	//ʹemΪ�նӣ�noemΪ�ǿն�
	EmptyCmp(&em, &noem, &stq);
	//�ѷǿ��е�Ԫ�س������һ��ȫ�������д���ն���
	while (QueueSize(noem) > 1)
	{
		QueuePush(em, QueueFront(noem));
		QueuePop(noem);
	}
	//��ȡ���һ��Ԫ�ش���tmp
	tmp = QueueFront(noem);
	//�����һ��Ԫ��Ҳ���Ӵ�����һ������
	QueuePop(noem);
	QueuePush(em, tmp);
	//����tmp
	return tmp;
}

int StackByTwoQueueEmpty(const StackByTwoQueue* stq)
{
	return QueueEmpty(&(stq->q1)) | QueueEmpty(&(stq->q2));//�п�
}

int StackByTwoQueueSize(const StackByTwoQueue* stq)
{
	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));//����ջ��Ԫ�ظ���֮��
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{

	Queue *em;
	Queue *noem;
	EmptyCmp(&em, &noem, &stq);
	QueuePush(noem, x);//ֻ����Ԫ�ص�ջ�����������
}

void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue *em;
	Queue *noem;
	EmptyCmp(&em, &noem, &stq);

	//��StackByTwoQueueTop()һ���Ĺ��̣�ֻ��������µ�Ԫ��ֱ�ӳ�����
	while (QueueSize(noem) > 1)
	{
		QueuePush(em, QueueFront(noem));
		QueuePop(noem);
	}
	printf("Pop:%d\n", noem->_front->_data);
	QueuePop(noem);
}

void TestStackByTwoQueue()
{
	StackByTwoQueue sq;
	DataType tmp = 0;
	StackByTwoQueueInit(&sq);
	StackByTwoQueuePush(&sq, 11);
	StackByTwoQueuePush(&sq, 12);
	StackByTwoQueuePush(&sq, 13);
	StackByTwoQueuePush(&sq, 14);
	tmp = StackByTwoQueueTop(&sq);
	printf("ջ����Ԫ���ǣ�%d\n", tmp);
	StackByTwoQueuePop(&sq);
	tmp = StackByTwoQueueTop(&sq);
	printf("ջ����Ԫ���ǣ�%d\n", tmp);
	if (!StackByTwoQueueEmpty(&sq))
	{
		printf("��\n");
	}
	else
	{
		printf("�ǿ�\n");
	}
	tmp = StackByTwoQueueSize(&sq);
	printf("Ԫ�ظ�����%d\n", tmp);
	StackByTwoQueueDestory(&sq);
}
