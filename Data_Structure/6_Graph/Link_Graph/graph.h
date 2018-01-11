#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int VexNum = 10;
//邻接表节点
struct node{
    int vertex;      //邻接点序号
    struct node *next;    //下一个邻接点
};
typedef struct node *Graph;    //指针
struct node Head[VexNum];     //顶点数组
int Visited[VexNum] = {0};    //设置未访问标志

/*初始化邻接表,以书上的无向图为例
         1                1->2->7
       /  \               2->1->3->4
     2      7             3->2
    / \    / \            4->2->5->6
   3   4   8——9           5->4
      / \                 6->4
     5  6                 7->1->8->9
                          8->7->9
                          9->7->8
*/
void setupList(int vertex)
{
    int i;
    if(vertex ==1)
    {
        Graph p[2];
        for(i=0; i<2; i++)
            p[i] = new node;
        p[0]->vertex = 2;
        p[1]->vertex = 7;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = NULL;
    }
    else if(vertex ==2)
    {
        Graph p[3];
        for(i=0; i<3; i++)
            p[i] = new node;
        p[0]->vertex = 1;
        p[1]->vertex = 3;
        p[2]->vertex = 4;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = p[2];
        p[2]->next = NULL;
    }
    else if(vertex ==3)
    {
        Graph p[1];
        for(i=0; i<1; i++)
            p[i] = new node;
        p[0]->vertex = 2;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = NULL;
    }
    else if(vertex ==4)
    {
        Graph p[3];
        for(i=0; i<3; i++)
            p[i] = new node;
        p[0]->vertex = 2;
        p[1]->vertex = 5;
        p[2]->vertex = 6;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = p[2];
        p[2]->next = NULL;
    }
    else if(vertex ==5)
    {
        Graph p[1];
        for(i=0; i<1; i++)
            p[i] = new node;
        p[0]->vertex = 4;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = NULL;
    }
    else if(vertex==6)
    {
        Graph p[1];
        for(i=0; i<1; i++)
            p[i] = new node;
        p[0]->vertex = 4;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = NULL;
    }
    else if(vertex==7)
    {
        Graph p[3];
        for(i=0; i<3; i++)
            p[i] = new node;
        p[0]->vertex = 1;
        p[1]->vertex = 8;
        p[2]->vertex = 9;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = p[2];
        p[2]->next = NULL;
    }
    else if(vertex==8)
    {
        Graph p[2];
        for(i=0; i<2; i++)
            p[i] = new node;
        p[0]->vertex = 7;
        p[1]->vertex = 9;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = NULL;
    }
    else if(vertex==9)
    {
        Graph p[2];
        for(i=0; i<2; i++)
            p[i] = new node;
        p[0]->vertex = 7;
        p[1]->vertex = 8;
        //建立链表
        Head[vertex].next = p[0];
        p[0]->next = p[1];
        p[1]->next = NULL;
    }
}
/* 20180111
由于数组下标以0开始的尿性,下面DFS被坑了一波(Head[0]->next的值为2,
递归调用实际访问了节点3(Head[2])的邻接表,且容易混乱),
现将Head数组长度设为10,
Head[0]轮空,不存数据
Head[1]-Head[9]存放邻接表的表头
*/
void Init()
{
    //cout << "初始化并建立邻接表" << endl;
    int i = 0;
    for(i=1; i<VexNum; i++)
        Head[i].vertex = i;
    for(i=1; i<VexNum; i++)
        setupList(i);
}

//打印邻接表
void Print()
{
    int i;
    Graph p;
    cout << "邻接表为:" << endl;
    for(i=1; i<VexNum; i++)
    {
        cout<< Head[i].vertex << " ==> ";
        p = Head[i].next;
        while(p)
        {
            cout<< p->vertex << " ==> ";
            p = p->next;
        }
        cout << endl;
    }
}

void DFS(int);
//深度优先搜索
void DFS_Traverse()
{
    int v;
    cout << "深度优先搜索的序列为:" << endl;
    for(v=1; v<VexNum; v++)
    {
        if(!Visited[v])   //如果该节点未访问,则进行深度优先搜索
        {
            cout << "访问节点: " << v << endl;
            DFS(v);
        }
    }
    cout << endl;
}

void DFS(int vertex)
{
    Graph pG;
    Visited[vertex] = 1;    //设置已访问标志
    printf("[%d] ==> ", vertex);
    pG = Head[vertex].next;  //下一个邻接点
    while(pG)
    {
        if(Visited[pG->vertex] == 0)  //未访问
            DFS(pG->vertex);      //递归调用
        pG = pG->next;
    }
}

//释放建立的邻接表中,申请的堆内存
void Del()
{
    int i = 0;
    Graph p,q;
    for(i=1; i<VexNum; i++)
    {
        p = Head[i].next;
        while(p)
        {
            q = p;
            p = p->next;
            delete q;
        }
    }
}
#endif