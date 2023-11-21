#include <stdio.h>
#include <string.h>
int max(int a,int b)
{
    return(a>b)?a:b;
}
int lcs(char *x,char*y,int m,int n)
{
    int l[m+1][n+1];
    int i, j;
    for (i=0;i<=m;i++)
    {
        for (j=0;j<=n;j++)
        {
            if (i==0||j==0)
            {
                l[i][j]=0;
            } else if (x[i-1]==y[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
            } else {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    return l[m][n];
}

void main()
{
    int i,m,n;
    scanf("%d%d",&n,&m);
    char x[n];
    char y[m];
    for(i=0;i<n;i++)
    {
        scanf("%c",x[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%c",y[i]);
    }
    printf("%d",lcs(x,y,m,n));
}

