#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void AddItem(Node * pq, Item item);
static void CopyItem(Node * pnode, Item * pitem);

//接口函数

//初始化队列
void InitializeQueue(Queue * pq)
{
    pq->head = NULL;
    pq->end = NULL;
    pq->items = 0;
}

//确定队列为空
int QueueIsEmpty(const Queue * pq)
{
    if (pq->items == 0)
        return 1;
    else
        return 0;
}

//确定队列为满
int QueueIsFull(const Queue * pq)
{
    if (pq->items == MAXSIZE)
        return 1;
    else
        return 0;
}

//确定队列项数
unsigned int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

//给队列末尾添加项
int EnQueue(Queue * pq, Item item)
{
    Node * pnode;

    if (QueueIsFull(pq))
    {
        fprintf(stderr, "The queue is full.\n");
        return 0;
    }

    pnode = (Node *) malloc(sizeof(Node));
    if (pnode == NULL)
    {
        fprintf(stderr, "Can't alloc memory.\n");
        return 0;
    }
    
    AddItem(pnode, item);
    pnode->next = NULL;
    pq->items++;
    if (pq->head == NULL)
    {
        pq->head = pnode;
    }
    else
        pq->end->next = pnode;
    pq->end = pnode;

    return 1;
}

//从队列开头删除项
int DeQueue(Queue * pq, Item * pitem)
{
    Node * pnode;

    if (QueueIsEmpty(pq))
    {
        fprintf(stderr, "the queue is empty.\n");
        return 0;
    }
    
    CopyItem(pq->head, pitem);
    pnode = pq->head;
    pq->head = pq->head->next;
    free(pnode);
    pq->items--;

    if (pq->items == 0)
        pq->end = NULL;

    return 1;
}

//清空队列
void DeleteAll(Queue * pq)
{
    Item item;

    while (!QueueIsEmpty(pq))
        DeQueue(pq, &item);
}

//局域函数
static void AddItem(Node * pnode, Item item)
{
    pnode->item = item;
}

static void CopyItem(Node * pnode, Item * pitem)
{
    *pitem = pnode->item;
}
