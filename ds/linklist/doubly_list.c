#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};

struct node *root=NULL;


void insertbeg(int val)
{
struct node *temp;
struct node *track=root;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=val;
if(root==NULL)
{
root=temp;
root->next=NULL;
root->prev=NULL;
}
else
{
root->prev=temp;
temp->next=root;
temp->prev=NULL;
root=temp;
}
}


void display()
{	printf("\n\n---------------------------------------------\n");
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
	printf("THE LIST IS EMPTY\n");
	}
	else
	{

	while(temp!=NULL)
	{
	temp=temp->next;
	printf("%d\t",temp->data);
	temp=temp->prev;
	}
	}
	printf("\n---------------------------------------------\n\n");
}

//-------------------------------------main()


int main()
{
insertbeg(1);
insertbeg(2);
insertbeg(3);
insertbeg(4);
display();
return 0;
}
