#include<stdio.h>
void dup(int arr[],int n)
{
    int i,temp,count;
     for (i=0;i<n;i++)
    {
        count=1;
        for (int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if (count>1)
            printf("%d repeats %d times\n", arr[i], count);
    }
}
/*void display(int arr[])
{
    int i;
    for(i=0;i<20;i++)
    {
        printf("%d\n",arr[i]);
    }
}*/
void main()
{
    int i,n;
    //FILE *f=fopen("input.txt","r");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    printf("\n\n");
    dup(arr,n);
   // fclose(f);
}
