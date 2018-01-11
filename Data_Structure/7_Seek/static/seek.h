#ifndef SEEK_H
#define SEEK_H

#include <iostream>
using namespace std;

typedef int KeyType;
typedef char InfoType;
typedef struct {
    KeyType key;      //关键字(数据项)
    InfoType info;    //数据元素的其他属性,为简化算法通常忽略此数据项
}ElemType;
typedef struct{
    ElemType *elem;   //数据元素存储空间基址,0号单元留空,从1号单元开始存储
    int length;       //查找表的长度
}STable;

void Create_STable(STable &ST)
{
    int len;    //元素个数
    int key;    //关键字
    int i;
    cout << "请输入元素个数:" <<endl;
    cin >> len;
    ST.length = len;
    ST.elem = new ElemType[len+1];  //0号位留空,多申请1个空间
    ST.elem[0].key = 0;
    for(i=1; i<=len; i++)
    {
        cout << "请输入元素的值" << endl;
        cin >> key;
        ST.elem[i].key = key;
    }
    cout << "数据元素列表为:" << endl;
    for(i=1; i<=len; i++)
        cout << ST.elem[i].key << "  ";
    cout << endl;
}

//删除申请的堆内存
void Destroy_STable(STable &ST)
{
    delete[] ST.elem;
}

/*在表ST中顺序查找关键字为key的数据元素,
找到则返回元素在表中的位置,否则返回0
*/

//顺序查找
int Search_Seq(STable ST, KeyType key)
{
    int i;
    ST.elem[0].key = key;    //设定"哨兵",从后向前查找时,不必判断表是否检测完
    for(i=ST.length; ST.elem[i].key != key; i--);   //从后向前查找
    return i;
}

/*折半查找
前提条件: 查找表必须是有序表(在此为升序)
*/
int Search_Bin(STable ST, KeyType key)
{
    int low=1, mid;
    int high=ST.length;         //设置查找区域
    while(low <= high)
    {
        mid = (low+high)/2;      //计算中间元素下标
        if(ST.elem[mid].key == key)
            return mid;
        else if(ST.elem[mid].key > key)   //调整到左半区
                high = mid-1;
        else
            low = mid+1;            //调整到右半区
    }
    return 0;   //查找失败
}

#endif