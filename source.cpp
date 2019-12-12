#include "Function.h"

void getChoice(void)
{
    int choose;
    BSTree T;
    int arr[15] = {19, 38, 12, 40, 41, 39, 54, 76, 35, 47, 80, 14, 9, 44, 60};
    ElemType e;

    do
    {
        msg();
        cin >> choose;
        switch (choose)
        {
        case 1:
            Create_BST(T, arr, 15);
            cout << "\nCreate Finished." << endl;
            break;

        case 2:
            BST_Delete(T, BST_Search(T, e));
            cout << "\nDelete Finished." << endl;
            break;

        case 3:
            inOderTraversal(T);
            cout << "\nTraversal Finished." << endl;
            break;

        case 9:
            
        case 0:
            exit(1);
        }

    } while (choose != 0);
}

int main(int argc, char const *argv[])
{
    getChoice();
    return 0;
}
