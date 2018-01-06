#include "stack.h"
using namespace std;

int main()
{
    LinkStack top;
    InitStack(top);
    Push(top, 100);
    Push(top, 99);
    Push(top, 98);
    Elemtype e;
    Pop(top, &e);
    cout<<"出栈的数据为:" <<e<<endl;
    return 0;
}