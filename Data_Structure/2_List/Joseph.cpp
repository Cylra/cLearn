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

void Create_L(LinkList &L, int n)
{
    int i;
    LNode *s,*r;  //r为尾指针
    L= new LNode;
    L->data = 1;
    L->next = NULL;
    r=L;
    for(i=2; i<=n; i++)
    {
        s = new LNode;
        s->data = i;
        r->next = s;
        r = s;
    }
    r->next = L; //循环单链表
}

//一共n个人,从第k个人开始报数,报m的出圈
void Josephus(LinkList &L,int k, int n, int m)
{
    LNode *s,*t;
    s = L;
    int i;
    for(i=1; i<k; i++) //从第k个人开始
        s = s->next;
    cout<< "所有人的出队序列如下:"<<endl;
    while( s->next != s)
    {
        for(i=1; i<m; i++)
        {
            t = s;
            s = s->next;
        }
        t->next = s->next;
        cout << s->data <<'\t';
        delete s;
        s = t->next;
    }
    cout << s->data <<'\t';
    delete s;
    cout <<endl;
}

int main()
{
    LinkList L;
    Create_L(L, 6);
    Josephus(L, 3, 6, 4);
    return 0;
}