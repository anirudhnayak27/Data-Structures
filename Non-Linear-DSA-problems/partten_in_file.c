#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lines 10
void read_file(char *line,int *num,int n)
{
    char l[n];
    FILE *f;
    f=fopen("text.txt","r");
    while(*num<lines&& fgets(l,n,f)!=NULL)
    {
       strcpy(line[*num],l);
       (*num)++;
    }
    fclose(f);
}
int length(char *string)
{
    int i;
    for(i=0;string[i]!='\0';i++);
    return i;
}
void search(char *line,char *p)
{
   int n,m;
    n=length(line);
    m=length(p);
    int i,j;
    for(i=0;i<n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(line[i+j]!=p[j])
                break;
        }
        if(j==m)
        {
            printf("%s",line);
        }
    }
}
void main()
{
    int n,i;
    printf("Enter maximum length of string: ");
    scanf("%d",&n);
    char line[lines][n];
    int num=0;
    read_file(line,&num,n);
    char p[10]="ould";
    for(i=0;i<10;i++)
    {
        search(p,line[i]);
    }
}

