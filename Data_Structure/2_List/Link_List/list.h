#ifndef LIST_H
#define LIST_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int FALSE = 0;
const int flag = -1;
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
}LNode, *LinkList;

//初始化
void Init_LinkList(LinkList &L)
{
    L = new LNode;
    memset(L, 0, sizeof(LNode));
    L->next = NULL;
}

//头插法
void Create_LinkList1(LinkList &L)
{
    cout << "使用头插法" <<endl;
    LNode *s;
    DataType x;
    cout << "输入一个整数,-1作为结束符" <<endl;
    cin >> x;
    while(x != flag)
    {
        s = new LNode;
        s->data = x;
        s->next = L->next; //注意
        L->next = s;
        cout << "输入一个整数,-1作为结束符" <<endl;
        cin >> x;        
    }
}

//尾插法
void Create_LinkList2(LinkList &L)
{
    cout << "使用尾插法" <<endl;
    LNode *s, *r; //r为尾指针
    DataType x;
    cout << "输入一个整数,-1作为结束符" <<endl;
    cin >> x;
    r = L;
    while(x != flag)
    {
        s = new LNode;
        s->data = x;
        s->next = NULL; //注意
        r->next = s;
        r = s;
        cout << "输入一个整数,-1作为结束符" <<endl;
        cin >> x;        
    }
    r->next = NULL;
}

//打印
void Print_LinkList(LinkList L)
{
    LNode *Head = L->next;
    while(Head != NULL)
    {
        cout << Head->data << '\t';
        Head = Head->next;
    }
    cout << endl;
}

//查找第i个位置,没有则返回NULL
LNode *Get_LinkList1(LinkList L, int i)
{
    LNode *p = L;
    int j = 0; //具有头结点
    while(p !=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按照数值查找
LNode *Get_LinkList2(LinkList L, DataType x)
{
    LNode *p = L->next;
    while(p !=NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}

//将值x插入到第i个位置,默认从头插
void Insert_LinkList(LinkList &L, DataType x, int i=1)
{
    LNode *p = Get_LinkList1(L, i-1);//查找第i-1个位置
    LNode *s;
    if(p == NULL)
    {
        cout << "插入位置不合法!\n";
        exit(1);
    }
    else
    {
        s = new LNode;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

//删除第i个位置的节点,默认从头删
void Delete_LinkList(LinkList &L, int i=1)
{
    LNode *p = Get_LinkList1(L, i-1);
    LNode *q;
    if(p == NULL) //第i-1个位置不存在,不能执行删除
    {
        cout << "删除位置不合法!\n";
        exit(1);
    }
    else
    {
        if(p->next == NULL) //第i个位置不存在,不能执行删除
        {
            cout << "删除位置不合法!\n";
            exit(1);
        }
        else
        {
            q = p->next;
            p->next = q->next;
            delete q;
        }
    }
}

//获取表长
int Length_LinkList(LinkList L)
{
    int len =0;
    LNode *p = L->next;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}


/*--------------------------------
         单链表的一些算法
--------------------------------*/
//将链表倒置
void reverse(LinkList &L)
{
    LNode *p, *q;
    p = L->next;
    L->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        //头插法
        q->next = L->next;
        L->next = q;
    }
}

/*单调递增单链表,从表中去除
值大于min,小于max的数据节点
*/
void Del_L(LinkList &L, int min, int max)
{
    LNode *ptr, *qtr;
    LNode *s;
    ptr = L->next;
    while( (ptr !=NULL) && (ptr->data <= min))
    {
        qtr = ptr; //需要记录前驱节点
        ptr = ptr->next;
    }
    while( (ptr != NULL) && (ptr->data < max))
    {
        s = ptr;
        ptr = ptr->next;
        delete s;
    }
    qtr->next = ptr;
}

//将2个有序递增链表合并成1个
LNode *MergeList(LinkList &La, LinkList &Lb)
{
    LNode *Lc; //头结点
    LNode *p,*q;
    LNode *r;  //r指向Lc链表的尾节点
    p = La->next;
    q = Lb->next;
    Lc = La; //用La的头结点作为Lc的头结点
    r = La;
    while(p && q)
    {
        if(p->data <= q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    if(p)
        r->next = p;
    else
        r->next = q;
    
    delete Lb; //删除Lb的头节点
    return Lc;
}

#endif