#include <stdio.h>
void fib(int n)
{
    int arr[n];
    int i;
    arr[0] = 0;
    arr[1] = 1;
    for(i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    int n,i;
    scanf("%d",&n);
    fib(n);
}
