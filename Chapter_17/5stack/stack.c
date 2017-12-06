#include <stdio.h>
#include "stack.h"

//初始化栈
void InitializeStack(Stack * ps)
{
    ps->items = 0;
}

//确定栈为空
int StackIsEmpty(const Stack * ps)
{
    return (ps->items == 0) ? 1 : 0;
}

//确定栈为满
int StackIsFull(const Stack * ps)
{
    return (ps->items == SMAX) ? 1 : 0;
}

//统计栈内项数
int StackItemCount(const Stack * ps)
{
    return ps->items;
}

//从栈顶压入项
int AddItem(Stack * ps, Item item)
{
    if (StackIsFull(ps))
        return 0;
    else
    {
        ps->item[ps->items] = item;
        ps->items++;
        return 1;
    }
}

//从栈顶弹出项
int DelItem(Stack * ps, Item * pitem)
{
    if (StackIsEmpty(ps))
        return 0;
    else
    {
        * pitem = ps->item[ps->items - 1];
        ps->item[ps->items - 1] = '\0';
        ps->items--;
        return 1;
    }
}
