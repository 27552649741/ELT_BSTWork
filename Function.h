#include "Headerfile.h"
void msg(void)
{
    cout << "-------------------------Menu-------------------------\n"
         << "*       1.Create a BSTree.                           *\n"
         << "*       2.Insert a Elem.                             *\n"
         << "*       3.Delete a Elem.                             *\n"
         << "*       4.inOderTraversal the BSTree.                *\n"
         << "*       9.Destroy the BSTree.                        *\n"
         << "*       0.Exit.                                      *\n"
         << "-------------------------Menu-------------------------\n"
         << "Enter the function you want to choose(0-9):";
} // msg

bool BST_Insert(BSTree &T, ElemType k)
{
    if(T == NULL)
    {
        BSTree T = new BSTNode;
        T->data = k;
        T->Lchild = NULL;
        T->Rchild= NULL;
        return 1;  // 返回1表示成功
    }
    else if(k == T->data)
        return 0;  // 树中存在相同关键字
    else if(k < T->data)
        return BST_Insert(T, k);
    else
        return BST_Insert(T, k);
}

