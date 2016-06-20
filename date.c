#include<stdio.h>

int check(int day,int month){
if((month==4)&&day==31)
return 1;
else 
return 0;
}

int isleap(year){
if((year%4==0&&year%100!=0)||year%400==0)
return 1;
else 
return 0;
}

void main()
{
int dd,mm,yy,ndd,nmm,nyy;char flag;
do{
printf("Enter dd mm yy");
scanf("%d%d%d",&dd,&mm,&yy);
nmm=mm;
nyy=yy;

if(check(dd,mm)){
flag='n';
printf("no");
}
if(mm==2){
if(isleap(yy)&&dd>29){
flag='n';
printf("no");
}
else if(!isleap(yy)&&dd>28){
flag='n';
printf("no");
}}
}while(flag=='n');

switch(mm)
{
case 1:if(dd<31)
ndd=dd+1;
else
{
ndd=1;
nmm=mm+1;
}
break;
case 2:
if(dd<28)
ndd=dd+1;
else if(isleap(yy)&&dd<29)
ndd+1;
else if(dd==28||dd==29)
{
ndd=1;
nmm=3;
}
break;
}
printf("%d%d%d",ndd,nmm,nyy);
}

