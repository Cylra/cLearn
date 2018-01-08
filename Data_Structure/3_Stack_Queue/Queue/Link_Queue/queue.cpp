#include "queue.h"
using namespace std;

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    En_Queue(Q, 100);
    En_Queue(Q, 99);
    En_Queue(Q, 98);
    cout << "队列长度为:" << Len_Queue(Q) << endl;
    Elemtype e;
    De_Queue(Q, &e);
    cout <<"出队数据为:" << e <<endl;
    cout << "队列长度为:" << Len_Queue(Q) << endl;
    return 0;
}
