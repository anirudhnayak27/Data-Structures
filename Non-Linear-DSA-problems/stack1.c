//
//  stacks using array.c
//  stacks
//
//  Created by Anirudh on 8/13/22.
//

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data[10];
    int top;
};
void push(struct stack *a)
{
    if(a->top<10)
    {
    a->top++;
    printf("Enter data\n");
    scanf("%d",&a->data[a->top]);
    }
    else
    {
        printf("stack overflow\n");
    }
}
void pop(struct stack *a)
{
    int temp=0;
    if(a->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
    temp=a->data[a->top];
    a->top--;
    }
}
int peek(struct stack *a)
{
    return(a->data[a->top]);
}
int main()
{
     struct stack a;
    int c;
    a.top=-1;
    while(1)
    {
        printf("enter stack operation \n");
        printf("1--push\n");
        printf("2--pop\n");
        printf("3--peek\n");
        printf("4--exit\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1:push(&a);break;
            //case 2:printf("pop element is %d\n",pop(&a));break;
            case 3:printf("peek element is %d\n",peek(&a));break;
            case 4:exit(0);break;
            default:printf("invalid choice\n");break;
        }
    }

}
