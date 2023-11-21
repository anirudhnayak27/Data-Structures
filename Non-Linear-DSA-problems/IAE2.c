//code for reversing an array
#include<stdio.h>
void main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int a=0,b=n-1;
   while(a<b)
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
        a++;
        b--;
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
