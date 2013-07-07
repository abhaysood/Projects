#include<stdio.h>
#define MAX 100

int queue[MAX];
int rear=-1;
int front=-1;

void insert(int val)
{
	if((front==0 && rear==MAX-1) ||	(front==rear+1)
	{
	printf("OVERFLOW");
	}
	else
	{
		if(front==-1)
		{
		front = 0;
		}
		else if(rear==n-1)
		{
		rear=0;
		}
		else
		{
		rear++;
		}
	queue[rear]=val;
	}
}


int delete()
{
int val;
	
}



void display()
{
int i;
if (front == -1)
printf("Queue is empty\n");
else
{
printf("Queue is :\n");
for(i=front;i<= rear;i++)
printf("%d ",queue[i]);
printf("\n");
}
}

int main()
{
insert(1);
insert(2);
insert(3);
insert(4);
insert(5);
display();

return 0;
}
