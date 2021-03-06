#include<stdio.h>
#include<stdlib.h>

struct bst
{
int data;
struct bst *left,*right;
};
struct bst *root=NULL;

//------------------------------------------------
void build_tree(struct bst *node,int val)
{
struct bst *temp=(struct bst*)malloc(sizeof(struct bst));
struct bst *temp1=node;
	if(node==NULL)
	{
	temp->data=val;
	temp->right=NULL;
	temp->left=NULL;
	root=temp;
	}
	else
	{
		
		if(val>temp1->data)
		{
		temp1=temp1->right;
		build_tree(temp1,val);
		}
		else
		{
		temp1=temp1->left;
		build_tree(temp1,val);
		}
	
	}
}
//----------------------------------------------
void delete(int val)
{
}
//---------------------------------
struct bst* findmin(struct bst *node)
{
struct bst *temp;
if(node==NULL)
{
return NULL;
}
else
{
	temp=node;
	if(temp->left!=NULL)
	{
	findmin(temp->left);
	}
	else
	{
	return temp;
	}
}
}
//--------------------------------------------
struct bst* findmax(struct bst *node)
{
struct bst *temp;
if(node==NULL)
{
return NULL;
}
else
{
	temp=node;
	if(temp->right!=NULL)
	{
	findmax(temp->left);
	}
	else
	{
	return temp;
	}
}
}
//-----------------------------------------------
void inorder(struct bst *node)
{
struct bst *temp=node;
if(temp==NULL)
{
return;
}
else
{
temp=root;
inorder(temp->left);
printf("%d\t",temp->data);
inorder(temp->right);
}
}
//---------------------------------------------
void preorder(struct bst *node)
{
struct bst *temp;
if(node==NULL)
{
printf("EMPTY TREE FIRST ENTER A VALUE\n");
}
else
{
temp=node;
printf("%d\t",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}
//-----------------------------------------------------
void postorder(struct bst *node)
{
struct bst *temp;
if(node==NULL)
{
printf("EMPTY TREE FIRST ENTER A VALUE\n");
}
else
{
temp=node;
postorder(temp->left);
postorder(temp->right);
printf("%d\t",temp->data);
}
}
//----------------------------------------------------
int leaf(struct bst *node)
{
int t;
struct bst *temp;
	if(node==NULL)
	{
	return 0;
	}
	else if((node->left)==NULL&&(node->right)==NULL)
	{
	return 1;
	}
	else
	{
	temp=node;
	t=leaf(temp->left)+leaf(temp->right);
	return t;
	}
}

//----------------------------------------------------
int main()
{

int ch,data;
struct bst *min,*max;
while(1)
{
printf("Enter your choice:\n1.insert an element in the tree\n2.display inorder traversal of tree\n3.preorder traversal\n4.postorder traversal\n5.delete an element from tree\n6.find the least element in the tree\n7.find the largest element in the tree\n8.print the leaf node in a tree\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("Enter the data\n");
	scanf("%d",&data);
	build_tree(root,data);
	printf("now the tree's inorder traversal is:\n");
	inorder(root);
	break;

case 2:
	inorder(root);
	break;

case 3:
	preorder(root);
	break;

case 4:
	postorder(root);
	break;

case 5:
	printf("enter the value you want to delete:\n");
	scanf("%d",&data);
	delete(data);
	break;
case 6:
	min=findmin(root);
	printf("The least element is:%d\t",min->data);
	printf("\n");
	break;
case 7:
	max=findmax(root);
	printf("The largest element is:%d\t",max->data);
	printf("\n");
	break;
case 8:
	leaf(root);
	break;
}
}
return 0;
}




