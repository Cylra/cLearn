#include "tree.h"

using namespace std;

int main()
{
    BiTree BT;
    cout << "建立二叉树,输入字符,以#表示虚节点" << endl;
    Create_BiTree(BT);
    cout << "先序遍历二叉树" << endl;
    PreOrder(BT);
    cout << endl;
    cout << "非递归先序遍历二叉树" << endl;
    PreOrder2(BT);
/*     cout << "中序遍历二叉树" << endl;
    InOrder(BT);
    cout << endl;
    cout << "后序遍历二叉树" << endl;
    PostOrder(BT);
    cout << endl; */

    cout << "层次遍历二叉树" << endl;
    LevelOrder(BT);
    return 0;
}
