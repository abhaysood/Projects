#include<stdio.h>
#define MAX 10

struct list{
int data;
struct list *next;
};

struct list *root=NULL;
struct list *tmp=root;
void insert(int val)//insertion at rear or if list is empty make a new node
{
	//if(root==NULL)//if list is empty make the first node
	//{
	//root=(struct list*)malloc(sizeof(struct list));
	//root->data=val;
	//root->next=NULL;
	//}
	//else//if list is not empty isert new node at the end of list
	//{
	
	while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
	tmp->next=(struct list*)malloc(sizeof(struct list));
	tmp->next->next=NULL;
	tmp->next->data=val;
	//}
}
void printlist(struct list *tmp)
{
	if(tmp==NULL)
	{
	printf("empty list\n");
	return;
	}
	else
	{
	printf("%d\n",tmp->data);	
	printlist(tmp->next);
	}
}


int main()
{
struct list *start,*temp;
start = (struct list*)malloc(sizeof(struct list)); 
temp = start;
temp -> next = NULL;

printlist(start);
insert(1);
insert(2);
insert(3);
printlist(start);
insert(4);
insert(5);
insert(6);
printlist(start);
return 0;
}








	
	
 	
