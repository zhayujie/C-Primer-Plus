#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pet.h"

//局域数据类型
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

//内部链接，文件作用域
static int count = 0;

//局域函数声明
static Pair SeekItem(const Tree * ptree, Item * pi);
static int ToLeft(Item * p1, Item * p2);
static int ToRight(Item * p1, Item * p2);
static Trnode * MakeNode(Item * item);
static void AddNode(Trnode * new_node, Trnode * root);
static void DeleteNode(Trnode * * ptr);
static void InOrder(Trnode * root, void (*pfun)(Item item));
static void DeleteAllNodes(Trnode * root);
static void CountItem(Trnode * root);

//接口函数

//初始化树
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

//确认树为满
int TreeIsFull(const Tree * ptree)
{
    if (ptree->size == SIZE)
        return 1;
    else
        return 0;
}

//确认树为空
int TreeIsEmpty(const Tree * ptree)
{
    if (ptree->size == 0)
        return 1;
    else
        return 0;
}

//统计项数
int TreeItemCount(const Tree * ptree)
{
    count = 0;

    CountItem(ptree->root);

    return count;
}

//查找项
void FindItem(const Tree * ptree, const Item * pi)
{
    Pair look;
    int i;

    look = SeekItem(ptree, pi);
    if (look.child != NULL)
    {
        printf("name: %s\t\tkind: ", look.child->item.name);
        for (i = 0; i < look.child->item.num; i++)
            printf("%s ", look.child->item.kind[i]);
        printf("\n");
    }
    else
        printf("Can't find the pet.\n");

}
    
//添加项
int AddItem(Tree * ptree, const Item * pi)
{
    Pair look;
    Trnode * new_node;

    if (TreeIsFull(ptree))
        return 0;
    
    look = SeekItem(ptree, pi);
    if (look.child != NULL)
    {
        strcpy(look.child->item.kind[look.child->item.num], pi->kind[0]);
        (look.child->item.num)++;
        return 1;
    }
    else
    {
        new_node = MakeNode(pi);
        if (new_node == NULL)
        {
            fprintf(stderr, "Could't eate node\n");
            return 0;
        }
        ptree->size++;
        
        if (ptree->root == NULL)
            ptree->root = new_node;
        else
            AddNode(new_node, ptree->root);
    }
    
    return 1;
}

//删除项
int DelItem(Tree * ptree, const Item * pi)
{
    Pair look;
    
    look = SeekItem(ptree, pi);
    if (look.child == NULL)
        return 0;
    
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return 1;
}

//遍历树
void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

//清空树
void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

//局域函数
//寻找项
static Pair SeekItem(const Tree * ptree, const Item * pi)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    
    if (look.child == NULL)
        return look;

    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }

    return look;
}

//项在左边
static int ToLeft(Item * p1, Item * p2)
{
    if (strcmp(p1->name, p2->name) < 0)
        return 1;
    else
        return 0;
}

//项在右边
static int ToRight(Item * p1, Item * p2)
{
    if (strcmp(p1->name, p2->name) > 0)
        return 1;
    else
        return 0;
}

static Trnode * MakeNode(Item * item)
{
    Trnode * pnode;

    pnode = (Trnode *) malloc(sizeof(Trnode));
    if (pnode != NULL)
    {
        pnode->item = *item;
        pnode->left = NULL;
        pnode->right = NULL;
    }

    return pnode;
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&(new_node->item), &(root->item)))
    {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }

    else if (ToRight(&(new_node->item), &(root->item)))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }

    else
    {
        fprintf(stderr, "location error in AddNode().\n");
        exit(1);
    }
}

//ptr 是父节点指向目标节点的指针的地址
static void DeleteNode(Trnode * * ptr)
{
    Trnode * pnode;

    if ((*ptr)->left == NULL)
    {
        pnode = *ptr;
        *ptr = (*ptr)->right;
        free(pnode);
    }

    else if ((*ptr)->right == NULL)
    {
        pnode = *ptr;
        *ptr = (*ptr)->left;
        free(pnode);
    }

    else
    {
        for (pnode = (*ptr)->left; pnode->right != NULL; pnode = pnode->right)
            continue;
        pnode->right = (*ptr)->right;
        pnode = (*ptr);
        *ptr = (*ptr)->left;
        free(pnode);
    }
}

static void InOrder(Trnode * root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void CountItem(Trnode * root)
{
    if (root != NULL)
    {
        CountItem(root->left);
        count += root->item.num;
        CountItem(root->right);
    }
}
