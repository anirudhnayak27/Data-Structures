// code for expression tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct stack
{
    struct node *data[10];
    int top;
};
void push(struct stack *a,struct node *b)
{
    if(a->top<10)
    {
    a->top++;
    a->data[a->top]=b;
    }
    else
    {
        printf("stack overflow\n");
    }
}
struct node *pop(struct stack *a)
{
    struct node *temp=NULL;
    if(a->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
    temp=a->data[a->top];
    a->top--;
    }
    return(temp);
}
struct node *peek(struct stack *a)
{
    return(a->data[a->top]);
}
int isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
struct node *create(char c)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=c;
    temp->left=NULL;
    temp->right=NULL;
    return(temp);
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct stack a;
    struct node *temp=NULL;
    struct node *t1=NULL;
    struct node *t2=NULL;
    char c[10];
    int i=0;
    a.top=-1;
    printf("enter postfix expression\n");
    scanf("%s",c);
    while(c[i]!='\0')
    {
        if(isoperator(c[i]))
        {
            temp=create(c[i]);
            t1=pop(&a);
            t2=pop(&a);
            temp->left=t2;
            temp->right=t1;
            push(&a,temp);
        }
        else
        {
            temp=create(c[i]);
            push(&a,temp);
        }
        i++;
    }
    inorder(peek(&a));
}
//input : ab+cde+**