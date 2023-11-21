#include <stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int part(int arr[],int l,int h)
{
	int i,j;
	int pivot=arr[h];
    i=(l-1);
	for (j=l;j<=h-1;j++)
    {
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return (i+1);
}

void quick_Sort(int arr[],int l,int h)
{
	if (l<h)
    {
		int p=part(arr,l,h);
		quick_Sort(arr,l,p-1);
		quick_Sort(arr,p+1,h);
	}
}
void printArray(int arr[],int n)
{
	int i;
	for (i=0; i<n;i++)
    printf("%d ",arr[i]);
	printf("\n");
}
void main()
{
	int i,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
	quick_Sort(arr,0,n-1);
	printf("Sorted array:\n");
	printArray(arr,n);
}
