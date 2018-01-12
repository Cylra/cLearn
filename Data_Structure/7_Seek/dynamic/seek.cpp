#include "seek.h"
using namespace std;


int main()
{
    BiTree BT;
    ElemType e;
    int i;
    for(i=0; i<11; i++)
    {
        cout << "请输入一个整数:" << endl;
        cin >> e.key;
        e.info = '#';
        BST_Insert(BT, e);
    }
    return 0;
}