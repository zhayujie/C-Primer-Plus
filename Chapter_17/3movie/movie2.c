#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie2.h"

//初始化链表为空
void InitializeList(List * plist)
{
    int i;

    for (i = 0; i < MAXSIZE; i++)
    {
        strcpy((plist->entries[i]).titile, "");
        (plist->entries[i]).rating = 0;
        plist->items = 0;
    }
}

//链表为空,返回1
int ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return 1;
    else
        return 0;
}

//链表为满，返回1
int ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return 1;
    else
        return 0;
}

//为链表添加项，成功返回1
int AddItem(List * plist, Item item)
{
    if (plist->items == MAXSIZE)
    {
        fprintf(stderr, "The list is full.\n");
        return 0;
    }

    plist->entries[plist->items] = item;
    (plist->items)++;

    return 1;
}

//确定链表的项数
unsigned int ListItemCount(List * plist)
{
    return plist->items;
}

//遍历链表
void Traverse(const List * plist, void (*pfun)(Item item))
{
    int i;
    
    for (i = 0; i < plist->items; i++)
    {
        (*pfun)(plist->entries[i]);
    }
}

//清空链表
void DeleteAll(List * plist)
{
    int i;

    for (i = 0; i < plist->items; i++)
    {
        strcpy((plist->entries[i]).titile, "");
        (plist->entries[i]).rating = 0;
        plist->items = 0;
    }
    
}
