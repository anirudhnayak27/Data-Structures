#include<stdio.h>
void recurr(int n)
{
    if(n>0)
    {
        printf("%d",n);
        recurr(n-1);
        recurr(n-1);
    }
}
void recur(int n)
{
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",n);
        }
        recur(n-1);
    }
}
void main()
{
    int n;
    scanf("%d",&n);
    recurr(n);
    printf("\n");
    recur(n);
}
