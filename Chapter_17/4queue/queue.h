#ifndef QUEUE_H_
#define QUEUE_H_

#define MAXSIZE 10

typedef struct item {
	long arrive;
	int processtime;
} Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct queue {
	Node * head;
	Node * end;
	int items;
} Queue;

//初始化队列
void InitializeQueue(Queue * pq);

//确定队列为空
int QueueIsEmpty(const Queue * pq);

//确定队列为满
int QueueIsFull(const Queue * pq);

//确定队列项数
unsigned int QueueItemCount(const Queue * pq);

//给队列末尾添加项
int EnQueue(Queue * pq, Item item);

//从队列开头删除项
int DeQueue(Queue * pq, Item * pitem);

//清空队列
void DeleteAll(Queue * pq);

#endif