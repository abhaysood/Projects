#include<stdio.h>
#define SIZE 6

int arr[SIZE];

int bs(int *a,int val)
{
int low=0;
int up=SIZE;
int mid;
for(mid=(up+low)/2;low<=up;mid=(up+low)/2)
{
	if(val==a[mid])
	{
	return mid;
	}

	else
	{
		if(val<=a[mid])
		{
		up=mid-1;
		}
		else
		{
		low=mid+1;
		}
	}
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

result=bs(arr,value);

if(result==-1){
printf("Not Found\n");
}
else{
printf("Location = %d\n",result+1);
}

return 0;
}
	


