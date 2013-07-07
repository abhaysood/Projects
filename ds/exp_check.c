//make the user enter an expression,check if it is valid or not

#include<stdio.h>
#include<string.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char ch)
{
	if(top==MAX-1)
	{
	printf("satck overflow\n");
	}
	else
	{
	top++;
	stack[top]=ch;
	}
}

char pop()
{
	char m;
	if(top==-1)
	{
	printf("UNDERFLOW\n");
	}
	else
	{
	m=stack[top];
	top--;
	return m;
	}
}


int main()
{
char a[20];
char ch;
int count,track=0;
int temp;
int valid;//0=TRUE,1=FALSE

printf("enter the expression\n");
gets(a);

for(count=0;count<=strlen(a);count++)
{
	if(a[count]=='('||a[count]==')')
	{
	push(a[count]);
	}
}

	while(top!=0||valid!=1)
	{
	ch=pop();
		if(ch==')')
		{
			track--;
			if(top==-1)
			{
			valid=1;
			}
			else
			{
			valid=0;
			}
		}

		if(ch=='(')
		{
		track++;
		}
	}
if(track!=0 || valid==1)
{
printf("INVALID STRING\n");
}
else
{
printf("VALID");
}
return 0;
}



