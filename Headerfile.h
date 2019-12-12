#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// --------------------ECORE--------------------
#define ElemType int
#define MAXSIZE 100      // 暂定二叉树中结点个数的最大值为100
#define MAXSTACKSIZE 100 // 栈的最大值
#define MAXDATA 1000
// --------------------ECORE--------------------

// --------------------BiTree--------------------
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *Lchild;
    struct BSTNode *Rchild; // 左右孩子指针
    struct BSTNode *parent; // 双亲指针
} BSTNode, *BSTree;         // 二叉树的链式存储结构
// --------------------BiTree--------------------
