#ifndef STACK_H_
#define STACK_H_

#define SMAX 100

typedef char Item;
typedef struct stack {
	Item item[SMAX];
	int items;
} Stack;

//初始化栈
void InitializeStack(Stack * ps);

//确定栈为空
int StackIsEmpty(const Stack * ps);

//确定栈为满
int StackIsFull(const Stack * ps);

//统计栈内项数
int StackItemCount(const Stack * ps);

//从栈顶压入项
int AddItem(Stack * ps, Item item);

//从栈顶弹出项
int DelItem(Stack * ps, Item * pitem);

//清空项
void EmptyItem(Stack * ps);

#endif