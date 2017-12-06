#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

//初始化链表为空
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

//链表为空,返回1
int ListIsEmpty(const List * plist)
{
    if (plist->head == NULL)
        return 1;
    else
        return 0;
}

//链表为满，返回1
int ListIsFull(const List * plist)
{
    Node * pt;
    int full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = 1;
    else
        full = 0;
    free(pt);

    return full;
}

//为链表添加项，成功返回1
int AddItem(List * plist, Item item)
{
    Node * pnew;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return 0;
    
    pnew->next = NULL;
    pnew->item = item;
    
    if (plist->head == NULL)
        plist->head = pnew;
    else
        plist->end->next = pnew;
    plist->end = pnew;
    
    return 1;
}

//确定链表的项数
unsigned int ListItemCount(List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        pnode = pnode->next;
        count++;
    }

    return count;
}

//遍历链表
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

//清空链表
void DeleteAll(List * plist)
{
    Node * pnode;

    while (plist->head != NULL)
    {
        pnode = plist->head;
        plist->head = plist->head->next;
        free(pnode);
    }
}
