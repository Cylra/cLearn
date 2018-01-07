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
        else //20180107 更新优先级比较
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
    Elemtype ch_in; //栈顶运算符
    int value;   //存储表达式运算的结果
    int i=0;

    char ret;
    while(i<=len)  //修改循环判定
    {
        ch_out = expression[i];
        if('0' <= ch_out && ch_out<= '9')  //20180107更正 错误写法:'0' <= ch_out <= '9',此时if判定一直为真
        {
            Push(&opnd, ch_out); //入栈
            cout << "数字 [" << ch_out << "]入栈" << endl;
            i++;
        }
        else //在此,默认输入的运算符都是正确的,不进行判错处理
        {
            GetTop(&optr, &ch_in);
            cout << "栈内外操作符分别是: " << ch_in << "和" << ch_out <<endl;
            int res = Judge(ch_in, ch_out);
            if(res == LT)
            {
                cout << "运算符 [" << ch_out <<"]入栈" << endl;
                Push(&optr, ch_out);
                i++;
            }
            else if(res == GT)
            {
                //cout << "呵呵" <<endl;
                Pop(&optr, &ch_in);
                char tmp_ch1,tmp_ch2; //接收2个操作数
                Pop(&opnd, &tmp_ch2); //先出栈的是后面的操作数
                Pop(&opnd, &tmp_ch1);
                cout << "计算:" << tmp_ch1 << ch_in << tmp_ch2<<endl;
                int result = Cal(tmp_ch1-'0', tmp_ch2-'0', ch_in); //计算结果为整数,需要转换为char
                Push(&opnd, result+'0');
            }
            else if(res == EQ)
            {
                if(ch_in == '#' && ch_out == '#')
                {
                    //出栈
                    GetTop(&opnd, &ret);
                    return (ret-'0');
                }
                //'('和')'
                Pop(&optr, &ch_in); //直接出栈,不做计算
                i++;
            }
        }
    }
}

int main()
{
    int result = evaluation("4+2*(7-3)#", 10); //注意运算式以#结束
    cout << "运算结果是: " << result << endl;
    return 0;
}
