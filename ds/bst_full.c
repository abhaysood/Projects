#include<stdio.h>
#include<stdlib.h>

struct bst
{
int data;
struct bst *right;
struct bst *left;
};
struct bst *root=NULL;


void preorder(struct bst *node,int val)
{
struct bst *temp,*temp1;
temp=(*struct bst)malloc(sizeof(struct bst));
if(root==NULL)
{
temp->data=val;
temp->right=NULL;
temp->left=NULL;
root=temp;
}
else 
{
temp1=node;
if()


int main()
{
int choice;
printf("Enter Your Choice:\n1.inorder traversal\n2.preorder traversal\n3.postorder traversal\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
inorder(root,val);
break;
return 0;

