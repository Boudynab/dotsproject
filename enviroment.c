#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 14
#include "login.h"
#include "computer.h"
#include "load.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define A         "|"
#define B         "-"
#define C      RED"|"RESET
#define D      RED"-"RESET
#define E      BLUE"-"RESET
#define F      BLUE"-"RESET
 extern int num=0;
void storage_data(char player1[20],char player2[20],int *ptr1,int* ptr2);
void dis_compu(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr2,int*ptr1);
void undo2(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2)
{
     if(rows1==rows2)
        {   int x=(columns1>columns2) ? columns1:columns2;
            board[rows1*2][2*x-1]=' ' ;
             printBoard(board, rows, columns);

        }
        else if(columns1==columns2)
        {   int x=(rows1>rows2) ? rows1:rows2;
            board[2*x-1][2*columns1]=' ';
             printBoard(board, rows, columns);
        }
       scan_player2(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
}
void undo(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2)
{
     if(rows1==rows2)
        {   int x=(columns1>columns2) ? columns1:columns2;
            board[rows1*2][2*x-1]=' ' ;
             printBoard(board, rows, columns);
        }
        else if(columns1==columns2)
        {   int x=(rows1>rows2) ? rows1:rows2;
            board[2*x-1][2*columns1]=' ';
             printBoard(board, rows, columns);
        }
       scan_player1(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
}
void scan_computer(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2);
void dfs2(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2,int*ptr2)
{
for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(i%2==1 && board[d][i]==' '&& d%2==0)
        {
        if(d<(2*rows-1) && board[d+2][i]=='-' &&board[d+1][i-1]=='|' && board[d+1][i+1]=='|')
         { board[d][i]='-';
           board[d+1][i]='B';
           ++*ptr2;
         }
        if(d>0 && board[d-2][i]=='-' && board[d-1][i+1]=='|' && board[d-1][i-1]=='|')
          {
           board[d][i]='-';
           board[d-1][i]='B';
           ++*ptr2;
          }
        }
    }
}


for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(d%2==1 && board[d][i]==' '&& i%2==0)
        {
        if(i<(2*columns-1)&& board[d][i+2]=='|' && board[d+1][i+1]=='-' && board[d-1][i+1]=='-')
           {
            board[d][i]='|';
            board[d][i+1]='B';
            ++*ptr2;
           }
         if(i>0 && board[d][i-2]=='|' && board[d+1][i-1]=='-' && board[d-1][i-1]=='-' )
            {
                board[d][i]='|';
                board[d][i-1]='B';
                ++*ptr2;
            }
}
    }
}
}
int dfs1(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2,int*ptr1)
{
for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(i%2==1 && board[d][i]==' '&& d%2==0)
        {
        if(d<(2*rows-1) && board[d+2][i]=='-'  &&board[d+1][i-1]=='|' && board[d+1][i+1]=='|')
         { board[d][i]='-' ;
           board[d+1][i]='A';
            ++*ptr1;
         }
        if(d>0 && board[d-2][i]=='-'  && board[d-1][i+1]=='|' && board[d-1][i-1]=='|')
          {
           board[d][i]='-' ;
           board[d-1][i]='A';
          ++*ptr1;
          }
        }
    }
}

for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(d%2==1 && board[d][i]==' '&& i%2==0)
        {
        if(i<(2*columns-1)&& board[d][i+2]=='|' && board[d+1][i+1]=='-' && board[d-1][i+1]=='-' )
           {
            board[d][i]='|';
            board[d][i+1]='A';
             ++*ptr1;
           }
         if(i>0 && board[d][i-2]=='|' && board[d+1][i-1]=='-' && board[d-1][i-1]=='-' )
            {
                board[d][i]='|';
                board[d][i-1]='A';
               ++*ptr1;
            }
}
    }
}
}

void comp_player2(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;

    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-'  &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
           board[rows1*2+1][2*x-1]='B';
        if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-'  && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            board[rows1*2-1][2*x-1]='B';
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-'  && board[2*x-2][(columns1*2)+1]=='-' )
            board[2*x-1][columns1*2+1]='B';
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-' && board[2*x-2][(columns1*2)-1]=='-' )
             board[2*x-1][columns1*2-1]='B';
     }


}
void comp_player1(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;

    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-'  &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
           board[rows1*2+1][2*x-1]='A';
         if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-' && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            board[rows1*2-1][2*x-1]='A';
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-'  && board[2*x-2][(columns1*2)+1]=='-' )
            board[2*x-1][columns1*2+1]='A';
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-'  && board[2*x-2][(columns1*2)-1]=='-' )
             board[2*x-1][columns1*2-1]='A';
     }


}

int winBoxes(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;
int count=0;
    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-'  &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
            count++;
         if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-' && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            count++;
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-'  && board[2*x-2][(columns1*2)+1]=='-' )
            count++;
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-' && board[2*x-2][(columns1*2)-1]=='-' )
             count++;
     }
return count;

}

int countBoxes(char board[][SIZE], int rows, int columns) {
   int boxes = 0;

for (int i = 0; i < 2 * rows - 1; i += 2) {
    for (int j = 0; j < 2 * columns - 1; j += 2) {
        if (i + 1 < 2 * rows - 1 && j + 1 < 2 * columns - 1) {
            if (board[i][j + 1] == '-'  && board[i + 2][j + 1] == '-'  &&
                board[i + 1][j] == '|' && board[i + 1][j + 2] == '|') {
                boxes++;
            }
        }
    }
}

return boxes;

}

void lines(char board[][SIZE],int rows1,int columns1,int rows2,int columns2)
{
        if(rows1==rows2)
        {   int x=(columns1>columns2) ? columns1:columns2;
            board[rows1*2][2*x-1]='-' ;
        }
        else if(columns1==columns2)
        {   int x=(rows1>rows2) ? rows1:rows2;
            board[2*x-1][2*columns1]='|';
        }


}
int isValidMove(char board[][SIZE],int rows1,int columns1,int rows2,int columns2) {
     if(rows1==rows2){
    int x=(columns1>columns2) ? columns1:columns2;
      if(board[rows1*2][2*x-1]=='-' )
        return 1;
     else return 0;
     }
     else if(columns1==columns2)
        {
          int x=(rows1>rows2) ? rows1:rows2;
           if (board[2*x-1][2*columns1]=='|')
            return 1;
          else return 0;
        }




}

int check_coordinates(int rows1, int columns1, int rows2, int columns2) {
    if ((rows1 == rows2 && abs(columns2 - columns1) == 1) || (columns1 == columns2 && abs(rows1 - rows2) == 1)) {
        return 0;
    } else {
        return 1;
    }
}

void player2(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
    for (int i = 0; i < 2 * rows - 1; i++) {
        for (int j = 0; j < 2 * columns - 1; j++) {
            if (i == rows1 && j == columns1)
                board[i * 2][j * 2] = 'X';
            else if (i == rows2 && j == columns2)
                board[i * 2][j * 2] = 'X';
        }
    }
}

void player1(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
    for (int i = 0; i < 2 * rows - 1; i++) {
        for (int j = 0; j < 2 * columns - 1; j++) {
            if (i == rows1 && j == columns1)
                board[i * 2][j * 2] = 'O';
            else if (i == rows2 && j == columns2)
                board[i * 2][j * 2] = 'O';
        }
    }
}

void initializeBoard(char board[][SIZE], int rows, int columns) {
    for (int i = 0; i < 2 * rows - 1; i++) {
        for (int j = 0; j < 2 * columns - 1; j++) {
                if(i%2==1 || j%2==1)
               {
                   board[i][j]=' ';

               }
            else
             {board[i][j] = '.';

             }
        }
    }
     printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\t\t|LET'S START THE GAME|\n");
            printf("\t\t\t\t\t\t\t======================\n");

}

void printBoard(char board[][SIZE], int rows, int columns) {
    printf("  ");
    int b = 0;
    for (int i = 0; i < 2 * columns - 1; i++) {
        if (i % 2 == 1)
            printf("  ");
        else if (i == 0)
            printf("%d ",i );
        else {
            printf("%d ",i - b-1);
            b++;
        }
    }
    int x,y,z,w,o,p,n,m;
    b = 0;
    printf("\n");

    for (int i = 0; i < 2 * rows - 1; i++) {
        if (i % 2 == 1)
            printf(" ");
        else if (i == 0)
            printf("%d",i );
        else {
            printf("%d",i - b-1);
            b++;
        }
        for (int j = 0; j < 2 * columns - 1; j++) {
                if(board[i][j]=='A')
                    printf(RED" %c"RESET,board[i][j]);
                else if(board[i][j]=='B')
                    printf(BLUE" %c"RESET,board[i][j]);
                else
                    printf(" %c",board[i][j]);
        }
        printf("\n");
    }
}

void scan_coordinates1(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player[20])
{

     if(check_coordinates(rows1,columns1,rows2,columns2)==0 )
     {
    player1(board,rows,columns,rows1,columns1,rows2,columns2);
     lines(board,rows1,columns1,rows2,columns2);
      comp_player1(board,rows,columns,rows1,columns1,rows2,columns2);
         printBoard(board, rows, columns);
     }
    while (check_coordinates(rows1,columns1,rows2,columns2)==1)
{
  printf("%s:Enter your place:",player);
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
     save_ga(rows1,columns1,rows2,columns2);
         if(check_coordinates(rows1,columns1,rows2,columns2)==0 ){
             player1(board, rows, columns, rows1, columns1, rows2, columns2);
             lines(board,rows1,columns1,rows2,columns2);
              comp_player1(board,rows,columns,rows1,columns1,rows2,columns2);
                printBoard(board, rows, columns);
                break;

         } }
}
void scan_coordinates2(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player[20])
{

     if(check_coordinates(rows1,columns1,rows2,columns2)==0 )
     {

    player2(board, rows, columns, rows1, columns1, rows2, columns2);
    lines(board,rows1,columns1,rows2,columns2);
    comp_player2(board,rows,columns,rows1,columns1,rows2,columns2);
         printBoard(board, rows, columns);
     }
    while (check_coordinates(rows1,columns1,rows2,columns2)==1)
{
  printf("%s:Enter your place:",player);
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
     save_ga(rows1,columns1,rows2,columns2);
         if(check_coordinates(rows1,columns1,rows2,columns2)==0 ){
             player2(board, rows, columns, rows1, columns1, rows2, columns2);
             lines(board,rows1,columns1,rows2,columns2);
             comp_player2(board,rows,columns,rows1,columns1,rows2,columns2);
                printBoard(board, rows, columns);
                    break;

         } }
}
void scan_player1(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2)
       {

         printf("his compboxes(%d) %s:Enter your place:",*ptr1,player1);
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
   if(isValidMove(board,rows1,columns1,rows2,columns2)==0)
      {scan_coordinates1(board,rows,columns,rows1,columns1,rows2,columns2,player1);
        printf("\n playing boxes= %d\n",(*ptr1+*ptr2));
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-(*ptr1+*ptr2));
     char ch;
      fflush(stdin);
     printf("\n do you want undo?[y/n]");
      scanf("%c",&ch);
    if(ch=='y')
    {
       undo(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
    }
   else if(ch=='n')
                   {
save_ga(player1,player2,rows1,columns1,rows2,columns2,ptr1,ptr2);

         if(winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==1||winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==2)
       {
          *ptr1=*ptr1+winBoxes(board, rows, columns,rows1,columns1,rows2,columns2);
         dfs1(board,rows,columns,rows1,columns1,rows2,columns2,ptr1);
          dfs1(board,rows,columns,rows1,columns1,rows2,columns2,ptr1);
           dfs1(board,rows,columns,rows1,columns1,rows2,columns2,ptr1);
           dfs1(board,rows,columns,rows1,columns1,rows2,columns2,ptr1);
          printBoard(board, rows, columns);
            printf("\n playing boxes= %d\n",(*ptr1+*ptr2));
        printf("remaining boxes= %d\n",(rows-1)*(columns-1)-(*ptr1+*ptr2));
          if((*ptr1+*ptr2)<(rows-1)*(columns-1))
         scan_player1(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);

       }
                   }


    }else
        scan_player1(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);


       }


void scan_player2(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2)
       {

         printf("his compboxes(%d) %s:Enter your place:",*ptr2,player2);
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);

   if(isValidMove(board,rows1,columns1,rows2,columns2)==0)
      {scan_coordinates2(board,rows,columns,rows1,columns1,rows2,columns2,player2);
     printf("\n playing boxes= %d\n",(*ptr1+*ptr2));
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-(*ptr1+*ptr2));
      char ch;
      fflush(stdin);
     printf("\n do you want undo?[y/n]");
      scanf("%c",&ch);
    if(ch=='y')
    {
       undo2(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
    }
   else if(ch=='n')
{

save_ga(player1,player2,rows1,columns1,rows2,columns2,ptr1,ptr2);
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
    scan_player2(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);

  }
                   }


    }else
        scan_player2(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);


       }



void operate_game(int board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2){
        while (*ptr1+*ptr2<(rows-1)*(columns-1)) {
      scan_player1(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
      if((*ptr1+*ptr2)<(rows-1)*(columns-1))
      scan_player2(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);

    }
    if(*ptr1>*ptr2)
        printf("the WINNER is %s",player1);
    else if (*ptr1<*ptr2)
        printf("the WINNER is %s",player2);
    else
        printf("the game is DRAW");

    printf("\n\t\t\t\t\t\t\t\t\GAME END");

    }
void compu_operation(int board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2,char player1[20],char player2[20],int*ptr1,int*ptr2){
        while (*ptr1+*ptr2<(rows-1)*(columns-1)) {
      scan_player1(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
      if((*ptr1+*ptr2)<(rows-1)*(columns-1))
        scan_computer(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,ptr1,ptr2);
    }
    if(*ptr1>*ptr2)
        printf("the WINNER is %s",player1);
    else if (*ptr1<*ptr2)
        printf("the WINNER is %s",player2);
    else
        printf("the game is DRAW");
    printf("\n\t\t\t\t\t\t\t\t\GAME END");



    }

int game(int rows,int columns,char player1[20],char player2[20],int state) {
    char board[2 * rows - 1][SIZE];
    int score1=0; int score2=0;
    initializeBoard(board, rows, columns);
    printBoard(board, rows, columns);
    int rows1, columns1, rows2, columns2;
   int* ptr1;
   int*ptr2;
   ptr1=&score1;  ptr2=&score2;
    if (score1+score2<(rows-1)*(columns-1))
      {

        if(state==1)
          {operate_game(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,&score1,&score2);
           storage_data(player1,player2,ptr1,ptr2);
           read_and_sort_top_players();
          }
        if (state==0)
            compu_operation(board,rows,columns,rows1,columns1,rows2,columns2,player1,player2,&score1,&score2);

      }

}
