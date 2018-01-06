#include "stack.h"
using namespace std;

int main()
{
    SqStack s;
    InitStack(&s);
    Push(&s, 100);
    Push(&s, 99);
    Push(&s, 98);
    Elemtype e;
    Pop(&s, &e);
    cout <<"出栈数据为:" << e <<endl;
    return 0;
}