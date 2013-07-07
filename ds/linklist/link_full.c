#include<stdio.h>
#include<stdlib.h>


struct node
{
int data;
struct node *next;
};
struct node *p=NULL;

//----------------------------insert a node...at the last 
void append(int val)
{
struct node *temp,*track;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	track=(struct node*)p;
	//if list is null then create the first node
	if(p==NULL)
	{
	p=temp;
	p->next=NULL;
	}
	//else insert at the last
	else
	{
	while(track->next!=NULL)
	{
	track=track->next;
	}
	track->next=temp;
	temp->next=NULL;
	}
}

//............................insert node at begining
void insertbeg(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	//if list is empty create list
	if (p== NULL)
	{
	p=temp;
	p->next=NULL;
	}
	//else add at begining
	else
	{
	temp->next=p;
	p=temp;
	}
}

//--------------------------------delete a node of given value


delete(int val)
{
struct node *temp, *m;
temp=p;
while(temp!=NULL)
{
	if(temp->data==val)
		{
			if(temp==p)
			{
			p=temp->next;
			free(temp);
			return;
			}
			else
			{
			m->next=temp->next;
			free(temp);
			return;
			}
		}
	else
	{
	m=temp;
	temp= temp->next;
	}

}
printf("%d not found\n",val);
}

//-----------------------------------------delete a node of given position
void deletepos(int pos)
{
struct node *temp=p;
struct node *m;
int count=1;
	while(temp!=NULL)
	{
		if(count==pos)
		{
			if(temp==p)
			{
			p=temp->next;
			free(temp);
			return;
			}
			else
			{
			m->next=temp->next;
			free(temp);
			return;
			}
		}
		else
		{
			count++;
			m=temp;
			temp=temp->next;
		}
	}
printf("%d is an invalid position\n",pos);
}



//---------------------------------reverse list






//--------------------------------dislpay list
void display()
{	printf("\n\n---------------------------------------------\n");
	struct node *r;
	r=p;
	if(r==NULL)
	{
	printf("THE LIST IS EMPTY\n");
	}
	else
	{
	
	while(r!=NULL)
	{
	printf("%d\t",r->data);
	r=r->next;
	}
	}
	printf("\n---------------------------------------------\n\n");
}

//-------------------------------------main()
int main()
{
int ch;
int val;
while(1)
	{
	printf("\n----------------------LINK LIST MENU---------------------------\n");
	printf("1.insert at begining of list \n2.Insert an element at the last\n3.Display\n4.Delete\n5.Delete the value at position\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: printf("\nenter the value you want to insert:\t\n");scanf("%d",&val);insertbeg(val); break;
	case 2: printf("\nenter the value you want to insert:\t\n");scanf("%d",&val);append(val); break;
	case 3: printf("\nTHE LINK LIST IS:\n");display();break;
	case 4: printf("\nEnter the value to be deleted:\t");scanf("%d",&val);delete(val);break;
	case 5: printf("\nEnter the position:\t");scanf("%d",&val);deletepos(val);break;
	
	}
	}
return 0;
}






