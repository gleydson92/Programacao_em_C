#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* Find_Min(treeNode *node);
treeNode* Find_Max(treeNode *node);
treeNode * add(treeNode *node,int data);
treeNode * rm(treeNode *node, int data);
treeNode * find(treeNode *node, int data);
void in_order(treeNode *node);
void pre_order(treeNode *node);
void post_order(treeNode *node);
