#include <stdio.h>
#define size 8
char board[size][size];
void init_board()
{
    int i;
    for (i=0;i<size;i++)
    {
        board[1][i]='p';
        board[6][i]='P';
    }
    board[0][0]='r';
    board[0][7]='r';
    board[7][0]='R';
    board[7][7]='R';
    board[0][1]='n';
    board[0][6]='n';
    board[7][1]='N';
    board[7][6]='N';
    board[0][2]='b';
    board[0][5]='b';
    board[7][2]='B';
    board[7][5]='B';
    board[0][3]='q';
    board[7][3]='Q';
    board[0][4]='k';
    board[7][4]='K';
}
void print_board()
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
}
void main()
{
   int n;
   char p;
   scanf("%c",&p);
   scanf("%d",&n);
    init_board();
    print_board();
}
