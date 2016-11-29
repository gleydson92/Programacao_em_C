#include"avl_tree.h"
node * insert(node *root, int element)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=element;
        root->left=NULL;
        root->right=NULL;
    }
    else
        if(element > root->data)       
        {
            root->right=insert(root->right,element);
            if(BF(root)==-2)
                if(element>root->right->data)	root=rotation_RR(root);
                else		                    root=rotation_RL(root);
        }
        else
            if(element<root->data)
            {
                root->left=insert(root->left,element);
                if(BF(root)==2)
                    if(element < root->left->data)	root=rotation_LL(root);
                    else	                        root=rotation_LR(root);
            }
			root->ht=height(root);     
			return(root);
}
node * Delete(node *root, int element)
{
    node *p;
    
    if(root==NULL)	return NULL;
    else if(element > root->data)
        {
            root->right=Delete(root->right,element);
            if(BF(root)==2)
                if(BF(root->left)>=0)	root=rotation_LL(root);
                else					root=rotation_LR(root);
        }
        else if(element<root->data)
            {
                root->left=Delete(root->left,element);
                if(BF(root)==-2) 
                    if(BF(root->right)<=0)	root=rotation_RR(root);
                    else					root=rotation_RL(root);
            }
            else
            {          
                if(root->right!=NULL)
                {    
                    p=root->right;
                    
                    while(p->left!= NULL){
                        p=p->left;
                        root->data=p->data;
                    	root->right=Delete(root->right,p->data);}
                    
                    if(BF(root)==2)
                        if(BF(root->left)>=0)	root=rotation_LL(root);
                        else				root=rotation_LR(root);
                }
                else	return(root->left);
            }
    root->ht=height(root);
    return(root);
}
 
int height(node *root)
{
    int left_ht,right_ht;

    if(root==NULL)			return(0);
    
    if(root->left==NULL)	left_ht=0;
    else			        left_ht=1+root->left->ht;

    if(root->right==NULL)	right_ht=0;
    else			        right_ht=1+root->right->ht;
    
    if(left_ht>right_ht)	return(left_ht);
    					    return(right_ht);
}
 
node * rotateright(node *element)
{
    node *element2;
    element2=element->left;
    element->left=element2->right;
    element2->right=element;
    element->ht=height(element);
    element2->ht=height(element2);
    return(element2);
}
 
node * rotateleft(node *element)
{
    node *element2;
    element2=element->right;
    element->right=element2->left;
    element2->left=element;
    element->ht=height(element);
    element2->ht=height(element2);
    
    return(element2);
}
 
node * rotation_RR(node *root)
{
    root=rotateleft(root);
    return(root);
}
 
node * rotation_LL(node *root)
{
    root=rotateright(root);
    return(root);
}
 
node * rotation_LR(node *root)
{
    root->left=rotateleft(root->left);
    root=rotateright(root);
    
    return(root);
}
 
node * rotation_RL(node *root)
{
    root->right=rotateright(root->right);
    root=rotateleft(root);
    return(root);
}
 
int BF(node *root)
{
    int left_ht,right_ht;

    if(root==NULL)			return(0);
 
    if(root->left==NULL)	left_ht=0;
    else			        left_ht=1+root->left->ht;
 
    if(root->right==NULL)	right_ht=0;
    else					right_ht=1+root->right->ht;
 
    return(left_ht - right_ht);
}
 
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d(Bf=%d)",root->data,BF(root));
        preorder(root->left);
        preorder(root->right);
    }
}
 
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d(Bf=%d)",root->data,BF(root));
        inorder(root->right);
    }
}
