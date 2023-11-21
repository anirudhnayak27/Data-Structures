#include<stdio.h>
#include<stdlib.h>
#include <time.h>
typedef struct node
{
    int data;
    struct node *next;
}stack;
stack *top=NULL;
void push(int data)
{
    stack* new_node = (stack*) malloc(sizeof(stack));
    if (new_node==NULL)
    {
        return;
    }
    new_node->data=data;
    new_node->next=top;
    top=new_node;
}
int generate_random_number(int p, int q)
{
    return rand()%(q-p+1)+p;
}
int pop()
{
    if (top==NULL)
    {
        return -1;
    }
    stack*temp=top;
    int data=temp->data;
    top=top->next;
    free(temp);
    return data;
}
void main()
{
    FILE*f=fopen("Read.txt","w");
    int n, p, q,num,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of p: ");
    scanf("%d",&p);
    printf("Enter the value of q: ");
    scanf("%d",&q);
    srand(time(0));
    if (f==NULL)
    {
        printf("Failed to open file for writing.\n");
    }
    for (i=0;i<n;i++)
    {
        num=generate_random_number(p,q);
        fprintf(f,"%d\n",num);
        push(num);
    }
    fclose(f);
    FILE* f1=fopen("Write.txt","w");
    for(i=0;i<n;i++)
    {
        num=pop();
        fprintf(f1,"%d\n",2*num);
    }
    fclose(f1);
    FILE* f2=fopen("Write.txt","r");
    for(i=0;i<n;i++)
    {
        fprintf(f2,"%d\n",num);
        push(num);
    }
    fclose(f2);
    FILE* f3=fopen("Write.txt","w");
    for(i=0;i<n;i++)
    {
        num=pop();
        fprintf(f3,"%d\n",num);
    }
    fclose(f3);
}
