#ifndef QUEUE_H
#define QUEUE_H

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
typedef int Elemtype;

typedef struct Node{
    Elemtype data;
    struct Node *next;
}QueueNode;  //节点类型
typedef struct{
    QueueNode *front; //队头
    QueueNode *rear;  //队尾
}LinkQueue;  //链队列

//初始化,带头结点
int InitQueue(LinkQueue &Q)
{
    memset(&Q, 0, sizeof(LinkQueue));
    Q.front = new QueueNode;
    Q.front->next = NULL;
    Q.rear = Q.front;
    return OK;
}

//判队空
int QueueEmpty(LinkQueue &Q)
{
    return (Q.front == Q.rear ? TRUE: FALSE);
}

//入队
int En_Queue(LinkQueue &Q, Elemtype e)
{
    QueueNode *s = new QueueNode;
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return OK;
}

//出队
//注意:队列中只有1个元素时,唯一的元素出列后,队列为空,需要修改rear的值
int De_Queue(LinkQueue &Q, Elemtype *e)
{
    if(QueueEmpty(Q))
    {
        cout << "队列为空,无法出队!\n";
        return ERROR;
    }
    QueueNode *p;
    p = Q.front->next;
    *e = p->data;
    Q.front->next = p->next;
    delete p;
    if(Q.front->next == NULL)
        Q.rear = Q.front;
    return OK;
}

int Len_Queue(LinkQueue &Q)
{
    int len = 0;
    QueueNode *p = Q.front->next;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}
#endif