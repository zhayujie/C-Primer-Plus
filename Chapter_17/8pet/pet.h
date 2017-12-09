#ifndef WORD_H_
#define WORD_H_

#define MAX 10
#define LEN 40
#define SIZE 100

typedef struct item {
	char name[LEN];
	char kind[MAX][LEN];
	int num;
} Item;

typedef struct trnode {
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree {
	Trnode * root;
	int size;
} Tree;

//初始化树
void InitializeTree(Tree * ptree);

//确认树为满
int TreeIsFull(const Tree * ptree);

//确认树为空
int TreeIsEmpty(const Tree * ptree);

//统计项数
int TreeItemCount(const Tree * ptree);

//查找项
void FindItem(const Tree * ptree, const Item * item);

//添加项
int AddItem(Tree * ptree, const Item * pi);

//删除项
int DelItem(Tree * ptree, const Item * pi);

//遍历树
void Traverse(const Tree * ptree, void (*pfun)(Item item));

//清空树
void DeleteAll(Tree * ptree);

#endif