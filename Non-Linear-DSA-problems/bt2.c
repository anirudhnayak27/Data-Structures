#include <stdio.h>
#include <stdbool.h>
void combination(int arr[],int data[],int q,int p,int x,int y)
 {
    int i;
    if (x==y)
    {
        for(i=0;i<y;i++)
        {
            printf("%d\t",data[i]);
        }
        printf("\n");
    }
    for (i=x;i<=p&&p-i+1>=y-x;i++)
    {
        data[x]=arr[i];
        combination(arr,data,i+1,p,x+1,y);
    }
}

void print(int arr[], int n, int r)
{
    int data[r];
    combination(arr,data,0,n-1,0,r);
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
    i=2;
    print(arr,n,i);
}

