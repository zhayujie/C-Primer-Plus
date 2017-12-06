#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "word.h"

//局域数据类型
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

//局域函数声明
static Pair SeekItem(const Tree * ptree, Item * pi);
static int ToLeft(Item * p1, Item * p2);
static int ToRight(Item * p1, Item * p2);
static Trnode * MakeNode(Item * item);
static void AddNode(Trnode * new_node, Trnode * root);
static void DeleteNode(Trnode * * ptr);
static void InOrder(Trnode * root, void (*pfun)(Item item));
static void DeleteAllNodes(Trnode * root);

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
    if (ptree->size == MAX)
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
    return ptree->size;
}

//查找项
int InTree(const Tree * ptree, const Item * pi)
{
    Pair look;
    look = SeekItem(ptree, pi);

    if (look.child != NULL)
        return 1;
    else
        return 0;
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

//每一项计数
int ItemCount(const Tree * ptree, const Item * item)
{
    Pair look;

    look = SeekItem(ptree, item);
    if (look.child == NULL)
        return 0;
    else
        return look.child->item.num;
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
    if (strcmp(p1->word, p2->word) < 0)
        return 1;
    else
        return 0;
}

//项在右边
static int ToRight(Item * p1, Item * p2)
{
    if (strcmp(p1->word, p2->word) > 0)
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

