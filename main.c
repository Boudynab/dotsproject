#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "login.h"
#include "enviro.h"
#include "computer.h"
#include "load.h"
int main() {
printf("\t\t\t\t\t\t\t|BOXES & DOTS GAME|\n");
printf("\t\t\t\t\t\t\t====================\n");
int mode;
printf("1:computer mode\n2:one to one mode:\n");
printf("select your mode:");
scanf("%d",&mode);
 printf("\n========================================================================================================================\n");
if(mode==2)

{int cho;
  printf("1:new game\n2:load saved game\n");
  printf("Select your choice:");
  scanf("%d",&cho);
  printf("\n========================================================================================================================\n");
  if(cho==1)
  {
  login();
  }
  else if(cho==2)
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
load(lev[x-1].rows,lev[x-1].columns);
  }
  else
    printf("NOT VALID INPUTS");
}
else if(mode==1)
  compu_mode();
  return 0;

}
