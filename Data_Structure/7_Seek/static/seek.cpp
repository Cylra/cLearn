#include "seek.h"
using namespace std;


int main()
{
    STable ST;
    Create_STable(ST);
    cout << "顺序查找23的位置:"   <<Search_Seq(ST, 23) << endl;
    cout << "折半查找23的位置:"   <<Search_Bin(ST, 23) << endl;
    cout << "折半查找30的位置:"   <<Search_Bin(ST, 30) << endl;
    Destroy_STable(ST);
    return 0;
}