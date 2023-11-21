#include <stdio.h>
void main()
{
    int n,i,a,num=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    FILE *f;
    f=fopen("input.txt","r");
    fscanf(f,"%d",&a);
    fclose(f);
    for (i=0;i<n;i++)
    {
      while (a>=arr[i])
     {
       a-=arr[i];
       num++;
    }
   }
   f=fopen("output.txt","w");
   fprintf(f,"%d",num);
   fclose(f);
}
