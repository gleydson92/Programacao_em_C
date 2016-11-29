#include<stdlib.h>
#include<stdio.h>
 
typedef struct node
{
    int data;
    struct node *left,*right;
    int ht;
}node;
 
node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *rotation_RR(node *);
node *rotation_LL(node *);
node *rotation_LR(node *);
node *rotation_RL(node *);
int BF(node *);

