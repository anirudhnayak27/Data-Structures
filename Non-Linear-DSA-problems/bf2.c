#include <stdio.h>
int subarray(int arr[],int n)
{
    int i,max=0,j;
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<n;j++)
        {
            sum+=arr[j];
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}
void main()
{
   int n,i,max;
   scanf("%d",&n);
   int arr[n];
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   max=subarray(arr,n);
   printf("%d",max);
}
