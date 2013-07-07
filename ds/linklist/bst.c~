//binary search tree
//1.user enter values for tree,construct tree
//2.inorder,preorder and postorder traversals 
//3.Leaf Count

#include<stdio.h>
#include<stdlib.h>

struct bst
{
int data;
struct bst *left,*right;
};
int count=0;
struct bst *root=NULL;
//################### INSERT ############################
void insert(int val)
{
struct bst *temp;
struct bst *temp1;
temp=(struct bst*)malloc(sizeof(struct bst));
	if(root==NULL)
	{
		temp->data=val;
		temp->right=NULL;
		temp->left=NULL;
		root=temp;
	}
	else
	{
		temp1=root;
		while(1)	
		{
			if(temp1->data>=val)
			{
				if(temp1->left==NULL)
				{
				temp->data=val;
				temp1->left=temp;
				temp->left=NULL;
				temp->right=NULL;
				return;			
				}	
				else
				{
				temp1=temp1->left;
				}
			}
			else
			{
				if(temp1->right==NULL)
				{			
				temp->data=val;
				temp1->right=temp;
				temp->left=NULL;
				temp->right=NULL;	
				return;
				}
				else
				{
				temp1=temp1->right;
				}
			}
		}
	}
}






//############## INORDER ##########################
void inorder(struct bst *root)
{
struct bst *temp=root;
if(temp==NULL)
{
//printf("BST EMPTY!!!!!!!\n");
return;
}
else
{
inorder(temp->left);
printf("%d\t",temp->data);
inorder(temp->right);
}
}

//############## PREORDER ##########################
int preorder(struct bst *root)
{
struct bst *temp=root;
if(temp==NULL)
{
//printf("BST EMPTY!!!!!!!\n");
return;
}
else
{
printf("%d\t",temp->data);
count++;
preorder(temp->left);
preorder(temp->right);
}
return count;
}
//########### SMALLEST AND LARGEST #######################


//############## POSTORDER ##########################
void postorder(struct bst *root)
{
struct bst *temp=root;
if(temp==NULL)
{
//printf("BST EMPTY!!!!!!!\n");
return;
}
else
{
postorder(temp->left);
postorder(temp->right);
printf("%d\t",temp->data);
}
}

//################### LEAF NODES #############
int leafnode(struct bst* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return leafnode(node->left) + leafnode(node->right);
}
//################## SEARCH ######################

struct bst* search(struct bst *node,int val)
{

	if(val<node->data)
	{
	return search(node->left,val);
	}
	else if(val>node->data)
	{
	return search(node->right,val);
	}
	else
	{
	return node;				//value found
	}
}
//################# DELETE ########################
struct bst* delete(struct bst *node,int val)
{
struct bst *temp,*temp1;
temp=search(node,val);
if(temp->left!=NULL && temp->right!=NULL)  //two child
{
temp1=findmin(temp->right);
temp->data=temp1->data;
free(temp1);
return;
}
else
{
temp = node;
if(node->left==NULL)
node = node->right;
else if(node->right==NULL)
node = node->left;
free(temp);
}
return node;





//################## FIND MIN ###################
struct bst* findmin(struct bst *node)
{
struct bst *temp=node;
while(temp->left!=NULL)
{
temp=temp->left;
}
return temp;
}	


//################## FIND MAX ###################
struct bst* findmax(struct bst *node)
{
struct bst *temp=node;
while(temp->right!=NULL)
{
temp=temp->right;
}
return temp;
}	
//################### MAIN #################

int main()
{







int val,i,leaf,nodenum,del,f;
struct bst *x;
for(i=0;i<8;i++)
{
printf("Enter the value\n");
scanf("%d",&val);
insert(val);
}
printf("INORDER\n");
inorder(root);
printf("\n");
//printf("preORDER\n");
//nodenum=preorder(root);
//printf("\n");
//printf("postORDER\n");
//postorder(root);
//printf("\n");
//leaf=leafnode(root);
//printf("There are %d leaf nodes & %d nodes in your BST\n",leaf,nodenum);
printf("enter the value to be searched\n");
scanf("%d",&f);
x=search(root,f);
if(x!=NULL)
printf("element found\n");
printf("Least element:\t%d\n",findmin(root));
printf("Largest element:\t%d\n",findmax(root));
return 0;
}





