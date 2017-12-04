#ifndef MOVIE_H_
#define MOVIE_H_

#define TSIZE 45
#define MAXSIZE 5

typedef struct film {
	char titile[TSIZE];
	int rating;
} Item;

typedef struct list {
	Item entries[MAXSIZE];
	int items;
} List;

//初始化链表为空
void InitializeList(List * plist);

//链表为空,返回1
int ListIsEmpty(const List * plist);

//链表为满，返回1
int ListIsFull(const List * plist);

//为链表添加项，成功返回1
int AddItem(List * plist, Item item);

//确定链表的项数
unsigned int ListItemCount(List * plist);

//遍历链表
void Traverse(const List * plist, void (*pfun)(Item item));

//清空链表
void DeleteAll(List * plist);

#endif