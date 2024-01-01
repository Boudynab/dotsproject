#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 14
#include "login.h"
#include "enviro.h"
#include "computer.h"


void dis_compu(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2)
       {



         printf("his compboxes(%d) %s",*ptr2,player2);
        printf("\n playing boxes= %d\n",(*ptr1+*ptr2));
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-(*ptr1+*ptr2));
      if(winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==1||winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==2)
       {
          *ptr2=*ptr2+winBoxes(board, rows, columns,rows1,columns1,rows2,columns2);
          dfs2(board,rows,columns,rows1,columns1,rows2,columns2,ptr2);
          dfs2(board,rows,columns,rows1,columns1,rows2,columns2,ptr2);
           dfs2(board,rows,columns,rows1,columns1,rows2,columns2,ptr2);
           dfs2(board,rows,columns,rows1,columns1,rows2,columns2,ptr2);
          printBoard(board, rows, columns);
            printf("\n playing boxes= %d\n",(*ptr1+*ptr2));
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-(*ptr1+*ptr2));

        if((*ptr1+*ptr2)<(rows-1)*(columns-1))
    scan_computer(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);

  }


 }



void scan_computer(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2, char player1[20], char player2[20], int *ptr1, int *ptr2)
{
    int x = 0;
    int d,i;
    srand(time(NULL));

    while (x == 0)
    {
        int b = rand() % (2 * rows - 1);
        int j = rand() % (2 * columns - 1);
        for ( d = b; d < 2 * rows - 1; d++)
        {
            for ( i = j; i < 2 * columns - 1; i++)
            {
                if (d % 2 == 1 && board[d][i] ==' ' && i % 2 == 0)
                {
                    board[d][i] = '|';

                     lines(board,(d-1)/2, i/2, (d+1)/2, i/2);
                      comp_player2(board,rows,columns,(d-1)/2, i/2, (d+1)/2, i/2);
                       printBoard(board, rows, columns);
                        printf("\n%d %d\n",d,i);
                     x = 1;
                    break;
                }
                else if (i % 2 == 1 && board[d][i] == ' ' && d % 2 == 0)
                {
                    board[d][i] = '-';
                     lines(board, d/2, (i-1)/2, d/2, (i+1)/2);
                      comp_player2(board,rows,columns, d/2, (i-1)/2, d/2, (i+1)/2);
                       printBoard(board, rows, columns);
                       printf("\n%d %d\n",d,i);
                     x = 2;
                    break;
                }
            }
            if (x == 1 || x==2)
                break;
        }
    }
    if(x==1)
        dis_compu(board, rows, columns,(d-1)/2, i/2, (d+1)/2, i/2, player1, player2, ptr1, ptr2);
   else if(x==2)
        dis_compu(board, rows, columns,d/2, (i-1)/2, d/2, (i+1)/2, player1, player2, ptr1, ptr2);
}




void compu_mode()
{
char name1[20];
fflush(stdin);
printf("input your name :");
gets(name1);

 printf("\n========================================================================================================================\n");
typedef struct
{
 int rows;
 int columns;

}level;
level lev[2]={
    {3,3},{6,6}
};
int x;
printf("1:beginners\n2:expert\n");
printf("select the number of level=");
scanf("%d",&x);
char cmp[20]="computer";
game(lev[x-1].rows,lev[x-1].columns,name1,cmp,0);

}
