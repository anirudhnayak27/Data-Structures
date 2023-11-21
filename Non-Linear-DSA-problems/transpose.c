#include<stdio.h>
void main()
{
    FILE*f=fopen("input.txt","r");
    //int n,m;
    //scanf("%d",&n);
    //scanf("%d",&m);
    int arr[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            fscanf(f,"%d",arr[i][j]);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf(f,"%d",arr[j][i]);
        }
    }
}
