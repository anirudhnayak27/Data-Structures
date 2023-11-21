#include<stdio.h>
#include<stdlib.h>
int main(){
 int n,a[1000],i,t;
 //int *arr;
 FILE *f;
 f=fopen("text.txt","r");
 fscanf(f,"%d",&n);
 //arr=(int*)malloc(int *sizeof(arr));
 for(i=0;i<n;i++)
 {
     fscanf(f,"%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
     if(a[i]>a[i+1])
     {
         t=a[i];
         a[i]=a[i+1];
         a[i+1]=t;
     }
 }
 fclose(f);
 f=fopen("text.txt","a");
 fprintf(f,"\n");
 for(i=0;i<n;i++)
 {
     fprintf(f,"%d\t",a[i]);
 }

}
