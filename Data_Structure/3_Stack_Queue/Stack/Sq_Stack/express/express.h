#ifndef EXPRESS_H
#define EXPRESS_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXSIZE = 100;
const int TRUE = 1;
const int FALSE = 0;
const int OK = 1;
const int ERROR = 0;
typedef char Elemtype;

typedef struct{
    Elemtype data[MAXSIZE];
    int top;  //当前栈顶的位置
}SqStack;

//初始化
int InitStack(SqStack *s) //传指针省空间
{
    memset(s, 0, sizeof(SqStack));
    s->top = -1;
    return OK;
}

//判栈空
int StackEmpty(SqStack *s)
{
    return (s->top == -1 ? TRUE : FALSE);
}

//判栈满
int StackFull(SqStack *s)
{
    return (s->top == MAXSIZE-1 ? TRUE: FALSE);
}

//进栈
int Push(SqStack *s, Elemtype e)
{
    if(StackFull(s))
    {
        cout <<"栈满,无法入栈" <<endl;
        return ERROR;
    }
    s->top++; //top加1,栈顶位置上移
    s->data[s->top] = e;
    return OK;
}

int Pop(SqStack *s, Elemtype *e)
{
    if(StackEmpty(s))
    {
        cout <<"栈空,无法出栈" <<endl;
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;   //top减1,栈顶位置下移
    return OK;
}

//取栈顶元素
int GetTop(SqStack *s, Elemtype *e)
{
    if(StackEmpty(s))
        return ERROR;
    *e = s->data[s->top];  //取出数据,top值不变
    return OK;
}
#endif