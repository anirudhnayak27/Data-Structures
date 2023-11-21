#include<stdio.h>
#include<stdlib.h>
void read_matrix(int *arr,int n,int m)
{
  int i,j;
   printf("Enter matrix elements:\n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           scanf("%d",(*(arr+i)+j));
       }
   }
}
void multipy_matrix(int *a,int *b,int *c)
{
    int n,m,i=0;
    n=sizeof(*a)/sizeof(*(a+i));
    m=sizeof(*b)/sizeof(*(b+i));
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<(n+m);k++)
            {
               (*(c+i)+j)=(*(a+i)+k)*(*(b+k)+j);
            }
        }
    }
}
void display_matrix(int *arr,int n,int m)
{
     int c[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d",*(*(c+i)+j));
        }
    }
}
void main()
{
    int n,m,d,e;
    printf("Enter matrix1 row and column:\n");
    scanf("%d %d",&n,&m);
    printf("Enter matrix2 row and column:\n");
    scanf("%d %d",&d,&e);
    int a[n][m],b[n][m],c[n][m];
    read_matrix(a,n,m);
    read_matrix(b,n,m);
    multipy_matrix(a,b,c);
    display_matrix(c,n,m);
}
