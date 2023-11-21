#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m,n,i,j,s;
    scanf("%d%d",&n,&m);
    if(n!=m)
    {
        printf("Not a square matrix\n");
        exit(0);
    }
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[n][m]);
        }
    }
      for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==arr[j][i])
            {
                s=1;
            }
        }
    }
    if(s)
    {
        printf("Matrix is symmetric\n");
    }
    else
    {
        printf("Matrix is non-symmetric\n");
    }
}
