#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 14
void dfs2(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2)
{
for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(i%2==1 && board[d][i]==' '&& d%2==0)
        {
        if(d<(2*rows-1) && board[d+2][i]=='-' &&board[d+1][i-1]=='|' && board[d+1][i+1]=='|')
         { board[d][i]='-';
           board[d+1][i]='B';
         }
        if(d>0 && board[d-2][i]=='-' && board[d-1][i+1]=='|' && board[d-1][i-1]=='|')
          {
           board[d][i]='-';
           board[d-1][i]='B';
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
           }
         if(i>0 && board[d][i-2]=='|' && board[d+1][i-1]=='-' && board[d-1][i-1]=='-')
            {
                board[d][i]='|';
                board[d][i-1]='B';

            }
}
    }
}
}
void dfs1(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2)
{
for(int d=0;d<2*rows-1;d++){
    for(int i=0;i<2*columns-1;i++){
        if(i%2==1 && board[d][i]==' '&& d%2==0)
        {
        if(d<(2*rows-1) && board[d+2][i]=='-' &&board[d+1][i-1]=='|' && board[d+1][i+1]=='|')
         { board[d][i]='-';
           board[d+1][i]='A';
         }
        if(d>0 && board[d-2][i]=='-' && board[d-1][i+1]=='|' && board[d-1][i-1]=='|')
          {
           board[d][i]='-';
           board[d-1][i]='A';
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
            board[d][i+1]='A';
           }
         if(i>0 && board[d][i-2]=='|' && board[d+1][i-1]=='-' && board[d-1][i-1]=='-')
            {
                board[d][i]='|';
                board[d][i-1]='A';

            }
}
    }
}
}

void comp_player2(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;

    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-' &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
           board[rows1*2+1][2*x-1]='B';
        if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-' && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            board[rows1*2-1][2*x-1]='B';
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-' && board[2*x-2][(columns1*2)+1]=='-')
            board[2*x-1][columns1*2+1]='B';
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-' && board[2*x-2][(columns1*2)-1]=='-')
             board[2*x-1][columns1*2-1]='B';
     }


}
void comp_player1(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;

    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-' &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
           board[rows1*2+1][2*x-1]='A';
         if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-' && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            board[rows1*2-1][2*x-1]='A';
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-' && board[2*x-2][(columns1*2)+1]=='-')
            board[2*x-1][columns1*2+1]='A';
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-' && board[2*x-2][(columns1*2)-1]=='-')
             board[2*x-1][columns1*2-1]='A';
     }


}

int winBoxes(char board[][SIZE], int rows, int columns, int rows1, int columns1, int rows2, int columns2) {
int x;
int count=0;
    if (rows1 == rows2) {
        x = (columns1 > columns2) ? columns1 : columns2;
        if(rows1<(2*rows-1) && board[(rows1*2)+2][2*x-1]=='-' &&board[(rows1*2)+1][2*x]=='|' && board[(rows1*2)+1][2*x-2]=='|')
            count++;
         if(rows1>0 && board[(rows1*2)-2][2*x-1]=='-' && board[(rows1*2)-1][2*x]=='|' && board[(rows1*2)-1][2*x-2]=='|')
            count++;
    }
     else if (columns1 == columns2) {
        x = (rows1 > rows2) ? rows1 : rows2;
        if(columns1<(2*columns-1)&& board[2*x-1][(columns1*2)+2]=='|' && board[2*x][(columns1*2)+1]=='-' && board[2*x-2][(columns1*2)+1]=='-')
            count++;
         if(columns1>0 && board[2*x-1][(columns1*2)-2]=='|' && board[2*x][(columns1*2)-1]=='-' && board[2*x-2][(columns1*2)-1]=='-')
             count++;
     }
return count;

}

int countBoxes(char board[][SIZE], int rows, int columns) {
   int boxes = 0;

for (int i = 0; i < 2 * rows - 1; i += 2) {
    for (int j = 0; j < 2 * columns - 1; j += 2) {
        if (i + 1 < 2 * rows - 1 && j + 1 < 2 * columns - 1) {
            if (board[i][j + 1] == '-' && board[i + 2][j + 1] == '-' &&
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
            board[rows1*2][2*x-1]='-';
        }
        else if(columns1==columns2)
        {   int x=(rows1>rows2) ? rows1:rows2;
            board[2*x-1][2*columns1]='|';
        }


}
int isValidMove(char board[][SIZE],int rows1,int columns1,int rows2,int columns2) {
     if(rows1==rows2){
    int x=(columns1>columns2) ? columns1:columns2;
      if(board[rows1*2][2*x-1]=='-')
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
                board[i][j]=' ';
            else
             board[i][j] = '.';


        }
    }
}

void printBoard(char board[][SIZE], int rows, int columns) {
    printf("  ");
    int b = 0;
    for (int i = 0; i < 2 * columns - 1; i++) {
        if (i % 2 == 1)
            printf("  ");
        else if (i == 0)
            printf("%d ", i );
        else {
            printf("%d ", i - b-1);
            b++;
        }
    }
    b = 0;
    printf("\n");

    for (int i = 0; i < 2 * rows - 1; i++) {
        if (i % 2 == 1)
            printf(" ");
        else if (i == 0)
            printf("%d", i );
        else {
            printf("%d", i - b-1);
            b++;
        }
        for (int j = 0; j < 2 * columns - 1; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}
void scan_coordinates1(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2)
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
  printf("player1:Enter your place:");
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
         if(check_coordinates(rows1,columns1,rows2,columns2)==0 ){
             player1(board, rows, columns, rows1, columns1, rows2, columns2);
             lines(board,rows1,columns1,rows2,columns2);
              comp_player1(board,rows,columns,rows1,columns1,rows2,columns2);
                printBoard(board, rows, columns);
                break;

         } }
}
void scan_coordinates2(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2)
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
  printf("player2:Enter your place:");
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
         if(check_coordinates(rows1,columns1,rows2,columns2)==0 ){
             player2(board, rows, columns, rows1, columns1, rows2, columns2);
             lines(board,rows1,columns1,rows2,columns2);
             comp_player2(board,rows,columns,rows1,columns1,rows2,columns2);
                printBoard(board, rows, columns);
                    break;

         } }
}
void scan_player1(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2)
       {

        printf("player1:Enter your place:");
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
   if(isValidMove(board,rows1,columns1,rows2,columns2)==0)
      {scan_coordinates1(board,rows,columns,rows1,columns1,rows2,columns2);
       int     y= countBoxes(board,rows,columns);
     printf("\n playing boxes= %d\n",y);
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-y);

     if(winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==1||winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==2)
       {
           static int x=0;
           x=x+winBoxes(board, rows, columns,rows1,columns1,rows2,columns2);
         printf("score player1= %d\n",x);
         dfs1(board,rows,columns,rows1,columns1,rows2,columns2);
          printBoard(board, rows, columns);
         scan_player1(board,rows,columns,rows1,columns1,rows2,columns2);
      }
    }else
        scan_player1(board,rows,columns,rows1,columns1,rows2,columns2);
       }
void scan_player2(char board[][SIZE],int rows,int columns,int rows1,int columns1,int rows2,int columns2)
       {

        printf("player2:Enter your place:");
    scanf("%d %d %d %d", &rows1, &columns1, &rows2, &columns2);
     if(isValidMove(board,rows1,columns1,rows2,columns2)==0)
      {scan_coordinates2(board,rows,columns,rows1,columns1,rows2,columns2);
     int   y= countBoxes(board,rows,columns);
       printf("\n playing boxes= %d\n",y);
     printf("remaining boxes= %d\n",(rows-1)*(columns-1)-y);
     if(winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==1||winBoxes(board, rows, columns,rows1,columns1,rows2,columns2)==2)
       {
           static int x=0;
            x=x+winBoxes(board, rows, columns,rows1,columns1,rows2,columns2);
         printf("score player2= %d\n",x);
          dfs2(board,rows,columns,rows1,columns1,rows2,columns2);
           printBoard(board, rows, columns);
         scan_player2(board,rows,columns,rows1,columns1,rows2,columns2);
       }

    } else{
        scan_player2(board,rows,columns,rows1,columns1,rows2,columns2);
       }
       }
   void printMenu() {
    printf("\nMain Menu:\n");
    printf("1. Play Level A\n");
    printf("2. Play Level B\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}
void showTime() {
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    printf("Current time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}
int main() {
     int rows, columns;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    char board[2 * rows - 1][SIZE];
    initializeBoard(board, rows, columns);
    printBoard(board, rows, columns);
    int rows1, columns1, rows2, columns2;
   check_coordinates(rows1,columns1,rows2,columns2);
    while ((pow((rows-1),2)-countBoxes(board,rows,columns))!=0) {
      scan_player1(board,rows,columns,rows1,columns1,rows2,columns2);
      scan_player2(board,rows,columns,rows1,columns1,rows2,columns2);
    }
    return 0;
}
