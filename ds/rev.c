//my name is abhay    ----------->    yahba si eman ym

#include<stdio.h>

#define MAX 20
char val;
int top;
//---------
void push(char stack[],char val)
{
 if(top==MAX-1)
 {
 printf("overflow!!!!!!!\n");
 }
 else
 {
 ++top;
 stack[top]=val;
 }
}
//---------------

char pop(char stack[])
{
char temp;
 if(top==-1)
 {

 return -1; //underflow condition...no element in stack
 }
 else
 {
 temp=stack[top]; //pop successful

 return temp;
 }
} 
//----------------
void display(char stack[],int top)
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



int main()
{
char stack[MAX];
char array1[]="ab cde";
top=-1;
static char array2[MAX];
int a,i=0;
int j=0;

while(array1[i]!='\0')
{
	if(array1[i]!=' ')
	{
	push(stack,array1[i]);
	}
	else
	{
	array2[j]=pop(stack);
	j++;
        a=j+1;
	array2[a]='\0';
	}
	i++;
}
array2[j+1]='\0';
for(i=0;array2[i]!='\0';i++)
{
printf("\n\n%c",array2[i]);
}





return 0;
}






