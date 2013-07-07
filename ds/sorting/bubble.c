#include<stdio.h>
#define SIZE 6

int arr[SIZE];

int* bs(int *a)
{
int i,j,temp;
for(i=SIZE-1;i>=0;i--)
{
	for(j=0;j<i;j++)
	{
		if(a[j]>a[j+1])
		{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
}
return a;
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
printf("Unsorted array:\n");
display(arr);
printf("Sorted array:\n");
display(bs(arr));
return 0;
}
