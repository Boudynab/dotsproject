#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 14
#include "login.h"
#include "enviro.h"
#include "computer.h"
typedef struct{
int row1;
int column1;
int row2;
int column2;
}coor;
coor co[49];
int x=0;
void save_ga(char player1[20], char player2[20],int row1, int row2, int column1, int column2, int* ptr1, int* ptr2) {
    co[x].row1 = row1;
    co[x].row2 = row2;
    co[x].column1 = column1;
    co[x].column2 = column2;

    FILE*save;
      if ((save = fopen("games.txt", "ab")) == NULL) {
        printf("Can't open file");
        exit(1);
    }
    fprintf(save,"%d %d %d %d ",co[x].row1,co[x].column1,co[x].row2,co[x].column2);
    fclose(save);
  x++;

}
void load(int rows,int columns,char player1[20],char player2[2]) {
    char board[2*rows-1][SIZE];
    FILE *load;
    if ((load = fopen("games.txt", "rb")) == NULL) {
        printf("Can't open file");
        exit(1);
    }
 initializeBoard(board, rows, columns);
    while (fscanf(load, "%d %d %d %d", &co[x].row1, &co[x].column1, &co[x].row2, &co[x].column2) == 4) {

        x++;
    }

    fclose(load);
}



