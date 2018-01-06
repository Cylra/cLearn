#include "list.h"
using namespace std;

int main()
{
    LinkList La, Lb, Lc;
    Init_LinkList(La);
    Create_LinkList2(La);
    Print_LinkList(La);
    Init_LinkList(Lb);
    Create_LinkList2(Lb);
    Print_LinkList(Lb);
    //cout << "顺序表的长度为:" << Length_LinkList(L) << endl;
    //Insert_LinkList(L, 100);
    //Print_LinkList(L);
    //Delete_LinkList(L, 2);
    //Print_LinkList(L);
    //reverse(L);
    //Print_LinkList(L);
    //Del_L(La,2,6);
    //Print_LinkList(La);
    Lc = MergeList(La, Lb);
    Print_LinkList(Lc);
    return 0;
}