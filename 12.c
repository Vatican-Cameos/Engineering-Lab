#include<stdio.h>
#include<conio.h>
#define min(x,y)((x)<(y)?(x):(y))
#define max(x,y)((x)>(y)?(x):(y))
#define MAX 25
int main()
{
clrscr();
int cap,oprt,nsec,cont,i=0,inp[MAX],ch;
printf("LEAKY BUCKET ALGO\n");
printf("\nENTER BUCKET SIZE\n");
scanf("%d",&cap);
printf("\nENTER THE OUTPUT RATE\n");
scanf("%d",&oprt);
do
{
printf("\nENTER THE NO. OF PACKETS ENTERING AT %d SECOND\n",i+1);
scanf("%d",&inp[i]);
i++;
printf("\n ENTER 1 TO INSERT PACKETS OR 0 TO QUIT\n");

