#include "queue.h"
using namespace std;

int main()
{
    SqQueue q;
    InitQueue(&q);
    En_Queue(&q, 100);
    En_Queue(&q, 99);
    En_Queue(&q, 98);
    cout << "队列长度为:" << Len_Queue(&q) << endl;
    Elemtype e;
    De_Queue(&q, &e);
    cout <<"出队数据为:" << e <<endl;
    cout << "队列长度为:" << Len_Queue(&q) << endl;
    return 0;
}
