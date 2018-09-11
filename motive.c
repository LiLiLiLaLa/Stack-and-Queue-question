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
	//使em为空队，noem为非空队
	EmptyCmp(&em, &noem, &stq);
	//把非空中的元素除了最后一个全部出队列存入空队列
	while (QueueSize(noem) > 1)
	{
		QueuePush(em, QueueFront(noem));
		QueuePop(noem);
	}
	//获取最后一个元素存入tmp
	tmp = QueueFront(noem);
	//把最后一个元素也出队存入另一个队列
	QueuePop(noem);
	QueuePush(em, tmp);
	//返回tmp
	return tmp;
}

int StackByTwoQueueEmpty(const StackByTwoQueue* stq)
{
	return QueueEmpty(&(stq->q1)) | QueueEmpty(&(stq->q2));//判空
}

int StackByTwoQueueSize(const StackByTwoQueue* stq)
{
	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));//两个栈里元素个数之和
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{

	Queue *em;
	Queue *noem;
	EmptyCmp(&em, &noem, &stq);
	QueuePush(noem, x);//只往有元素的栈里加入新数据
}

void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue *em;
	Queue *noem;
	EmptyCmp(&em, &noem, &stq);

	//与StackByTwoQueueTop()一样的过程，只是最后余下的元素直接出队列
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
	printf("栈顶的元素是：%d\n", tmp);
	StackByTwoQueuePop(&sq);
	tmp = StackByTwoQueueTop(&sq);
	printf("栈顶的元素是：%d\n", tmp);
	if (!StackByTwoQueueEmpty(&sq))
	{
		printf("空\n");
	}
	else
	{
		printf("非空\n");
	}
	tmp = StackByTwoQueueSize(&sq);
	printf("元素个数：%d\n", tmp);
	StackByTwoQueueDestory(&sq);
}
