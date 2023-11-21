#include<stdio.h>
void display(char board[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%s ",board[i+j]);
        }
        //i++;
    }
    /*for(i=0;i<2;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%s ",board[i][j]);
        }
    }
    for(i=7;i>5;i--)
    {
        for(j=0;j<8;j++)
        {
            printf("%s ",board[i][j]);
        }
    }*/
}
void main()
{
    char board[8][8];
    int i,j;
    char p[4];
    int pos=0;
    scanf("%s",p);
    scanf("%d",&pos);
    char w1[7]={'w_r1','w_b1','w_k1','w_k','w_q','w_k2','w_b2','w_r2'};
    char w2[7]={'w_p1','w_p2','w_p3','w_p4','w_p5','w_p6','w_p7','w_p8'};
    char b1[7]={'b_r1','b_b1','b_k1','b_k','b_q','b_k2','b_b2','b_r2'};
    char b2[7]={'b_p1','b_p2','b_p3','b_p4','b_p5','b_p6','b_p7','b_p8'};
    for(i=0;i<2;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i==0)
            {
                  board[i][j]=w1[j];
            }
            else
            {
                  board[i][j]=w2[j];
            }
        }
    }
    for(i=7;i>5;i--)
    {
        for(j=0;j<8;j++)
        {
            if(i==0)
            {
                  board[i][j]=b1[j];
            }
            else
            {
                  board[i][j]=b2[j];
            }
        }
    }
    display(board);
}
