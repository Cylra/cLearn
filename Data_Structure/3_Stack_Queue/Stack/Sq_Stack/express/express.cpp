/*使用char栈实现
简单表达式求值
*/
#include "express.h"
using namespace std;

const int LT = -1;
const int EQ = 0;
const int GT = 1;
/*判断运算符的优先级别,in<out,返回-1,入栈
in = out,返回0,出栈
in > out,返回1,出栈
*/
int Judge(Elemtype in,Elemtype out)
{
    //此处算法从简,只判断测试表达式用到的操作符
    if(in == '#')
    {
        if(out == '+' || out == '-' || out == '*' || out == '/' ||out == '(')
            return LT;
        else if(out == '#')
            return EQ;
    }
    if(in == '+' || in == '-')
    {
        if(out == '*' || out == '/'||out == '(')
            return LT;
        else if(out == ')')
            return GT;
    }
    if(in == '*' || in == '/')
    {
        if(out == '(')
            return LT;
        else
            return GT;
    }
    if(in == '(')
    {
        if(out =='+'||out =='-'||out =='*'||out =='/'||out =='(')
            return LT;
        else if(out ==')')
            return EQ;
    }
    if(in == ')')
    {
        if(out =='+'||out =='-'||out =='*'||out =='/'||out==')'||out=='#')
            return GT;
    }
}

int Cal(int op1, int op2, Elemtype op_symbol)
{
    switch(op_symbol)
    {
        case('+'):
            return op1+op2;
            break;
        case('-'):
            return op1-op2;
            break;
        case('*'):
            return op1*op2;
            break;
        case('/'):
            return op1/op2;
            break;
    }
}

//传递运算表达式和长度
int evaluation(char* expression, int len)
{
    SqStack opnd; //操作数0-9
    SqStack optr; //运算符+-*/()
    InitStack(&opnd);
    InitStack(&optr);
    Push(&optr, '#');  //压入#
    Elemtype ch_out;  //读取表达式字符串的字符
    Elemtype ch_in; //栈顶元素
    int value;   //存储表达式运算的结果
    int i;

    char ret;
    for(i=0; i<len; i++)
    {
        ch_out = expression[i];
        if('0' <= ch_out <= '9')
        {
            Push(&opnd, ch_out); //入栈
        }
        else //在此,默认输入的运算符都是正确的,不进行判错处理
        {
            GetTop(&optr, &ch_in);
            int res = Judge(ch_in, ch_out);
            if(res == LT)
            {
                Push(&optr, ch_out);
            }
            else if(res == GT)
            {
                cout << "呵呵" <<endl;
                Pop(&optr, &ch_in);
                char tmp_ch1,tmp_ch2; //接收2个操作数
                Pop(&opnd, &tmp_ch1);
                Pop(&opnd, &tmp_ch2);
                cout << "计算:" << tmp_ch1 << ch_in << tmp_ch2<<endl;
                Push(&opnd, Cal(tmp_ch1-'0', tmp_ch2-'0', ch_in));
            }
            else if(res == EQ)
            {
                if(ch_in == '#' && ch_out == '#')
                GetTop(&opnd, &ret);
                return (ret-'0');
            }
        }
    }
}

int main()
{
    int result = evaluation("4+2*(7-3)#", 10);
    cout << "运算结果是: " << result << endl;
    return 0;
}
