//hello world    ----->>  dlrow olleh 
#include<stdio.h>
#define MAX 30
char stack[MAX];
int top=-1;


int push(char);
char pop();
void display();

int main()
{
int i;
char a1[MAX];
printf("Enter the string\n");
gets(a1);
for(i=0;a1[i]!='\0';i++)
{
push(a1[i]);
}
display();
return 0;
}




int push(char ch)
{
	if(top==MAX-1)
	{
	return -1;
	}
	else
	{
	top++;
	stack[top]=ch;
	return 0;
	}
}

char pop()
{
	if(top==-1)
	{
	return -1;
	}
	else
	{
	char a=stack[top];
	top--;
	return 0;
	}
}


void display(int top)
{
 int count;
 if(top==-1)
 {
 printf("Stack is EMPTY!!!!!!!\n");
 }
 else
 {
 for(count=top;count>=0;count--)
 {
 printf("%c",stack[count]);
 }
 printf("\n");
 }
}
