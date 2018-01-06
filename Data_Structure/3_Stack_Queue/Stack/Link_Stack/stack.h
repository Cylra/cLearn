#ifndef STACK_H
#define STACK_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXSIZE = 100;
const int TRUE = 1;
const int FALSE = 0;
const int OK = 0;
const int ERROR = -1;
typedef int Elemtype;

typedef struct node
{
    Elemtype data;
    struct node *next;
}StackNode, *LinkStack;

/* 将单链表表头作为栈顶
*/
void InitStack(LinkStack &top)
{
    top = NULL;
}

//判栈空
int StackEmpty(LinkStack top)
{
    return (top == NULL ? TRUE : FALSE);
}

//进栈
void Push(LinkStack &top, Elemtype e)
{
    StackNode *p = new StackNode;
    p->data = e;
    p->next = top;
    top = p;
}

//出栈
int Pop(LinkStack &top, Elemtype *e)
{
    if(StackEmpty(top))
    {
        cout << "栈空,无法出栈" <<endl;
        return ERROR;
    }
    *e = top->data;
    StackNode *p = top;
    top = top->next;
    delete p;
    return OK;
}

#endif