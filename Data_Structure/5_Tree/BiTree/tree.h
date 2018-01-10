/*
二叉树非递归写法参考网页
(http://blog.csdn.net/zhangxiangdavaid/article/details/37115355)
*/
#ifndef TREE_H
#define TREE_H

//非递归遍历二叉树需要借助栈,二叉树的结构体定义也需要写入栈的头文件
#include "stack.h"
//层次遍历二叉树需要借助队列
#include "queue.h"
using namespace std;

/*创建二叉树,使用递归算法,
按先序次序输入扩展的正则二叉树中节点的值(1个char字符)
先建立根节点,再建立左子树,
再建立右子树
*/
int Create_BiTree(BiTree &BT)
{
    char ch;
    cin >> ch;
    //读到#时建立空二叉树
    if(ch == '#'){
        BT = NULL;
    }
    else{
        BT = new BiTNode;          //根节点
        BT->data = ch;
        Create_BiTree(BT->left);   //建立左子树
        Create_BiTree(BT->right);  //建立右子树
    }
    return OK;
}

/***********************
     3种递归遍历算法
***********************/
//先序遍历
void PreOrder(BiTree BT)
{
    if(BT)
    {
        cout << BT->data;
        PreOrder(BT->left);
        PreOrder(BT->right);
    }
}
//中序遍历
void InOrder(BiTree BT)
{
    if(BT)
    {
        InOrder(BT->left);
        cout << BT->data;
        InOrder(BT->right);
    }
}
//后序遍历
void PostOrder(BiTree BT)
{
    if(BT)
    {
        PostOrder(BT->left);
        PostOrder(BT->right);
        cout << BT->data;
    }
}

/***********************
     3种非递归遍历算法
     借助栈
中序遍历的非递归写法最简单
后序遍历最难     
***********************/
//非递归先序遍历
void PreOrder2(BiTree BT)
{
    SqStack s;
    InitStack(&s);
    BiTree p = BT;
    while(p || !StackEmpty(&s))
    {
        //边遍历边打印，并存入栈中
        if(p){
            cout << p->data;
            Push(&s, p);
            p = p->left;
        }
        //当p为空时,说明根和左子树都遍历完了,该处理右子树了
        else{
            Pop(&s, &p);
            p = p->right;
        }
    }
    cout << endl;
}

//非递归中序遍历
void InOrder2(BiTree BT)
{
    SqStack s;
    InitStack(&s);
    BiTree p = BT;
    while(p || !StackEmpty(&s))
    {
        if(p){
            Push(&s, p);
            p = p->left;
        }
        //当p为空时,根和左子树节点都遍历完了,需要打印根节点,并进入右子树
        else{
            Pop(&s, &p);
            cout << p->data;
            p = p->right;
        }
    }
    cout << endl;
}

//非递归后序遍历
/*
后序遍历的难点在于：需要判断上次访问的节点是位于左子树,还是右子树.
若是位于左子树,则需跳过根节点,先进入右子树,再回头访问根节点;
若是位于右子树,则直接访问根节点
*/
void PostOrder2(BiTree BT)
{
    SqStack s;
    InitStack(&s);
    //pCur:当前访问节点,pLastVisit:上次访问节点 
    BiTree pCur = BT;
    BiTree pLastVisit = NULL;
    //先将pCur移动到左子树最下边
    while(pCur)
    {
        Push(&s, pCur);
        pCur = pCur->left;
    }
    while(!StackEmpty(&s))
    {
        //走到这里,pCu等于NULL,并已经遍历到左子树底端(看成扩充二叉树,则等于空,亦是某棵树的左孩子)
        Pop(&s, &pCur);
        //一个根节点被访问的前提是: 无右子树或右子树已被访问过 
        if(pCur->right == NULL || pCur->right == pLastVisit)
        {
            cout << pCur->data;
            pLastVisit = pCur;
        }
        /*上面的条件没通过,则需先进入右子树(根节点需再次入栈)
        */
        else
        {
            //根节点再次入栈
            Push(&s, pCur);
            //进入右子树,而且可以肯定右子树一定不为空
            pCur = pCur->right;
            while(pCur)
            {
                Push(&s, pCur);
                pCur = pCur->left;
            }
        }
    }
    cout << endl;
}

/***********************
     层次遍历算法
     借助队列
***********************/
void LevelOrder(BiTree BT)
{
    SqQueue Q;
    InitQueue(&Q);
    BiTree p = BT;
    En_Queue(&Q, p); //根节点入队
    while(!QueueEmpty(&Q))  //队列不为空
    {
        De_Queue(&Q, &p);
        cout << p->data;  //访问队头节点
        if(p->left)
            En_Queue(&Q, p->left);  //有左子树,入队
        if(p->right)
            En_Queue(&Q, p->right); //有右子树,入队
    }
    cout << endl;
}

//递归算法,统计二叉树中叶子节点个数
//left==right==NULL
void CountLeaves(BiTree BT, int &count)
{
    if(BT)
    {
        //左右节点都为空,叶子数加1
        if(!(BT->left) && !(BT->right))
            count++;
        CountLeaves(BT->left, count);
        CountLeaves(BT->right, count);
    }
}

//二叉树高度
int BiTreeDepth(BiTree BT)
{
    int leftDep, rightDep;
    if(!BT)
        return 0;   //空树的高度为0
    else
    {
        leftDep = BiTreeDepth(BT->left);
        rightDep = BiTreeDepth(BT->right);
        return (leftDep > rightDep)? (leftDep+1):(rightDep+1);
    }
}

//求根节点到指定节点之间的路径

#endif