

#include<stdio.h>
#define SIZE 7
int arr[SIZE];

int ls(int *a,int val)
	{
	if(a==NULL)
	{
	printf("Empty array\n");
	}
	int i;
	for(i=0;i<SIZE;i++)
		{
		if(a[i]==val)
		return i;
		}
	return -1;
	}

void display(int *a)
{
int i;
	for(i=0;i<SIZE;i++)
	{
	printf("%d\t",a[i]);
	}
	printf("\n");
}

int main()
{
int i,result,value;
printf("Enter the elements of array\n");
for(i=0;i<SIZE;i++)
{
scanf("%d",&arr[i]);
}

display(arr);

printf("Enter the value you want to search:\n");
scanf("%d",&value);

result=ls(arr,value);

if(result==-1){
printf("Not Found\n");
}
else{
printf("Location = %d\n",result+1);
}

return 0;
}
	

