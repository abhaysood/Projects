#include<stdio.h>
#define MAX 3
int val;
int top;
int count;


//push function
//----------------------------------------------------------------
void push(int stack[],int val)
{
 if(top==MAX-1)
 {
 printf("overflow!!!!!!\n");
 }
 else
 {
 ++top; //increment to status to point to new top element
 stack[top]=val;
 }
}

//pop function
//---------------------------------------------------------
int pop(int stack[])
{
 int temp=0;
 if(top==-1)
 {
 printf("UNDERFLOW!!!!\n");
 return -1; //underflow condition...no element in stack
 }
 else
 {
 temp=stack[top]; //pop successful
 top--;
 return temp;
 }
} 


//display stack function
//-------------------------------------------------------

void display(int stack[],int top)
{
 if(top==-1)
 {
 printf("stack empty\n");
 }
 else
 {
	 for(count=top;count>=0;--count) 
	 {
    	 printf("\nthe stack is:\n");
	 printf("%d\n",stack[count]); 
	 }
 }
}


/*int main()
{
int item;
int stack[MAX];
top=-1;
push(stack,100);
display(stack,top);
item=pop(stack);
printf("the popped item is=%d\n",item);
return 0;
}*/







