#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int p, int q)
{
    int pivot=arr[q];
    int i=p-1,j;
    for (j=p;j<q;j++) {
        if (arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[q]);
    return i+1;
}

int random_partition(int arr[],int p,int q)
{
    int pivot_index=rand()%(q-p+1)+p;
    swap(&arr[pivot_index],&arr[q]);
    return partition(arr,p,q);
}

void quicksort(int arr[],int p, int q)
{
    if (p < q) {
        int pivot_index = random_partition(arr, p, q);
        quicksort(arr, p, pivot_index - 1);
        quicksort(arr, pivot_index + 1, q);
    }
}

void main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    srand(0);
    for (i=0;i<n;i++)
    {
        //arr[i]=rand()%n;
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

