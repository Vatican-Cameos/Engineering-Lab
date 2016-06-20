#include<stdio.h>
void main(){
int locks,stocks,barrels,tstocks,tlocks,tbarrels;
float com,sales,lprice,sprice,bprice;
tstocks=0;
tlocks=0;
tbarrels=0;
lprice=45;
sprice=30;
bprice=25;
int c1,c2,c3;
int temp;

printf("Enter the locks");
scanf("%d",&locks);
while(locks!=-1)
{
c1=locks<0&&locks>70;
printf("Enter the number of stocks and barrels");
scanf("%d%d",&stocks,&barrels);
c2=stocks<0&&stocks>80;
c3=barrels<0&&barrels>90;

if(c1)
printf("Locks not in range");
else
{
temp=tlocks+locks;
if(temp>70)
printf("Locks went out of range");
else
tlocks=temp;
}

if(c2)
printf("Stocks not in range");
else
{
temp=tstocks+stocks;
if(temp>80)
printf("stocks went out of range");
else
tstocks=temp;
}

if(c3)
printf("Barrels not in range");
else
{
temp=tbarrels+barrels;
if(temp>90)
printf("Barrels went out of range");
else
tbarrels=temp;
}
printf("enter locks value %d",locks);
scanf("%d",&locks);
}

printf("Locks stocks and barrels are %d%d%d",tlocks,tstocks,tbarrels);
sales = lprice*tlocks+sprice*stocks+bprice*tbarrels;

if(sales>0)
{
if(sales>1800){
com=1000*0.10;
com=800*0.15+com;
com=com+(sales-1800)*0.20;
}
else if(sales>1000){
com=1000*0.10;
com=(sales-1000)*0.15+com;
}
else com=sales*0.10;
printf("The sales and comm are %f%f",sales,com);
}
else
{
printf("No sales");

}
}
