#include<stdio.h>
#define SIZE 6

int arr[SIZE];


int* ss(int *a)
{
int index,i,j,temp;

for(i=0;i<=SIZE-1;i++)
	{
	index=i;
	for(j=i+1;j<=SIZE-1;j++)
		{
		if(a[j]<a[index])
		index=j;
		}
	temp=a[i];
	a[i]=a[index];
	a[index]=temp;
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
display(ss(arr));
return 0;
}
