#include<stdio.h>
void merge(int arr[],int left[],int l,int right[],int r)
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)
    {
        if (left[i]<right[j])
        {
            arr[k++]=left[i++];
        } else {
            arr[k++]=right[j++];
        }
    }
    while (i<l)
    {
        arr[k++]=left[i++];
    }
    while (j<r)
    {
        arr[k++]=right[j++];
    }
}

void merge_sort(int arr[], int n)
{
    if (n<=1)
    {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    memcpy(left,&arr[0],mid*sizeof(int));
    memcpy(right,&arr[mid],(n-mid)*sizeof(int));
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merge(arr,left,mid,right,n - mid);
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
	merge_sort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
}
