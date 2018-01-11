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

/*使用循环队列
队头front指向队头元素的前面一个位置
队尾rear指向队尾元素
*/
typedef struct{
    Elemtype data[MAXSIZE];
    int front, rear; //队头,队尾
}SqQueue;

//初始化
int InitQueue(SqQueue *q) //传指针省空间
{
    memset(q, 0, sizeof(SqQueue));
    q->front = -1;
    q->rear = -1;
    return OK;
}

/*循环队列队空与队满的判定
采用方法2,牺牲1个存储空间来区分
队空: rear == front
队满: (rear+1)%MAXSIZE == front
*/
//判队空
int QueueEmpty(SqQueue *q)
{
    return (q->rear == q->front ? TRUE : FALSE);
}
//判队满
int QueueFull(SqQueue *q)
{
    return ((q->rear+1)%MAXSIZE == q->front ? TRUE : FALSE);
}

//入队,rear=(rear+1)%MAXSIZE
int En_Queue(SqQueue *q, Elemtype e)
{
    if(QueueFull(q))
    {
        cout << "队列已满,无法入队!\n";
        return ERROR;
    }
    q->rear = (q->rear+1)%MAXSIZE;
    q->data[q->rear] = e;
    return OK;
}

//出队,front=(front+1)%MAXSIZE
int De_Queue(SqQueue *q, Elemtype *e)
{
    if(QueueEmpty(q))
    {
        cout << "队列为空,无法出队!\n";
        return ERROR;
    }
    q->front = (q->front+1)%MAXSIZE;
    *e = q->data[q->front];
    return OK;
}

//取队头
int QueueFront(SqQueue *q, Elemtype *e)
{
    if(QueueEmpty(q))
    {
        cout << "队列为空,取队头!\n";
        return ERROR;
    }
    *e = q->data[(q->front+1)%MAXSIZE]; //注意,front自身值不变
    return OK;
}

//队列长度,(rear-front+MAXSIZE)%MAXSIZE
int Len_Queue(SqQueue *q)
{
    int len = (q->rear-q->front+MAXSIZE)%MAXSIZE;
    return len;
}
#endif