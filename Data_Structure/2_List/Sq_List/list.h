#ifndef LIST_H
#define LIST_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXSIZE = 100;
const int FALSE = 0;
typedef int DataType;

typedef struct{
    DataType data[MAXSIZE];
    int length;
}Sq_List;

//初始化
void Init_Sq_List(Sq_List &L)
{
    memset(&L, 0, sizeof(Sq_List));
    L.length = 0;
}

//将x插入到表中第i个位置,默认头插
void Insert_Sq_List(Sq_List &L, DataType x, int i=1)
{
    int j;
    if(L.length == MAXSIZE)
    {
        cout << "顺序表是满的!无法插入!\n";
        exit(1);
    }
    if(i<1 || i >L.length+1)
    {
        cout << "指定的插入位置不存在!\n";
        exit(1);
    }
    for(j=L.length-1; j>=i-1; j--)
    {
        L.data[j+1] = L.data[j];
    }
    L.data[i-1] = x;
    L.length++;
}

//删除第i个位置的元素,默认第1位
void Delete_Sq_List(Sq_List &L, int i=1)
{
    int j;
    if(L.length == 0)
    {
        cout << "顺序表是空的!无法删除!\n";
        exit(1);
    }
    if(i<1 || i>L.length)
    {
        cout << "指定的删除位置不存在!\n";
        exit(1);        
    }
    for(j=i-1; j<=L.length-1; j++)
    {
        L.data[j] = L.data[j+1];
    }
    L.length--;
}

//按值查找
int Location_Sq_List(Sq_List &L, DataType x)
{
    int i;
    for(i=0; i<L.length; i++)
    {
        if(L.data[i] == x){
            return (i+1);
        }
    }
    if(i == L.length){
        return FALSE;
    }
}

//打印一个顺序表
void Print_Sq_List(Sq_List &L)
{
    int i=0;
    while(i < L.length)
    {
        cout << L.data[i] << '\t';
        i++;
    }
    cout << endl;
}

/*顺序表A和B,其元素均从小到大升序排列,
  将其合并成表C,C依然从小到大排序
*/
void merge(Sq_List &A,Sq_List &B, Sq_List &C)
{
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length)
    {
        if(A.data[i] < B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while(i < A.length)
        C.data[k++] = A.data[i++];
    while(j < B.length)
        C.data[k++] = B.data[j++];

    C.length = k;
}

//将顺序表逆置
void Reverse_Sq_List(Sq_List &L)
{
    int i;
    DataType x;
    int Len = L.length;
    for(i=1; i<= L.length/2; i++)
    {
        x = L.data[i-1];  //完成元素i和Len-i+1的交换
        L.data[i-1] = L.data[Len-i];
        L.data[Len-i] = x;
    }
}
#endif