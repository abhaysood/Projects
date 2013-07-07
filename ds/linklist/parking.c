//tannenbaum parking

#include<stdio.h>
#include<stdlib.h>

struct node
{
int carno;
struct node *next;
};

struct node *north=NULL;
struct node *south=NULL;
int queue[5];
int stack[10];
int rear = -1;
int front = -1;


int space=10;

void waiting_queue_insert(int val)
{
//int added_item;
if (rear==4)
	{
	printf("Queue Overflow GET LOST\n");
	return;
	}
else
	{
		if (front==-1) /*If queue is initially empty */
		{
		front=0;
		}
		rear=rear+1;
		queue_arr[rear] =val;
	}
}


int waiting_queue_del(int )
{
	if (front == -1 || front > rear)
	{
	printf("Queue Underflow\n");
	return ;
	}
	else
	{
	printf("PARKING IS NOW AVAILABLE\n")
	return(queue_arr[front]);
	front=front+1;
}
}


void pushcar(int val)
{
space--;

	struct node *temp;	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->carno=val;
		if(north==NULL)			//the parking is empty	
		{	
		south=temp;
		north=temp;
		north->next=NULL;
		}
		else				//parking has some cars so insert at north
		{
		temp->next=north;
		north=temp;
		}
//}
}


int delete_car(int val)//-------------------------------------------------------------------------------------------------------
{
struct node *temp;
while(temp!=NULL)
{
if(temp->carno==val)
{




void display_parking(int val)
{
printf("\n\n---->NORTH\t\t\tPARKING\t\t\tSOUTH<----\n");
struct node *temp=north;
if(temp==NULL)
{
printf("\t\tPARKING EMPTY\n");
}
else
{
while(temp!=NULL)
{
printf("car%d\t",temp->carno);
temp=temp->next;
}
}
printf("\n------------------------------------------------------------------------------\n");
}



int main()
{
int num,i=0;
int ch;
while(1)
{
printf("\nDO YOU WANT TO PARK YOUR CAR?\nIF YES PRESS (1) ELSE PRESS (2)\n");
scanf("%d",&ch);
switch(ch)
{
case 1: 
	if(space==0)
	{
	printf("Sorry Parking is full enter your car number and wait in the queue\n");
	scanf("%d",&num);	
	waiting_queue_insert(num);
	}
	else
	{
	printf("%d Cars can be parked\n",space);
	printf("Enter your car number\n");
	scanf("%d",&num);
	pushcar(num);
	display_parking(num);
	}
break;
case 2:
	printf("THANKS FOR VISITING\n");
	break;
case 3:
        



}
}
return 0;
}








