#include<stdio.h>
#define MAX 100
int top=-1;
int stack[MAX];

int push(int);
int pop();

				/*int main()
				{
				int i;
				int data,d;
				for(i=0;i<5;i++)
				{
				printf("Enter:\n");
				scanf("%d",&data);
				push(data);
				}
				for(i=0;i<7;i++)
				{
				d=pop();
					if(d==-1)
					{
					printf("\nERROR\n");
					}
					else
					{
					printf("\npopped=%d\n",d);
					}
				}
				return 0;
				}
				*/
int push(int val)
{
if(top==MAX-1)
{
return -1;
}
else
{
top++;
stack[top]=val;
return 0;
}
}

int pop()
{
if(top==-1)
{
return -1;
}
else
{
int temp;
temp=stack[top];
top--;
return temp;
}
}

