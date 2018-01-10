#ifndef COMMON_H
#define COMMON_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int MAXSIZE = 100;
const int TRUE = 1;
const int FALSE = 0;
const int OK = 1;
const int ERROR = 0;

typedef struct Node
{
    char data;
    struct Node *left,*right;
}BiTNode, *BiTree;
#endif