#include "list.h"
using namespace std;

int main()
{
    int i;
    Sq_List A,B,C;
    Init_Sq_List(A);
    Init_Sq_List(B);
    Init_Sq_List(C);
    for(i=9; i>0;)
    {
        Insert_Sq_List(A, i);
        i -= 2;
    }
    cout << "A表:" <<endl;
    Print_Sq_List(A);
    for(i=10; i>0;)
    {
        Insert_Sq_List(B, i);
        i -= 2;
    }
    cout << "B表:" <<endl;
    Print_Sq_List(B);
    
    merge(A, B, C);
    cout << "C表" << endl;
    Print_Sq_List(C);

    Reverse_Sq_List(A);
    cout << "倒置后的A表:" << endl;
    Print_Sq_List(A);
    return 0;
}