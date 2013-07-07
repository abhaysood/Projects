#include<stdio.h>


int a[1000000];

void quickSort (int a[], int lo, int hi)
{
//  lo is the lower index, hi is the upper index
//  of the region of array a that is to be sorted
    int i=lo, j=hi, h;
    int x=a[(lo+hi)/2];

    //  partition
    do
    {    
        while (a[i]<x) i++; 
        while (a[j]>x) j--;
        if (i<=j)
        {
            h=a[i]; a[i]=a[j]; a[j]=h;
            i++; j--;
        }
    } while (i<=j);

    //  recursion
    if (lo<j) quickSort(a, lo, j);
    if (i<hi) quickSort(a, i, hi);
}






int main()
{

int i,result,value,p;
int SIZE,t;

scanf("%d",&SIZE);

for(i=0;i<SIZE;i++)
{
scanf("%d",&a[i]);
}
quickSort(a,0,SIZE-1);


for(i=0;i<SIZE;i=i++)
{
printf("%d\n",a[i]);
}


return 0;
}

