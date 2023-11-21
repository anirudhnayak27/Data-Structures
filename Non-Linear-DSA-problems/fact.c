#include<stdio.h>
int fact(int n)
{
    if(n==1}
       break;
    else
        {
         int f=n*fact(n-1);
        }
   return f;
}
int main()
{
    int n,f;
    scanf("%d",&n);
    f=fact(n);
    printf("%d",f);
}
