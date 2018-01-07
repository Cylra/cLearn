/*
括号匹配的检验,使用char栈实现
*/
#include "match.h"
using namespace std;

int bracketmatching()
{
    SqStack s;
    InitStack(&s);
    Elemtype ch;

    cout <<"输入括号:" <<endl;
    cin >> ch;
    while(ch != '\n')
    {
        switch(ch)
        {
        case '(':
        case '[':
        case '{':
            Push(&s, ch);
            break;
        //当遇到右括号时,栈空,错误
        //当栈弹出的左括号与检验的右括号不匹配,错误
        case ')':
            if(StackEmpty(&s))
                return FALSE;
            else
            {
                Pop(&s, &ch);
                if(ch != '(')
                    return FALSE;
            }
            break;
        case ']':
            if(StackEmpty(&s))
                return FALSE;
            else
            {
                Pop(&s, &ch);
                if(ch != '[')
                    return FALSE;
            }
            break;
        case '}':
            if(StackEmpty(&s))
                return FALSE;
            else
            {
                Pop(&s, &ch);
                if(ch != '{')
                    return FALSE;
            }
            break;
        default:
            break;
        }
        cout <<"输入括号:" <<endl;
        cin >> ch;
    }
    //当停止输入后,栈不空(还有待匹配的左括号),错误
    if(StackEmpty(&s))
        return TRUE;
    else
        return FALSE;
}

int main()
{
    int ret = bracketmatching();
    if(ret)
        cout <<"括号匹配成功!" <<endl;
    else
        cout <<"括号匹配失败!" <<endl;
    return 0;
}