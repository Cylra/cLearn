#include "../stack.h"
using namespace std;

//将非负10进制证书N转换为r进制数
void conversion(int N, int r)
{
    SqStack s;
    InitStack(&s);
    while(N)
    {
        Push(&s, N%r); //余数入栈
        N = N/r;
    }
    Elemtype e;
    while(!StackEmpty(&s))
    {
        Pop(&s, &e);
        cout<< e;
    }
    cout <<endl;
}

int main()
{
    conversion(1348, 8);
    return 0;
}