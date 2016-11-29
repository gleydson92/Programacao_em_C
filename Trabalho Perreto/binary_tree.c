#include"binary_tree.h"

treeNode* Find_Min(treeNode *node){
        if(node==NULL)	return NULL;
        if(node->left)	return Find_Min(node->left);
        else			return node;
}

treeNode* Find_Max(treeNode *node){
        if(node==NULL)	return NULL;
        if(node->right)	Find_Max(node->right);
        else			return node;
}

treeNode * add(treeNode *node,int data){
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))			node->right = add(node->right,data);
        else if(data < (node->data))	node->left = add(node->left,data);
        return node;

}

treeNode * rm(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)					printf("Element Not Found");
        else if(data < node->data)		node->left = rm(node->left, data);
        else if(data > node->data)		node->right = rm(node->right, data);
        else
        {
        	if(node->right && node->left)
                {
                        temp = Find_Min(node->right);
                        node -> data = temp->data; 
                        node -> right = rm(node->right,temp->data);
                }
                else
                {
                        temp = node;
                        if(node->left == NULL)				node = node->right;
                        else if(node->right == NULL)		node = node->left;
                        free(temp); 
                }
        }
        return node;

}

treeNode * find(treeNode *node, int data)
{
        if(node==NULL)				return NULL;
        if(data > node->data)		return find(node->right,data);
        else if(data < node->data)	return find(node->left,data);
        else		                return node;
}

void in_order(treeNode *node)
{
        if(node==NULL)	return;
        in_order(node->left);
        printf("%d ",node->data);
        in_order(node->right);
}

void pre_order(treeNode *node)
{
        if(node==NULL) return;
        printf("%d ",node->data);
        pre_order(node->left);
        pre_order(node->right);
}

void post_order(treeNode *node)
{
        if(node==NULL) return;
        post_order(node->left);
        post_order(node->right);
        printf("%d ",node->data);
}

