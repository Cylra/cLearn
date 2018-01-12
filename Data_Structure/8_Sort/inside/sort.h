#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

typedef char InfoType;
typedef struct{
    int key;
    InfoType info;    //其他数据项,为简化算法通常忽略
}Rectype;

/*插入排序,从小到大排序
3种
*/
//直接插入排序,r[0]留空,数据存放在r[1..n]
void Insert_sort_st(Rectype r[], int n)
{
    int i,j;
    for(i=2; i<=n; i++)   //共进行n-1趟插入
    {
        r[0] = r[i];   //r[0]为监视哨
        j = i-1;
        while(r[j].key > r[0].key)
        {
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = r[0];   //将r[0]即原r[i]记录的内容插入到r[j]后一位置
    }
}

//折半插入排序
void Insert_sort_bin(Rectype r[], int n)
{
    int i,j,low, mid, high;
    for(i=2; i<=n; i++)
    {
        r[0] = r[i];    //保存待插入元素r[i]
        low = 0;
        high = i-1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(r[0].key > r[mid].key)
                low = mid+1;
            else
                high = mid-1;
        }
        for(j=i-1; j>=high+1; j--)
            r[j+1] = r[j];      //后移元素,空出插入位置
        r[high+1] = r[0];
    }
}

//希尔插入排序,dk为当前增量
void ShellInsert(Rectype r[], int dk, int n)
{
    int i,j;
    for(i=dk+1; i<=n; i++)
    {
        if(r[i].key < r[i-dk].key)
        {
            r[0] = r[i];
            for(j=i-dk; j>0&&r[0].key<r[j].key; j++)
                r[j+dk] = r[j];
            r[j+dk] = r[0];
        }
    }
}
//按增量序列d[1..t]对序列r[1..n]进行希尔排序
void Insert_sort_shell(Rectype r[], int d[], int t, int n)
{
    int k;
    for(k=1; k<=t; k++)
        ShellInsert(r, d[k], n);    //进行一趟增量为d[k]的插入排序
}

/*交换排序,从小到大排序
2种
*/
//冒泡排序
void sort_Bubble(Rectype r[], int n)
{
    int i, j;
    int swap;
    for(i=1; 1<n; i++)
    {
        swap = 0;    //交换标志
        for(j=1; j<=n-i; j++)
        {
            if(r[j].key > r[j+1].key) //不满足排序规则,交换
            {
                r[0] = r[j+1];
                r[j+1] = r[j];
                r[j] = r[0];
                swap = 1;
            }
        }
        if(0 == swap)  //此趟没有发生交换,排序结束
            break;
    }
}
#endif