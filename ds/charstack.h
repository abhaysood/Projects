//my name is abhay    ----------->    yahba si eman ym

#include<stdio.h>

#define MAX 200
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
 printf("cant pop stack empty\n");
 return -1; //underflow condition...no element in stack
 }
 else
 {
 temp=stack[top]; //pop successful
 --top;
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
char array[MAX];
int lines=0;
int words=0;
top=-1;
int i=0;
int j=0;
printf("Enter the string\n");
gets(array);
while(array[j]!='\0')
{
	while(array[i]!=" ")
	{
		if((array[i]>'a'&&array[i]<'z')||(array[i]>'A'&&array[i]<'Z'));
		{
		push(stack,array[i]);
		}
		else if(array[i]=="\n")
		{
		lines++;
		}
	i++;
	}
	words++;
	j=i+1;
}

printf("\n%d%d",words,lines);
display(stack,top);

return 0;
}






