//my name is -----> ym eman si
#include<stdio.h>
#include<string.h>
#define MAX 30
char stack[MAX];
int top=-1;

int push(char);
char pop();


int main()
{
char a[MAX],data;
int j,i=0;
printf("Enter the string\n");
gets(a);
int f=0;
for(j=0;j<strlen(a);)
{
	top=-1;
	while(a[i]!=' ' && a[i]!='\0')
	{
	push(a[i]);
	i++;	
	j=i;
	}
	if(f!=0)
	{
	push(' ');
	}
	i++;
	j=i;
	while(top!=-1)
	{
	data=pop();
	printf("%c",data);
	f++;
	}
		
}
printf("\n");
return 0;
}





int push(char ch)
{
	if(top==MAX-1)
	{
	return -1;
	}
	
	top++;
	stack[top]=ch;
	return 0;
	
}

char pop()
{
	char a;
	if(top==-1)
	{
	printf("error\n");
	}
	a=stack[top];
	top--;
	return a;
	
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
