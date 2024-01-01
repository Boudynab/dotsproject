#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enviro.h"
#include "computer.h"

typedef struct {
    char name[30];
    int score;
} emp;

emp ranks[100];

void storage_data(char player1[20], char player2[20], int* ptr1, int* ptr2) {
    FILE *fptr;

    ranks[0].score = *ptr1;
    ranks[1].score = *ptr2;

    printf("\n%d\n", ranks[0].score);

    strcpy(ranks[0].name, player1);
    strcpy(ranks[1].name, player2);

    if ((fptr = fopen("ranks.txt", "ab")) == NULL) {
        printf("Can't open file");
        exit(1);
    }

    int x = 0;
    do {
        fprintf(fptr, "%s %d\n", ranks[x].name, ranks[x].score);
        x++;
    } while (x < 2);

    fclose(fptr);
}

void read_and_sort_top_players() {
    FILE *fptr;
    int i, j;
    emp temp;

    if ((fptr = fopen("ranks.txt", "rb")) == NULL) {
        printf("Can't open file");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        fscanf(fptr, "%s %d", ranks[i].name, &ranks[i].score);
    }

    fclose(fptr);

    for (i = 0; i < 100; i++) {
        for (j = i + 1; j < 100; j++) {
            if (ranks[i].score < ranks[j].score) {
                temp = ranks[i];
                ranks[i] = ranks[j];
                ranks[j] = temp;
            }
        }
    }

    printf("Top 10 Scores:\n");
    for (i = 0; i < 10; i++) {
        printf("%s - %d\n", ranks[i].name, ranks[i].score);
    }
}



void login()
{
typedef struct
{
    char name[100];
}informations;
informations players[2];
fflush(stdin);
for(int i=0;i<2;i++)
{
printf("input name for player %d:",i+1);
gets(players[i].name);
}
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
game(lev[x-1].rows,lev[x-1].columns,players[0].name,players[1].name,1);

}



