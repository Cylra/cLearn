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

typedef struct Node
{
    ElemType elem;
    struct Node *left,*right;
}BiTNode, *BiTree;

/*二叉排序树查找算法
在二叉排序树上查找关键字为key的数据元素,
若查找成功,返回指向该元素节点的指针,q指向其父节点,
若待查找的元素在根节点或BT为空树,q为空,
否则,返回空指针,q指向查找失败前的最后一个节点
*/
BiTree BST_Search(BiTree BT, KeyType key, BiTree &q)
{
    BiTree p = BT;   //p指向待比较的节点
    q = NULL;  //若待查元素为根节点(成功),q为空
    while(p)
    {
        if(p->elem.key == key)  //查找成功
            return p;
        else if(p->elem.key > key)  //key比根节点的值小,向左子树走
        {
            q = p;
            p = p->left;
        }
        else  //否则,向右子树走
        {
            q = p;
            p = p->right;
        }
    }
    return p;   //查找失败,返回NULL
}

/*二叉排序树的插入算法,用于构建二叉排序树
当BT中不存在关键字等于e.key的元素时,插入e对应的节点并返回1,
否则返回0
*/
int BST_Insert(BiTree &BT, ElemType e)
{
    int flag = 0;
    BiTree q, s;
    if(!BST_Search(BT, e.key, q)) //查找失败,则插入新节点,q指向查找失败前的最后一个节点
    {
        s = new BiTNode;
        s->elem = e;
        s->left = NULL;
        s->right = NULL;
        if(!q)   //原树BT为空树
            BT = s;
        else
        {
            if(e.key > q->elem.key) //插入的key值较大,插入右子树
                q->right = s;
            else            //插入左子树
                q->left = s;
        }
        flag = 1;  //设置插入成功标志
    }
    return flag;
}

#endif