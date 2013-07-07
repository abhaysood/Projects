#include<stdio.h>
#define MAX 5
int front,rear;
int queue[MAX];


void insert(int val,int queue[])
{

if((front==(rear+1)%MAX)||(front==0&&rear==MAX-1))
{
	printf("QUEUE FULL\n");
	return;
}

else
{
	if(front==-1)
	{
	front=0;
	rear=rear+1;
	queue[rear%MAX]=val;
	}

}
}

int del(int queue[])
{
	int item;
	if(front==-1)
	{
	printf("Underflow\n");
	return;
	}
	else 
	{
		item=queue[front];
		if(front==rear)
		{
		front=-1;rear=-1;
		}
		else
		{
		front=(++front)%MAX;
		}
		return(item);
	}
}




void display(int queue[])
{
int i;
if(front==-1)
	{
	printf("Underflow\n");
	}
else

	{
        printf("Front[%d]->",front);
        for(i=front;i!=rear;i=(i+1)%MAX)
           { printf("%d ",queue[i]);
	}
        printf("%d ",queue[i]);
        printf("<-[%d]Rear",rear);
	}
}


int main()
{
//int queue[MAX];
int a;
front=-1;
rear=-1;;
insert(1,queue);
insert(2,queue);
insert(3,queue);
insert(4,queue);
insert(5,queue);
insert(6,queue);
insert(7,queue);
insert(8,queue);
display(queue);
a=del(queue);
printf("%d",a);
return 0;
}



