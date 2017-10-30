#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *left, *right;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T)
{
    int i;
    scanf("%d", &i);
    if(i > 0){
        (*T) = (BiTree)malloc(sizeof(BiTNode) * 1);
        (*T)->data = i;
        printf("创建左子树\n");
        CreateBiTree(&((*T)->left));
        printf("创建右子树\n");
        CreateBiTree(&((*T)->right));
    }
    else{
        (*T) = NULL;
    }

    return;
}

void PrintBiTree(BiTree T)
{
    if(NULL == T)
        return;
    else
    {
        printf("%d\t", T->data);
        PrintBiTree(T->left);
        PrintBiTree(T->right);
    }
}

int main()
{
    //printf("hello world!\n");
    printf("每次输入一个整数，最后以0结尾\n");
    BiTree root = NULL;
    CreateBiTree(&root);
    //printf("%x\n", root);
    PrintBiTree(root);

    return 0;
}