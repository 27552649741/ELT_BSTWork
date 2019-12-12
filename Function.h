#include "Headerfile.h"
// ------------------------------------
// 菜单
// ------------------------------------
void msg(void)
{
    cout << "-------------------------Menu-------------------------\n"
         << "*       1.Create a BSTree.                           *\n"
         << "*       2.Delete a Elem.                             *\n"
         << "*       3.inOderTraversal the BSTree.                *\n"
         << "*       9.Destroy the BSTree.                        *\n"
         << "*       0.Exit.                                      *\n"
         << "-------------------------Menu-------------------------\n"
         << "Enter the function you want to choose(0-9):";
} // msg

// ------------------------------------
// 为二叉排序树插入数据
// ------------------------------------
int BST_Insert(BSTree &T, int k)
{
    if(T == NULL)
    {
        BSTree T = new BSTNode;
        T->data = k;
        T->Lchild = NULL;
        T->Rchild = NULL;
        return OK;
    }
    else if(k == T->data)
        return FALSE;
    else if(k < T->data)
        return BST_Insert(T->Lchild, k);
    else
        return BST_Insert(T->Rchild, k);
} // BST_Insert

// ------------------------------------
// 创建二叉排序树
// ------------------------------------
void Create_BST(BSTree &T, int arr[], int n)
{
    T = NULL; // 初始时为空树
    for (int i = 0; i < n; ++i)
        BST_Insert(T, arr[i]);
} // Create_BST

// ------------------------------------
// 递归查找：返回指向包含关键字k的结点的指针
// ------------------------------------

BSTNode *BST_Search(BSTree T, int k)
{
    if (T == NULL || k == T->data)
        return T;
    if (k < T->data)
        return BST_Search(T->Lchild, k);
    else
        return BST_Search(T->Rchild, k);
} // BST_Search

// ------------------------------------
// 查询最小值与最大值
// ------------------------------------
BSTNode *BST_Minimum(BSTree T)
{
    while (T->Lchild != NULL)
        T = T->Lchild;
    return T;
} // BST_Minimum

BSTNode *BST_Maximum(BSTree T)
{
    while (T->Rchild != NULL)
        T = T->Rchild;
    return T;
} // BST_Maximum

// ------------------------------------
// 后继：查找给定结点在中序遍历中的后继结点
// ------------------------------------
BSTNode *BST_Successor(BSTNode *node)
{
    if (node->Rchild != NULL)
        return BST_Minimum(node->Rchild);
    BSTNode *p = node->parent;
    while (p != NULL && p->Rchild == node)
    {
        node = p;
        p = p->parent;
    }
    return p;
} // BST_Successor

// ------------------------------------
// 删除结点
// ------------------------------------
void BST_Delete(BSTree &T, BSTNode *z)
{
    if (z->Lchild == NULL && z->Rchild == NULL)
    {
        if (z->parent != NULL)
        {
            if (z->parent->Lchild == z)
                z->parent->Lchild = NULL;
            else
                z->parent->Rchild = NULL;
        }
        else
        {
            T = NULL; // 只剩一个结点的情况
        }
        free(z);
    }
    else if (z->Lchild != NULL && z->Rchild == NULL)
    {
        z->Lchild->parent = z->parent;
        if (z->parent != NULL)
        {
            if (z->parent->Lchild == z)
                z->parent->Lchild = z->Lchild;
            else
                z->parent->Rchild = z->Lchild;
        }
        else
        {
            T = z->Lchild; // 删除左斜单支树的根结点
        }
        free(z);
    }
    else if (z->Lchild == NULL && z->Rchild != NULL)
    {
        z->Rchild->parent = z->parent;
        if (z->parent != NULL)
        {
            if (z->parent->Lchild == z)
                z->parent->Lchild = z->Rchild;
            else
                z->parent->Rchild = z->Rchild;
        }
        else
        {
            T = z->Rchild; // 删除右斜单支树的根结点
        }
        free(z);
    }
    else
    {
        BSTNode *s = BST_Successor(z);
        z->data = s->data; // s的关键字替换z的关键字
        BST_Delete(T, s);  // 转换为第一或第二种情况
    }
} //BST_Delete

// ------------------------------------
// 中序递归遍历二叉树
// ------------------------------------
void inOderTraversal(BSTree T)
{
    // 中序遍历链二叉树（递归法）
    if (T != NULL)
    {
        inOderTraversal(T->Lchild);
        cout << setw(4) << T->data;
        inOderTraversal(T->Rchild);
    }
} //inOrderTraversalBiTreeR

// ------------------------------------
// 销毁二叉树
// ------------------------------------
// 采用后序遍历法
void TreeNodeDestroy(BSTree &T)
{
    if (T == NULL)
        return;
    delete T;
} // TreeNodeDestroy

void TreeDestroy(BSTree &T)
{
    if (T == NULL)
        return;
    TreeDestroy(T->Lchild);
    TreeDestroy(T->Rchild);
    TreeNodeDestroy(T);
} // TreeDestroy